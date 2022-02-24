/* Problem statement:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> stack;
        for (auto c : s) 
        {
            switch (c) 
            {
                case '(': stack.push(')'); continue;
                case '{': stack.push('}'); continue;
                case '[': stack.push(']'); continue;
            }

            if (!stack.empty() && (stack.top() == c))
                stack.pop();
            else
                return false;
        }

        if (!stack.empty()) return false;

        return true;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)