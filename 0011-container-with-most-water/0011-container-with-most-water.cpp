class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        if(n==0||n==1)return 0;
     int left=0;
     int right=n-1;
     int maxwater=0;

     while(left<=right){
      int water=min(height[left],height[right])*(right-left);
      maxwater=max(water,maxwater);
      if(height[left]<height[right]){
        left++;
      }else{
        right--;
      }
     }
     return maxwater;
    }
};