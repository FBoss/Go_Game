#include "GameEngine/StrassbourgEngine.h"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <random>

namespace Go::GameEngine::Player {

enum class MoveType { move, pass, resign };

struct Move
{
    MoveType type;
    Point point;
};

template <typename PLAYER, typename Engine>
struct Player{

  Move nextMove(Engine &engine, Stone stone) { return static_cast<PLAYER *>(this)->nextMove(engine, stone); }
};

template <typename Engine>
struct Contestant
{
    Contestant(int rank, std::string contestant_name): ranking{rank}, name{contestant_name}{}
    virtual Move nextMove(Engine &engine, Stone stone) = 0;

    int ranking;
    std::string name;
};

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

static std::default_random_engine generator{};

template <typename Engine> Move generateRandomMove(GameEngine<Engine> &engine, Stone stone) {
  // std::random_device r;
  //{r()};
  std::uniform_int_distribution<int> rowDistribution(0, engine.board().getDimension().row - 1);
  std::uniform_int_distribution<int> columnDistribution(0, engine.board().getDimension().column - 1);

  int row = rowDistribution(generator);
  int column = columnDistribution(generator);

  for (int limit = 1000; not engine.is_play_valid(stone, row, column); --limit) {
    row = rowDistribution(generator);
    column = columnDistribution(generator);

    if (limit <= 0) {
      return Move{MoveType::pass, {}};
    }
  }
  return Move{MoveType::move, {row, column}};
}

template <typename Engine>
struct RandomPlayer : public Player<ResignPlayer<Engine>, Engine>, Contestant<Engine>
{
    RandomPlayer(): Contestant<Engine>{2000, "Random"} {};

    Move nextMove(Engine &engine, Stone stone) override { return generateRandomMove(engine, stone); }

  private:
    std::default_random_engine generator;
};

template <typename Engine>
struct MonteCarloTreeSearchPlayer : public Player<MonteCarloTreeSearchPlayer<Engine>, Engine>, Contestant<Engine> {
  MonteCarloTreeSearchPlayer(unsigned int numberOfNodes, unsigned int depth, unsigned int playoutNumber)
      : Contestant<Engine>{2000,
                           {std::string{"MCTS-N"} + std::to_string(numberOfNodes) + "-D" + std::to_string(depth) + "-P" +
                            std::to_string(playoutNumber)}},
        mNumberOfNodes{numberOfNodes}, mDepth{depth}, mPlayoutNumber{playoutNumber} {};

  Move nextMove(Engine &engine, Stone stone) override {
    Node root = createTree(engine, stone);

    for (unsigned int i = 0; i < mPlayoutNumber; ++i) {
      playout(root);
    }

    const auto best_move =
        std::max_element(root.childeren.begin(), root.childeren.end(), [](const auto &lhs, const auto &rhs) { return lhs.win < rhs.win; });

    return (*best_move).move;
  }

private:
  struct Node {
    int win;
    int played;
    Engine engine;
    Stone stone;
    Move move;
    std::vector<Node> childeren;
  };

  Node createTree(Engine &engine, Stone stone) {
    Node root{0, 0, engine, stone, {}, {}};

    unsigned int nodeCount = 0;

    const std::function<void(Node &, int)> addNode = [&](Node &node, int depth) {
      if (depth == 0) {
        return;
      }

      if (node.engine.state() == GameState::game_over || node.engine.state() == GameState::end_of_game) {
        return;
      }

      const unsigned int path = std::uniform_int_distribution<>(0, node.childeren.size())(generator);

      if (path == node.childeren.size() || node.childeren.empty()) {
        Node newNode{0, 0, node.engine, node.stone, generateRandomMove(node.engine, node.stone), {}};
        applyMove(newNode.engine, newNode.move, newNode.stone);
        newNode.stone = inverse(newNode.stone);
        node.childeren.emplace_back(newNode);
        ++nodeCount;
      } else {
        addNode(node.childeren.at(path), --depth);
      }
    };

    while (nodeCount < mNumberOfNodes) {
      addNode(root, mDepth);
    }

    return root;
  }

