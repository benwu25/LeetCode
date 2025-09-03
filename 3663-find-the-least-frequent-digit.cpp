#include <vector>
#include <algorithm>
using namespace std;

int getLeastFrequentDigit(int n) {
    vector<int> count{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int tmp = n;
    while (tmp > 0) {
        int next = tmp % 10;
        ++count[next];
        tmp /= 10;
    }
    int min = std::distance(count.begin(), std::find_if(count.begin(), count.end(), [](const int& x) {
        return x > 0;
    }));
    for (int i = 0; i < 10; ++i) {
        if (count[i] < count[min] && count[i] != 0)
            min = i;
    }
    return min;
}
