#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    template <typename T>
    using v = vector<T>;

    template <typename K, typename V>
    using m = unordered_map<K, V>;

    m<int, int> parent;
    m<int, int> size;

    int max = 1;

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
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b]) {
                parent[a] = b;
                size[b] += size[a];
                max = std::max(max, size[b]);
            } else {
                parent[b] = a;
                size[a] += size[b];
                max = std::max(max, size[a]);
            }
        }
    }

    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        unordered_set<int> items(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            // lookup nums[i], nums[i] + 1, and nums[i] - 1 and union all if they exist
            int a = find_set(nums[i]);
            if (items.contains(nums[i] - 1) && items.contains(nums[i] + 1)) {
                int b = find_set(nums[i] - 1), c = find_set(nums[i] + 1);
                union_sets(a, b);
                union_sets(a, c);
            } else if (items.contains(nums[i] - 1)) {
                int b = find_set(nums[i] - 1);
                union_sets(a, b);
            } else if (items.contains(nums[i] + 1)) {
                int b = find_set(nums[i] + 1);
                union_sets(a, b);
            }
        }
        return max;
    }
};
