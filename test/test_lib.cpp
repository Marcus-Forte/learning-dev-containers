#include <gmock/gmock-nice-strict.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "lib.h"
using namespace testing;


class TestLib : public ::testing::Test {};

TEST_F(TestLib, sum) {
  
  EXPECT_EQ(Adder::sumInt(5, 5), 10);
}