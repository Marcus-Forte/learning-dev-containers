#include <gmock/gmock-nice-strict.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "lib.h"
using namespace testing;


class TestLib : public ::testing::Test {};

TEST_F(TestLib, sum5) {
  
  EXPECT_EQ(Adder::sumInt(5, 5), 10);
}

TEST_F(TestLib, sum37) {
  
  EXPECT_EQ(Adder::sumInt(37, 37), 10);
}