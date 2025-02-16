class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minvalue=prices[0];
        int maxprofit=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
           maxprofit=max(maxprofit,prices[i]-minvalue);
           minvalue=min(minvalue,prices[i]);
        }
        return maxprofit;
    }
};