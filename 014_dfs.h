//
// Created by Andrei Covaci on 22.09.2021.
// https://infoarena.ro/problema/dfs
//

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_014_DFS_H
#define INFOARENA_ARHIVA_EDUCATIONALA_014_DFS_H

#include <fstream>
#include <vector>
#include <stack>

//#define INPUT "dfs.in"
//#define OUTPUT "dfs.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

using namespace std;

vector<vector<int>> read() {
    ifstream in(INPUT);

    int n, m, tail, head;
    in >> n >> m;

    vector<vector<int> > list;
    list.reserve(n);
    for(int i = 0; i < n; ++i) {
        list.emplace_back();
    }

    for(int i = 0; i < m; ++i) {
        in >> tail >> head;
        tail--;
        head--;
        list[tail].push_back(head);
        list[head].push_back(tail);
    }

    in.close();
    return list;
}



int solve(vector<vector<int>>& list) {
    vector<bool> visited;
    visited.reserve(list.size());
    for(int i = 0; i < list.size(); ++i) {
        visited.push_back(false);
    }

    int cnt = 0;

    for(int i = 0; i < list.size(); ++i) {
        if (!visited[i]) {
            cnt++;
            stack<int> s;
            s.push(i);

            while(!s.empty()) {
                int curr = s.top();
                s.pop();

                for(auto e : list[curr]) {
                    if(!visited[e]) {
                        s.push(e);
                        visited[e] = true;
                    }
                }
            }
        }
    }

    return cnt;
}

void print(int c) {
    ofstream out(OUTPUT);

    out << c;

    out.close();
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_014_DFS_H
