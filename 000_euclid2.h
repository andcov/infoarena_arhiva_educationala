/**
Created by Andrei Covaci on 04.09.2021.
https://infoarena.ro/problema/euclid2

IN:
3
12 42
21 7
9 10

OUT:
6
7
1
**/

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_MAIN_H
#define INFOARENA_ARHIVA_EDUCATIONALA_MAIN_H

#include <fstream>
#include <vector>

//#define INPUT "euclid2.in"
//#define OUTPUT "euclid2.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

using namespace std;

vector<pair<int, int>> read() {
    ifstream in(INPUT);

    vector<pair<int, int>> nums;
    int n, a, b;
    in >> n;
    for(; n; --n) {
        in >> a >> b;
        nums.emplace_back(a, b);
    }

    return nums;
}

vector<int> solve_euclid(vector<pair<int, int>>& nums) {
    vector<int> res;
    for(auto pair : nums) {
        int a = pair.first, b = pair.second;
        int r = a % b;
        a = b;
        b = r;
        while(b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        res.push_back(a);
    }

    return res;
}

void print(vector<int>& res) {
    ofstream out(OUTPUT);

    for(auto r : res) {
        out << r << '\n';
    }
}

void solve() {
    auto in = read();
    auto out = solve_euclid(in);
    print(out);
}
#endif //INFOARENA_ARHIVA_EDUCATIONALA_MAIN_H
