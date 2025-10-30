#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    template <typename K, typename V>
    using m = unordered_map<K, V>;

    template <typename T>
    using v = vector<T>;

    v<int> parent;
    v<int> size;

    int find_set(int i) {
        if (parent[i] == -1) {
            make_set(i);
            return i;
        }

        if (parent[i] == i)
            return i;

        return parent[i] = find_set(parent[i]);
    }

    void make_set(int i) {
        parent[i] = i;
        size[i] = 1;
    }

    void union_sets(int a, int b) {
        int sa = find_set(a), sb = find_set(b);
        if (sa != sb) {
            // attach smaller rank onto larger rank
            if (size[sa] < size[sb]) {
                parent[sa] = sb;
                size[sb] += size[sa];
            } else {
                parent[sb] = sa;
                size[sa] += size[sb];
            }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        parent.resize(s.size(), -1);
        size.resize(s.size(), -1);

        for (int k = 0; k < pairs.size(); ++k) {
            int i = pairs[k][0], j = pairs[k][1];
            int si = find_set(i), sj = find_set(j);
            union_sets(si, sj);
        }

        // iterate disjoint sets
        m<int, priority_queue<char, vector<char>, greater<char>>> strings; // strings[parent] -> sorted string
        for (int i = 0; i < s.size(); ++i) {
            int p = find_set(i);
            if (p == -1)
                continue;
            strings[p].push(s[i]);
        }

        string res = s;
        for (int i = 0; i < s.size(); ++i) {
            int p = find_set(i);
            if (p == -1)
                continue;
            res[i] = strings[p].top();
            strings[p].pop();
        }
        return res;
    }
};
