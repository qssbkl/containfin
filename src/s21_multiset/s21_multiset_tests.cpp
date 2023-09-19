#include <gtest/gtest.h>

#include <iostream>

#include "../s21_vector/s21_vector.h"
#include "s21_multiset.h"

TEST(multiset_1_int, test_1) {
  using namespace s21;
  multiset<int> a;
  a.insert(5);
  a.insert(6);
  a.insert(3);
  a.insert(11);
  a.insert(12);
  a.insert(14);
  a.print_multiset();
  size_t size = a.size();
  EXPECT_EQ(size, 6);
}

TEST(multiset_1_int, test_2) {
  using namespace s21;
  multiset<int> a = {3, 4, 5, 2};
  size_t size = a.size();
  EXPECT_EQ(size, 4);
}

TEST(multiset_1_int, test_3) {
  using namespace s21;
  multiset<int> b = std::move(s21::multiset({3, 4, 5, 6}));
  size_t size = b.size();
  EXPECT_EQ(size, 4);
}

TEST(multiset_1_int, test_4) {
  using namespace s21;
  multiset<int> b = {3, 4, 5, 6};
  multiset<int>::iterator begin = b.begin();
  multiset<int>::iterator lower_bound = b.lower_bound(3);
  EXPECT_EQ(begin, lower_bound);
}

TEST(multiset_1_int, test_5) {
  using namespace s21;
  multiset<int> b = {3, 4, 5, 6};
  multiset<int>::iterator end = b.end();
  multiset<int>::iterator upper_bound = b.upper_bound(6);
  EXPECT_EQ(end, upper_bound);
}

TEST(multiset_1_int, test_6) {
  using namespace s21;
  multiset<int> b = {3, 4, 5, 6};
  bool temp = b.contains(4);
  EXPECT_EQ(true, temp);
}

TEST(multiset_1_int, test_7) {
  using namespace s21;
  multiset<int> b = {3, 4, 5, 5, 5, 6};
  size_t temp = b.count(5);
  EXPECT_EQ(3, temp);
}

TEST(multiset_1_int, test_8) {
  using namespace s21;
  multiset<int> b = {3, 4, 5, 5, 5, 6};
  b.insert(5);
  size_t temp = b.count(5);
  EXPECT_EQ(4, temp);
}

TEST(multiset_1_int, test_9) {
  using namespace s21;
  multiset<int> b = {3, 4, 5, 5, 5, 6, 11, 20, 2, 1, 40};
  multiset<int>::iterator temp = b.find(5);
  b.erase(temp);
  size_t size = b.count(5);
  EXPECT_EQ(2, size);
}

TEST(multiset_1_int, test_10) {
  using namespace s21;
  multiset<int> b = {3, 4, 5, 5, 5, 6};
  multiset<int> a = {4, 6, 10};
  b.swap(a);
  size_t size = b.size();
  EXPECT_EQ(3, size);
}

TEST(multiset_1_int, test_11) {
  using namespace s21;
  multiset<int> b = {3, 4, 5, 5, 5, 6};
  multiset<int> a = {4, 6, 10};
  b.merge(a);
  size_t size = b.size();
  EXPECT_EQ(9, size);
}

TEST(multiset_1_int, test_12) {
  using namespace s21;
  multiset<int> a = {10, 11, 12, 13, 4, 5, 9, 13, 13, 4, 23};
  multiset<int>::iterator lower_bound = a.lower_bound(13),
                          upper_bound = a.upper_bound(13);
  std::pair<multiset<int>::iterator, multiset<int>::iterator> pair;
  pair = a.equal_range(13);
  EXPECT_EQ(upper_bound, pair.second);
  EXPECT_EQ(lower_bound, pair.first);
}

TEST(multiset_1_int, test_13) {
  using namespace s21;
  multiset<int> a = {10, 11, 12, 13, 4, 5, 9, 13, 13, 4, 23};
  size_t max_size = a.max_size();
  EXPECT_EQ(max_size, (size_t)-1);
}

TEST(multiset_1_int, test_14) {
  using namespace s21;
  multiset<int> a = {10, 11, 12, 13, 4, 5, 9, 13, 13, 4, 23};
  a.clear();
  bool full = a.empty();
  size_t size = a.size();
  EXPECT_EQ(size, 0);
  EXPECT_EQ(full, false);
}

TEST(multiset_1_int, test_15) {
  using namespace s21;
  multiset<int> a = {2, 4, 5};
  a = std::move(s21::multiset({3, 4, 5, 6}));
  size_t size = a.size();
  EXPECT_EQ(4, size);
}

TEST(multiset_1_int, test_16) {
  using namespace s21;
  multiset<int> b = {3, 4, 5, 40};
  vector<std::pair<multiset<int>::iterator, bool> > answer =
      b.emplace(20, 30, 60, 50);
  std::pair<multiset<int>::iterator, bool> pair = answer.back();
  multiset<int>::iterator temp = b.find(50);
  EXPECT_EQ(temp, pair.first);
}

