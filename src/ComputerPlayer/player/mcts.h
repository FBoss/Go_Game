#ifndef MONTECARLOTREESEARCH_PLAYER_H
#define MONTECARLOTREESEARCH_PLAYER_H

#include "player.h"
#include "player/random.h"

#include <cmath>
#include <functional>
#include <random>

namespace Go::GameEngine::Player {

template <typename Engine>
struct MonteCarloTreeSearchPlayer : public Player<MonteCarloTreeSearchPlayer<Engine>, Engine>, Contestant<Engine> {
  MonteCarloTreeSearchPlayer(unsigned int numberOfNodes, unsigned int depth, unsigned int playoutNumber)
      : Contestant<Engine>{2000,
                           {std::string{"MCTS-N"} + std::to_string(numberOfNodes) + "-D" + std::to_string(depth) + "-P" +
                            std::to_string(playoutNumber)}},
        mNumberOfNodes{numberOfNodes}, mDepth{depth}, mPlayoutNumber{playoutNumber} {};

  Move nextMove(Engine &engine, Stone stone) override {
    Node root = createTree(engine, stone);
    mPlayer = stone;

    for (unsigned int i = 0; i < mPlayoutNumber; ++i) {
      playout(root);
    }

    const auto best_move = std::max_element(root.childeren.begin(), root.childeren.end(), [&](const auto &lhs, const auto &rhs) {
      const auto branchScore = [&](const auto &branch) {
        const double win = branch.win;
        const double branchPlayed = branch.played;
        const double totalPlayed = mPlayoutNumber;
        const double exploration = 0.1; // std::log2(2);

        return win / branchPlayed + exploration * std::sqrt(std::log(totalPlayed) / branchPlayed);
      };

      return branchScore(lhs) < branchScore(rhs);
    });

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
        if (score.winner.value() == mPlayer) {
          ++node.win;
          return 1;
        }
      } else if (score.type == ScoreType::ongoing) {
        if (mPlayer == Stone::black) {
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
  Stone mPlayer;
  std::default_random_engine generator{1};
};

} // namespace Go::GameEngine::Player
#endif // MONTECARLOTREESEARCH_PLAYER_H
