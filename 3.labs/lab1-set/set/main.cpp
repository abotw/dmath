#include "set.h"

int main() {
    Set<int> set1;
    set1.add(1);
    set1.add(2);
    set1.add(3);
    std::cout << "Set 1: " << set1 << std::endl;

    Set<int> set2;
    set2.add(3);
    set2.add(4);
    set2.add(5);
    std::cout << "Set 2: " << set2 << std::endl;

    Set<int> unionSet = set1 + set2;
    std::cout << "Union: " << unionSet << std::endl;

    Set<int> diffSet = set1 - set2;
    std::cout << "Difference: " << diffSet << std::endl;

    Set<int> intersectSet = set1 * set2;
    std::cout << "Intersection: " << intersectSet << std::endl;

    std::cout << "Set 1 is a subset of Set 2: " << (set1.isSubsetOf(set2) ? "Yes" : "No") << std::endl;

    // Demonstrate lowercase complement (only for char sets)
    Set<char> charSet;
    charSet.add('a');
    charSet.add('b');
    charSet.add('c');
    Set<char> complementSet = charSet.lowercaseComplement();
    std::cout << "Lowercase complement: " << complementSet << std::endl;

    return 0;
}
