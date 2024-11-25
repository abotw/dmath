/*
 * File: lab3.cpp
 * Compile command: `g++ -std=c++11 -o lab2 lab2.cpp relation.cpp`
 * --------------
 * Last updated: Mon Nov 25 23:01:24 CST 2024
 */
#include "relation.h"

int displayRelProps(const string& filepath);

int main() {
    displayRelProps("r0.txt");
    displayRelProps("r1.txt");
    displayRelProps("r2.txt");
    displayRelProps("r3.txt");

    return 0;
}

int displayRelProps(const string& filepath) {
    Relation relation;

    if (!relation.loadFromFile(filepath)) {
        return 1;
    }

    cout << "\nRelation Matrix:\n";
    relation.displayMatrix();

    cout << "Relation Properties:\n";
    cout << "\tReflexive: " << (relation.isReflexive() ? "\tYes" : "\tNo") << endl;
    cout << "\tAnti-Reflexive: " << (relation.isAntiReflexive() ? "\tYes" : "\tNo") << endl;
    cout << "\tSymmetric: " << (relation.isSymmetric() ? "\tYes" : "\tNo") << endl;
    cout << "\tAnti-Symmetric: " << (relation.isAntiSymmetric() ? "\tYes" : "\tNo") << endl;
    cout << "\tTransitive: " << (relation.isTransitive() ? "\tYes" : "\tNo") << endl;
    return 0;
}
