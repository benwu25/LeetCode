class Solution {
public:
    bool is_set(int k) {
        while (k) {
            int bit = k % 2;
            if (!bit)
                return false;
            k /= 2;
        }
        return true;
    }

    int smallestNumber(int n) {
        int next = n;
        while (1) {
            if (is_set(next))
                return next;
            ++next;
        }
        return 0;
    }
};
