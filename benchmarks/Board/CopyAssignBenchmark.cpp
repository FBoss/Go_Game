#include <benchmark/benchmark.h>

#include "BoardBenchmarkStructure.h"
#include "BitFieldBoard.h"
#include "TwoDimensionArrayBoard.h"
#include "ArrayBoard.h"


//CopyAssign
BENCHMARK_TEMPLATE(CopyAssign, Go::BitFieldBoard<0,0> );
BENCHMARK_TEMPLATE(CopyAssign, Go::BitFieldBoard<4,4> );
BENCHMARK_TEMPLATE(CopyAssign, Go::BitFieldBoard<9,9> );
BENCHMARK_TEMPLATE(CopyAssign, Go::BitFieldBoard<13,13> );
BENCHMARK_TEMPLATE(CopyAssign, Go::BitFieldBoard<17,17> );
BENCHMARK_TEMPLATE(CopyAssign, Go::BitFieldBoard<19,19> );
BENCHMARK_TEMPLATE(CopyAssign, Go::BitFieldBoard<100,100>);

BENCHMARK_TEMPLATE(CopyAssign, Go::TwoDimensionArrayBoard<0,0> );
BENCHMARK_TEMPLATE(CopyAssign, Go::TwoDimensionArrayBoard<4,4> );
BENCHMARK_TEMPLATE(CopyAssign, Go::TwoDimensionArrayBoard<9,9> );
BENCHMARK_TEMPLATE(CopyAssign, Go::TwoDimensionArrayBoard<13,13> );
BENCHMARK_TEMPLATE(CopyAssign, Go::TwoDimensionArrayBoard<17,17> );
BENCHMARK_TEMPLATE(CopyAssign, Go::TwoDimensionArrayBoard<19,19> );
BENCHMARK_TEMPLATE(CopyAssign, Go::TwoDimensionArrayBoard<100,100>);

BENCHMARK_TEMPLATE(CopyAssign, Go::ArrayBoard<0,0> );
BENCHMARK_TEMPLATE(CopyAssign, Go::ArrayBoard<4,4> );
BENCHMARK_TEMPLATE(CopyAssign, Go::ArrayBoard<9,9> );
BENCHMARK_TEMPLATE(CopyAssign, Go::ArrayBoard<13,13> );
BENCHMARK_TEMPLATE(CopyAssign, Go::ArrayBoard<17,17> );
BENCHMARK_TEMPLATE(CopyAssign, Go::ArrayBoard<19,19> );
BENCHMARK_TEMPLATE(CopyAssign, Go::ArrayBoard<100,100>);


BENCHMARK_MAIN();
