class Solution {
public:
    int count_two(int n, int limit) {
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

    int distributeCandies(int n, int limit) {
        int ways = 0;
        int min = (limit < n) ? limit : n;
        for (int i = 0; i <= min; ++i) {
            ways += count_two(n - i, limit);
        }
        return ways;
    }
};
