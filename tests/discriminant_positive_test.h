#ifndef DISCRIMINANT_POSITIVE_H
#define DISCRIMINANT_POSITIVE_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "myfunc.h"
}

float x1, x2, vx1, vx2;
int flag, vflag;

//D > 0, TwoRoots
TEST(TwoRoots, integer) {
    discriminant(1, -5, 4, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(1, x1);
    ASSERT_FLOAT_EQ(4, x2);
    ASSERT_EQ(0, flag);
}

TEST(TwoRoots, fractional) {
    discriminant(-7, 13, 5, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(2.18417113, x1);
    ASSERT_FLOAT_EQ(-0.32702827, x2);
    ASSERT_EQ(0, flag);
}

TEST(TwoRoots, zero) {
    discriminant(8, 3, 0, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-0.375, x1);
    ASSERT_FLOAT_EQ(0, x2);
    ASSERT_EQ(0, flag);
}

//D = 0, OneRoot
TEST(OneRoot, integer_positive) {
    discriminant(1, 4, 4, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-2, x1);
    ASSERT_FLOAT_EQ(-2, x2);
    ASSERT_EQ(0, flag);
}

#endif // DISCRIMINANT_H
