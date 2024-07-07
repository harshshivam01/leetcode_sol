class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       
        int empty=numBottles;
         int count=0;
        if(numBottles<numExchange)return numBottles;
      while(empty>=numExchange){
        count+=numBottles;
          numBottles=empty/numExchange;
          empty=empty%numExchange;
        
      
        empty+=numBottles;
        
      }
      return count+numBottles; 
    }
};