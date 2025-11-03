#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;

    template <typename T>
    using v = vector<T>;

    template <typename K, typename V>
    using m = unordered_map<K, V>;

    // segment tree counting how many times we have seen a given sum of values to the right
    v<ll> count_per_sum;

    void update(ll i, ll sum, ll l, ll r) {
        if (l == r) {
            count_per_sum[i]++;
        } else {
            ll mid = (l + r)/2;
            if (sum <= mid)
                update(2*i, sum, l, mid);
            else
                update(2*i + 1, sum, mid+1, r);
            count_per_sum[i] = count_per_sum[2*i] + count_per_sum[2*i + 1];
        }
    }

    int query_sum_range(ll i, ll ql, ll qr, ll l, ll r) {
        if (ql > qr)
            return 0;

        if (ql == l && qr == r)
            return count_per_sum[i];

        ll mid = (l + r)/2;
        return query_sum_range(2*i, ql, min(mid, qr), l, mid)
                + query_sum_range(2*i + 1, max(mid+1, ql), qr, mid+1, r);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // build suffix sum map into the counter segment tree for ranges of sums
        v<ll> suffix(nums.size());
        set<ll> ordered_suffix_sums;

        suffix[nums.size() - 1] = nums[nums.size() - 1];
        ordered_suffix_sums.insert(suffix[nums.size() - 1]);

        for (int i = nums.size() - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + nums[i];
            ordered_suffix_sums.insert(suffix[i]);
        }

        v<ll> ordered_suffix(ordered_suffix_sums.begin(), ordered_suffix_sums.end());

        count_per_sum = v<ll>(4*ordered_suffix.size());

        ll ans = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            // sum from i to end
            ll si = suffix[i];

            if (lower <= si && si <= upper)
                ++ans;

            // ans += count of sums we have seen to the right in the range [si - upper, si - lower]
            auto left = lower_bound(ordered_suffix.begin(), ordered_suffix.end(), si - upper);
            auto right = lower_bound(ordered_suffix.begin(), ordered_suffix.end(), si - lower);
            if (right == ordered_suffix.end() || *right != si - lower)
                --right;
            ll lidx = distance(ordered_suffix.begin(), left);
            ll ridx = distance(ordered_suffix.begin(), right);
            ans += query_sum_range(1, lidx, ridx, 0, ordered_suffix.size() - 1);

            // add si to the count_per_sum tree, but first map to a unique index
            auto rank = lower_bound(ordered_suffix.begin(), ordered_suffix.end(), si);
            ll idx = distance(ordered_suffix.begin(), rank);
            update(1, idx, 0, ordered_suffix.size() - 1);
        }
        return ans;
    }
};

    /*

        1 ... i ... n
        We have si = S(i, n) in logN time
        want to know how many indices j > i such that S(j+1, n) == si - lower through S(j+1, n) == si - upper,
            i.e., such that si - upper <= S(j+1, n) <= si - lower
            that is the number of range sums from right to end that we have seen in this range

        si = S(i, j) + S(j+1, n)

        space concerns: there are at most O(n^2) unique range sums (increasing powers of 2 for unique binary numbers)
        so you just need O(n) space, but it's hard to map each possible suffix sum to one of those places.
        what I will do is create an ordered set of all possible suffix sums. then, get the rank of a particular
        sum in logN time using set::find and std::distance, and use this to find its index into the segment tree
        which counts how many times we have seen a given sum

    */
