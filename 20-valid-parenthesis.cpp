#include <deque>
#include <string>
using namespace std;

class Solution {
public:
    bool matches(char a, char b) {
        if (a == '(' && b == ')' ||
            a == '[' && b == ']' ||
            a == '{' && b == '}') {
            return true;
        }
        return false;
    }

    bool is_open(char a) {
        return (a == '(' || a == '[' || a == '{');
    }

    bool isValid(string s) {
        deque<char> paren_stack;
        int next = 0;
        while (next < s.size()) {
            if (paren_stack.size() && matches(paren_stack.back(), s[next])) {
                paren_stack.pop_back();
                ++next;
            } else if (is_open(s[next])) {
                paren_stack.push_back(s[next]);
                ++next;
            } else {
                return false;
            }
        }
        return paren_stack.size() == 0;
    }
};
