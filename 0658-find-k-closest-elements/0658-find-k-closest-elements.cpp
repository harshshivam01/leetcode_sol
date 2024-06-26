class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //   for(int i=0;i<arr.size();i++){
    //     pq.push({abs(arr[i]-x),arr[i]});
    //   } 

    // //   for(int i=k+1;i<arr.size();i++){
    // //     if(pq.top().second<abs(arr[i]-x)){
    // //         pq.pop();
    // //         pq.push({arr[i],arr[i]-x});
    // //     }
    // //   }
    //   vector<int>ans;
    //   int count=0;
    //   while(count<k){
    //     ans.push_back(pq.top().second);
    //     count++;
    //     pq.pop();
    //   }
    //     //  sort(ans.begin(), ans.end());
    //   return ans;
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<k;i++){
       pq.push({abs(arr[i]-x),arr[i]}); 
    }
    
    for(int j=k;j<arr.size();j++){
        pair<int,int>p;
        p=pq.top();
        if(p.first>abs(arr[j]-x)){
           pq.pop();
           pq.push({abs(arr[j]-x),arr[j]});
        }
    }
     vector<int>ans;
     while(!pq.empty()){
     ans.push_back(pq.top().second);
     pq.pop();
     } 
     sort(ans.begin(),ans.end());
     return ans;
    }
};