/*
 * File: relation.cpp
 * ------------------
 * Last updated: Mon Nov 25 23:01:10 CST 2024
 */
#include "relation.h"

Relation::Relation() : size(0) {
    // cout << "Relation object created with size = " << size << endl;
}

bool Relation::loadFromFile(const string& filepath) {
    ifstream ifs(filepath);
    if (!ifs.is_open()) {
        cerr << "Error: Could not open file: " << filepath << endl;
        return false;
    }

    ifs >> size;
    matrix.resize(size, vector<int>(size));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ifs >> matrix[i][j];
        }
    }

    ifs.close();
    return true;
}

void Relation::displayMatrix() const {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

bool Relation::isReflexive() const {
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] != 1) {
            return false;
        }
    }
    return true;
}

bool Relation::isAntiReflexive() const {
    for (int i = 0; i < size; ++i) {
        if (matrix[i][i] != 0) {
            return false;
        }
    }
    return true;
}

bool Relation::isSymmetric() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool Relation::isAntiSymmetric() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1) {
                return false;
            }
        }
    }
    return true;
}

bool Relation::isTransitive() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 1) {                                // i -> j
                for (int k = 0; k < size; k++) {
                    if (matrix[j][k] == 1 && matrix[i][k] != 1) {   // j -> k && i -/> k
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

Relation::~Relation() {}
