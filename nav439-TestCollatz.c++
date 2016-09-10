// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

// ----
// eval
// ----
TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(1, 1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(2, 2);
    ASSERT_EQ(2, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(200, 100);
    ASSERT_EQ(125, v);}

// -----
// cycles
// -----

TEST(CollatzFixture, cycles_1) {
    const int v = collatz_cycles(1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, cycles_2) {
    const int v = collatz_cycles(27);
    ASSERT_EQ(112, v);}

TEST(CollatzFixture, cycles_3) {
    const int v = collatz_cycles(64);
    ASSERT_EQ(7, v);}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("1 1\n2 3\n 100 150\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 1 1\n2 3 8\n100 150 122\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("10 1\n3 2\n150 100\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("10 1 20\n3 2 8\n150 100 122\n", w.str());}