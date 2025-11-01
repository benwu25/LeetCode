#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    template <typename T>
    using v = vector<T>;

    // count_tree acts as a simple count map for the elements in nums.
    // we can increment values in the map in logN time, and we can sum
    // together a range of values in the map in logN time, where N = max(nums)
    // after shifting everything nonnegative
    v<int> count_tree;

    // increment entry in the map for given val
    void update(int i, int val, int l, int r) {
        if (l == r) {
            count_tree[i]++;
        } else {
            int mid = (l + r)/2;
            if (val <= mid) {
                update(2*i, val, l, mid);
            } else {
                update(2*i + 1, val, mid+1, r);
            }
            count_tree[i] = count_tree[2*i] + count_tree[2*i + 1];
        }
    }

    // get sum of values in map between ql and qr
    int query(int i, int ql, int qr, int l, int r) {
        if (ql > qr)
            return 0;

        if (ql == l && qr == r) {
            return count_tree[i];
        }

        int mid = (l + r)/2;
        int lsum = query(2*i, ql, min(mid, qr), l, mid);
        int rsum = query(2*i + 1, max(mid+1, ql), qr, mid+1, r);
        return lsum + rsum;
    }

    vector<int> countSmaller(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end()), abs_min = abs(min);
        if (min < 0) {
            for_each(nums.begin(), nums.end(), [&](int &elem) {
                elem += abs_min;
            });
        }
        int max = *max_element(nums.begin(), nums.end());

        count_tree = v<int>(4*(max + 1));

        v<int> counts(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            // add nums[i] to the tree
            update(1, nums[i], 0, max);
            // query for sum of values less than nums[i]
            counts[i] = query(1, 0, nums[i] - 1, 0, max);
        }
        return counts;
    }
};
