/*
 * Lab 1: 2. 求集合的补集。
 * -----------
 * Last updated: Thu Nov 21 13:17:41 CST 2024
 */
#include <iostream>
#include <string>
#include "set.h"
using namespace std;

int main() {
    Set<char> universalSet, setChar, complement;
    string setStr;

    // Universal set
    for (char c = 'a'; c <= 'z'; ++c) {
        universalSet.add(c);
    }
    getline(cin, setStr);
    for (int i = 0; i < setStr.size(); i++) {
        if (setStr[i] >= 'a' && setStr[i] <= 'z') {
            setChar.add(setStr[i]);
        }
    }
    
    cout << setChar << endl;

    // complement = universalSet - setChar;
    complement = setChar.lowercaseComplement();

    cout << complement << endl;

    return 0;
}