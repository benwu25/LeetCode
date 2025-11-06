#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    template <typename T>
    using v = vector<T>;

    template <typename K, typename V>
    using m = unordered_map<K, V>;

    template <typename T>
    using s = set<T>;

    v<int> parent;
    v<int> rank;

    m<int, set<int>> parent_to_operational;

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

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent = v<int>(c, -1);
        rank = v<int>(c);

        for (auto &conn : connections) {
            int a = find_set(conn[0] - 1);
            int b = find_set(conn[1] - 1);
            union_sets(a, b);
        }

        // build map to ordered sets
        for (int i = 0; i < parent.size(); ++i) {
            parent_to_operational[find_set(i)].insert(i);
        }

        v<int> results;
        for (auto &query : queries) {
            int x = query[1] - 1;
            int p = find_set(x);
            if (query[0] == 1) {
                if (parent_to_operational[p].size() == 0) {
                    results.emplace_back(-1);
                } else if (parent_to_operational[p].contains(x)) {
                    results.emplace_back(x+1);
                } else {
                    results.emplace_back((*parent_to_operational[p].begin()) + 1);
                }
            } else {
                parent_to_operational[p].erase(x);
            }
        }
        return results;
    }
};
