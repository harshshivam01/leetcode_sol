class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int maxprofit=0;
      int mini=prices[0];
      for(int i=0;i<prices.size()-1;i++){
        int profit=0;
        if(prices[i]<prices[i+1]){
            profit=prices[i+1]-prices[i];
            maxprofit+=profit;
        }
        else{
            mini=prices[i+1];
        }
      } 
      return maxprofit; 
    }
};