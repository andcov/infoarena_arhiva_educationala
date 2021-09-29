//
// Created by Andrei Covaci on 22.09.2021.
// https://infoarena.ro/problema/bfs
//

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_013_BFS_H
#define INFOARENA_ARHIVA_EDUCATIONALA_013_BFS_H

#include <fstream>
#include <iostream>
#include <vector>
#include <queue>

//#define INPUT "bfs.in"
//#define OUTPUT "bfs.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

using namespace std;

pair<vector<vector<int> >, int> read() {
    ifstream in(INPUT);

    int n, m, s, tail, head;
    in >> n >> m >> s;
    vector<vector<int> > list;

    list.reserve(n);
    for(int i = 0; i < n; ++i) {
        list.emplace_back();
    }

    for(int i = 0; i < m; ++i) {
        in >> tail >> head;
        list[--tail].push_back(--head);
    }

    in.close();
    return pair<vector<vector<int> >, int>(list, --s);
}



vector<int> solve(pair<vector<vector<int> >, int>& plist) {
    auto list = plist.first;
    int s = plist.second;
    queue<pair<int, int> > q;
    q.push(pair<int, int>(s, 0));

    vector<int> len;
    len.reserve(list.size());
    for(int i = 0; i < list.size(); ++i) {
        len.push_back(-1);
    }

    vector<bool> visited;
    visited.reserve(list.size());
    for(int i = 0; i < list.size(); ++i) {
        visited.push_back(false);
    }

    visited[s] = true;

    while(!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        len[curr.first] = curr.second;

        for(auto e : list[curr.first]) {
            if(!visited[e]) {
                q.push(pair<int, int>(e, curr.second + 1));
                visited[e] = true;
            }
        }
    }

    return len;
}

void print(vector<int>& l) {
    ofstream out(OUTPUT);

    for(auto e : l) {
        out << e << ' ';
    }

    out.close();
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_013_BFS_H
