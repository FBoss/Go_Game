#include <benchmark/benchmark.h>

#include "ArrayBoard.h"
#include "BitFieldBoard.h"
#include "BoardBenchmarkStructure.h"
#include "TwoDimensionArrayBoard.h"
#include "MapBoard.h"

// SerialReadRowMajor
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::BitFieldBoard<0, 0>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::BitFieldBoard<4, 4>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::BitFieldBoard<9, 9>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::BitFieldBoard<13, 13>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::BitFieldBoard<17, 17>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::BitFieldBoard<19, 19>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::BitFieldBoard<100, 100>);

BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::TwoDimensionArrayBoard<0, 0>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::TwoDimensionArrayBoard<4, 4>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::TwoDimensionArrayBoard<9, 9>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::TwoDimensionArrayBoard<13, 13>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::TwoDimensionArrayBoard<17, 17>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::TwoDimensionArrayBoard<19, 19>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::TwoDimensionArrayBoard<100, 100>);

BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::ArrayBoard<0, 0>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::ArrayBoard<4, 4>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::ArrayBoard<9, 9>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::ArrayBoard<13, 13>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::ArrayBoard<17, 17>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::ArrayBoard<19, 19>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::ArrayBoard<100, 100>);

BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::MapBoard<0, 0>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::MapBoard<4, 4>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::MapBoard<9, 9>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::MapBoard<13, 13>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::MapBoard<17, 17>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::MapBoard<19, 19>);
BENCHMARK_TEMPLATE(SerialReadRowMajor, Go::MapBoard<100, 100>);


BENCHMARK_MAIN();
