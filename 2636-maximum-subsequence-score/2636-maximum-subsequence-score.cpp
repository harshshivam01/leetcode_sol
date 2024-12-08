class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long sum=0;
        long long ans=0;
        vector<pair<int, int >>v;
        priority_queue<int,vector<int>,greater<int>>pq;
        int n =nums1.size();
        for(int i=0;i<n;i++){
            v.push_back({nums2[i],nums1[i]});

        }
        sort(v.begin(),v.end(),greater<>());

        int j=0;
        while(j<n){
            sum+=v[j].second;
            pq.push(v[j].second);
            if(pq.size()<k){
                j++;
            }else{
                ans=max(ans,sum*v[j].first);
                sum-=pq.top();
                pq.pop();
              
                j++;
            }
        }
        return ans ;

    }
};