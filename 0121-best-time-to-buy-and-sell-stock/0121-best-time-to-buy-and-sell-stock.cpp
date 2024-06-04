class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0];
        int maxprofit=0;
    for(int i=1;i<prices.size();i++){
        int profit=0;
        if(prices[i]<min){
            min=prices[i];
        }
        else{
           profit=prices[i]-min;
          
        }
       
        maxprofit=max(maxprofit,profit);


    }
     return maxprofit;
    }
};