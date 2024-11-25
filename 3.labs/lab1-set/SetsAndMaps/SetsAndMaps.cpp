#include "console.h"
#include "hashmap.h"
#include "hashset.h"
#include "map.h"
#include "set.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    // init
    Set<char> setChar1, setChar2, setUnion, setDiff, setIntersect;
    string setStr1, setStr2;
    char resp;

    do {
        // input
        cout << "Input set1 string: ";
        getline(cin, setStr1);
        cout << "Input set2 string: ";
        getline(cin, setStr2);

        for (int i = 0; i < setStr1.size(); i++) {
            if (setStr1[i] >= 'a' && setStr1[i] <= 'z') {
                setChar1.add(setStr1[i]);
            }
        }
        for (int i = 0; i < setStr2.size(); i++) {
            if (setStr2[i] >= 'a' && setStr2[i] <= 'z') {
                setChar2.add(setStr2[i]);
            }
        }

        setUnion = setChar1 + setChar2;
        setDiff = setChar1 - setChar2;
        setIntersect = setChar1.intersect(setChar2);

        cout << "Union: ";
        for (char ch : setUnion) {
            cout << ch;
        }
        cout << endl;
        cout << "Difference: ";
        for (char ch : setDiff) {
            cout << ch;
        }
        cout << endl;
        cout << "Intersect: ";
        for (char ch : setIntersect) {
            cout << ch;
        }
        cout << endl;
        // more ?
        cout << "\nMore (Y or N)? ";
        cin >> resp;
        cin.ignore(); // clear input buffer
        // reset
        setStr1 = "";
        setStr2 = "";
        setChar1.clear();
        setChar2.clear();
    } while (resp == 'Y' || resp == 'y');


    return 0;
}
