#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), [](const int& e1, const int& e2) {
            return e1 > e2;
        });
        long long total = 0;
        for (int i = 0; i < happiness.size(); ++i) {
            if (i == k || i >= happiness[i])
                break;
            total += (happiness[i] - i);
        }
        return total;
    }
};
