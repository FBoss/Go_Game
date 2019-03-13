#include <benchmark/benchmark.h>

#include "BoardBenchmarkStructure.h"
#include "BitFieldBoard.h"
#include "TwoDimensionArrayBoard.h"
#include "ArrayBoard.h"
#include "MapBoard.h"

//RandomWrite
BENCHMARK_TEMPLATE(RandomWrite, Go::BitFieldBoard<0,0> );
BENCHMARK_TEMPLATE(RandomWrite, Go::BitFieldBoard<4,4> );
BENCHMARK_TEMPLATE(RandomWrite, Go::BitFieldBoard<9,9> );
BENCHMARK_TEMPLATE(RandomWrite, Go::BitFieldBoard<13,13> );
BENCHMARK_TEMPLATE(RandomWrite, Go::BitFieldBoard<17,17> );
BENCHMARK_TEMPLATE(RandomWrite, Go::BitFieldBoard<19,19> );
BENCHMARK_TEMPLATE(RandomWrite, Go::BitFieldBoard<100,100>);

BENCHMARK_TEMPLATE(RandomWrite, Go::TwoDimensionArrayBoard<0,0> );
BENCHMARK_TEMPLATE(RandomWrite, Go::TwoDimensionArrayBoard<4,4> );
BENCHMARK_TEMPLATE(RandomWrite, Go::TwoDimensionArrayBoard<9,9> );
BENCHMARK_TEMPLATE(RandomWrite, Go::TwoDimensionArrayBoard<13,13> );
BENCHMARK_TEMPLATE(RandomWrite, Go::TwoDimensionArrayBoard<17,17> );
BENCHMARK_TEMPLATE(RandomWrite, Go::TwoDimensionArrayBoard<19,19> );
BENCHMARK_TEMPLATE(RandomWrite, Go::TwoDimensionArrayBoard<100,100>);

BENCHMARK_TEMPLATE(RandomWrite, Go::ArrayBoard<0,0> );
BENCHMARK_TEMPLATE(RandomWrite, Go::ArrayBoard<4,4> );
BENCHMARK_TEMPLATE(RandomWrite, Go::ArrayBoard<9,9> );
BENCHMARK_TEMPLATE(RandomWrite, Go::ArrayBoard<13,13> );
BENCHMARK_TEMPLATE(RandomWrite, Go::ArrayBoard<17,17> );
BENCHMARK_TEMPLATE(RandomWrite, Go::ArrayBoard<19,19> );
BENCHMARK_TEMPLATE(RandomWrite, Go::ArrayBoard<100,100>);

BENCHMARK_TEMPLATE(RandomWrite, Go::MapBoard<0,0> );
BENCHMARK_TEMPLATE(RandomWrite, Go::MapBoard<4,4> );
BENCHMARK_TEMPLATE(RandomWrite, Go::MapBoard<9,9> );
BENCHMARK_TEMPLATE(RandomWrite, Go::MapBoard<13,13> );
BENCHMARK_TEMPLATE(RandomWrite, Go::MapBoard<17,17> );
BENCHMARK_TEMPLATE(RandomWrite, Go::MapBoard<19,19> );
BENCHMARK_TEMPLATE(RandomWrite, Go::MapBoard<100,100>);


BENCHMARK_MAIN();