  Stone inverse(Stone stone) { return (stone == Stone::black ? Stone::white : Stone::black); }

  int playout(Node &node) {
    ++node.played;

    if (node.childeren.empty()) {
      auto playoutEngine = node.engine;
      Stone stone = node.stone;

      while (playoutEngine.state() != GameState::game_over && playoutEngine.state() != GameState::end_of_game) {
        auto move = generateRandomMove(playoutEngine, stone);
        applyMove(playoutEngine, move, stone);
        stone = inverse(stone);
      }

      auto score = playoutEngine.score();
      if (score.type == ScoreType::score) {
        if (score.winner.value() == node.stone) {
          ++node.win;
          return 1;
        }
      } else if (score.type == ScoreType::ongoing) {
        if (node.stone == Stone::black) {
          if (score.black > score.white) {
            ++node.win;
            return 1;
          }
        } else {
          if (score.black < score.white) {
            ++node.win;
            return 1;
          }
        }
      }
      return 0;
    } else {
      const int path = std::uniform_int_distribution<>(0, node.childeren.size() - 1)(generator);

      const int result = playout(node.childeren.at(path));
      node.win += result;
      return result;
    }
  }

  void applyMove(Engine &engine, Move &move, Stone stone) {
    if (move.type == MoveType::move) {
      if (stone == Stone::black) {
        engine.play_black(move.point.row, move.point.column);
      } else {
        engine.play_white(move.point.row, move.point.column);
      }
    } else {
      if (stone == Stone::black) {
        engine.play_black_pass();
      } else {
        engine.play_white_pass();
      }
    }
  }

  const unsigned int mNumberOfNodes;
  const unsigned int mDepth;
  const unsigned int mPlayoutNumber;
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

    constexpr int numberOfRounds = 20;

    using UsedEngine = Go::GameEngine::StrassbourgEngine;

    MonteCarloTreeSearchPlayer<UsedEngine> mcts1{2, 1, 10};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts2{2, 1, 20};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts3{2, 1, 30};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts4{2, 1, 40};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts5{2, 1, 50};
    MonteCarloTreeSearchPlayer<UsedEngine> mcts6{2, 1, 60};
    ResignPlayer<UsedEngine> resign{};
    PassPlayer<UsedEngine> pass{};
    RandomPlayer<UsedEngine> random{};

    std::vector<Contestant<UsedEngine> *> contestants{&mcts1, &mcts2, &mcts3, &mcts4, &mcts5, &mcts6, &random};

    if(contestants.size()% 2 != 0)
    {
      contestants.emplace_back(&pass);
    }

    auto rng = std::default_random_engine {};

    const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    for(int i = 0; i < numberOfRounds; ++i)
    {
        std::shuffle(contestants.begin(), contestants.end(), rng);

    for(auto iterator = contestants.begin(); iterator != contestants.end(); iterator=iterator+2)
    {
        const auto player_black = *iterator;
        const auto player_white = *(iterator+1);
        const auto result = compete(player_black, player_white);

        float estimate_black = 1/(1+std::pow(10, (player_white->ranking - player_black->ranking)/400));
        float estimate_white = 1-estimate_black;

        float result_value_black = [&](){
            if(result.type == Go::GameEngine::ScoreType::jigo)
            {
                return 0.5;
            }
            if(result.type == Go::GameEngine::ScoreType::win_by_resign || result.type == Go::GameEngine::ScoreType::score)
            {
            if(result.winner == Go::Stone::black)
            {
                return 1.0;
            }else
            {
                return 0.0;
            }
            }
            if(result.type == Go::GameEngine::ScoreType::ongoing)
            {
                if (result.black == result.white)
                {
                    return 0.5;
                }else if( result.black>result.white)
                {
                    return 1.0;
                }else
                {
                    return 0.0;
                }
            }
            return 0.0;
        }();

        float result_value_white = 1-result_value_black;

        player_black->ranking = player_black->ranking + 50*(result_value_black-estimate_black);
        player_white->ranking = player_white->ranking + 50*(result_value_white-estimate_white);
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
