//
// Created by Andrei Covaci on 29.09.2021.
// https://infoarena.ro/problema/heapuri
//

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_025_HEAPURI_H
#define INFOARENA_ARHIVA_EDUCATIONALA_025_HEAPURI_H

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

//#define INPUT "heapuri.in"
//#define OUTPUT "heapuri.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

using namespace std;

int heap[200002];
int len = 0;

void insert(int ele) {
    ++len;
    heap[len] = ele;
    int pos = len;

    while(pos > 1) {
        if(heap[pos / 2] > heap[pos]) {
            swap(heap[pos / 2], heap[pos]);
            pos /= 2;
        } else {
            break;
        }
    }
}

int peek() {
    return (len != 0) * heap[1];
}

void remove_top() {
    int pos = 1;
    heap[pos] = heap[len];
    --len;

    while(pos <= (len - 1) / 2) {
        if(heap[pos * 2] < heap[pos * 2 + 1] && heap[pos * 2] < heap[pos]) {
            swap(heap[pos], heap[pos * 2]);
            pos *= 2;
        } else if (heap[pos * 2] >= heap[pos * 2 + 1] && heap[pos * 2 + 1] < heap[pos]) {
            swap(heap[pos], heap[pos * 2 + 1]);
            pos = pos * 2 + 1;
        } else {
            break;
        }
    }
    if(len % 2 != 0 && heap[len - 1] < heap[len] && heap[len - 1] < heap[len / 2])
        swap(heap[len - 1], heap[len / 2]);
    else if (heap[len] < heap[len / 2])
        swap(heap[len], heap[len / 2]);
}

void remove(int ele) {
    int pos = 1;
    for(; pos <= len; ++pos) if (heap[pos] == ele) break;

    if (pos == len + 1) return;
    if (pos == len) { len--; return; }
    if (pos == 1) { remove_top(); return; }

    heap[pos] = heap[len];
    --len;

    if (heap[pos] < heap[pos / 2]) {
        while(pos > 1) {
            if(heap[pos / 2] > heap[pos]) {
                swap(heap[pos / 2], heap[pos]);
                pos /= 2;
            } else {
                break;
            }
        }
    } else if (heap[pos] > heap[pos * 2] || heap[pos] > heap[pos * 2 + 1]) {
        while(pos <= (len - 1) / 2) {
            if(heap[pos * 2] < heap[pos * 2 + 1] && heap[pos * 2] < heap[pos]) {
                swap(heap[pos], heap[pos * 2]);
                pos *= 2;
            } else if (heap[pos * 2] >= heap[pos * 2 + 1] && heap[pos * 2 + 1] < heap[pos]) {
                swap(heap[pos], heap[pos * 2 + 1]);
                pos = pos * 2 + 1;
            } else {
                break;
            }
        }
        if(len % 2 != 0 && heap[len - 1] < heap[len] && heap[len - 1] < heap[len / 2])
            swap(heap[len - 1], heap[len / 2]);
        else if (heap[len] < heap[len / 2])
            swap(heap[len], heap[len / 2]);
    }
}

int read() {
    return 0;
}

vector<int> solve(int w) {
    ifstream in(INPUT);

    vector<int> res, hist;

    int n, task, val;
    in >> n;

    for(; n; --n) {
        in >> task;
        if(task == 1) {
            in >> val;
            hist.emplace_back(val);
            insert(val);
        } else if(task == 2) {
            in >> val;
            remove(hist[--val]);
        } else {
            res.emplace_back(peek());
        }
    }

    in.close();

    return res;
}

void print(vector<int>& res) {
    ofstream out(OUTPUT);

    for(auto e : res) {
        out << e << '\n';
    }

    out.close();
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_025_HEAPURI_H
