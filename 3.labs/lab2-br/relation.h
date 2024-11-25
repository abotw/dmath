/*
 * File: relation.h
 * ----------------
 * Last updated: Mon Nov 25 23:01:17 CST 2024
 */
#ifndef RELATION_H
#define RELATION_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::ifstream;

class Relation {
private:
    vector<vector<int>> matrix; // a boolean relation matrix
    int size;                   // size

public:
    Relation();

    bool loadFromFile(const string& filepath);

    void displayMatrix() const;

    bool isReflexive() const;
    bool isAntiReflexive() const;
    bool isSymmetric() const;
    bool isAntiSymmetric() const;
    bool isTransitive() const;

    

    ~Relation();
};

#endif // RELATION_H
