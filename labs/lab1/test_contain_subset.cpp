/*
 * Lab 1: 1. 集合的元素判定和子集判定运算。
 * ---------------------------
 * Last updated: Thu Nov 21 13:43:50 CST 2024
 */
#include <iostream>
#include "set.h"
using namespace std;

template <typename T>
void testContains(const Set<T>& set, const T& element) {
    cout << "Testing 'contains' method:\n";
    cout << "Set: " << set << "\n";
    cout << "Element: " << element << "\n";
    if (set.contains(element)) {
        cout << "Result: The set contains the element.\n\n";
    } else {
        cout << "Result: The set does not contain the element.\n\n";
    }
}

template <typename T>
void testIsSubsetOf(const Set<T>& subset, const Set<T>& superset) {
    cout << "Testing 'isSubsetOf' method:\n";
    cout << "Subset: " << subset << "\n";
    cout << "Superset: " << superset << "\n";
    if (subset.isSubsetOf(superset)) {
        cout << "Result: The first set is a subset of the second set.\n\n";
    } else {
        cout << "Result: The first set is not a subset of the second set.\n\n";
    }
}

int main() {
    // INIT
    Set<int> set1;
    Set<int> set2;
    Set<int> set3;

    set1.add(1);
    set1.add(2);
    set1.add(3);

    set2.add(1);
    set2.add(2);

    set3.add(4);
    set3.add(5);

    testContains(set1, 2);
    testContains(set1, 4);

    testIsSubsetOf(set2, set1);
    testIsSubsetOf(set3, set1);

    return 0;
}