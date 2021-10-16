/**
Created by Andrei Covaci on 05.09.2021.
https://infoarena.ro/problema/strmatch

IN:
ABA
CABBCABABAB

OUT:
2
5 7
**/

#ifndef INFOARENA_ARHIVA_EDUCATIONALA_005_STRMATCH_H
#define INFOARENA_ARHIVA_EDUCATIONALA_005_STRMATCH_H

#include <fstream>
#include <vector>

//#define INPUT "strmatch.in"
//#define OUTPUT "strmatch.out"
#define INPUT "input.in"
#define OUTPUT "output.out"

using namespace std;

const int BASE = 73;
const int PRIME_MODULUS_ONE = 100007;
const int PRIME_MODULUS_TWO = 100021;
int OFFSET_ONE = 1;
int OFFSET_TWO = 1;

pair<string, string> read() {
    ifstream in(INPUT);

    pair<string, string> res;
    getline(in, res.first);
    getline(in, res.second);

    in.close();
    return res;
}

int hash_one(string s) {
    int hash = (unsigned char) s[0];
    for(int i = 1; i < s.size(); ++i) {
        hash *= BASE;
        hash %= PRIME_MODULUS_ONE;
        hash += s[i];
        hash %= PRIME_MODULUS_ONE;
    }

    return hash;
}

int hash_two(string s) {
    int hash = (unsigned char) s[0];
    for(int i = 1; i < s.size(); ++i) {
        hash *= BASE;
        hash %= PRIME_MODULUS_TWO;
        hash += s[i];
        hash %= PRIME_MODULUS_TWO;
    }

    return hash;
}

void calc_offsets(int size) {
    for(int i = 0; i < size - 1; ++i) {
        OFFSET_ONE %= PRIME_MODULUS_ONE;
        OFFSET_ONE *= BASE;
    }
    for(int i = 0; i < size - 1; ++i) {
        OFFSET_TWO %= PRIME_MODULUS_TWO;
        OFFSET_TWO *= BASE;
    }
}

vector<int> solve_strmatch(pair<string, string>& strings) {
    string pattern = strings.first, s = strings.second;

    if(pattern.size() > s.size()) {
        return {};
    }

    calc_offsets(pattern.size());

    auto pattern_hash_one = hash_one(pattern);
    auto pattern_hash_two = hash_two(pattern);

    auto curr_hash_one = hash_one(s.substr(0, pattern.size()));
    auto curr_hash_two = hash_two(s.substr(0, pattern.size()));

    vector<int> pos;


    for(int i = 0; i <= s.size() - pattern.size(); ++i) {
        if (pattern_hash_one == curr_hash_one && pattern_hash_two == curr_hash_two) {
            pos.push_back(i);
        }

        curr_hash_one = ((curr_hash_one + PRIME_MODULUS_ONE - s[i] * OFFSET_ONE % PRIME_MODULUS_ONE) * BASE + s[i + pattern.size()]) % PRIME_MODULUS_ONE;
        curr_hash_two = ((curr_hash_two + PRIME_MODULUS_TWO - s[i] * OFFSET_TWO % PRIME_MODULUS_TWO) * BASE + s[i + pattern.size()]) % PRIME_MODULUS_TWO;
    }

    return pos;
}

void print(vector<int>& res) {
    ofstream out(OUTPUT);

    out << res.size() << '\n';
    for(int i = 0; i < 1000 && i < res.size(); ++i) {
        out << res[i] << ' ';
    }

    out.close();
}

void solve() {
    auto in = read();
    auto out = solve_strmatch(in);
    print(out);
}

#endif //INFOARENA_ARHIVA_EDUCATIONALA_005_STRMATCH_H
