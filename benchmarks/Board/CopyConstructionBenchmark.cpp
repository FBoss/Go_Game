#include <benchmark/benchmark.h>

#include "BoardBenchmarkStructure.h"
#include "BitFieldBoard.h"
#include "TwoDimensionArrayBoard.h"
#include "ArrayBoard.h"
#include "MapBoard.h"
#include "UnorderedMapBoard.h"

//CopyConstruction
BENCHMARK_TEMPLATE(CopyConstruction, Go::BitFieldBoard<0,0> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::BitFieldBoard<4,4> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::BitFieldBoard<9,9> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::BitFieldBoard<13,13> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::BitFieldBoard<17,17> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::BitFieldBoard<19,19> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::BitFieldBoard<100,100>);

BENCHMARK_TEMPLATE(CopyConstruction, Go::TwoDimensionArrayBoard<0,0> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::TwoDimensionArrayBoard<4,4> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::TwoDimensionArrayBoard<9,9> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::TwoDimensionArrayBoard<13,13> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::TwoDimensionArrayBoard<17,17> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::TwoDimensionArrayBoard<19,19> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::TwoDimensionArrayBoard<100,100>);

BENCHMARK_TEMPLATE(CopyConstruction, Go::ArrayBoard<0,0> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::ArrayBoard<4,4> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::ArrayBoard<9,9> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::ArrayBoard<13,13> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::ArrayBoard<17,17> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::ArrayBoard<19,19> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::ArrayBoard<100,100>);

BENCHMARK_TEMPLATE(CopyConstruction, Go::MapBoard<0,0> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::MapBoard<4,4> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::MapBoard<9,9> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::MapBoard<13,13> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::MapBoard<17,17> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::MapBoard<19,19> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::MapBoard<100,100>);

BENCHMARK_TEMPLATE(CopyConstruction, Go::UnorderedMapBoard<0,0> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::UnorderedMapBoard<4,4> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::UnorderedMapBoard<9,9> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::UnorderedMapBoard<13,13> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::UnorderedMapBoard<17,17> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::UnorderedMapBoard<19,19> );
BENCHMARK_TEMPLATE(CopyConstruction, Go::UnorderedMapBoard<100,100>);


BENCHMARK_MAIN();
