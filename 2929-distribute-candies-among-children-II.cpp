class Solution {
public:
    long long count_two(long long n, long long limit) {
        if (n == 0) {
            return 1;
        }
        if (n - n/2 > limit) {
            return 0;
        }
        if (limit < n) {
            return n - 2*(n - limit) + 1;
        }
        return n + 1;
    }

    long long distributeCandies(int n, int limit) {
        long long ways = 0;
        int min = (limit < n) ? limit : n;
        for (int i = 0; i <= min; ++i) {
            ways += count_two(static_cast<long long>(n - i), static_cast<long long>(limit));
        }
        return ways;
    }
};
