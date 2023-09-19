#include <gtest/gtest.h>

#include <iostream>

#include "s21_array.h"

TEST(array_1_bool, test_1) {
  using namespace s21;
  array<bool, 6> one = {true, false, true};
  std::cout << " this is array one: " << std::endl;
  one.print_array();
  EXPECT_EQ(one[0], true);
}

TEST(array_1_bool, test_2) {
  using namespace s21;
  array<bool, 6> one;
  EXPECT_TRUE(one.empty());
}

TEST(array_1_bool, test_3) {
  using namespace s21;
  array<bool, 6> one = {true, false, true};
  EXPECT_FALSE(one.empty());
}

TEST(array_1_bool, test_4) {
  using namespace s21;
  array<bool, 6> one = {true, false, true};
  array<bool, 6> two = one;
  EXPECT_EQ(two[0], true);
}

TEST(array_1_bool, test_5) {
  using namespace s21;
  array<bool, 6> one = {true, false, true};
  array<bool, 6> two;
  two = one;
  EXPECT_EQ(two[0], true);
}

TEST(array_1_bool, test_6) {
  using namespace s21;
  array<bool, 6> one = {true, false, true};
  array<bool, 6> two(one);
  EXPECT_EQ(two[0], true);
}

TEST(array_1_bool, test_7) {
  using namespace s21;
  array<bool, 6> one = std::move(s21::array<bool, 6>({true, false, true}));
  array<bool, 6> two(one);
  EXPECT_EQ(two[0], true);
}

TEST(array_1_bool, test_8) {
  using namespace s21;
  array<bool, 6> one = std::move(s21::array<bool, 6>({true, false, true}));
  array<bool, 6> two = {false, false};
  one.swap(two);
  EXPECT_EQ(two[0], 1);
}

TEST(array_1_bool, test_9) {
  using namespace s21;
  array<bool, 6> one = std::move(s21::array<bool, 6>({true, false, true}));
  one.fill(true);
  EXPECT_EQ(one[0], true);
}

TEST(array_1_bool, test_10) {
  using namespace s21;
  array<bool, 6> one = std::move(s21::array<bool, 6>({true, false, true}));
  array<bool, 6> two;
  two = (s21::array<bool, 6>({true, false, true}));
  EXPECT_EQ(two[0], true);
}

TEST(array_1_bool, test_11) {
  using namespace s21;
  array<bool, 6> one = {true, false, true};
  bool front = one.front();
  EXPECT_EQ(front, true);
}

TEST(array_1_bool, test_12) {
  using namespace s21;
  array<bool, 6> one = {true, false, true};
  bool back = one.back();
  EXPECT_EQ(back, true);
}

TEST(array_1_bool, test_13) {
  using namespace s21;
  array<bool, 6> one = {true, false, true};
  bool at = one.at(1);
  EXPECT_EQ(at, false);
}

TEST(array_1_bool, test_14) {
  using namespace s21;
  array<bool, 6> one = {true, false, true};
  bool const *p = one.begin();
  bool const *b = one.end();
  bool *d = one.data();
  EXPECT_EQ(*p, *d);
  d++;
  d++;
  EXPECT_EQ(*d, *b);
}

TEST(array_1_bool, test_15) {
  using namespace s21;
  array<bool, 6> one = {true, false, true};
  size_t size = one.size();
  size_t max_size = one.max_size();
  EXPECT_EQ(size, 3);
  EXPECT_EQ(max_size, 6);
}

TEST(array_1_int, test_1) {
  using namespace s21;
  array<int, 6> one = {1, 2, 3};
  std::cout << " this is array one: " << std::endl;
  one.print_array();
  EXPECT_EQ(one[0], 1);
}

TEST(array_1_int, test_2) {
  using namespace s21;
  array<int, 6> one;
  EXPECT_TRUE(one.empty());
}

TEST(array_1_int, test_3) {
  using namespace s21;
  array<int, 6> one = {1, 2, 3};
  EXPECT_FALSE(one.empty());
}

TEST(array_1_int, test_4) {
  using namespace s21;
  array<int, 6> one = {1, 2, 3};
  array<int, 6> two = one;
  EXPECT_EQ(two[0], 1);
}

