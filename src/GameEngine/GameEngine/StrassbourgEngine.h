
#include "GameEngine/GameEngine.h"
#include "TwoDimensionArrayBoard.h"

#include <functional>

#include "Stone.h"

namespace Go::GameEngine {

using Group = std::vector<Go::Point>;

template <typename T> Group group(const Go::Board<T> &board, const Go::Point &point) {
  Group group{};

  if (not Go::isPointValid<T>(point)) {
    return group;
  }

  const Go::Stone player = board.get(point);

  T storage{};
  Go::Board<T> &visited = storage;

  const std::function<void(Go::Point)> func = [&](Go::Point p) {
    if (not Go::isPointValid<T>(p)) {
      return;
    }

    if (visited.get(p) == Go::Stone::empty) {
      visited.set(p, Go::Stone::black);

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

template <typename T> void remove_group(Go::Board<T> &board, const Group &grp) {
  std::for_each(grp.begin(), grp.end(), [&](auto &element) { board.set(element, Go::Stone::empty); });
}

using Liberties = std::vector<Go::Point>;

template <typename T> Liberties liberties(const Go::Board<T> &board, const Group &group) {
  Liberties list{};

  std::for_each(group.begin(), group.end(), [&](const Go::Point &p) {
    if (Go::Point upper{p.row, p.column + 1}; Go::isPointValid<T>(upper)) {
      if (board.get(upper) == Go::Stone::empty) {
        if (std::find(list.begin(), list.end(), upper) == list.end()) {
          list.emplace_back(upper);
        }
      }
    }
    if (Go::Point lower{p.row, p.column - 1}; Go::isPointValid<T>(lower)) {
      if (board.get(lower) == Go::Stone::empty) {
        if (std::find(list.begin(), list.end(), lower) == list.end()) {
          list.emplace_back(lower);
        }
      }
    }
    if (Go::Point right{p.row + 1, p.column}; Go::isPointValid<T>(right)) {
      if (board.get(right) == Go::Stone::empty) {
        if (std::find(list.begin(), list.end(), right) == list.end()) {
          list.emplace_back(right);
        }
      }
    }
    if (Go::Point left{p.row - 1, p.column}; Go::isPointValid<T>(left)) {
      if (board.get(left) == Go::Stone::empty) {
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

class StrassbourgEngine : public GameEngine<StrassbourgEngine> {
public:
  void play_black(int row, int column) {
    if (not(mState == GameState::start || mState == GameState::turn_black || mState == GameState::end_of_game)) {
      throw std::runtime_error("not blacks turn");
    }
    if (not isPlayValid(mBoard, {row, column}, Stone::black, mKo)) {
      throw std::runtime_error("invalid play");
    }

    mBoard.set(row, column, Stone::black);
    mPlayerPassed = false;
    mState = GameState::turn_white;

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

    if (mPrisoners.black >= 5) {
      mState = GameState::game_over;
    }
  }

  void play_white(int row, int column) {
    if (not(mState == GameState::start || mState == GameState::turn_white || mState == GameState::end_of_game)) {
      throw std::runtime_error("not whites turn");
    }

    if (not isPlayValid(mBoard, {row, column}, Stone::white, mKo)) {
      throw std::runtime_error("invalid play");
    }
    mBoard.set(row, column, Stone::white);
    mPlayerPassed = false;
    mState = GameState::turn_black;

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

    if (mPrisoners.white >= 5) {
      mState = GameState::game_over;
    }
  }

  bool is_play_valid(Stone stone, int row, int column)
  {
      return isPlayValid(mBoard, {row, column}, stone, mKo);
  }

  void play_white_pass() {
    if (not(mState == GameState::start || mState == GameState::turn_white)) {
      throw std::runtime_error("not whites turn");
    }

    if (mPlayerPassed == true) {
      mState = GameState::end_of_game;
    } else {
      mState = GameState::turn_black;
    }

    mPlayerPassed = true;
    mKo = std::nullopt;
  }

  void play_black_pass() {
    if (not(mState == GameState::start || mState == GameState::turn_black)) {
      throw std::runtime_error("not blacks turn");
    }

    if (mPlayerPassed == true) {
      mState = GameState::end_of_game;
    } else {
      mState = GameState::turn_white;
    }

    mPlayerPassed = true;
    mKo = std::nullopt;
  }

  const auto &board() { return mBoard; }

  const Prisoners &prisoners() { return mPrisoners; }

  Score score(const std::vector<Territory> &territory = {}) {
    int score_white = mPrisoners.white;
    int score_black = mPrisoners.black;

    if (mState == GameState::end_of_game) {

      for (int x = 0; x < mBoard.getDimension().row; ++x) {
        for (int y = 0; y < mBoard.getDimension().column; ++y) {
          const auto point = mBoard.get(x, y);
          if (point == Stone::empty) {
            const auto iterator = std::find_if(territory.begin(), territory.end(), [&](const auto &terr) {
              if (terr.point == Point{x, y}) {
                return true;
              } else {
                return false;
              }
            });
            if (iterator != territory.end()) {
              if (iterator->player == Stone::black) {
                ++score_black;
              } else if (iterator->player == Stone::white) {
                ++score_white;
              }
            }
          } else if (point == Stone::white) {
            ++score_white;
          } else {
            ++score_black;
          }
        }
      }
    }

    if (mState == GameState::game_over && mScoreType != ScoreType::win_by_resign) {
      mScoreType = ScoreType::score;
      if (score_black > score_white) {
        mWinner = Stone::black;
      } else if (score_black < score_white) {
        mWinner = Stone::white;
      } else {
        mScoreType = ScoreType::jigo;
      }
    }

    return Score{score_black, score_white, mWinner, mScoreType};
  }

  GameState state() { return mState; };

  void remove_dead_stones(const std::vector<Point> &points) {
    if (mState != GameState::end_of_game) {
      throw std::runtime_error("removing dead stones is not allow in current game state");
    }

    for (const auto &point : points) {
      const auto stone = mBoard.get(point.row, point.column);

      if (stone == Stone::black) {
        ++mPrisoners.white;
      } else if (stone == Stone::white) {
        ++mPrisoners.black;
      }

      mBoard.set(point.row, point.column, Stone::empty);
    }
  }

  void place_stones(const std::vector<Territory> &stones) {
    if (mState != GameState::end_of_game) {
      throw std::runtime_error("removing dead stones is not allow in current game state");
    }

    std::for_each(stones.begin(), stones.end(), [&](const auto &entry) { mBoard.set(entry.point.row, entry.point.column, entry.player); });
  }

  void play_black_resign() {
    if (mState == GameState::game_over) {
      throw std::runtime_error("game has already ended");
    }
    mState = GameState::game_over;
    mScoreType = ScoreType::win_by_resign;
    mWinner = Stone::white;
  }

  void play_white_resign() {
    if (mState == GameState::game_over) {
      throw std::runtime_error("game has already ended");
    }
    mState = GameState::game_over;
    mScoreType = ScoreType::win_by_resign;
    mWinner = Stone::black;
  }

private:
  BoardImpl mBoard;

  GameState mState = GameState::start;

  std::optional<Point> mKo;

  ScoreType mScoreType = ScoreType::ongoing;
  std::optional<Stone> mWinner = std::nullopt;

  bool mPlayerPassed = false;
  Prisoners mPrisoners;
};

} // namespace Go::GameEngine
