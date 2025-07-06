class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int *ways = new int[n+1];
        ways[n] = 1, ways[n-1] = 1;
        for (int i = n-2; i >= 0; --i) {
            ways[i] = ways[i+1] + ways[i+2];
        }
        int res = ways[0];
        delete[] ways;
        return res;
    }
};

/*
ways to climb from stair i
base case: ways[top] = 1, ways[top-1] = 1
ways[i] = ways[i+1] + ways[i+2]
*/
