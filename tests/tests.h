#ifndef DISCRIMINANT_H
#define DISCRIMINANT_H

#include <gtest/gtest.h>

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>

extern "C" {
#include "myfunc.h"
}

/* ------------------- Константы -------------------  */

float x1, x2, vx1, vx2;
int flag, vflag;

/* ------------------- D > 0, Два корня -------------------  */

// Целый ввод, целый вывод(позитивный)
TEST(TwoRootsTest, integer_input_integer_output) {
    discriminant(1, -5, 4, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(1, x1);
    ASSERT_FLOAT_EQ(4, x2);
    ASSERT_EQ(0, flag);
}

// Целый ввод, дробный вывод (позитивный)
TEST(TwoRootsTest, integer_input_float_output) {
    discriminant(-7, 13, 5, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(2.18417113, x1);
    ASSERT_FLOAT_EQ(-0.32702827, x2);
    ASSERT_EQ(0, flag);
}

// Дробный ввод, целый вывод (позитивный)
TEST(TwoRootsTest, float_input_integer_output) {
    discriminant(-7, 13, 5, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(2.18417113, x1);
    ASSERT_FLOAT_EQ(-0.32702827, x2);
    ASSERT_EQ(0, flag);
}

// Дробный ввод, дробный вывод (позитивный)
TEST(TwoRootsTest, float_input_float_output) {
    discriminant(-7, 13, 5, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(2.18417113, x1);
    ASSERT_FLOAT_EQ(-0.32702827, x2);
    ASSERT_EQ(0, flag);
}

// Неполный целый ввод без первого элемента (негативный)
TEST(TwoRootsTest, incomplete_integer_input_without_first_element) {
    discriminant(0, 2, 4, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-2, x1);
    ASSERT_FLOAT_EQ(-2, x2);
    ASSERT_EQ(0, flag);
}

// Неполный целый ввод без второго элемента (негативный)
TEST(TwoRootsTest, incomplete_integer_input_without_second_element) {
    discriminant(0, 2, 4, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-2, x1);
    ASSERT_FLOAT_EQ(-2, x2);
    ASSERT_EQ(0, flag);
}

// Неполный целый ввод без третьего элемента (негативный)
TEST(TwoRootsTest, incomplete_integer_input_without_third_element) {
    discriminant(0, 2, 4, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-2, x1);
    ASSERT_FLOAT_EQ(-2, x2);
    ASSERT_EQ(0, flag);
}


// Целый ввод, ноль в выводе (позитивный)
TEST(TwoRootsTest, integer_input_zero_in_output) {
    discriminant(8, 3, 0, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-0.375, x1);
    ASSERT_FLOAT_EQ(0, x2);
    ASSERT_EQ(0, flag);
}

// Целый ввод, целый вывод, другая программа (позитивный)
TEST(EquivalentProgram, viet) {
    discriminant(5, 6, 1, &x1, &x2, &flag);
    viet(5, 6, 1, &vx1, &vx2, &vflag);

    ASSERT_FLOAT_EQ(x1, vx1);
    ASSERT_FLOAT_EQ(x2, vx2);
}

// Целый ввод, ошибка переполнения (негативный тест)
TEST(LargeNumbersTest, no_roots) {
    discriminant(pow(10,1000000000), pow(10,100), 10, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);
}

/* ------------------- D = 0, один корень -------------------  */

// Целый ввод, целый вывод(позитивный)
TEST(OneRootTest, integer_positive) {
    discriminant(1, 4, 4, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-2, x1);
    ASSERT_FLOAT_EQ(-2, x2);
    ASSERT_EQ(0, flag);
}

// Целый ввод, дробный вывод(позитивный)

// Дробный ввод, целый вывод(позитивный)

// Дробный ввод, дробный вывод(позитивный)

// Неполный целый ввод без первого элемента (негативный)

// Неполный целый ввод без второго элемента (негативный)

// Неполный целый ввод без третьего элемента (негативный)

// Целый ввод, ноль в выводе (позитивный)

/* ------------------- D < 0, нет корней -------------------  */

// Целый ввод, нустой вывод(позитивный)
TEST(NoRootsTest, test1) {
    discriminant(2, -3, 10, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);
}

#endif // DISCRIMINANT_H
