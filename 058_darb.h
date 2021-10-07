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
#include <climits>

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

int solve(__unused int q) {
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


/*
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

//#define INPUT "darb.in"
//#define OUTPUT "darb.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

int maxg;
unordered_map<int, unordered_set<int>> adj;

int read() {
    ifstream in(INPUT);

    int a, b, n;

    in >> n;
    n--;
    for(; n; --n) {
        in >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    in.close();
    return a;
}

int solve(int n) {
    int max1 = 0, max2 = 0, temp;
    for(int c : adj[n]) {
        adj[c].erase(n);

        temp = solve(c);

        if (temp > max1) {
            max2 = max1;
            max1 = temp;
        } else if (temp > max2) {
            max2 = temp;
        }
    }

    maxg = max(maxg, max1 + max2 + 1);

    return max1 + 1;
}

void print(int res) {
    ofstream out(OUTPUT);

    res = max(res, maxg);
    out << res;

    out.close();
}

*/

#endif //INFOARENA_ARHIVA_EDUCATIONALA_058_DARB_H
