//
// Created by Andrei Covaci on 07.09.2021.
// https://infoarena.ro/problema/scmax
//

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_008_SCMAX_H
#define INFOARENA_ARHIVA_EDUCATIONALA_008_SCMAX_H

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

#include <fstream>
#include <iostream>
#include <vector>

#define INPUT "scmax.in"
#define OUTPUT "scmax.out"
//#define INPUT "input.in"
//#define OUTPUT "output.out"

using namespace std;

vector<int> read() {
    ifstream in(INPUT);

    int n, aux;
    in >> n;

    vector<int> v;
    v.reserve(n);
    for(; n; --n) {
        in >> aux;
        v.push_back(aux);
    }

    in.close();
    return v;
}

int binary_search(vector<int>& vec, int s, int e, int el) {
    if(s == e) {
        if (vec[s] < el) {
            return s + 1;
        }
        return s;
    }

    int m = (s + e) / 2;
    if(vec[m] < el) {
        return binary_search(vec, m + 1, e, el);
    }
    return binary_search(vec, s, m, el);

}

vector<int> solve(vector<int>& vec) {
    int n = vec.size(), m, j;
    vector<int> cap, ins;
    cap.reserve(n);
    ins.reserve(n);

    cap[1] = vec[0];
    ins[0] = 1;
    m = 2;

    for(int i = 1; i < n; ++i) {
        j = binary_search(cap, 1, m - 1, vec[i]);

        if(j == m && cap[j] < vec[i]) {
            cap[m] = vec[i];
            ins[i] = m;
            ++m;
            continue;
        }

        cap[j] = vec[i];
        ins[i] = j;
    }

    vector<int> res;
    res.reserve(m - 1);
    int curr = m - 1;
    j = n;
    while(j > 0) {
        if (ins[j] == curr) {
            --curr;
            res.push_back(vec[j]);
        }
        --j;
    }

    return res;
}

void print(vector<int>& res) {
    ofstream out(OUTPUT);

    out << res.size() << '\n';

    for(int i = res.size() - 1; i >= 0; --i) {
        out << res[i] << ' ';
    }

    out.close();
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_008_SCMAX_H
