class Solution {
public:
    void check(vector<int>& nums, vector<vector<int>>& res, vector<int>& rows, int i){
        if(i >= nums.size()){
            res.push_back(rows);
            return;
        }
        rows.push_back(nums[i]);
        check(nums,res,rows,i+1);
        rows.pop_back();
        check(nums,res,rows,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> rows;
        int idx = 0;
        check(nums,res,rows,idx);
        return res;
    }
};