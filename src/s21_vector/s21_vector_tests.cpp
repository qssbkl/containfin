#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "s21_vector.h"

TEST(construct_1, test_1) {
  s21::vector<int> v;

  EXPECT_EQ(v.size(), 0U);
  EXPECT_EQ(v.capacity(), 0U);
}

TEST(construct_2, test_1) {
  size_t n = 5;
  s21::vector<int> v(n);

  EXPECT_EQ(v.size(), 0U);
  EXPECT_EQ(v.capacity(), n);
}

TEST(construct_3, test_1) {
  s21::vector<int> v({1, 2, 3});

  for (size_t i = 0; i < 3; ++i) {
    EXPECT_EQ(v[i], i + 1);
  }

  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v.capacity(), 3);
}

TEST(construct_4, test_1) {
  s21::vector<int> v1({1, 2, 3});
  s21::vector<int> v2(v1);

  for (size_t i = 0; i < 3; ++i) {
    EXPECT_EQ(v1[i], v2[i]);
  }

  EXPECT_EQ(v1.size(), v2.size());
  EXPECT_EQ(v1.capacity(), v2.capacity());
}

TEST(construct_5, test_1) {
  s21::vector<int> v1({1, 2, 3});
  size_t v1_size = v1.size();
  size_t v1_capacity = v1.capacity();
  s21::vector<int> v2(std::move(v1));

  for (size_t i = 0; i < 3; ++i) {
    EXPECT_EQ(v2[i], i + 1);
  }

  EXPECT_EQ(v2.size(), v1_size);
  EXPECT_EQ(v2.capacity(), v1_capacity);
  EXPECT_EQ(v2.capacity(), v1_capacity);

  EXPECT_EQ(v1.size(), 0U);
  EXPECT_EQ(v1.capacity(), 0U);
}

TEST(at_1, test_2) {
  s21::vector<int> v({1, 2, 3});

  for (size_t i = 0; i < 3; ++i) {
    EXPECT_EQ(v.at(i), i + 1);
  }
}

TEST(front_1, test_3) {
  s21::vector<int> v({1, 2, 3});

  EXPECT_EQ(v.front(), v[0]);
}

TEST(back_1, test_4) {
  s21::vector<int> v({1, 2, 3});

  EXPECT_EQ(v.back(), v[2]);
}

TEST(push_back_1, test_5) {
  s21::vector<int> v;

  v.push_back(4);
  v.push_back(1);

  EXPECT_EQ(v[0], 4);
  EXPECT_EQ(v[1], 1);
}

TEST(pop_back_1, test_6) {
  s21::vector<int> v({1, 2, 3});

  v.pop_back();
  v.pop_back();

  EXPECT_EQ(v.size(), 1);
}

TEST(reserve_1, test_7) {
  s21::vector<int> v({1, 2, 3});
  int value = 2;

  v.reserve(value);

  EXPECT_EQ(v.size(), value);
  EXPECT_EQ(v.capacity(), value);
  EXPECT_EQ(v[1], value);
}

TEST(reserve_2, test_7) {
  s21::vector<int> v({1, 2, 3});

  v.reserve(5);

  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v.capacity(), 5);
  EXPECT_EQ(v[2], 3);
}

TEST(clear_1, test_9) {
  s21::vector<int> v({1, 2, 3});

  v.clear();

  EXPECT_EQ(v.size(), 0U);
  EXPECT_EQ(v.capacity(), 0U);
}

TEST(erase_1, test_10) {
  s21::vector<int> v({1, 2, 3});

  v.erase(v.begin());

  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v[0], 2);
}

TEST(erase_2, test_10) {
  s21::vector<int> v({1, 2, 3});

  v.erase(v.end());

  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
}

TEST(swap_1, test_11) {
  s21::vector<int> v1({1, 2, 3});
  s21::vector<int> v2({2, 3, 4});

  v1.swap(v2);

  for (size_t i = 0; i < v1.size(); ++i) {
    EXPECT_EQ(v1[i], i + 2);
    EXPECT_EQ(v2[i], i + 1);
  }
}

TEST(swap_2, test_11) {
  s21::vector<int> v1({0, 1, 2, 3});
  s21::vector<int> v2({2, 3, 4});

  v1.swap(v2);

  for (size_t i = 0; i < v2.size(); ++i) {
    EXPECT_EQ(v2[i], i);

    if (i != v2.size() - 1) {
      EXPECT_EQ(v1[i], i + 2);
    }
  }
}

TEST(operator_1, test_12) {
  s21::vector<int> v({1, 2, 3});

  for (size_t i = 0; i < v.size(); ++i) {
    EXPECT_EQ(v[i], i + 1);
  }
}

TEST(capacity_1, test_17) {
  s21::vector<int> v({1, 2, 3});

  EXPECT_EQ(v.capacity(), 3);
}

TEST(capacity_2, test_17) {
  s21::vector<int> v;

  EXPECT_EQ(v.capacity(), 0);
}

TEST(capacity_3, test_17) {
  s21::vector<int> v(2);

  EXPECT_EQ(v.capacity(), 2);
}

TEST(size_1, test_18) {
  s21::vector<int> v({1, 2, 3});

  EXPECT_EQ(v.size(), 3);
}

TEST(size_2, test_18) {
  s21::vector<int> v(2);

  EXPECT_EQ(v.size(), 0U);
}

TEST(size_3, test_18) {
  s21::vector<int> v;

  EXPECT_EQ(v.size(), 0U);
}

TEST(emplace_1, test_19) {
  s21::vector<int> v({1, 2, 3});
  v.emplace(v.begin(), 6, 7, 8);
  v.emplace_back(10);
  EXPECT_EQ(v.size(), 7);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
