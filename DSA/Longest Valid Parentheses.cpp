#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        stack<int> stk;
        stk.push(-1);
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    max_len = max(max_len, i - stk.top());
                }
            }
        }
        
        return max_len;
    }
};

int main() {
    string s = "(()))())(";
    Solution sol;
    cout << "Longest Valid Parentheses: " << sol.longestValidParentheses(s) << endl;

    return 0;
}
