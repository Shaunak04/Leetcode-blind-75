/* Problem statement: Given a stack, sort it using an additional temporary stack */

class Solution
{
    public:
    stack<int> sortStack(stack<int>& st)
    {
        stack<int> temp;
        while(!st.empty())
        {
            int inputTop = st.top();
            st.pop();

            while(!temp.empty() && temp.top() > inputTop)
            {
                st.push(temp.top());
                temp.pop();
            }
            temp.push(inputTop);
        }
        return temp;
    }
}


// Time Complexity: O(n)
// Space Complexity: O(n)