/*
 * Lab 1: 编制一个能演示执行集合的并、交和差运算的程序。
 * -----
 * Last updated: Thu Nov 21 13:42:10 CST 2024
 */
#include <iostream>
#include <string>
#include "set.h"
using namespace std;

int main() {
    // INIT
    Set<char> setChar1, setChar2, setUnion, setDiff, setIntersect, setComplement;
    string setStr1, setStr2;
    char resp;

    do {
        // INPUT
        cout << "Input set1 string: ";
        getline(cin, setStr1);
        cout << "Input set2 string: ";
        getline(cin, setStr2);

        // INIT setChar1
        for (int i = 0; i < setStr1.size(); i++) {
            if (setStr1[i] >= 'a' && setStr1[i] <= 'z') {
                setChar1.add(setStr1[i]);
            }
        }

        // INIT setChar2
        for (int i = 0; i < setStr2.size(); i++) {
            if (setStr2[i] >= 'a' && setStr2[i] <= 'z') {
                setChar2.add(setStr2[i]);
            }
        }

        // PERFORM SET OPERATIONS
        setUnion = setChar1 + setChar2; // Union
        setDiff = setChar1 - setChar2; // Difference
        setIntersect = setChar1 * setChar2; // Intersection
        setComplement = setUnion.lowercaseComplement();

        // OUTPUT
        cout << "Union: " << setUnion << endl;
        cout << "Difference: " << setDiff << endl;
        cout << "Intersection: " << setIntersect << endl;
        cout << "Complement of setUnion: " << setComplement << endl;

        // MORE?
        cout << "\nMore (Y or N)? ";
        cin >> resp;
        cin.ignore();

        // RESET
        setStr1 = "";
        setStr2 = "";
        setChar1.clear();
        setChar2.clear();
    } while (resp == 'Y' || resp == 'y');

    return 0;
}

// set1 = "magazine"
// set2 = "paper"
// set1 + set2 = "aegimnprz"
// set1 - set2 = "gimnz"
// set1.intersect(2) = "ae"

// set1 = "012oper4a6tion89"
// set2 = "error data"
// set1 + set2 = "adeinoprt"
// set1 - set2 = "inp"
// se1.intersect(set2) = "aeort"