class Solution {
public:
    int countPrimes(int N) {
        vector<bool>mask(N+1,1);
        mask[0]=0;
        mask[1]=0;
        for(int i=2;i<=sqrt(N);i++){
            if(mask[i]==1){
                for(int j=i*i;j<=N;j=j+i){
                    mask[j]=0;
                }
            }
            }
            int ans=0;
        for(int i=0;i<N;i++){
            if(mask[i]){
              ans++;  
            }
        }
        return ans;
    }
};