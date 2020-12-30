/*Best Time to Buy and Sell Stock
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Not 7-1 = 6, as selling price needs to be larger than buying price.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=INT_MAX,max_profit=0;
        for(int i=0;i<prices.size();i++){
            min_price=min(prices[i],min_price);
            max_profit=max(max_profit,prices[i]-min_price);
        }
        return max_profit;
    }
};
