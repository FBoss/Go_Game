#include <benchmark/benchmark.h>

#include "BoardBenchmarkStructure.h"
#include "BitFieldBoard.h"
#include "TwoDimensionArrayBoard.h"
#include "ArrayBoard.h"
#include "MapBoard.h"
#include "UnorderedMapBoard.h"

//RandomRead
BENCHMARK_TEMPLATE(RandomRead, Go::BitFieldBoard<0,0> );
BENCHMARK_TEMPLATE(RandomRead, Go::BitFieldBoard<4,4> );
BENCHMARK_TEMPLATE(RandomRead, Go::BitFieldBoard<9,9> );
BENCHMARK_TEMPLATE(RandomRead, Go::BitFieldBoard<13,13> );
BENCHMARK_TEMPLATE(RandomRead, Go::BitFieldBoard<17,17> );
BENCHMARK_TEMPLATE(RandomRead, Go::BitFieldBoard<19,19> );
BENCHMARK_TEMPLATE(RandomRead, Go::BitFieldBoard<100,100>);

BENCHMARK_TEMPLATE(RandomRead, Go::TwoDimensionArrayBoard<0,0> );
BENCHMARK_TEMPLATE(RandomRead, Go::TwoDimensionArrayBoard<4,4> );
BENCHMARK_TEMPLATE(RandomRead, Go::TwoDimensionArrayBoard<9,9> );
BENCHMARK_TEMPLATE(RandomRead, Go::TwoDimensionArrayBoard<13,13> );
BENCHMARK_TEMPLATE(RandomRead, Go::TwoDimensionArrayBoard<17,17> );
BENCHMARK_TEMPLATE(RandomRead, Go::TwoDimensionArrayBoard<19,19> );
BENCHMARK_TEMPLATE(RandomRead, Go::TwoDimensionArrayBoard<100,100>);

BENCHMARK_TEMPLATE(RandomRead, Go::ArrayBoard<0,0> );
BENCHMARK_TEMPLATE(RandomRead, Go::ArrayBoard<4,4> );
BENCHMARK_TEMPLATE(RandomRead, Go::ArrayBoard<9,9> );
BENCHMARK_TEMPLATE(RandomRead, Go::ArrayBoard<13,13> );
BENCHMARK_TEMPLATE(RandomRead, Go::ArrayBoard<17,17> );
BENCHMARK_TEMPLATE(RandomRead, Go::ArrayBoard<19,19> );
BENCHMARK_TEMPLATE(RandomRead, Go::ArrayBoard<100,100>);

BENCHMARK_TEMPLATE(RandomRead, Go::MapBoard<0,0> );
BENCHMARK_TEMPLATE(RandomRead, Go::MapBoard<4,4> );
BENCHMARK_TEMPLATE(RandomRead, Go::MapBoard<9,9> );
BENCHMARK_TEMPLATE(RandomRead, Go::MapBoard<13,13> );
BENCHMARK_TEMPLATE(RandomRead, Go::MapBoard<17,17> );
BENCHMARK_TEMPLATE(RandomRead, Go::MapBoard<19,19> );
BENCHMARK_TEMPLATE(RandomRead, Go::MapBoard<100,100>);

BENCHMARK_TEMPLATE(RandomRead, Go::UnorderedMapBoard<0,0> );
BENCHMARK_TEMPLATE(RandomRead, Go::UnorderedMapBoard<4,4> );
BENCHMARK_TEMPLATE(RandomRead, Go::UnorderedMapBoard<9,9> );
BENCHMARK_TEMPLATE(RandomRead, Go::UnorderedMapBoard<13,13> );
BENCHMARK_TEMPLATE(RandomRead, Go::UnorderedMapBoard<17,17> );
BENCHMARK_TEMPLATE(RandomRead, Go::UnorderedMapBoard<19,19> );
BENCHMARK_TEMPLATE(RandomRead, Go::UnorderedMapBoard<100,100>);


BENCHMARK_MAIN();