TEST(array_1_int, test_5) {
  using namespace s21;
  array<int, 6> one = {1, 2, 3};
  array<int, 6> two;
  two = one;
  EXPECT_EQ(two[0], 1);
}

TEST(array_1_int, test_6) {
  using namespace s21;
  array<int, 6> one = {1, 2, 3};
  array<int, 6> two(one);
  EXPECT_EQ(two[0], 1);
}

TEST(array_1_int, test_7) {
  using namespace s21;
  array<int, 6> one = std::move(s21::array<int, 6>({1, 2, 3}));
  array<int, 6> two;
  two = one;
  EXPECT_EQ(two[0], 1);
}

TEST(array_1_int, test_8) {
  using namespace s21;
  array<int, 6> one = std::move(s21::array<int, 6>({1, 2, 3}));
  array<int, 6> two = {5, 6};
  one.swap(two);
  EXPECT_EQ(two[0], 1);
}

TEST(array_1_int, test_9) {
  using namespace s21;
  array<int, 6> one = std::move(s21::array<int, 6>({1, 2, 3}));
  one.fill(4);
  EXPECT_EQ(one[0], 4);
}

TEST(array_1_int, test_10) {
  using namespace s21;
  array<int, 6> one = std::move(s21::array<int, 6>({1, 2, 3}));
  array<int, 6> two;
  two = std::move(s21::array<int, 6>({1, 2, 3}));
  EXPECT_EQ(two[0], 1);
}

TEST(array_1_int, test_11) {
  using namespace s21;
  array<int, 6> one = {1, 2, 3};
  int front = one.front();
  EXPECT_EQ(front, 1);
}

TEST(array_1_int, test_12) {
  using namespace s21;
  array<int, 6> one = {1, 2, 3};
  int back = one.back();
  EXPECT_EQ(back, 3);
}

TEST(array_1_int, test_13) {
  using namespace s21;
  array<int, 6> one = {1, 2, 3};
  int at = one.at(1);
  EXPECT_EQ(at, 2);
}

TEST(array_1_int, test_14) {
  using namespace s21;
  array<int, 6> one = {1, 2, 3};
  int const *p = one.begin();
  int const *b = one.end();
  int *d = one.data();
  EXPECT_EQ(*p, *d);
  d++;
  d++;
  EXPECT_EQ(*d, *b);
}

TEST(array_1_int, test_15) {
  using namespace s21;
  array<int, 6> one = {1, 2, 3};
  array<int, 6> two = {1, 2, 3, 4};
  two = one;
  size_t size = two.size();
  size_t max_size = two.max_size();
  EXPECT_EQ(size, 3);
  EXPECT_EQ(max_size, 6);
}

TEST(array_1_double, test_1) {
  using namespace s21;
  array<double, 6> one = {1.1, 2.1, 3.1};
  std::cout << " this is array one: " << std::endl;
  one.print_array();
  EXPECT_EQ(one[0], 1.1);
}

TEST(array_1_double, test_2) {
  using namespace s21;
  array<double, 6> one;
  EXPECT_TRUE(one.empty());
}

TEST(array_1_double, test_3) {
  using namespace s21;
  array<double, 6> one = {1.1, 2.1, 3.1};
  EXPECT_FALSE(one.empty());
}

TEST(array_1_double, test_4) {
  using namespace s21;
  array<double, 6> one = {1.1, 2.1, 3.1};
  array<double, 6> two = one;
  EXPECT_EQ(two[0], 1.1);
}

TEST(array_1_double, test_5) {
  using namespace s21;
  array<double, 6> one = {1.1, 2.1, 3.1};
  array<double, 6> two;
  two = one;
  EXPECT_EQ(two[0], 1.1);
}

TEST(array_1_double, test_6) {
  using namespace s21;
  array<double, 6> one = {1.1, 2.1, 3.1};
  array<double, 6> two(one);
  EXPECT_EQ(two[0], 1.1);
}

TEST(array_1_double, test_7) {
  using namespace s21;
  array<double, 6> one = std::move(s21::array<double, 6>({1.1, 2.1, 3.1}));
  array<double, 6> two(one);
  EXPECT_EQ(two[0], 1.1);
}

