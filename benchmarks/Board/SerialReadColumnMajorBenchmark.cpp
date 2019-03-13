#include <benchmark/benchmark.h>

#include "ArrayBoard.h"
#include "BitFieldBoard.h"
#include "BoardBenchmarkStructure.h"
#include "TwoDimensionArrayBoard.h"
#include "MapBoard.h"
#include "UnorderedMapBoard.h"

// SerialReadColumnMajor
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::BitFieldBoard<0, 0>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::BitFieldBoard<4, 4>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::BitFieldBoard<9, 9>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::BitFieldBoard<13, 13>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::BitFieldBoard<17, 17>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::BitFieldBoard<19, 19>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::BitFieldBoard<100, 100>);

BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::TwoDimensionArrayBoard<0, 0>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::TwoDimensionArrayBoard<4, 4>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::TwoDimensionArrayBoard<9, 9>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::TwoDimensionArrayBoard<13, 13>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::TwoDimensionArrayBoard<17, 17>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::TwoDimensionArrayBoard<19, 19>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::TwoDimensionArrayBoard<100, 100>);

BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::ArrayBoard<0, 0>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::ArrayBoard<4, 4>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::ArrayBoard<9, 9>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::ArrayBoard<13, 13>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::ArrayBoard<17, 17>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::ArrayBoard<19, 19>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::ArrayBoard<100, 100>);

BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::MapBoard<0, 0>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::MapBoard<4, 4>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::MapBoard<9, 9>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::MapBoard<13, 13>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::MapBoard<17, 17>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::MapBoard<19, 19>);
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::MapBoard<100, 100>);

BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::UnorderedMapBoard<0,0> );
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::UnorderedMapBoard<4,4> );
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::UnorderedMapBoard<9,9> );
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::UnorderedMapBoard<13,13> );
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::UnorderedMapBoard<17,17> );
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::UnorderedMapBoard<19,19> );
BENCHMARK_TEMPLATE(SerialReadColumnMajor, Go::UnorderedMapBoard<100,100>);


BENCHMARK_MAIN();
