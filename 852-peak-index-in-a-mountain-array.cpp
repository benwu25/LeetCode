#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 0, hi = arr.size()-1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (lo == hi) {
                return lo;
            } else if (lo+1 == hi && arr[lo] < arr[hi]) {
                return hi;
            } else if (lo+1 == hi && arr[lo] > arr[hi]) {
                return lo;
            }
            if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
                return mid;
            } else if (arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1]) {
                lo = mid+1;
            } else if (arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1]) {
                hi = mid-1;
            }
        }
        return -1;
    }
};
