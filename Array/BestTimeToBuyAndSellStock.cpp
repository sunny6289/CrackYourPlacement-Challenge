class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1){
            return 0;
        }
        int maxProfit = 0;
        int buy = prices[0];
        for(int i=1;i<prices.size();i++){
            int sell = prices[i];
            int profitOnThisDay = sell-buy;
            maxProfit=max(profitOnThisDay, maxProfit);
            buy=min(buy, prices[i]);
        }

        return maxProfit;
    }
};