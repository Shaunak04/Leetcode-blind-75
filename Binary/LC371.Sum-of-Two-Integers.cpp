/* Problem Statement
Given two integers a and b, return the sum of the two integers without using the operators + and -.
*/

class Solution 
{
public:
    int getSum(int a, int b)
    {
        while(b!=0)
        {
            unsigned int carry = a & b;
            a^=b;
            b = carry<<1;
        }
        return a;
    }
};

// Time Complexity: O(b)
// Space Complexity: O(1)