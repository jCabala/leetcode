class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> own, notOwn;

        own.push_back(-prices[0]);
        notOwn.push_back(0);

        for (int i = 1; i < prices.size(); i++) {
            own.push_back(max(own[i-1], notOwn[i-1] - prices[i]));
            notOwn.push_back(max(notOwn[i-1], own[i-1] + prices[i]));
        }

        return notOwn[notOwn.size() - 1];
    }
};