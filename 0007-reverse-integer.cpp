#include <limits.h>

class Solution {
public:
    int reverse(int x) {
        if (x == 0x80000000) {
            return 0;
        }
        int absVal = x;
        if (x < 0) {
            absVal = ~absVal + 0x1;
        }
        // what is the most significant place value
        int tVal = absVal;
        int place = 0;
        while (tVal/10 > 0) {
            tVal /= 10;
            place++;
        }
        // prepare to load digits
        int fact = 1;
        for (int i = 0; i < place; i++) {
            fact *= 10;
        }
        int finalVal = 0;
        char safe = 0;
        for (int i = 0; i <= place; i++) {
            if (place == 9 && safe == 0 && (((0x7FFFFFFF/fact) % 10) < (absVal%10))) {
                return 0;
            } else if (place == 9 && safe == 0 && (((0x7FFFFFFF/fact) % 10) > (absVal%10))) {
                safe = 1;
            }
            finalVal += fact*(absVal % 10);
            fact /= 10;
            absVal /= 10;
        }
        if (x < 0) {
            finalVal = ~finalVal + 0x1;
        }

        // outside of signed int range??
        return finalVal;
    }
};
