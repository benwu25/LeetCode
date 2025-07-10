#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result = string("");
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i][i] == '0')
                result += "1";
            else
                result += "0";
        }
        return result;
    }
};
