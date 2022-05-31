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
    discriminant(1, -0.5, -0.5, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-0.5, x1);
    ASSERT_FLOAT_EQ(1, x2);
    ASSERT_EQ(0, flag);
}

// Дробный ввод, дробный вывод (позитивный)
TEST(TwoRootsTest, float_input_float_output) {
    discriminant(5.5, -1.5, -5, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-0.82680094, x1);
    ASSERT_FLOAT_EQ(1.0995282, x2);
    ASSERT_EQ(0, flag);
}

// Неполный целый ввод без первого элемента (негативный)
TEST(TwoRootsTest, incomplete_integer_input_without_first_element) {
    discriminant(0, -2, 2, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(1, x1);
    ASSERT_FLOAT_EQ(1, x2);
    ASSERT_EQ(0, flag);
}

// Неполный целый ввод без второго элемента (негативный)
TEST(TwoRootsTest, incomplete_integer_input_without_second_element) {
    discriminant(10, -20, 0, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(0, x1);
    ASSERT_FLOAT_EQ(2, x2);
    ASSERT_EQ(0, flag);
}

// Неполный целый ввод без третьего элемента (негативный)
TEST(TwoRootsTest, incomplete_integer_input_without_third_element) {
    discriminant(1, 3, 0, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-3, x1);
    ASSERT_FLOAT_EQ(0, x2);
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

/* ------------------- D = 0, один корень -------------------  */

// Целый ввод, целый вывод(позитивный)
TEST(OneRootTest, integer_input_integer_output) {
    discriminant(1, 4, 4, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-2, x1);
    ASSERT_FLOAT_EQ(-2, x2);
    ASSERT_EQ(0, flag);
}

// Целый ввод, дробный вывод (позитивный)
TEST(OneRootTest, integer_input_float_output) {
    discriminant(9, 6, 1, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-0.33333334, x1);
    ASSERT_FLOAT_EQ(-0.33333334, x2);
    ASSERT_EQ(0, flag);
}

// Неполный целый ввод без первого элемента (негативный)
TEST(OneRootTest, incomplete_integer_input_without_first_element) {
    discriminant(0, 5, 5, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(-1, x1);
    ASSERT_FLOAT_EQ(-1, x2);
    ASSERT_EQ(0, flag);
}

// Неполный целый ввод без второго элемента (негативный)
TEST(OneRootTest, incomplete_integer_input_without_second_element) {
    discriminant(10, 0, 0, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(0, x1);
    ASSERT_FLOAT_EQ(0, x2);
    ASSERT_EQ(0, flag);
}


// Неполный целый ввод без третьего элемента (негативный)
TEST(OneRootTest, incomplete_integer_input_without_third_element) {
    discriminant(1, 0, 0, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(0, x1);
    ASSERT_FLOAT_EQ(0, x2);
    ASSERT_EQ(0, flag);
}

// Целый ввод, ноль в выводе (позитивный)
TEST(OneRootTest, integer_input_zero_in_output) {
    discriminant(1, 0, 0, &x1, &x2, &flag);
    ASSERT_FLOAT_EQ(0, x1);
    ASSERT_FLOAT_EQ(0, x2);
    ASSERT_EQ(0, flag);
}

/* ------------------- D < 0, нет корней -------------------  */

// Целый ввод, пустой вывод (позитивный)
TEST(NoRootsTest, float_input_no_output) {
    discriminant(2, -3, 10, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);
}

// Целый ввод, ошибка переполнения (негативный тест)
TEST(LargeNumbersTest, large_numbers_input_no_output) {
    discriminant(pow(10,1000000000), pow(10,100), 10, &x1, &x2, &flag);
    ASSERT_EQ(1, flag);
}

#endif // DISCRIMINANT_H
