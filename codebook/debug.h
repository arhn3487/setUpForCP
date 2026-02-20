#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>
using namespace std;

// ================= Debug Template =================

// Base __print functions
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

// Pair
template<typename T, typename V>
void __print(const pair<T,V> &x) { cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'; }

// Iterable containers (generic)
template<typename T>
auto __print(const T &x) -> decltype(x.begin(), void()) {
    cerr << '{';
    bool first = true;
    for (const auto &i : x) {
        if (!first) cerr << ", ";
        __print(i);
        first = false;
    }
    cerr << '}';
}

// Specialization for 2D vector: print like a table
// template<typename T>
// void __print(const vector<vector<T>> &matrix) {
//     cerr << "\n[\n";
//     for (const auto &row : matrix) {
//         cerr << "  ";
//         for (size_t i = 0; i < row.size(); i++) {
//             __print(row[i]);
//             if (i + 1 < row.size()) cerr << " ";
//         }
//         cerr << "\n";
//     }
//     cerr << "]\n";
// }



template<typename T>
void __print(const vector<vector<T>> &matrix) {
    if (matrix.empty()) {
        cerr << "[]";
        return;
    }
    cerr << "\n[\n";
    for (const auto &row : matrix) {
        cerr << "  ";
        for (const auto &val : row) {
            // Adjust the number 4 to 2 or 5 depending on your usual data size
            cerr << std::setw(4); 
            __print(val);
        }
        cerr << "\n";
    }
    cerr << "]";
}

// priority_queue
template<typename T>
void __print(priority_queue<T> pq) {
    cerr << "pq{";
    bool first = true;
    while(!pq.empty()) {
        if(!first) cerr << ", ";
        __print(pq.top());
        pq.pop();
        first = false;
    }
    cerr << "}";
}

// stack
template<typename T>
void __print(stack<T> st) {
    cerr << "stack{";
    bool first = true;
    while(!st.empty()) {
        if(!first) cerr << ", ";
        __print(st.top());
        st.pop();
        first = false;
    }
    cerr << "}";
}

// queue
template<typename T>
void __print(queue<T> q) {
    cerr << "queue{";
    bool first = true;
    while(!q.empty()) {
        if(!first) cerr << ", ";
        __print(q.front());
        q.pop();
        first = false;
    }
    cerr << "}";
}

// deque
template<typename T>
void __print(deque<T> dq) {
    cerr << "deque{";
    bool first = true;
    for(const auto &x : dq) {
        if(!first) cerr << ", ";
        __print(x);
        first = false;
    }
    cerr << "}";
}

// Base _print
void _print() { cerr << "]\n"; }

template<typename T, typename... V>
void _print(T t, V... v) { __print(t); if(sizeof...(v)) cerr << ", "; _print(v...); }

// Main debug macro
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#endif // DEBUG_H
