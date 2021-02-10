/*
Basic Calculator II
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
*/
class Solution {
public:
  int calculate(string s) {
    stack<int> myStack;
    char sign = '+';
    int res = 0;
    long tmp = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (isdigit(s[i]))
            tmp = 10*tmp + s[i]-'0';
        if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1) {
            if (sign == '-')
                myStack.push(-tmp);
            else if (sign == '+')
                myStack.push(tmp);
            else {
                int num;
                if (sign == '*' )
                    num = myStack.top()*tmp;
                else
                    num = myStack.top()/tmp;
                myStack.pop();
                myStack.push(num);
            } 
            sign = s[i];
            tmp = 0;
        }
    }
    while (!myStack.empty()) {
        res += myStack.top();
        myStack.pop();
    }
    return res;
  }
};