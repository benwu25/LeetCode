#include <vector>
using namespace std;

class NumArray {
public:
    template <typename T>
    using v = vector<T>;

    int size;
    v<int> sum_tree;

    void build(v<int> &nums, int i, int l, int r) {
        if (l == r) {
            sum_tree[i] = nums[l];
        } else {
            int mid = (l + r)/2;
            build(nums, 2*i, l, mid);
            build(nums, 2*i + 1, mid+1, r);
            sum_tree[i] = sum_tree[2*i] + sum_tree[2*i + 1];
        }
    }

    void assign(int i, int idx, int val, int l, int r) {
        if (l == r) {
            if (l == idx)
                sum_tree[i] = val;
        } else {
            int mid = (l + r)/2;
            if (idx <= mid)
                assign(2*i, idx, val, l, mid);
            else
                assign(2*i + 1, idx, val, mid+1, r);
            sum_tree[i] = sum_tree[2*i] + sum_tree[2*i + 1];
        }
    }

    int find_sum(int i, int ql, int qr, int l, int r) {
        if (ql > qr)
            return 0;

        if (ql == l && qr == r)
            return sum_tree[i];

        int mid = (l + r)/2;
        int lsum = find_sum(2*i, ql, min(mid, qr), l, mid);
        int rsum = find_sum(2*i + 1, max(mid+1, ql), qr, mid+1, r);
        return lsum + rsum;
    }

    NumArray(vector<int>& nums) : sum_tree(v<int>(4*nums.size())), size(nums.size()) {
        build(nums, 1, 0, size - 1);
    }

    void update(int index, int val) {
        assign(1, index, val, 0, size - 1);
    }

    int sumRange(int left, int right) {
        return find_sum(1, left, right, 0, size - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
