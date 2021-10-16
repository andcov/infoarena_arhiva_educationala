/**
Created by Andrei Covaci on 06.10.2021.
https://infoarena.ro/problema/apm

IN:
9 14
1 2 10
1 3 -11
2 4 11
2 5 11
5 6 13
3 4 10
4 6 12
4 7 5
3 7 4
3 8 5
8 7 5
8 9 4
9 7 3
6 7 11

OUT:
37
8
3 1
7 9
7 3
9 8
7 4
2 1
5 2
7 6
**/

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_026_APM_H
#define INFOARENA_ARHIVA_EDUCATIONALA_026_APM_H

#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

//#define INPUT "apm.in"
//#define OUTPUT "apm.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

class Edge {
public:
    int tail;
    int head;
    int weight;

    Edge(int _tail, int _head, int _weight) {
        tail = _tail;
        head = _head;
        weight = _weight;
    }

    bool operator<( const Edge & e ) const {
        return weight < e.weight;
    }
    bool operator>( const Edge & e ) const {
        return weight > e.weight;
    }
};

unordered_map<int, vector<Edge>> adj;
unordered_map<int, vector<int>> res_adj;

void read() {
    ifstream in(INPUT);

    int n, m, a, b, w;
    in >> n >> m;

    for(; m; --m) {
        in >> a >> b >> w;
        adj[a].push_back(Edge(a, b, w));
        adj[b].push_back(Edge(b, a, w));
    }

    in.close();
}

pair<int, int> solve_apm() {
    priority_queue<Edge, vector<Edge>, greater<>> heap;
    int curr_node = 1;
    int res_cost = 0, res_edges = 0;

    for(auto e : adj[curr_node]) {
        heap.push(e);
    }

    while(res_adj.size() != adj.size()) {
        auto curr_edge = heap.top();
        heap.pop();
        curr_node = curr_edge.head;

        if (res_adj[curr_node].empty()) {
            res_cost += curr_edge.weight;
            res_edges++;

            res_adj[curr_edge.tail].push_back(curr_node);
            res_adj[curr_node].push_back(curr_edge.tail);

            for (auto e: adj[curr_node]) {
                heap.push(e);
            }
        }
    }

    return make_pair(res_cost, res_edges);
}

void print(pair<int, int> res) {
    ofstream out(OUTPUT);

    out << res.first << '\n' << res.second << '\n';

    unordered_set<int> used;

    for(auto e : res_adj) {
        used.insert(e.first);
        for(auto h : e.second) {
            if(!used.count(h)) out << e.first << ' ' << h << '\n';
        }
    }

    out.close();
}

void solve() {
    read();
    auto out = solve_apm();
    print(out);
}


#endif //INFOARENA_ARHIVA_EDUCATIONALA_026_APM_H
