#include "gtest/gtest.h"

#include "GameEngine/GameEngine.h"
#include "TwoDimensionArrayBoard.h"

#include <functional>

#include "Stone.h"

namespace Go::GameEngine {

using Group = std::vector<Point>;

template <typename T> Group group(const Board<T> &board, const Point &point) {
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

struct CapturedStones {
  std::vector<Group> black;
  std::vector<Group> white;
};

template <typename T> CapturedStones capture(const Board<T> &board, const Point &point) {
  CapturedStones captured{};
  if (isPointValid<T>(point)) {

    const auto update_capture_list = [&](const Point &p) -> void {
      if (Group grp = group(board, p); liberties(board, grp).empty()) {
        if (board.get(p) == Stone::black) {
          bool is_permutation = false;

          for (const auto &group : captured.black) {
            is_permutation |= std::is_permutation(grp.begin(), grp.end(), group.begin());
          }

          if (not is_permutation) {
            captured.black.emplace_back(grp);
          }
        } else if (board.get(p) == Stone::white) {
          bool is_permutation = false;

          for (const auto &group : captured.white) {
            is_permutation |= std::is_permutation(grp.begin(), grp.end(), group.begin());
          }

          if (not is_permutation) {
            captured.white.emplace_back(grp);
          }
        }
      }
    };

    if (const Point p{point.row - 1, point.column}; isPointValid<T>(p)) {
      update_capture_list(p);
    }
    if (const Point p{point.row + 1, point.column}; isPointValid<T>(p)) {
      update_capture_list(p);
    }
    if (const Point p{point.row, point.column - 1}; isPointValid<T>(p)) {
      update_capture_list(p);
    }
    if (const Point p{point.row, point.column + 1}; isPointValid<T>(p)) {
      update_capture_list(p);
    }
  }
  return captured;
}

template <typename T> bool isPlayValid(T b, const Point &point, Stone player, std::optional<Point> ko = std::nullopt) {
  Board<T> &board = b;
  // check coodrinates
  if (not isPointValid<T>(point)) {
    return false;
  }

  // check empty point
  if (board.get(point) != Stone::empty) {
    return false;
  }
  board.set(point, player);

  const auto captured = capture<T>(board, point);

  if (Stone::black == player) {
    if (captured.white.size() == 1) {
      if (captured.white.front().front() == ko.value_or(Point{-1, -1})) {
        return false;
      }
    }

    std::for_each(captured.white.begin(), captured.white.end(), [&](const auto &grp) { remove_group(board, grp); });
  } else {

    if (captured.black.size() == 1) {
      if (captured.black.front().front() == ko.value_or(Point{-1, -1})) {
        return false;
      }
    }

    std::for_each(captured.black.begin(), captured.black.end(), [&](const auto &grp) { remove_group(board, grp); });
  }

  if (liberties(board, group(board, point)).empty()) {
    return false;
  }

  return true;
}

using BoardImpl = TwoDimensionArrayBoard<9, 9>;

class StrassbourgEngine : public Go::GameEngine::GameEngine<StrassbourgEngine> {
public:
  void play_black(int row, int column) {
    if (not(mTurn != Stone::white)) {
      throw std::runtime_error("not blacks turn");
    }
    if (not isPlayValid(mBoard, {row, column}, Stone::black, mKo)) {
      throw std::runtime_error("invalid play");
    }

    mBoard.set(row, column, Stone::black);
    mPlayerPassed = false;
    mTurn = Stone::white;

    const auto captured = capture(mBoard, {row, column});

    std::for_each(captured.white.begin(), captured.white.end(), [&](const auto &group) {
      remove_group(mBoard, group);
      mPrisoners.black += group.size();
    });

    if (captured.white.size() == 1 && captured.white.front().size() == 1) {
      mKo = Point{row, column};
    } else {
      mKo = std::nullopt;
    }
  }

  void play_white(int row, int column) {
    if (not(mTurn != Stone::black)) {
      throw std::runtime_error("not whites turn");
    }

    if (not isPlayValid(mBoard, {row, column}, Stone::white, mKo)) {
      throw std::runtime_error("invalid play");
    }
    mBoard.set(row, column, Stone::white);
    mPlayerPassed = false;
    mTurn = Stone::black;

    const auto captured = capture(mBoard, {row, column});

    std::for_each(captured.black.begin(), captured.black.end(), [&](const auto &group) {
      remove_group(mBoard, group);
      mPrisoners.white += group.size();
    });

    if (captured.black.size() == 1 && captured.black.front().size() == 1) {
      mKo = Point{row, column};
    } else {
      mKo = std::nullopt;
    }
  }

  void play_white_pass() {
    if (not(mTurn != Stone::black)) {
      throw std::runtime_error("not whites turn");
    }
    mPlayerPassed = true;
    mTurn = Stone::black;
    mKo = std::nullopt;
  }

  void play_black_pass() {
    if (not(mTurn != Stone::white)) {
      throw std::runtime_error("not blacks turn");
    }
    mPlayerPassed = true;
    mTurn = Stone::white;
    mKo = std::nullopt;
  }

  const auto &board() { return mBoard; }

  const Prisoners &prisoners() { return mPrisoners; }

private:
  BoardImpl mBoard;

  Stone mTurn = Stone::empty;

  std::optional<Point> mKo;

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
