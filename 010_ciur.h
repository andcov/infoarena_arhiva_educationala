//
// Created by Andrei Covaci on 09.09.2021.
// https://infoarena.ro/problema/ciur
//

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_010_CIUR_H
#define INFOARENA_ARHIVA_EDUCATIONALA_010_CIUR_H

#include <fstream>
#include <iostream>

//#define INPUT "ciur.in"
//#define OUTPUT "ciur.out"
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

int solve(int n) {
    bool era[n + 1];
    for(int i = 3; i <= n; ++i) {
        era[i] = i % 2 != 0;
    }
    era[1] = false;
    era[2] = true;

    int prim = (n + 1) / 2;

    for(int i = 3; i <= n; i += 2) {
        for(int j = 2 * i; j <= n && era[i]; j += i) {
            if (era[j]) --prim;
            era[j] = false;
        }
    }

    return prim;
}

void print(int n) {
    ofstream out(OUTPUT);

    out << n;

    out.close();
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_010_CIUR_H
