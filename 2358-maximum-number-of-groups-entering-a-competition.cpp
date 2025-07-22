#include <vector>
using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int i = 1, sum_i = 1;
        while (grades.size()-sum_i > i) {
            ++i;
            sum_i += i;
        }
        return i;
    }
};

// sum i till n-sum(throuhg i) <= i, then i-1 + 1
// 1 11 111 1111 11

// 1 2 1000 1000

// min 1
// max N (not tight)

// 1  11  111  1111
// 1 + 2 + 3 + 4 + 5 + 6 = N(N+1)/2

// 1 35 555 69(10)(10)(11)(12)
// 13 555 569(10)
