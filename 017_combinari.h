#include <climits>
//
// Created by Andrei Covaci on 23.09.2021.
// https://infoarena.ro/problema/combinari
//

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_017_COMBINARI_H
#define INFOARENA_ARHIVA_EDUCATIONALA_017_COMBINARI_H

#include <fstream>
#include <iostream>
#include <vector>

//#define INPUT "combinari.in"
//#define OUTPUT "combinari.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

using namespace std;

int n, k;

pair<vector<int>, int> read() {
    ifstream in(INPUT);

    in >> n >> k;
    vector<int> res;
    res.reserve(n + 1);
    for(int i = 0; i <= n; ++i) {
        res.push_back(i);
    }

    in.close();
    return pair<vector<int>, int>(res, 1);
}

int solve(pair<vector<int>, int> x) {
    ofstream out(OUTPUT);

    vector<int> v = x.first;
    int pos = x.second;

    for(int i = pos; i <= n; ++i) {
        swap(v[pos], v[i]);

        if (v[pos] < v[pos - 1]) {
            swap(v[i], v[pos]);
            continue;
        }
        if (pos == k) {
            for (int j = 1; j <= k; ++j) {
                out << v[j] << ' ';
            }
            out << '\n';
            swap(v[i], v[pos]);
            continue;
        }

        solve(pair<vector<int>, int>(v, pos + 1));

        swap(v[i], v[pos]);
    }

    out.close();
    return 0;
}

void print(__unused int c) {
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_017_COMBINARI_H
