//
// Created by Andrei Covaci on 09.09.2021.
// https://infoarena.ro/problema/dijkstra
//

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_009_DIJKSTRA_H
#define INFOARENA_ARHIVA_EDUCATIONALA_009_DIJKSTRA_H

#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

//#define INPUT "dijkstra.in"
//#define OUTPUT "dijkstra.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

using namespace std;

int N;
int M;

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

unordered_map<int, vector<Edge>> create_adj_list(vector<Edge>& edges) {
    auto adj_list = unordered_map<int, vector<Edge>>();
    for(auto e : edges) {
        adj_list[e.tail].push_back(e);
    }

    return adj_list;
}

unordered_map<int, vector<Edge>> read() {
    ifstream in(INPUT);

    vector<Edge> res;

    int tail, head, weight;
    in >> N >> M;

    for(int i = 0; i < M; ++i) {
        in >> tail >> head >> weight;
        res.emplace_back(tail, head, weight);
    }

    in.close();
    return create_adj_list(res);
}

unordered_map<int, int> solve(unordered_map<int, vector<Edge>>& adj_list) {
    priority_queue <Edge, vector<Edge>, greater<> > heap;

    for(auto e : adj_list[1]) {
        heap.push(e);
    }

    auto res = unordered_map<int, int>();
    res[1] = 0;

    while(!heap.empty() && res.size() < N) {
        auto min_edge = heap.top();
        heap.pop();

        if (res.count(min_edge.head) == 0) {
            res[min_edge.head] = min_edge.weight;
            for (auto e : adj_list[min_edge.head]) {
                e.weight += min_edge.weight;
                heap.push(e);
            }
        }
    }

    return res;
}

void print(unordered_map<int, int>& res) {
    ofstream out(OUTPUT);

    for(int i = 2; i <= N; ++i) {
        out << res[i] << ' ';
    }

    out.close();
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_009_DIJKSTRA_H
