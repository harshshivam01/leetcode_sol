class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left =0;
        int right=0;
        int m=nums1.size()-1;
        int n =nums2.size()-1;
        vector<int>ans ;
        while(left<=m && right<=n){
            if(nums1[left]<=nums2[right]){
              ans.push_back(nums1[left]);
              left++;
            }
            else{
                ans.push_back(nums2[right]);
                right++;
            }
        }
        while(left<=m){
           ans.push_back(nums1[left]);
              left++;  
        }
        while(right<=n){
            ans.push_back(nums2[right]);
                right++;
        }
        
    
    int mid=0;
    int s=ans.size();

    if(s%2==0){
        int mi=s/2;
        double median=double((ans[mi]+ans[mi-1]))/2;
    
        return median;
    }else{
        int mi=s/2;
        double median= ans[mi];
        return median; 
    }
    }
};