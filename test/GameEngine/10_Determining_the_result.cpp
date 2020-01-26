#include "GameEngineTest.h"

TEST_F(GameEngineVerification, result_remove_dead_only_possible_at_end_of_game) {
  mEngine.play_black(0, 0);
  mEngine.play_white(1, 0);
  mEngine.play_black(0, 1);
  mEngine.play_white(1, 1);
  mEngine.play_black(0, 2);

  ASSERT_EQ(mEngine.board().get(0, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::white);

  EXPECT_EQ(mEngine.score(), (Score{0, 0, std::nullopt, ScoreType::ongoing}));

  EXPECT_ANY_THROW(mEngine.remove_dead_stones({Point{0, 0}}));
  EXPECT_EQ(mEngine.board().get(0, 0), Stone::black);
  mEngine.play_white_pass();
  mEngine.play_black_pass();
  ASSERT_EQ(mEngine.state(), GameState::end_of_game);
  mEngine.remove_dead_stones({{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}});

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::empty);

  EXPECT_EQ(mEngine.score(), (Score{2, 3, std::nullopt, ScoreType::ongoing}));
}

TEST_F(GameEngineVerification, result_remove_dead_no_win_over_5_prisoners) {
  mEngine.play_white(0, 0);
  mEngine.play_black_pass();
  mEngine.play_white(0, 1);
  mEngine.play_black_pass();
  mEngine.play_white(0, 2);
  mEngine.play_black_pass();
  mEngine.play_white(1, 0);
  mEngine.play_black_pass();
  mEngine.play_white(1, 1);
  mEngine.play_black_pass();
  mEngine.play_white(1, 2);
  mEngine.play_black_pass();
  mEngine.play_white_pass();

  ASSERT_EQ(mEngine.board().get(0, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 2), Stone::white);
  ASSERT_EQ(mEngine.state(), GameState::end_of_game);
  ASSERT_EQ(mEngine.score(), (Score{0, 6, std::nullopt, ScoreType::ongoing}));

  mEngine.remove_dead_stones({{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}});

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 2), Stone::empty);
  EXPECT_EQ(mEngine.state(), GameState::end_of_game);
  EXPECT_EQ(mEngine.score(), (Score{6, 0, std::nullopt, ScoreType::ongoing}));
}

TEST_F(GameEngineVerification, result_remove_dead_add_to_existing_prisoners) {
  mEngine.play_white(0, 1);
  mEngine.play_black(0, 0);
  mEngine.play_white(0, 2);
  mEngine.play_black(1, 1);
  mEngine.play_white(1, 0);
  mEngine.play_black(1, 2);

  mEngine.play_white_pass();
  mEngine.play_black_pass();

  ASSERT_EQ(mEngine.board().get(0, 0), Stone::empty);
  ASSERT_EQ(mEngine.board().get(0, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 2), Stone::black);
  ASSERT_EQ(mEngine.state(), GameState::end_of_game);
  ASSERT_EQ(mEngine.score(), (Score{2, 4, std::nullopt, ScoreType::ongoing}));

  mEngine.remove_dead_stones({{1, 0}, {1, 1}});
  mEngine.remove_dead_stones({{1, 2}});
  EXPECT_EQ(mEngine.board().get(0, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(0, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 2), Stone::empty);
  EXPECT_EQ(mEngine.state(), GameState::end_of_game);
  EXPECT_EQ(mEngine.score(), (Score{1, 5, std::nullopt, ScoreType::ongoing}));
}

TEST_F(GameEngineVerification, result_score_empty_board) {

  mEngine.play_black_pass();
  mEngine.play_white_pass();
  ASSERT_EQ(mEngine.board().get(0, 0), Stone::empty);
  ASSERT_EQ(mEngine.board().get(0, 1), Stone::empty);
  ASSERT_EQ(mEngine.board().get(1, 0), Stone::empty);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::empty);

  const std::vector<Territory> territory{
      {Point{0, 0}, Stone::black}, {Point{0, 1}, Stone::black}, {Point{1, 0}, Stone::white}, {Point{1, 1}, Stone::white}};

  EXPECT_EQ(mEngine.score(territory), (Score{2, 2, std::nullopt, ScoreType::ongoing}));
}

TEST_F(GameEngineVerification, result_score_with_prisoners) {
  mEngine.play_black(0, 1);
  mEngine.play_white(0, 0);
  mEngine.play_black(1, 0);
  mEngine.play_white(1, 2);
  mEngine.play_black(2, 1);

  ASSERT_EQ(mEngine.board().get(0, 0), Stone::empty);
  ASSERT_EQ(mEngine.board().get(0, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 2), Stone::empty);
  ASSERT_EQ(mEngine.board().get(1, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::empty);
  ASSERT_EQ(mEngine.board().get(1, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 0), Stone::empty);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::black);
  ASSERT_EQ(mEngine.score(), (Score{1, 0, std::nullopt, ScoreType::ongoing}));

  mEngine.play_white_pass();
  mEngine.play_black_pass();
  ASSERT_EQ(mEngine.state(), GameState::end_of_game);

  const std::vector<Territory> territory{{Point{0, 0}, Stone::black}, {Point{0, 1}, Stone::black}, {Point{1, 0}, Stone::black},
                                         {Point{1, 1}, Stone::black}, {Point{0, 2}, Stone::white}, {Point{1, 2}, Stone::white},
                                         {Point{2, 0}, Stone::white}, {Point{2, 1}, Stone::white}};
  EXPECT_EQ(mEngine.score(territory), (Score{6, 3, std::nullopt, ScoreType::ongoing}));
}

TEST_F(GameEngineVerification, result_score_with_playout) {
  mEngine.play_white_pass();
  mEngine.play_black_pass();
  ASSERT_EQ(mEngine.state(), GameState::end_of_game);

  mEngine.place_stones(
      {{Point{0, 0}, Stone::black}, {Point{1, 1}, Stone::black}, {Point{1, 2}, Stone::black}, {Point{2, 0}, Stone::black}});
  mEngine.place_stones({{Point{0, 1}, Stone::white}, {Point{2, 1}, Stone::white}});

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(0, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::empty);
  const std::vector<Territory> territory{{Point{0, 0}, Stone::white}, {Point{0, 1}, Stone::white}, {Point{1, 0}, Stone::white},
                                         {Point{1, 1}, Stone::white}, {Point{0, 2}, Stone::black}, {Point{1, 2}, Stone::black},
                                         {Point{2, 0}, Stone::black}, {Point{2, 1}, Stone::black}};
  EXPECT_EQ(mEngine.score(territory), (Score{5, 3, std::nullopt, ScoreType::ongoing}));
}

TEST_F(GameEngineVerification, result_playout_only_end_of_game) {

  ASSERT_ANY_THROW(mEngine.place_stones({}));

  mEngine.play_black_pass();
  mEngine.play_white_pass();
  ASSERT_EQ(mEngine.state(), GameState::end_of_game);

  mEngine.place_stones({{Point{0, 0}, Stone::black}});

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::black);
}
