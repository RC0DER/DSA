class Solution {
public:
    int minDeletion(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int res = 0;
        for(int i=0; i<nums.size()-1; i++){
            if((i-res)%2 == 0 && nums[i] == nums[i+1]){
                res++;
            }
        }
        if((nums.size()-res)%2 != 0){
            res++;
        }
        return res;
    }
};