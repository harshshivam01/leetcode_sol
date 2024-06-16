class Solution {
public:
    int maxIndex(vector<vector<int>> &mat, int r, int col) {
        int maxE = -1;
        int index = -1;
        for(int i=0;i<r;i++) {
            if(mat[i][col] > maxE) {
                maxE = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int low = 0;
        int high = c - 1;
        int left, right;
        while(low <= high) {
            int mid = (low + high) / 2;
            // find the row of max element in col(mid)
            int maxRowIndex = maxIndex(mat, r, mid);

            if(mid - 1 >= 0) {
                left = mat[maxRowIndex][mid-1];
            } else left = -1;

            if(mid + 1 < c) {
                right = mat[maxRowIndex][mid+1];
            } else right = -1;

            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right) {
                return {maxRowIndex, mid};
            } else if(mat[maxRowIndex][mid] > left) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return {-1, -1};
    }
};