TEST(array_1_double, test_8) {
  using namespace s21;
  array<double, 6> one = std::move(s21::array<double, 6>({1.1, 2.1, 3.1}));
  array<double, 6> two = {5.1, 6.1};
  one.swap(two);
  EXPECT_EQ(two[0], 1.1);
}

TEST(array_1_double, test_9) {
  using namespace s21;
  array<double, 6> one = std::move(s21::array<double, 6>({1.1, 2.1, 3.1}));
  one.fill(4.6);
  EXPECT_EQ(one[0], 4.6);
}

TEST(array_1_double, test_10) {
  using namespace s21;
  array<double, 6> one = std::move(s21::array<double, 6>({1.1, 2.1, 3.1}));
  array<double, 6> two;
  two = (s21::array<double, 6>({1.1, 2.1, 3.1}));
  EXPECT_EQ(two[0], 1.1);
}

TEST(array_1_double, test_11) {
  using namespace s21;
  array<double, 6> one = {1.1, 2.1, 3.1};
  double front = one.front();
  EXPECT_EQ(front, 1.1);
}

TEST(array_1_double, test_12) {
  using namespace s21;
  array<double, 6> one = {1.1, 2.1, 3.1};
  double back = one.back();
  EXPECT_EQ(back, 3.1);
}

TEST(array_1_double, test_13) {
  using namespace s21;
  array<double, 6> one = {1.1, 2.1, 3.1};
  double at = one.at(1);
  EXPECT_EQ(at, 2.1);
}

TEST(array_1_double, test_14) {
  using namespace s21;
  array<double, 6> one = {1.1, 2.1, 3.1};
  double const *p = one.begin();
  double const *b = one.end();
  double *d = one.data();
  EXPECT_EQ(*p, *d);
  d++;
  d++;
  EXPECT_EQ(*d, *b);
}

TEST(array_1_double, test_15) {
  using namespace s21;
  array<double, 6> one = {1.1, 2.1, 3.1};
  size_t size = one.size();
  size_t max_size = one.max_size();
  EXPECT_EQ(size, 3);
  EXPECT_EQ(max_size, 6);
}

TEST(array_1_char, test_1) {
  using namespace s21;
  array<char, 6> one = {'a', 'b', 'c'};
  std::cout << " this is array one: " << std::endl;
  one.print_array();
  EXPECT_EQ(one[0], 'a');
}

TEST(array_1_char, test_2) {
  using namespace s21;
  array<char, 6> one;
  EXPECT_TRUE(one.empty());
}

TEST(array_1_char, test_3) {
  using namespace s21;
  array<char, 6> one = {'a', 'b', 'c'};
  EXPECT_FALSE(one.empty());
}

TEST(array_1_char, test_4) {
  using namespace s21;
  array<char, 6> one = {'a', 'b', 'c'};
  array<char, 6> two = one;
  EXPECT_EQ(two[0], 'a');
}

TEST(array_1_char, test_5) {
  using namespace s21;
  array<char, 6> one = {'a', 'b', 'c'};
  array<char, 6> two = {'f', 'g', 'h', 'j'};
  two = one;
  EXPECT_EQ(two[0], 'a');
}

TEST(array_1_char, test_6) {
  using namespace s21;
  array<char, 6> one = {'a', 'b', 'c'};
  array<char, 6> two(one);
  EXPECT_EQ(two[0], 'a');
}

TEST(array_1_char, test_7) {
  using namespace s21;
  array<char, 6> one = std::move(s21::array<char, 6>({'a', 'b', 'c'}));
  array<char, 6> two(one);
  EXPECT_EQ(two[0], 'a');
}

TEST(array_1_char, test_8) {
  using namespace s21;
  array<char, 6> one = std::move(s21::array<char, 6>({'a', 'b', 'c'}));
  array<char, 6> two = {'t', 'y'};
  one.swap(two);
  EXPECT_EQ(two[0], 'a');
}

TEST(array_1_char, test_9) {
  using namespace s21;
  array<char, 6> one = std::move(s21::array<char, 6>({'a', 'b', 'c'}));
  one.fill('r');
  EXPECT_EQ(one[0], 'r');
}

