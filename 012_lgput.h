/**
Created by Andrei Covaci on 22.09.2021.
https://infoarena.ro/problema/lgput

IN:
2 4

OUT:
16
**/

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_012_LGPUT_H
#define INFOARENA_ARHIVA_EDUCATIONALA_012_LGPUT_H

#include <fstream>
#include <vector>

//#define INPUT "lgput.in"
//#define OUTPUT "lgput.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

using namespace std;

pair<long long, int> read() {
    ifstream in(INPUT);

    int a, b;
    in >> a >> b;

    in.close();
    return make_pair(a, b);
}

long long solve_lgput(pair<long long, int> p) {
    long long base = p.first;
    int exp = p.second;
    int m = 1999999973;

    if (exp == 0)
        return 1;
    if (exp == 1)
        return base % m;

    if (exp % 2 == 0)
        return solve_lgput(pair<long long, int>((base % m) * (base % m), exp / 2)) % m;
    else
        return (base % m) * solve_lgput(pair<long long, int>((base % m) * (base % m), (exp - 1) / 2)) % m;
}

void print(long long n) {
    ofstream out(OUTPUT);

    out << n % 1999999973;

    out.close();
}

void solve() {
    auto nums = read();
    auto res = solve_lgput(nums);
    print(res);
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_012_LGPUT_H
