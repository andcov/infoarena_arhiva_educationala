//
// Created by Andrei Covaci on 29.09.2021.
// https://infoarena.ro/problema/rmq
//

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_016_RMQ_H
#define INFOARENA_ARHIVA_EDUCATIONALA_016_RMQ_H

#include <fstream>
#include <vector>
#include <cmath>

//#define INPUT "rmq.in"
//#define OUTPUT "rmq.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

using namespace std;

int n, m, pre[20][100001];

pair<vector<int>, vector<pair<int, int>>> read() {
    ifstream in(INPUT);

    in >> n >> m;

    int a, b;
    vector<int> vals;
    vals.reserve(n);
    for(int i = 0; i < n; ++i) {
        in >> a;
        vals.emplace_back(a);
    }

    vector<pair<int, int>> ques;
    ques.reserve(m);
    for(int i = 0; i < m; ++i) {
        in >> a >> b;
        ques.emplace_back(--a, --b);
    }

    in.close();
    return make_pair(vals, ques);
}

int find_min(int a, int b, int minv) {
    int len = b - a + 1;
    int log_len = (int) log2(len);
    int len_pow = 1 << log_len;

    if (len_pow == len) {
        return pre[log_len][a];
    } else {
        int cmp = find_min(a + len_pow, b, minv);
        return min(min(cmp, minv), pre[log_len][a]);
    }
}

vector<int> solve(pair<vector<int>, vector<pair<int, int>>>& in) {
    auto vals = in.first;
    auto ques = in.second;

    for(int i = 0; i < n; ++i) {
        pre[0][i] = vals[i];
    }

    int level = 1, two = 2;
    while(two / 2 < n) {
        for(int i = 0; i < n; ++i) {
            pre[level][i] = (i + two / 2 >= n) ? pre[level - 1][i] : min(pre[level - 1][i], pre[level - 1][i + two / 2]);
        }
        ++level;
        two = two << 1;

    }

    vector<int> res;
    res.reserve(m);
    for(int i = 0; i < m; ++i) {
        res.push_back(find_min(ques[i].first, ques[i].second, 100001));
    }

    return res;
}

void print(vector<int>& res) {
    ofstream out(OUTPUT);

    for(auto e : res) {
        out << e << '\n';
    }

    out.close();
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_016_RMQ_H
