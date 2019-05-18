#include "gtest/gtest.h"

#include "ChiSquared.h"

#include <array>

namespace {

/*
 // https://rosettacode.org/wiki/Verify_distribution_uniformity/Chi-squared_test#C
TEST(chi_squared, original_printout) {
        double dset1[] = {199809., 200665., 199607., 200270., 199649.};
        double dset2[] = {522573., 244456., 139979., 71531., 21461.};
        double *dsets[] = {dset1, dset2};
        int dslens[] = {5, 5};
        int k, l;
        double dist, prob;
        int dof;

        for (k = 0; k < 2; k++) {
            printf("Dataset: [ ");
            for (l = 0; l < dslens[k]; l++)
                printf("%.0f, ", dsets[k][l]);

            printf("]\n");
            dist = Go::chi2UniformDistance(dsets[k], dslens[k]);
            dof = dslens[k] - 1;
            printf("dof: %d  distance: %.4f", dof, dist);
            prob = Go::chi2Probability(dof, dist);
            printf(" probability: %.6f", prob);
            printf(" uniform? %s\n", Go::chiIsUniform(dsets[k], dslens[k], 0.05) ? "Yes" : "No");
        }
}
*/

TEST(chi_squared, DataSet1) {
  constexpr auto val = []() {
    std::array dataSet1 = {199809., 200665., 199607., 200270., 199649.};
    return Go::chiIsUniform(dataSet1);
  };

  EXPECT_TRUE(val);
}

TEST(chi_squared, DataSet2) {
  auto val = []() {
    std::array dataSet2 = {522573., 244456., 139979., 71531., 21461.};
    return Go::chiIsUniform(dataSet2);
  }();
  EXPECT_FALSE(val);
}

// TEST(constants, eulerNumber) { EXPECT_DOUBLE_EQ(Go::e(), 2.71828182845904523536028747135266249775724709369995); }
/*
    TEST(exponential, exp_0){
        EXPECT_EQ(Go::exp(0), 1);
    }

    TEST(constants, exp_1){
        EXPECT_DOUBLE_EQ(Go::exp(1), Go::e());
    }

    TEST(exponential, exp_2){
        EXPECT_DOUBLE_EQ(Go::exp(2), 7.389056098930650227230427460575007813180315570551847324087);
    }

    TEST(exponential, exp_negative_1){
        EXPECT_DOUBLE_EQ(Go::exp(-1), 0.367879441171442321595523770161460867445811131031767834507);
    }

    TEST(square_root, four){
        EXPECT_EQ(Go::sqrt(4), 2);
    }

    TEST(square_root, one){
        EXPECT_EQ(Go::sqrt(1), 1);
    }

    TEST(square_root, two){
        EXPECT_DOUBLE_EQ(Go::sqrt(2), 1.414213562373095048801688724209698078569671875376948073176);
    }
*/

} // namespace
