/**
Created by Andrei Covaci on 23.09.2021.
https://infoarena.ro/problema/combinari

IN:
4 3

OUT:
1 2 3
1 2 4
1 3 4
2 3 4
**/

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_017_COMBINARI_H
#define INFOARENA_ARHIVA_EDUCATIONALA_017_COMBINARI_H

#include <fstream>
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
    return {res, 1};
}

ofstream out(OUTPUT);

void solve_combinari(pair<vector<int>, int> x) {

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

        solve_combinari(pair<vector<int>, int>(v, pos + 1));

        swap(v[i], v[pos]);
    }
}

void solve() {
    auto in = read();
    solve_combinari(in);
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_017_COMBINARI_H
