/**
Created by Andrei Covaci on 29.09.2021.
https://infoarena.ro/problema/rmq

IN:
5 4
1
5
6
4
3
2 4
1 2
3 5
1 4

OUT:
4
1
3
1
**/

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_016_RMQ_H
#define INFOARENA_ARHIVA_EDUCATIONALA_016_RMQ_H

#include <fstream>
#include <cmath>

//#define INPUT "rmq.in"
//#define OUTPUT "rmq.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

using namespace std;

int pre[19][100001];

int find_min(int start, int end) {
    int len = end - start + 1;

    if(len == 1) return pre[0][start];

    int pow = floor(log2(len));
    if ((len & (len - 1)) == 0) {
        return pre[pow][start];
    }

    while(len & len - 1) {
        len = len & len - 1;
    }

    return min(pre[pow][start], pre[pow][end - len + 1]);
}

void compute_pre(int n) {
    for(int j = 1; j <= ceil(log2(n)); ++j) {
        int len = 1 << (j - 1);
        for(int i = 0; i < n; ++i) {
            pre[j][i] = (i + len < n) ? min(pre[j - 1][i], pre[j - 1][i + len]) : pre[j - 1][i];
        }
    }
}

void read() {
    ifstream in(INPUT);
    ofstream out(OUTPUT);

    int n, q;
    in >> n >> q;

    for(int i = 0; i < n; ++i) {
        in >> pre[0][i];
    }

    compute_pre(n);

    int a, b;
    for(; q; --q) {
        in >> a >> b;
        --a; --b;
        out << find_min(a, b) << '\n';
    }

    in.close();
    out.close();
}

int solve() {
    read();
    return 0;
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_016_RMQ_H
