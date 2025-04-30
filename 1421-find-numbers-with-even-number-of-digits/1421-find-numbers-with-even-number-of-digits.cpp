class Solution {
public:
    int findNumbers(vector<int>& nums) {

        int counteven = 0;
        for (int i = 0; i < nums.size(); i++) {
                    int count = 1;
            int n = nums[i];
            while (n / 10) {
                count++;
                n = n / 10;
            }
            if(count%2==0){
                counteven++;
            }
        }
        return counteven++;
    }
};