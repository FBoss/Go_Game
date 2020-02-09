#include "GameEngine/StrassbourgEngine.h"
#include "player/mcts.h"
#include "player/player.h"
#include "player/random.h"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <future>
#include <iostream>
#include <random>

namespace Go::GameEngine::Player {

template <typename Engine>
struct ResignPlayer : public Player<ResignPlayer<Engine>, Engine>, Contestant<Engine>
{
    ResignPlayer(): Contestant<Engine>{2000, "Resign"} {}
    Move nextMove(Engine &, Stone) override { return Move{MoveType::resign, {}}; }
};

template <typename Engine>
struct PassPlayer : public Player<ResignPlayer<Engine>, Engine>, Contestant<Engine>
{
    PassPlayer(): Contestant<Engine>{2000, "Pass"} {}
    Move nextMove(Engine &, Stone) override { return Move{MoveType::pass, {}}; }
};



template <typename Engine>
Score compete(Contestant<Engine> * black, Contestant<Engine> * white)
{
    Engine engine{};

    while(engine.state() != GameState::game_over && engine.state() != GameState::end_of_game)
    {
       if(engine.state() == GameState::start || engine.state() == GameState::turn_black)
       {
           const auto move = black->nextMove(engine, Stone::black);

           if(move.type == MoveType::move)
           {
               engine.play_black(move.point.row, move.point.column);
           }else if(move.type == MoveType::pass)
           {
               engine.play_black_pass();
           }else {
                engine.play_black_resign();
            }
       }else
       {
           const auto move = white->nextMove(engine, Stone::white);

           if(move.type == MoveType::move)
           {
               engine.play_white(move.point.row, move.point.column);
           }else if(move.type == MoveType::pass)
           {
               engine.play_white_pass();
           }else {
                engine.play_white_resign();
            }
       }
    }

    return engine.score();
}


} // Go::GameEngine::Player






int main()
{
    using namespace Go::GameEngine::Player;

    constexpr int numberOfRounds = 500;

    using UsedEngine = Go::GameEngine::StrassbourgEngine;

    MonteCarloTreeSearchPlayer<UsedEngine> mcts1{32, 4, 10};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts2{32, 8, 10};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts3{32, 16, 10};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts4{32, 4, 100};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts5{32, 8, 100};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts6{32, 16, 100};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts7{32, 4, 1000};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts8{32, 8, 1000};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts9{32, 16, 1000};

    MonteCarloTreeSearchPlayer<UsedEngine> mcts10{128, 4, 10};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts11{128, 8, 10};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts12{128, 16, 10};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts13{128, 4, 100};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts14{128, 8, 100};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts15{128, 16, 100};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts16{128, 4, 1000};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts17{128, 8, 1000};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts18{128, 16, 1000};

    MonteCarloTreeSearchPlayer<UsedEngine> mcts19{512, 4, 10};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts20{512, 8, 10};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts21{512, 16, 10};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts22{512, 4, 100};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts23{512, 8, 100};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts24{512, 16, 100};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts25{512, 4, 1000};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts26{512, 8, 1000};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts27{512, 16, 1000};
    ResignPlayer<UsedEngine> resign{};
    PassPlayer<UsedEngine> pass{};
    RandomPlayer<UsedEngine> random{};

    std::vector<Contestant<UsedEngine> *> contestants{
        &mcts1,  &mcts2,  &mcts3,  &mcts4,  &mcts5,  &mcts6,  &mcts7,  &mcts8,  &mcts9,  &mcts10, &mcts11, &mcts12, &mcts13, &mcts14,
        &mcts15, &mcts16, &mcts17, &mcts18, &mcts19, &mcts20, &mcts21, &mcts22, &mcts23, &mcts24, &mcts25, &mcts26, &mcts27, &random};
    // std::vector<Contestant<UsedEngine> *> contestants{&mcts1, &mcts2, &mcts3, &mcts4};

    if(contestants.size()% 2 != 0)
    {
      contestants.emplace_back(&pass);
    }

    auto rng = std::default_random_engine {};

    const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    for(int i = 0; i < numberOfRounds; ++i)
    {
      std::cout << "starting round: " << i << std::endl;

      std::shuffle(contestants.begin(), contestants.end(), rng);

      const auto gamePlay = [](auto player_black, auto player_white) {
        const auto result = compete(player_black, player_white);

        float estimate_black = 1 / (1 + std::pow(10, (player_white->ranking - player_black->ranking) / 400));
        float estimate_white = 1 - estimate_black;

        float result_value_black = [&]() {
          if (result.type == Go::GameEngine::ScoreType::jigo) {
            return 0.5;
          }
          if (result.type == Go::GameEngine::ScoreType::win_by_resign || result.type == Go::GameEngine::ScoreType::score) {
            if (result.winner == Go::Stone::black) {
              return 1.0;
            } else {
              return 0.0;
            }
          }
          if (result.type == Go::GameEngine::ScoreType::ongoing) {
            if (result.black == result.white) {
              return 0.5;
            } else if (result.black > result.white) {
              return 1.0;
            } else {
              return 0.0;
            }
          }
          return 0.0;
        }();

        float result_value_white = 1 - result_value_black;

        player_black->ranking = player_black->ranking + 50 * (result_value_black - estimate_black);
        player_white->ranking = player_white->ranking + 50 * (result_value_white - estimate_white);
      };

      auto a2 = std::async(gamePlay, &pass, &resign);
      std::vector<decltype(a2)> gamesInThisRound{};

      for (auto iterator = contestants.begin(); iterator != contestants.end(); iterator = iterator + 2) {
        const auto player_black = *iterator;
        const auto player_white = *(iterator + 1);
        gamesInThisRound.emplace_back(std::async(gamePlay, player_black, player_white));
        // gamePlay(player_black, player_white);
    }
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << '\n';

    std::sort(contestants.begin(), contestants.end(), [](const auto & left, const auto & right){return left->ranking>right->ranking;});

    std::for_each(contestants.begin(), contestants.end(), [](const auto & contest){
        std::cout << "Name: " << contest->name << ", ranking: " << contest->ranking << '\n';
    });

    return 0;
}
