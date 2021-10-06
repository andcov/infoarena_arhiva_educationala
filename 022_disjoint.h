//
// Created by Andrei Covaci on 06.10.2021.
// https://infoarena.ro/problema/disjoint
//

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_022_DISJOINT_H
#define INFOARENA_ARHIVA_EDUCATIONALA_022_DISJOINT_H

#include <fstream>
#include <vector>

using namespace std;

//#define INPUT "disjoint.in"
//#define OUTPUT "disjoint.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

int dis[100001];
int n;

vector<tuple<int, int, int>> read() {
    ifstream in(INPUT);

    vector<tuple<int, int, int>> res;
    int m, s, x, y;

    in >> n >> m;
    for(; m; --m) {
        in >> s >> x >> y;
        res.emplace_back(s, x, y);
    }

    in.close();
    return res;
}

void init() {
    for(int i = 1; i <= n; ++i) {
        dis[i] = i;
    }
}

int find(int x) {
    if(dis[x] == x) {
        return x;
    }
    int father = find(dis[x]);
    dis[x] = father;
    return father;
}

void unite(int x, int y) {
    dis[find(x)] = y;
}

vector<bool> solve(vector<tuple<int, int, int>>& ins) {
    vector<bool> res;

    init();

    for(auto t : ins) {
        int x = get<1>(t), y = get<2>(t);
        if(get<0>(t) == 1) {
            unite(x, y);
        } else {
            if(find(x) == find(y))
                res.emplace_back(true);
            else
                res.emplace_back(false);
        }
    }

    return res;
}

void print(vector<bool>& res) {
    ofstream out(OUTPUT);

    for(auto b : res) {
        if (b)
            out << "DA\n";
        else
            out << "NU\n";
    }

    out.close();
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_022_DISJOINT_H
