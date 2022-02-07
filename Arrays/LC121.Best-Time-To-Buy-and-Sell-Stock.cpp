/*Problem-statement:
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int maxprofit = 0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<min_price) min_price = prices[i];
            else if(prices[i] - min_price > maxprofit)
            {
                maxprofit = prices[i] - min_price;
            }
        }
        return maxprofit;    
    }
};

//Time complexity: O(n)
//Space complexity: O(1)

