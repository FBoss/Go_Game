#include <benchmark/benchmark.h>

#include "ArrayBoard.h"
#include "BitFieldBoard.h"
#include "BoardBenchmarkStructure.h"
#include "TwoDimensionArrayBoard.h"
#include "MapBoard.h"
#include "UnorderedMapBoard.h"

// SerialWriteColumnMajor
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::BitFieldBoard<0, 0>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::BitFieldBoard<4, 4>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::BitFieldBoard<9, 9>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::BitFieldBoard<13, 13>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::BitFieldBoard<17, 17>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::BitFieldBoard<19, 19>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::BitFieldBoard<100, 100>);

BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::TwoDimensionArrayBoard<0, 0>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::TwoDimensionArrayBoard<4, 4>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::TwoDimensionArrayBoard<9, 9>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::TwoDimensionArrayBoard<13, 13>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::TwoDimensionArrayBoard<17, 17>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::TwoDimensionArrayBoard<19, 19>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::TwoDimensionArrayBoard<100, 100>);

BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::ArrayBoard<0, 0>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::ArrayBoard<4, 4>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::ArrayBoard<9, 9>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::ArrayBoard<13, 13>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::ArrayBoard<17, 17>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::ArrayBoard<19, 19>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::ArrayBoard<100, 100>);

BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::MapBoard<0, 0>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::MapBoard<4, 4>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::MapBoard<9, 9>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::MapBoard<13, 13>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::MapBoard<17, 17>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::MapBoard<19, 19>);
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::MapBoard<100, 100>);

BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::UnorderedMapBoard<0,0> );
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::UnorderedMapBoard<4,4> );
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::UnorderedMapBoard<9,9> );
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::UnorderedMapBoard<13,13> );
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::UnorderedMapBoard<17,17> );
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::UnorderedMapBoard<19,19> );
BENCHMARK_TEMPLATE(SerialWriteColumnMajor, Go::UnorderedMapBoard<100,100>);


BENCHMARK_MAIN();
