#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto &c : nums)
            count[c]++;

        vector<int> result;
        for (auto &[letter, cnt] : count)
            if (cnt > nums.size() / 3)
                result.push_back(letter);

        return result;
    }
};

/*

    most straightforward, count the characters and iterate the map.

    as for O(n) time and O(1), space, have to be more clever.
    observation: you can have at most 2 characters in result

*/
