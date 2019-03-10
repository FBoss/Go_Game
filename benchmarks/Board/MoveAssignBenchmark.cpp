#include <benchmark/benchmark.h>

#include "BoardBenchmarkStructure.h"
#include "BitFieldBoard.h"
#include "TwoDimensionArrayBoard.h"
#include "ArrayBoard.h"

//MoveAssign
BENCHMARK_TEMPLATE(MoveAssign, Go::BitFieldBoard<0,0> );
BENCHMARK_TEMPLATE(MoveAssign, Go::BitFieldBoard<4,4> );
BENCHMARK_TEMPLATE(MoveAssign, Go::BitFieldBoard<9,9> );
BENCHMARK_TEMPLATE(MoveAssign, Go::BitFieldBoard<13,13> );
BENCHMARK_TEMPLATE(MoveAssign, Go::BitFieldBoard<17,17> );
BENCHMARK_TEMPLATE(MoveAssign, Go::BitFieldBoard<19,19> );
BENCHMARK_TEMPLATE(MoveAssign, Go::BitFieldBoard<100,100>);

BENCHMARK_TEMPLATE(MoveAssign, Go::TwoDimensionArrayBoard<0,0> );
BENCHMARK_TEMPLATE(MoveAssign, Go::TwoDimensionArrayBoard<4,4> );
BENCHMARK_TEMPLATE(MoveAssign, Go::TwoDimensionArrayBoard<9,9> );
BENCHMARK_TEMPLATE(MoveAssign, Go::TwoDimensionArrayBoard<13,13> );
BENCHMARK_TEMPLATE(MoveAssign, Go::TwoDimensionArrayBoard<17,17> );
BENCHMARK_TEMPLATE(MoveAssign, Go::TwoDimensionArrayBoard<19,19> );
BENCHMARK_TEMPLATE(MoveAssign, Go::TwoDimensionArrayBoard<100,100>);

BENCHMARK_TEMPLATE(MoveAssign, Go::ArrayBoard<0,0> );
BENCHMARK_TEMPLATE(MoveAssign, Go::ArrayBoard<4,4> );
BENCHMARK_TEMPLATE(MoveAssign, Go::ArrayBoard<9,9> );
BENCHMARK_TEMPLATE(MoveAssign, Go::ArrayBoard<13,13> );
BENCHMARK_TEMPLATE(MoveAssign, Go::ArrayBoard<17,17> );
BENCHMARK_TEMPLATE(MoveAssign, Go::ArrayBoard<19,19> );
BENCHMARK_TEMPLATE(MoveAssign, Go::ArrayBoard<100,100>);


BENCHMARK_MAIN();
