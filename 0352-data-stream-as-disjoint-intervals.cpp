#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

class SummaryRanges {
public:
    template <typename K, typename V>
    using m = unordered_map<K, V>;

    template <typename T>
    using s = set<T>;

    m<int, int> parent;
    m<int, int> size;
    m<int, int> min, max;

    s<int> values;

    int find_set(int a) {
        if (!parent.contains(a)) {
            make_set(a);
            return a;
        }

        if (parent[a] == a)
            return a;

        return parent[a] = find_set(parent[a]);
    }

    void make_set(int a) {
        parent[a] = a;
        size[a] = 1;
        min[a] = a;
        max[a] = a;
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b]) {
                parent[a] = b;
                size[b] += size[a];
                max[b] = std::max(max[b], max[a]);
                min[b] = std::min(min[b], min[a]);
            } else {
                parent[b] = a;
                size[a] += size[b];
                max[a] = std::max(max[a], max[b]);
                min[a] = std::min(min[a], min[b]);
            }
        }
    }

    SummaryRanges() {

    }

    // find_set(value), find_set(value + 1), and find_set(value - 1)
    // union_sets on all valid sets
    void addNum(int value) {
        int a = find_set(value);
        if (values.contains(value + 1) && values.contains(value - 1)) {
            int b = find_set(value + 1);
            int c = find_set(value - 1);
            union_sets(a, b);
            union_sets(a, c);
        } else if (values.contains(value + 1)) {
            int b = find_set(value + 1);
            union_sets(a, b);
        } else if (values.contains(value - 1)) {
            int b = find_set(value - 1);
            union_sets(a, b);
        }
        values.insert(value);
    }

    // to implement efficiently, keep map[parent] -> lower bound, map[parent] -> upper bound
    // is it faster to keep a running result?
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;

        // values is already ordered, so result is sorted by the end
        s<int> visited;
        for (auto &value : values) {
            int p = find_set(value);
            if (!visited.contains(p)) {
                result.push_back({min[p], max[p]});
                visited.insert(p);
            }
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
