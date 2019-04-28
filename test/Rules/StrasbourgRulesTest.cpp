#include "gtest/gtest.h"

#include "StrasbourgRulesTestStructure.h"

#include "StrasbourgRules.h"
#include "TwoDimensionArrayBoard.h"

namespace {
using testing::Types;

typedef Types<Go::Rulset::StrasbourgRules<Go::TwoDimensionArrayBoard<19, 19>>> RulesImplementations; // NOLINT

// NOLINTNEXTLINE
INSTANTIATE_TYPED_TEST_CASE_P(StrasbourgRulesTest,   // Instance name
                              StrasbourgRulesTest,   // Test case name
                              RulesImplementations); // Type list

} // namespace
