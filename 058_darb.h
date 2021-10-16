/**
Created by Andrei Covaci on 29.09.2021.
https://infoarena.ro/problema/darb

IN:
11
1 2
1 3
1 4
2 5
3 6
4 7
5 8
5 9
6 10
10 11

OUT:
8
**/

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_058_DARB_H
#define INFOARENA_ARHIVA_EDUCATIONALA_058_DARB_H

#include <fstream>
#include <vector>
#include <queue>

using namespace std;

//#define INPUT "darb.in"
//#define OUTPUT "darb.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

vector<vector<int>> adj(100001, vector<int>());
vector<int> dist(100001);
bool vis1[100001];
bool vis2[100001];
int last;

void read() {
    ifstream in(INPUT);

    int a, b, n;

    in >> n;
    n--;

    for(; n; --n) {
        in >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    in.close();
}


void bfs1(int n) {
    queue<int> l;
    l.emplace(n);

    while(!l.empty()) {
        int curr = l.front();

        if(vis1[curr]) {
            continue;
        }

        vis1[curr] = true;
        last = curr;

        for(auto e : adj[curr]) {
            if (!vis1[e]) {
                l.emplace(e);
            }
        }

        l.pop();
    }
}

void bfs2(int n) {
    queue<int> l;
    l.emplace(n);
    dist[n] = 1;

    while(!l.empty()) {
        int curr = l.front();

        if(vis2[curr]) {
            continue;
        }

        vis2[curr] = true;
        last = curr;

        for(auto e : adj[curr]) {
            if (!vis2[e]) {
                l.emplace(e);
                dist[e] = dist[curr] + 1;
            }
        }

        l.pop();
    }
}

int solve_darb() {
    bfs1(1);
    bfs2(last);

    return dist[last];
}

inline void print(int res) {
    ofstream out(OUTPUT);

    out << res;

    out.close();
}

void solve() {
    read();
    auto out = solve_darb();
    print(out);
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_058_DARB_H
