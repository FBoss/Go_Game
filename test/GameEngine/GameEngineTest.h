#include "gtest/gtest.h"

#include "GameEngine/GameEngine.h"
#include "TwoDimensionArrayBoard.h"

#include <functional>

#include "Stone.h"

namespace Go::GameEngine {

using Group = std::vector<Point>;

template <typename T> Group group(Board<T> &board, const Point &point) {
  Group group{};

  if (not isPointValid<T>(point)) {
    return group;
  }

  const Stone player = board.get(point);

  T storage{};
  Board<T> &visited = storage;

  const std::function<void(Point)> func = [&](Point p) {
    if (not isPointValid<T>(p)) {
      return;
    }

    if (visited.get(p) == Stone::empty) {
      visited.set(p, Stone::black);

      if (board.get(p) == player) {
        group.emplace_back(p);

        func({p.row + 1, p.column});
        func({p.row, p.column + 1});
        func({p.row - 1, p.column});
        func({p.row, p.column - 1});
      }
    }
  };

  func(point);

  return group;
}

template <typename T> void remove_group(Board<T> &board, const Group &grp) {
  std::for_each(grp.begin(), grp.end(), [&](auto &element) { board.set(element, Stone::empty); });
}

using Liberties = std::vector<Point>;

template <typename T> Liberties liberties(const Board<T> &board, const Group &group) {
  Liberties list{};

  std::for_each(group.begin(), group.end(), [&](const Point &p) {
    if (Point upper{p.row, p.column + 1}; isPointValid<T>(upper)) {
      if (board.get(upper) == Stone::empty) {
        if (std::find(list.begin(), list.end(), upper) == list.end()) {
          list.emplace_back(upper);
        }
      }
    }
    if (Point lower{p.row, p.column - 1}; isPointValid<T>(lower)) {
      if (board.get(lower) == Stone::empty) {
        if (std::find(list.begin(), list.end(), lower) == list.end()) {
          list.emplace_back(lower);
        }
      }
    }
    if (Point right{p.row + 1, p.column}; isPointValid<T>(right)) {
      if (board.get(right) == Stone::empty) {
        if (std::find(list.begin(), list.end(), right) == list.end()) {
          list.emplace_back(right);
        }
      }
    }
    if (Point left{p.row - 1, p.column}; isPointValid<T>(left)) {
      if (board.get(left) == Stone::empty) {
        if (std::find(list.begin(), list.end(), left) == list.end()) {
          list.emplace_back(left);
        }
      }
    }
  });

  return list;
}

using BoardImpl = TwoDimensionArrayBoard<9, 9>;

class StrassbourgEngine : public Go::GameEngine::GameEngine<StrassbourgEngine> {
public:
  void play_black(int row, int column) {
    if (not(mTurn != Stone::white)) {
      throw std::runtime_error("not blacks turn");
    }
    if (not is_play_valid(Stone::black, row, column)) {
      throw std::runtime_error("invalid play");
    }

    mBoard.set(row, column, Stone::black);
    mPlayerPassed = false;
    mTurn = Stone::white;

    if (Point point{row - 1, column}; isPointValid<BoardImpl>(point)) {
      if (mBoard.get(point.row, point.column) == mTurn) {
        if (Group grp = group(mBoard, point); liberties(mBoard, grp).empty()) {
          mPrisoners.black += grp.size();
          remove_group(mBoard, grp);
        }
      }
    }

    if (Point point{row, column - 1}; isPointValid<BoardImpl>(point)) {
      if (mBoard.get(point.row, point.column) == mTurn) {
        if (Group grp = group(mBoard, point); liberties(mBoard, grp).empty()) {
          mPrisoners.black += grp.size();
          remove_group(mBoard, grp);
        }
      }
    }
    if (Point point{row + 1, column}; isPointValid<BoardImpl>(point)) {
      if (mBoard.get(point.row, point.column) == mTurn) {
        if (Group grp = group(mBoard, point); liberties(mBoard, grp).empty()) {
          mPrisoners.black += grp.size();
          remove_group(mBoard, grp);
        }
      }
    }

    if (Point point{row, column + 1}; isPointValid<BoardImpl>(point)) {
      if (mBoard.get(point.row, point.column) == mTurn) {
        if (Group grp = group(mBoard, point); liberties(mBoard, grp).empty()) {
          mPrisoners.black += grp.size();
          remove_group(mBoard, grp);
        }
      }
    }
  }

