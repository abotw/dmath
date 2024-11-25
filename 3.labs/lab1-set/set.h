#ifndef SET_H
#define SET_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using std::string;

// 4. 集合的元素类型推广到其他类型，甚至任意类型。
template <typename T>
class Set {
public:
    Set();
    Set(int capacity);
    ~Set();

    bool add(const T& element);
    bool remove(const T& element);
    void clear();
    int size() const;
    bool isEmpty() const;
    void print() const;
    string toString() const;

    // 3. 集合的混合运算表达式求值。
    Set operator+(const Set& other) const;  // union
    Set operator-(const Set& other) const;  // difference
    Set operator*(const Set& other) const;  // intersection

    // 1. 集合的元素判定和子集判定运算。
    bool contains(const T& element) const;
    bool isSubsetOf(const Set& other) const;
    // 2. 求集合的补集。
    Set<char> lowercaseComplement() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Set<U>& set);

    const T* begin() const;
    const T* end() const;

private:
    std::vector<T> elements;
    int capacity;
};

#include "setv.cpp"

#endif // SET_H
