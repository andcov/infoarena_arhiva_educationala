//
// Created by Andrei Covaci on 29.09.2021.
// https://infoarena.ro/problema/darb
//

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_058_DARB_H
#define INFOARENA_ARHIVA_EDUCATIONALA_058_DARB_H

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

//#define INPUT "darb.in"
//#define OUTPUT "darb.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

int n;
unordered_map<int, vector<int>> adj;
bool vis[100001];

int read() {
    ifstream in(INPUT);

    int a, b;

    in >> n;

    for(int i = 0; i < n - 1; ++i) {
        in >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    in.close();
    return 0;
}

pair<int, int> dfs(int no, int len) {
    if(vis[no]) {
        return make_pair(len, no);
    }

    vis[no] = true;
    len++;

    int maxv = len, maxn = no;
    for(auto e : adj[no]) {
        auto aux = dfs(e, len);
        int l = aux.first, nd = aux.second;
        if(l > maxv) {
            maxv = l;
            maxn = nd;
        }
    }

    return make_pair(maxv, maxn);
}

int solve(int q) {
    for(int i = 0; i <= n; ++i) {
        vis[i] = false;
    }
    int f = dfs(1, 0).second;

    for(int i = 0; i <= n; ++i) {
        vis[i] = false;
    }

    return dfs(f, 0).first;
}

void print(int res) {
    ofstream out(OUTPUT);

    out << res;

    out.close();
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_058_DARB_H
