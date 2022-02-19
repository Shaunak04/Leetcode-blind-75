/* Problem Statement
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution 
{
public:
    int climbStairs(int n) // fibonacci starting from 1,2 
    {
        if(n==1 || n==2)
        {
            return n;
        }
        else
        {
            int temp, first=1,second=2;
            for(int i=2;i<n;i++)
            {
                temp = first + second;
                first = second;
                second = temp;
            }
            return second;
        }
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)