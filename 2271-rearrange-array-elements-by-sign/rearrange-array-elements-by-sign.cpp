class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int posIdx = 0;
        int negIdx = 1;
        int i=0;
        for(int x: nums){
            if(x>0){
                ans[posIdx] = x;
                posIdx += 2;
            }
            else {
                ans[negIdx] = x;
                negIdx += 2;
            }
        }
        return ans;
    }
};