#include <benchmark/benchmark.h>

#include "BoardBenchmarkStructure.h"
#include "BitFieldBoard.h"
#include "TwoDimensionArrayBoard.h"
#include "ArrayBoard.h"
#include "MapBoard.h"

//EqualOperator
BENCHMARK_TEMPLATE(EqualOperator, Go::BitFieldBoard<0,0> );
BENCHMARK_TEMPLATE(EqualOperator, Go::BitFieldBoard<4,4> );
BENCHMARK_TEMPLATE(EqualOperator, Go::BitFieldBoard<9,9> );
BENCHMARK_TEMPLATE(EqualOperator, Go::BitFieldBoard<13,13> );
BENCHMARK_TEMPLATE(EqualOperator, Go::BitFieldBoard<17,17> );
BENCHMARK_TEMPLATE(EqualOperator, Go::BitFieldBoard<19,19> );
BENCHMARK_TEMPLATE(EqualOperator, Go::BitFieldBoard<100,100>);

BENCHMARK_TEMPLATE(EqualOperator, Go::TwoDimensionArrayBoard<0,0> );
BENCHMARK_TEMPLATE(EqualOperator, Go::TwoDimensionArrayBoard<4,4> );
BENCHMARK_TEMPLATE(EqualOperator, Go::TwoDimensionArrayBoard<9,9> );
BENCHMARK_TEMPLATE(EqualOperator, Go::TwoDimensionArrayBoard<13,13> );
BENCHMARK_TEMPLATE(EqualOperator, Go::TwoDimensionArrayBoard<17,17> );
BENCHMARK_TEMPLATE(EqualOperator, Go::TwoDimensionArrayBoard<19,19> );
BENCHMARK_TEMPLATE(EqualOperator, Go::TwoDimensionArrayBoard<100,100>);

BENCHMARK_TEMPLATE(EqualOperator, Go::ArrayBoard<0,0> );
BENCHMARK_TEMPLATE(EqualOperator, Go::ArrayBoard<4,4> );
BENCHMARK_TEMPLATE(EqualOperator, Go::ArrayBoard<9,9> );
BENCHMARK_TEMPLATE(EqualOperator, Go::ArrayBoard<13,13> );
BENCHMARK_TEMPLATE(EqualOperator, Go::ArrayBoard<17,17> );
BENCHMARK_TEMPLATE(EqualOperator, Go::ArrayBoard<19,19> );
BENCHMARK_TEMPLATE(EqualOperator, Go::ArrayBoard<100,100>);

BENCHMARK_TEMPLATE(EqualOperator, Go::MapBoard<0,0> );
BENCHMARK_TEMPLATE(EqualOperator, Go::MapBoard<4,4> );
BENCHMARK_TEMPLATE(EqualOperator, Go::MapBoard<9,9> );
BENCHMARK_TEMPLATE(EqualOperator, Go::MapBoard<13,13> );
BENCHMARK_TEMPLATE(EqualOperator, Go::MapBoard<17,17> );
BENCHMARK_TEMPLATE(EqualOperator, Go::MapBoard<19,19> );
BENCHMARK_TEMPLATE(EqualOperator, Go::MapBoard<100,100>);


BENCHMARK_MAIN();
