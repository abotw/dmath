#ifndef SET_H
#define SET_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using std::string;

// Template class for a Set, providing basic set operations
template <typename T>
class Set {
public:
    Set();
    explicit Set(int capacity);
    ~Set();

    bool add(const T& element);
    bool remove(const T& element);
    void clear();
    bool contains(const T& element) const;
    int size() const;
    bool isEmpty() const;

    void print() const;
    string toString() const;

    Set operator+(const Set& other) const;
    Set operator-(const Set& other) const;
    Set operator*(const Set& other) const;

    bool isSubsetOf(const Set& other) const;
    Set<char> lowercaseComplement() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Set<U>& set);

    const T* begin() const;
    const T* end() const;

private:
    std::vector<T> elements;
    int capacity;
};

#include "setv.cpp" // Include the implementation file (using vector-based implementation)
// Alternatively, use #include "setl.cpp" for a linked list-based implementation

#endif // SET_H
