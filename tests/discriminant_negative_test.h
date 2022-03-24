#ifndef DISCRIMINANT_NEGATIVE_H
#define DISCRIMINANT_NEGATIVE_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

extern "C" {
#include "myfunc.h"
}

//D < 0, NoRoots
TEST(NoRoots, test1) {
    discriminant(2, -3, 10, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);
}

//EquivalentProgram
TEST(EquivalentProgram, viet) {
    discriminant(5, 6, 1, &x1, &x2, &flag);
    viet(5, 6, 1, &vx1, &vx2, &vflag);
    ASSERT_FLOAT_EQ(x1, vx1);
    ASSERT_FLOAT_EQ(x2, vx2);
}

// LargeNumbers
TEST(LargeNumbers, no_roots) {
    discriminant(pow(10,1000000000), pow(10,100), 10, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);
}


#endif // DISCRIMINANT_H
