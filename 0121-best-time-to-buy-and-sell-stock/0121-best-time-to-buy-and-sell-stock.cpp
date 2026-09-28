class Solution {
public:
    int maxProfit(vector<int>& pri) {
        int minprice=pri[0];
        int profit=0;
        for(int i=1;i<pri.size();i++)
        {
            minprice=min(minprice,pri[i]);
            profit=max(profit,(pri[i] - minprice ));
        }
        return profit;
    }
};