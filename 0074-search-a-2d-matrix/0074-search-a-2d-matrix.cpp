class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix[0].size();
        int c=matrix.size();
        int cap=r*c;
        int low=0;int high=cap-1;
        while(low<=high){
            int mid=(low+high)>>1;
            int midval=matrix[mid/r][mid%r];
            if(midval==target)return true;
            else if(midval<target)low=mid+1;
            else high=mid-1;

        }
        return false;
    }
};