TEST(multiset_1_double, test_1) {
  using namespace s21;
  multiset<double> a;
  a.insert(5.1);
  a.insert(6.1);
  a.insert(3.1);
  a.insert(11.1);
  a.insert(12.1);
  a.insert(14.1);
  a.print_multiset();
  size_t size = a.size();
  EXPECT_EQ(size, 6);
}

TEST(multiset_1_double, test_2) {
  using namespace s21;
  multiset<double> a = {3.1, 4.1, 5.1, 2.1};
  size_t size = a.size();
  EXPECT_EQ(size, 4);
}

TEST(multiset_1_double, test_3) {
  using namespace s21;
  multiset<double> b = std::move(s21::multiset({3.1, 4.1, 5.1, 6.1}));
  size_t size = b.size();
  EXPECT_EQ(size, 4);
}

TEST(multiset_1_double, test_4) {
  using namespace s21;
  multiset<double> b = {3.1, 4.1, 5.1, 6.1};
  multiset<double>::iterator begin = b.begin();
  multiset<double>::iterator lower_bound = b.lower_bound(3.1);
  EXPECT_EQ(begin, lower_bound);
}

TEST(multiset_1_double, test_5) {
  using namespace s21;
  multiset<double> b = {3.1, 4.1, 5.1, 6.1};
  multiset<double>::iterator end = b.end();
  multiset<double>::iterator upper_bound = b.upper_bound(6.1);
  EXPECT_EQ(end, upper_bound);
}

TEST(multiset_1_double, test_6) {
  using namespace s21;
  multiset<double> b = {3.1, 4.1, 5.1, 6.1};
  bool temp = b.contains(4.1);
  EXPECT_EQ(true, temp);
}

TEST(multiset_1_double, test_7) {
  using namespace s21;
  multiset<double> b = {3.1, 4.1, 5.1, 5.1, 5.1, 6.1};
  size_t temp = b.count(5.1);
  EXPECT_EQ(3, temp);
}

TEST(multiset_1_double, test_8) {
  using namespace s21;
  multiset<double> b = {3.1, 4.1, 5.1, 5.1, 5.1, 6.1};
  b.insert(5.1);
  size_t temp = b.count(5.1);
  EXPECT_EQ(4, temp);
}

TEST(multiset_1_double, test_9) {
  using namespace s21;
  multiset<double> b = {3.1,  4.1,  5.1, 5.1, 5.1, 6.1,
                        11.1, 20.1, 2.1, 1.1, 40.1};
  multiset<double>::iterator temp = b.find(5.1);
  b.erase(temp);
  size_t size = b.count(5.1);
  EXPECT_EQ(2, size);
}

TEST(multiset_1_double, test_10) {
  using namespace s21;
  multiset<double> b = {3.1, 4.1, 5.1, 5.1, 5.1, 6.1};
  multiset<double> a = {4.1, 6.1, 10.1};
  b.swap(a);
  size_t size = b.size();
  EXPECT_EQ(3, size);
}

TEST(multiset_1_double, test_11) {
  using namespace s21;
  multiset<double> b = {3.1, 4.1, 5.1, 5.1, 5.1, 6.1};
  multiset<double> a = {4.1, 6.1, 10.1};
  b.merge(a);
  size_t size = b.size();
  EXPECT_EQ(9, size);
}

TEST(multiset_1_double, test_12) {
  using namespace s21;
  multiset<double> a = {10.1, 11.1, 12.1, 13.1, 4.1, 5.1,
                        9.1,  13.1, 13.1, 4.1,  23.1};
  multiset<double>::iterator lower_bound = a.lower_bound(13.1),
                             upper_bound = a.upper_bound(13.1);
  std::pair<multiset<double>::iterator, multiset<double>::iterator> pair;
  pair = a.equal_range(13.1);
  EXPECT_EQ(upper_bound, pair.second);
  EXPECT_EQ(lower_bound, pair.first);
}

TEST(multiset_1_double, test_13) {
  using namespace s21;
  multiset<double> a = {10.1, 11.1, 12.1, 13.1, 4.1, 5.1,
                        9.1,  13.1, 13.1, 4.1,  23.1};
  size_t max_size = a.max_size();
  EXPECT_EQ(max_size, (size_t)-1);
}

TEST(multiset_1_double, test_14) {
  using namespace s21;
  multiset<double> a = {10.1, 11.1, 12.1, 13.1, 4.1, 5.1,
                        9.1,  13.1, 13.1, 4.1,  23.1};
  a.clear();
  bool full = a.empty();
  size_t size = a.size();
  EXPECT_EQ(size, 0);
  EXPECT_EQ(full, false);
}

TEST(multiset_1_double, test_15) {
  using namespace s21;
  multiset<double> a = {2.1, 4.1, 5.1};
  a = std::move(s21::multiset({3.1, 4.1, 5.1, 6.1}));
  size_t size = a.size();
  EXPECT_EQ(4, size);
}

