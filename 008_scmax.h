/**
Created by Andrei Covaci on 07.09.2021.
https://infoarena.ro/problema/scmax

IN:
5
24 12 15 15 19

OUT:
3
12 15 19
**/

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_008_SCMAX_H
#define INFOARENA_ARHIVA_EDUCATIONALA_008_SCMAX_H

#include <fstream>
#include <stack>

using namespace std;

//#define INPUT "scmax.in"
//#define OUTPUT "scmax.out"
#define INPUT "input.in"
#define OUTPUT "output.out"


int n, m;
int vec[100001], pos[100001], ins_pos[100001];

/// Return the position of the
/// greatest number smaller than the given `val`
int binary_search(int start, int end, int val) {
    if (start == end) return start;

    int mid = (start + end) / 2;
    if (pos[mid] == val) return mid;

    if (pos[mid] > val) {
        return binary_search(start, mid, val);
    }
    return binary_search(mid + 1, end, val);
}

void read() {
    ifstream in(INPUT);

    in >> n;
    for(int i = 0; i < n; ++i) {
        in >> vec[i];
    }

    in.close();
}

void solve_scmax() {
    pos[0] = vec[0];
    m = 1;

    for(int i = 1; i < n; ++i) {
        int bs = binary_search(0, m, vec[i]);
        pos[bs] = vec[i];
        ins_pos[i] = bs;
        if (bs == m && vec[i] > pos[m - 1])
            ++m;
    }
}

void print() {
    ofstream out(OUTPUT);

    stack<int> res;
    out << m << '\n';
    --m;
    --n;
    while(n >= 0) {
        if(ins_pos[n] == m) {
            res.push(vec[n]);
            --m;
        }
        --n;
    }
    while(!res.empty()) {
        out << res.top() << ' ';
        res.pop();
    }

    out.close();
}

int solve() {
    read();
    solve_scmax();
    print();
    return 0;
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_008_SCMAX_H
