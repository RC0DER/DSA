class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        bool nonZero = false;
        for(int num:nums){
            totalXor ^= num;
            if(num != 0){
                nonZero = true;
            }
        }

        if(totalXor != 0) return nums.size();

        if(nonZero) return nums.size()-1;

        return 0;
    }
};