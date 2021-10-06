#include <climits>
//
// Created by Andrei Covaci on 21.09.2021.
// https://infoarena.ro/problema/permutari
//

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_011_PERMUTARI_H
#define INFOARENA_ARHIVA_EDUCATIONALA_011_PERMUTARI_H

#include <fstream>
#include <vector>

//#define INPUT "permutari.in"
//#define OUTPUT "permutari.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

using namespace std;

int read() {
    ifstream in(INPUT);

    int n;
    in >> n;

    in.close();
    return n;
}

int smallest_right(vector<int>& vec) {
    for(int i = vec.size() - 2; i >= 0; --i)
        if (vec[i] < vec[i + 1])
            return i;

    return -1;
}

int ceil_right(vector<int>& vec, int pos) {
    for(int i = vec.size(); i > pos; --i) {
        if (vec[pos] < vec[i]) {
            return i;
        }
    }
    return pos;
}

void reverse(vector<int>& vec, int first) {
    for(int i = 1; i <= (vec.size() - first) / 2; ++i) {
        swap(vec[first + i], vec[vec.size() - i]);
    }
}

int solve(int n) {
    ofstream out(OUTPUT);

    vector<int> base;
    for(int i = 1; i <= n; ++i) {
        base.emplace_back(i);
    }

    while(true) {
        for(auto e : base) {
            out << e << ' ';
        }
        out << '\n';

        int first = smallest_right(base);
        if (first == -1) {
            break;
        }

        int second = ceil_right(base, first);

        swap(base[first], base[second]);

        reverse(base, first);

    }

    out.close();
    return 0;
}

void print(__unused int n) {
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_011_PERMUTARI_H
