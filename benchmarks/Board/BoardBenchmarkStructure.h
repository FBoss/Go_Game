#ifndef BOARDBENCHMARKSTRUCTURE_H
#define BOARDBENCHMARKSTRUCTURE_H

#include <algorithm>

#include "Dimension.h"
#include "Stone.h"

template <class T> void SerialRead(benchmark::State &state) {
  T board;

  Go::Dimension dim = board.getDimension();

  for (auto _ : state) {
    for (volatile unsigned int row = 0; row < dim.row; ++row) {
      for (volatile unsigned int column = 0; column < dim.column; ++column) {
        board.get(row, column);
      }
    }
  }
}

template <class T> void RandomRead(benchmark::State &state) {
  T board;

  Go::Dimension dim = board.getDimension();

  std::vector<int> row_ids;
  std::vector<int> column_ids;

  for (int i = 0; i < dim.row; ++i) {
    row_ids.push_back(i);
  }
  std::random_shuffle(row_ids.begin(), row_ids.end());

  for (int i = 0; i < dim.column; ++i) {
    column_ids.push_back(i);
  }
  std::random_shuffle(column_ids.begin(), column_ids.end());

  for (auto _ : state) {
    for (auto row : row_ids) {
      for (auto column : column_ids) {
        board.get(row, column);
      }
    }
  }
}

template <class T> void SerialWrite(benchmark::State &state) {
  T board;

  Go::Dimension dim = board.getDimension();

  for (auto _ : state) {
    for (volatile unsigned int row = 0; row < dim.row; ++row) {
      for (volatile unsigned int column = 0; column < dim.column; ++column) {
        board.set(row, column, Go::Stone::black);
      }
    }
  }
}

template <class T> void RandomWrite(benchmark::State &state) {
  T board;

  Go::Dimension dim = board.getDimension();

  std::vector<int> row_ids;
  std::vector<int> column_ids;

  for (int i = 0; i < dim.row; ++i) {
    row_ids.push_back(i);
  }
  std::random_shuffle(row_ids.begin(), row_ids.end());

  for (int i = 0; i < dim.column; ++i) {
    column_ids.push_back(i);
  }
  std::random_shuffle(column_ids.begin(), column_ids.end());

  for (auto _ : state) {
    for (auto row : row_ids) {
      for (auto column : column_ids) {
        board.set(row, column, Go::Stone::black);
      }
    }
  }
}

template <class T> void DefaultConstruction(benchmark::State &state) {
  for (auto _ : state) {
    T board{};
  }
}

template <class T> void MoveConstruction(benchmark::State &state) {
  T board1{};
  for (auto _ : state) {
    T board2 = std::move(board1);
  }
}

template <class T> void MoveAssign(benchmark::State &state) {
  T board1{};
  T board2{};
  for (auto _ : state) {
    board2 = std::move(board1);
  }
}

template <class T> void CopyConstruction(benchmark::State &state) {
  T board1{};
  for (auto _ : state) {
    T board2 = board1;
  }
}

template <class T> void CopyAssign(benchmark::State &state) {
  T board1{};
  T board2{};
  for (auto _ : state) {
    board2 = board1;
  }
}

template <class T> void EqualOperator(benchmark::State &state) {
  T board1{};
  T board2{};

  for (auto _ : state) {
    board1 == board2;
  }
}

template <class T> void NotEqualOperator(benchmark::State &state) {
  T board1{};
  T board2{};

  for (auto _ : state) {
    board1 != board2;
  }
}

#endif // BOARDBENCHMARKSTRUCTURE_H
