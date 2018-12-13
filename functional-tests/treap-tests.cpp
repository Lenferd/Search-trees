#include <gtest/gtest.h>
#include "Treap.hpp"
#include <string>

#define DEBUG

class Treap_Functional_STR_INT : public ::testing::Test {
 protected:
  Treap<std::string, int> _tree;
};

class Treap_Functional_INT_DOUBLE : public ::testing::Test {
protected:
  Treap<int, double> _tree;
};

TEST_F(Treap_Functional_STR_INT, CanInsertKey) {
    const std::string key = "first_val";
    const int value = 10;
    ASSERT_NO_THROW(_tree.insert(key, value));
}

TEST_F(Treap_Functional_STR_INT, CorrectInsetNFind) {
    const std::string key = "first_val";
    int value = 42;
    ASSERT_NO_THROW(_tree.insert(key, value));
    ASSERT_EQ(*(_tree.find(key)), value);
}

TEST_F(Treap_Functional_STR_INT, CorrectErase) {
    const std::string key = "first_val";
    int value = 42;
    ASSERT_NO_THROW(_tree.insert(key, value));
    ASSERT_NO_THROW(_tree.erase(key));
    ASSERT_EQ(_tree.find(key), nullptr);
}

TEST_F(Treap_Functional_STR_INT, CorrectInsetNFind_Many) {
    const std::string key = "first_val";
    int value = 42;
    const int count = 10;

    for (size_t i = 0; i < count; i++) {
        #ifdef DEBUG
        std::cout << "key: " << key + std::to_string(i) << " value: " << value + i << '\n';
        #endif
        ASSERT_NO_THROW(_tree.insert(key + std::to_string(i), value + i));
    }

    #ifdef DEBUG
    std::cout << "Result: " << '\n';
    #endif

    for (int i = count - 1; i >= 0; --i) {
        #ifdef DEBUG
        std::cout << "key: " << key + std::to_string(i) << " value: " << value + i << '\n';
        #endif
        ASSERT_EQ(*_tree.find(key + std::to_string(i)), value + i);
    }
}

TEST_F(Treap_Functional_STR_INT, CorrectErase_Many) {
    const std::string key = "first_val";
    int value = 42;
    const int count = 10;

    for (int i = 0; i < count; i++) {
        #ifdef DEBUG
        std::cout << "key: " << key + std::to_string(i) << " value: " << value + i << '\n';
        #endif
        ASSERT_NO_THROW(_tree.insert(key + std::to_string(i), value + i));
    }

    #ifdef DEBUG
    std::cout << "Result: " << '\n';
    #endif

    for (int i = count - 1; i >= 0; --i) {
        #ifdef DEBUG
        std::cout << "key: " << key + std::to_string(i) << " value: " << value + i << '\n';
        #endif
        int * p;
        ASSERT_NO_THROW(p = _tree.find(key + std::to_string(i)));
        ASSERT_TRUE(p != nullptr);
        ASSERT_EQ(*p, value + i);
        ASSERT_NO_THROW(_tree.erase(key + std::to_string(i)));
    }
}

TEST_F(Treap_Functional_INT_DOUBLE, CanInsertKeyIntValDouble) {

    const int key1 = 1;
    const int key2 = 2;
    const int key3 = 3;

    const double value1 = 3.14;
    const double value2 = 3.16;
    const double value3 = 3.18;

    ASSERT_NO_THROW(_tree.insert(key1, value1));
    ASSERT_NO_THROW(_tree.insert(key2, value2));
    ASSERT_NO_THROW(_tree.insert(key3, value3));

    ASSERT_NO_THROW(_tree.erase(key2));

    ASSERT_EQ(*_tree.find(key1), value1);
    ASSERT_EQ(*_tree.find(key3), value3);
}
