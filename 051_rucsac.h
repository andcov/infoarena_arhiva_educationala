/**
Created by Andrei Covaci on 09.10.2021.
https://infoarena.ro/problema/rucsac

IN:
6 10
3 7
3 4
1 2
1 9
2 4
1 5

OUT:
29
**/

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_051_RUCSAC_H
#define INFOARENA_ARHIVA_EDUCATIONALA_051_RUCSAC_H

#include <fstream>
#include <vector>

using namespace std;

//#define INPUT "rucsac.in"
//#define OUTPUT "rucsac.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

#define usi unsigned short int

int maxw, n;
//      [weight][items]
int din0[10001];
int din1[10001];
vector<pair<usi, usi>> items;

void read() {
    ifstream in(INPUT);

    int w, p;

    in >> n >> maxw;

    for(int i = 0; i < n; ++i) {
        in >> w >> p;
        items.emplace_back(w, p);
    }

    in.close();
}

int solve_rucsac() {
    bool zero = true;
    for(int j = 1; j <= n; ++j) {
        for(int i = 1; i <= maxw; ++i) {
            if(zero) {
                int aux = (i >= items[j - 1].first) ? din0[i - items[j - 1].first] + items[j - 1].second : 0;
                din1[i] = max(din0[i], aux);
            } else {
                int aux = (i >= items[j - 1].first) ? din1[i - items[j - 1].first] + items[j - 1].second : 0;
                din0[i] = max(din1[i], aux);
            }
        }
        zero = !zero;
    }

    if(zero)
        return din0[maxw];

    return din1[maxw];
}

void print(int res) {
    ofstream out(OUTPUT);

    out << res;

    out.close();
}

void solve() {
    read();
    auto out = solve_rucsac();
    print(out);
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_051_RUCSAC_H