TEST(array_1_char, test_10) {
  using namespace s21;
  array<char, 6> one = std::move(s21::array<char, 6>({'a', 'b', 'c'}));
  array<char, 6> two;
  two = (s21::array<char, 6>({'a', 'b', 'c'}));
  EXPECT_EQ(two[0], 'a');
}

TEST(array_1_char, test_11) {
  using namespace s21;
  array<char, 6> one = {'a', 'b', 'c'};
  char front = one.front();
  EXPECT_EQ(front, 'a');
}

TEST(array_1_char, test_12) {
  using namespace s21;
  array<char, 6> one = {'a', 'b', 'c'};
  char back = one.back();
  EXPECT_EQ(back, 'c');
}

TEST(array_1_char, test_13) {
  using namespace s21;
  array<char, 6> one = {'a', 'b', 'c'};
  char at = one.at(1);
  EXPECT_EQ(at, 'b');
}

TEST(array_1_char, test_14) {
  using namespace s21;
  array<char, 6> one = {'a', 'b', 'c'};
  char const *p = one.begin();
  char const *b = one.end();
  char *d = one.data();
  EXPECT_EQ(*p, *d);
  d++;
  d++;
  EXPECT_EQ(*d, *b);
}

TEST(array_1_char, test_15) {
  using namespace s21;
  array<char, 6> one = {'a', 'b', 'c'};
  size_t size = one.size();
  size_t max_size = one.max_size();
  EXPECT_EQ(size, 3);
  EXPECT_EQ(max_size, 6);
}

TEST(array_1_std_string, test_1) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  std::cout << " this is array one: " << std::endl;
  one.print_array();
  EXPECT_EQ(one[0], "asd");
}

TEST(array_1_std_string, test_2) {
  using namespace s21;
  array<std::string, 6> one = {"fre"};
  EXPECT_TRUE(!one.empty());
}

TEST(array_1_std_string, test_3) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  EXPECT_FALSE(one.empty());
}

TEST(array_1_std_string, test_4) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  array<std::string, 6> two = one;
  EXPECT_EQ(two[0], "asd");
}

TEST(array_1_std_string, test_5) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  array<std::string, 6> two(one);
  EXPECT_EQ(two[0], "asd");
}

TEST(array_1_std_string, test_6) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  array<std::string, 6> two(one);
  EXPECT_EQ(two[0], "asd");
}

TEST(array_1_std_string, test_7) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  array<std::string, 6> two(one);
  EXPECT_EQ(two[0], "asd");
}

TEST(array_1_std_string, test_8) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  array<std::string, 6> two = {"grt", "hyu"};
  one.swap(two);
  EXPECT_EQ(two[0], "asd");
}

TEST(array_1_std_string, test_9) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  one.fill("fre");
  EXPECT_EQ(one[0], "fre");
}

TEST(array_1_std_string, test_10) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  array<std::string, 6> two = std::move(s21::array<std::string, 6>(one));
  two = std::move(s21::array<std::string, 6>(one));
  EXPECT_EQ(one[0], "asd");
}

TEST(array_1_std_string, test_11) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  std::string front = one.front();
  EXPECT_EQ(front, "asd");
}

TEST(array_1_std_string, test_12) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  std::string back = one.back();
  EXPECT_EQ(back, "jkl");
}

TEST(array_1_std_string, test_13) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  std::string at = one.at(1);
  EXPECT_EQ(at, "fgh");
}

TEST(array_1_std_string, test_14) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  std::string const *p = one.begin();
  std::string const *b = one.end();
  std::string *d = one.data();
  EXPECT_EQ(*p, *d);
  d++;
  d++;
  EXPECT_EQ(*d, *b);
}

TEST(array_1_std_string, test_15) {
  using namespace s21;
  array<std::string, 6> one = {"asd", "fgh", "jkl"};
  size_t size = one.size();
  size_t max_size = one.max_size();
  EXPECT_EQ(size, 3);
  EXPECT_EQ(max_size, 6);
}

TEST(array_1_std_string, test_16) {
  using namespace s21;
  array<std::string, 6> one = {"fre"};
  size_t size = one.size();
  size_t max_size = one.max_size();
  EXPECT_EQ(size, 1);
  EXPECT_EQ(max_size, 6);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
