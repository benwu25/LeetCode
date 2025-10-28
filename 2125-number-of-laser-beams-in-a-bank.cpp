#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int count(string &row) {
        int ones = 0;
        for (auto &x : row)
            if (x == '1')
                ++ones;
        return ones;
    }

    int numberOfBeams(vector<string>& bank) {
        int lasers = 0;
        int ones = count(bank[0]);
        for (int i = 1; i < bank.size(); ++i) {
            int next_ones = count(bank[i]);
            if (next_ones > 0) {
                lasers += ones * next_ones;
                ones = next_ones;
            }
        }
        return lasers;
    }
};