TEST(multiset_1_double, test_16) {
  using namespace s21;
  multiset<double> b = {3.1, 4.1, 5.1, 40.1};
  vector<std::pair<multiset<double>::iterator, bool> > answer =
      b.emplace(20.1, 30.1, 60.1, 50.1);
  std::pair<multiset<double>::iterator, bool> pair = answer.back();
  multiset<double>::iterator temp = b.find(50.1);
  EXPECT_EQ(temp, pair.first);
}

TEST(multiset_1_char, test_1) {
  using namespace s21;
  multiset<char> a;
  a.insert('a');
  a.insert('b');
  a.insert('c');
  a.insert('d');
  a.insert('g');
  a.insert('h');
  a.print_multiset();
  size_t size = a.size();
  EXPECT_EQ(size, 6);
}

TEST(multiset_1_char, test_2) {
  using namespace s21;
  multiset<char> a = {'a', 's', 'd', 'f'};
  size_t size = a.size();
  EXPECT_EQ(size, 4);
}

TEST(multiset_1_char, test_3) {
  using namespace s21;
  multiset<char> b = std::move(s21::multiset({'a', 's', 'd', 'd'}));
  size_t size = b.size();
  EXPECT_EQ(size, 4);
}

TEST(multiset_1_char, test_4) {
  using namespace s21;
  multiset<char> b = {'a', 's', 'd', 'f'};
  multiset<char>::iterator begin = b.begin();
  multiset<char>::iterator lower_bound = b.lower_bound('a');
  EXPECT_EQ(begin, lower_bound);
}

TEST(multiset_1_char, test_5) {
  using namespace s21;
  multiset<char> b = {'a', 's', 'd', 'f'};
  multiset<char>::iterator end = b.end();
  multiset<char>::iterator upper_bound = b.upper_bound('f');
  EXPECT_EQ(end, upper_bound);
}

TEST(multiset_1_char, test_6) {
  using namespace s21;
  multiset<char> b = {'a', 's', 'd', 'f'};
  bool temp = b.contains('d');
  EXPECT_EQ(true, temp);
}

TEST(multiset_1_char, test_7) {
  using namespace s21;
  multiset<char> b = {'a', 's', 'd', 'd', 'd', 'f'};
  size_t temp = b.count('d');
  EXPECT_EQ(3, temp);
}

TEST(multiset_1_char, test_8) {
  using namespace s21;
  multiset<char> b = {'a', 's', 'd', 'd', 'd', 'f'};
  b.insert('d');
  size_t temp = b.count('d');
  EXPECT_EQ(4, temp);
}

TEST(multiset_1_char, test_9) {
  using namespace s21;
  multiset<char> b = {'a', 's', 'd', 'd', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
  multiset<char>::iterator temp = b.find('d');
  b.erase(temp);
  size_t size = b.count('d');
  EXPECT_EQ(2, size);
}

TEST(multiset_1_char, test_10) {
  using namespace s21;
  multiset<char> b = {'a', 's', 'd', 'd', 'd', 'f'};
  multiset<char> a = {'y', 'u', 'i'};
  b.swap(a);
  size_t size = b.size();
  EXPECT_EQ(3, size);
}

TEST(multiset_1_char, test_11) {
  using namespace s21;
  multiset<char> b = {'a', 's', 'd', 'd', 'd', 'f'};
  multiset<char> a = {'e', 'r', 't'};
  b.merge(a);
  size_t size = b.size();
  EXPECT_EQ(9, size);
}

TEST(multiset_1_char, test_12) {
  using namespace s21;
  multiset<char> a = {'a', 's', 'd', 'f', 'e', 'r', 't', 'f', 'f', 'e', 'w'};
  multiset<char>::iterator lower_bound = a.lower_bound('f'),
                           upper_bound = a.upper_bound('f');
  std::pair<multiset<char>::iterator, multiset<char>::iterator> pair;
  pair = a.equal_range('f');
  EXPECT_EQ(upper_bound, pair.second);
  EXPECT_EQ(lower_bound, pair.first);
}

TEST(multiset_1_char, test_13) {
  using namespace s21;
  multiset<char> a = {'a', 's', 'd', 'd', 'd', 'f'};
  size_t max_size = a.max_size();
  EXPECT_EQ(max_size, (size_t)-1);
}

TEST(multiset_1_char, test_14) {
  using namespace s21;
  multiset<char> a = {'a', 's', 'd', 'd', 'd', 'f'};
  a.clear();
  bool full = a.empty();
  size_t size = a.size();
  EXPECT_EQ(size, 0);
  EXPECT_EQ(full, false);
}

TEST(multiset_1_char, test_15) {
  using namespace s21;
  multiset<char> a = {'a', 's', 'd'};
  a = std::move(s21::multiset({'q', 'e', 'r', 't'}));
  size_t size = a.size();
  EXPECT_EQ(4, size);
}

TEST(multiset_1_char, test_16) {
  using namespace s21;
  multiset<char> b = {'a', 's', 'd', 'f'};
  vector<std::pair<multiset<char>::iterator, bool> > answer =
      b.emplace('q', 'w', 'e', 'r');
  std::pair<multiset<char>::iterator, bool> pair = answer.back();
  multiset<char>::iterator temp = b.find('r');
  EXPECT_EQ(temp, pair.first);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
