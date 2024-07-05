class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      
        int j=0;
        int n=cardPoints.size();
          long long maxsum=INT_MIN;
        long long totalsum=accumulate(cardPoints.begin(), cardPoints.end(),0);
        if(k==n)return totalsum;
        long long currsum=0;
        while(j<(n-k)){
          currsum+= cardPoints[j];
          j++;
        }
        maxsum=max(maxsum,totalsum-currsum);
       
            for(int i=(n-k);i<n;i++){
               currsum+=cardPoints[i]-cardPoints[i-(n-k)];
                maxsum=max(totalsum-currsum,maxsum);
            }
           
        
      
return maxsum;
    }
};