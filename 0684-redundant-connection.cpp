#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    template <typename T>
    using v = vector<T>;

    template <typename T>
    using s = unordered_set<T>;

    v<int> parent;
    v<int> rank;

    void make_set(int a) {
        parent[a] = a;
        rank[a] = 1;
    }

    int find_set(int a) {
        if (parent[a] == -1) {
            make_set(a);
            return a;
        }

        if (parent[a] == a)
            return a;

        return parent[a] = find_set(parent[a]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                parent[a] = b;
                rank[b] += rank[a];
            } else {
                parent[b] = a;
                rank[a] += rank[b];
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for (auto &e : edges) {
            n = max(n, e[0] - 1);
            n = max(n, e[1] - 1);
        }
        ++n;

        parent = v<int>(n, -1);
        rank = v<int>(n);

        vector<int> ret;
        for (auto &e : edges) {
            int a = find_set(e[0] - 1);
            int b = find_set(e[1] - 1);
            if (a == b) {
                ret = e;
            } else {
                union_sets(a, b);
            }
        }
        return ret;
    }
};

    /*

        the last necessary edge is the first edge such that all vertices are connected (in the same set)
        of the remaining edges, return the last one

        a redundant connection is an edge that forms a cycle

    */