  void play_white(int row, int column) {
    if (not(mTurn != Stone::black)) {
      throw std::runtime_error("not whites turn");
    }

    if (not is_play_valid(Stone::black, row, column)) {
      throw std::runtime_error("invalid play");
    }
    mBoard.set(row, column, Stone::white);
    mPlayerPassed = false;
    mTurn = Stone::black;

    if (Point point{row - 1, column}; isPointValid<BoardImpl>(point)) {
      if (mBoard.get(point.row, point.column) == mTurn) {
        if (Group grp = group(mBoard, point); liberties(mBoard, grp).empty()) {
          mPrisoners.white += grp.size();
          remove_group(mBoard, grp);
        }
      }
    }

    if (Point point{row, column - 1}; isPointValid<BoardImpl>(point)) {
      if (mBoard.get(point.row, point.column) == mTurn) {
        if (Group grp = group(mBoard, point); liberties(mBoard, grp).empty()) {
          mPrisoners.white += grp.size();
          remove_group(mBoard, grp);
        }
      }
    }
    if (Point point{row + 1, column}; isPointValid<BoardImpl>(point)) {
      if (mBoard.get(point.row, point.column) == mTurn) {
        if (Group grp = group(mBoard, point); liberties(mBoard, grp).empty()) {
          mPrisoners.white += grp.size();
          remove_group(mBoard, grp);
        }
      }
    }

    if (Point point{row, column + 1}; isPointValid<BoardImpl>(point)) {
      if (mBoard.get(point.row, point.column) == mTurn) {
        if (Group grp = group(mBoard, point); liberties(mBoard, grp).empty()) {
          mPrisoners.white += grp.size();
          remove_group(mBoard, grp);
        }
      }
    }
  }

  void play_white_pass() {
    if (not(mTurn != Stone::black)) {
      throw std::runtime_error("not whites turn");
    }
    mPlayerPassed = true;
    mTurn = Stone::black;
  }

  void play_black_pass() {
    if (not(mTurn != Stone::white)) {
      throw std::runtime_error("not blacks turn");
    }
    mPlayerPassed = true;
    mTurn = Stone::white;
  }

  bool is_play_valid(Stone stone, int row, int column) const {
    if (mBoard.get(row, column) != Stone::empty) {
      return false;
    }

    auto board = mBoard;
    board.set(row, column, stone);

    if (Point point{row - 1, column}; isPointValid<BoardImpl>(point)) {
      if (board.get(point.row, point.column) != mTurn) {
        if (Group grp = group(board, point); liberties(board, grp).empty()) {
          remove_group(board, grp);
        }
      }
    }

    if (Point point{row, column - 1}; isPointValid<BoardImpl>(point)) {
      if (board.get(point.row, point.column) != mTurn) {
        if (Group grp = group(board, point); liberties(board, grp).empty()) {
          remove_group(board, grp);
        }
      }
    }
    if (Point point{row + 1, column}; isPointValid<BoardImpl>(point)) {
      if (board.get(point.row, point.column) != mTurn) {
        if (Group grp = group(board, point); liberties(board, grp).empty()) {
          remove_group(board, grp);
        }
      }
    }

    if (Point point{row, column + 1}; isPointValid<BoardImpl>(point)) {
      if (board.get(point.row, point.column) != mTurn) {
        if (Group grp = group(board, point); liberties(board, grp).empty()) {
          remove_group(board, grp);
        }
      }
    }

    if (liberties(board, group(board, {row, column})).empty()) {
      return false;
    }

    return true;
  }

  const auto &board() { return mBoard; }

  const Prisoners &prisoners() { return mPrisoners; }

private:
  BoardImpl mBoard;

  Stone mTurn = Stone::empty;

  bool mPlayerPassed = false;
  Prisoners mPrisoners;
};

} // namespace Go::GameEngine

using namespace Go;
using namespace Go::GameEngine;

class GameEngineVerification : public ::testing::Test {
protected:
  StrassbourgEngine mEngine{};
};
