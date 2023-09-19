#include <gtest/gtest.h>

#include <iostream>
#include <stack>

#include "s21_stack.h"

TEST(constructor_1, test_1) {
  s21::stack<int> s;

  EXPECT_EQ(s.empty(), true);
}

TEST(constructor_2, test_1) {
  s21::stack<int> s({1, 2, 3});

  EXPECT_EQ(s.top(), 3);
  EXPECT_EQ(s.size(), 3);
}

TEST(constructor_4, test_1) {
  s21::stack<int> s({1, 2, 3});
  s21::stack<int> s2(std::move(s));

  EXPECT_EQ(s.empty(), true);
  EXPECT_EQ(s2.top(), 3);
  EXPECT_EQ(s2.size(), 3);
}

TEST(push_1, test_2) {
  s21::stack<int> s;

  s.push(1);
  s.push(2);

  EXPECT_EQ(s.empty(), false);
  EXPECT_EQ(s.size(), 2);
  EXPECT_EQ(s.top(), 2);
}

TEST(push_2, test_2) {
  s21::stack<std::string> s;

  s.push("Bushido");
  s.push("Zho");

  EXPECT_EQ(s.empty(), false);
  EXPECT_EQ(s.size(), 2);
  EXPECT_EQ(s.top(), "Zho");
}

TEST(push_3, test_2) {
  s21::stack<int> s;

  s.push(1239128);
  s.push(-123193);

  EXPECT_EQ(s.empty(), false);
  EXPECT_EQ(s.size(), 2);
  EXPECT_EQ(s.top(), -123193);
}

TEST(pop_1, test_3) {
  s21::stack<int> s({1, 2, 3});

  s.pop();
  s.pop();

  EXPECT_EQ(s.empty(), false);
  EXPECT_EQ(s.size(), 1);
  EXPECT_EQ(s.top(), 1);
}

TEST(swap_1, test_4) {
  s21::stack<int> s1({1, 2, 3});
  s21::stack<int> s2({1});

  s1.swap(s2);

  EXPECT_EQ(s1.size(), 1);
  EXPECT_EQ(s1.top(), 1);

  EXPECT_EQ(s2.size(), 3);
  EXPECT_EQ(s2.top(), 3);
}

TEST(empty_1, test_5) {
  s21::stack<int> s1;

  EXPECT_EQ(s1.empty(), true);
}

TEST(empty_2, test_5) {
  s21::stack<int> s1({1, 2, 3});

  EXPECT_EQ(s1.empty(), false);
}

TEST(size_1, test_6) {
  s21::stack<int> s1;

  EXPECT_EQ(s1.size(), 0);
}

TEST(size_2, test_7) {
  s21::stack<int> s1({1, 2, 3});

  EXPECT_EQ(s1.size(), 3);
}

TEST(top_1, test_8) {
  s21::stack<int> s1({1, 2, 3});

  EXPECT_EQ(s1.top(), 3);
}

TEST(top_2, test_9) {
  s21::stack<int> s1;

  EXPECT_EQ(s1.top(), 0);
}

TEST(emplace_1, test_10) {
  s21::stack<int> s1({1, 2, 3});
  s1.emplace_front(4, 5, 6);
  EXPECT_EQ(s1.size(), 6);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}