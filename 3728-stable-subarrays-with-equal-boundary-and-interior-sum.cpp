#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    using ll = long long;

    template <typename T>
    using v = vector<T>;

    long long countStableSubarrays(vector<int>& capacity) {
        v<ll> prefix(capacity.size());
        prefix[0] = capacity[0];
        for (int i = 1; i < capacity.size(); ++i) {
            prefix[i] = prefix[i - 1] + capacity[i];
        }

        // given element value and required prefix sum, get count of indices matching
        map<ll, map<ll, int>> count;
        count[capacity[0]][prefix[0]]++;
        ll ans = 0;
        for (int r = 2, update_idx = 1; r < capacity.size(); ++r, ++update_idx) { // make sure length >= 3 with update_idx
            // require prefix[r - 1] - prefix[l] == a[r] and a[l] == a[r]
            // lookup (a[r], prefix[r - 1] - a[r])
            ans += count[capacity[r]][prefix[r - 1] - capacity[r]];
            count[capacity[update_idx]][prefix[update_idx]]++;
        }
        return ans;
    }
};
