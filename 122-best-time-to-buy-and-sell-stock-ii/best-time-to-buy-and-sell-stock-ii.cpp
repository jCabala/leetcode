class Solution {
public:
    int dpHold[30001], dpNo[30001];
    int maxProfit(vector<int>& prices) {
        dpHold[0] = -prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            dpHold[i] = max(dpHold[i-1], dpNo[i-1] - prices[i]);
            dpNo[i] = max(dpNo[i-1], dpHold[i-1] + prices[i]);
        }

        return dpNo[prices.size() - 1];
    }
};