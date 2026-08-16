class Solution {
public:
    set<vector<int>> check;
    void csum(vector<int>& candidates,vector<vector<int>> &ans, vector<int> &combination,int idx, int target){
        if(target == 0){
            if(check.find(combination) == check.end()){
                ans.push_back(combination);
                check.insert(combination);
            }
            return;
        }
        if(target<0 || idx == candidates.size()){
            return;
        }

        combination.push_back(candidates[idx]);
        csum(candidates, ans, combination, idx+1, target-candidates[idx]);
        csum(candidates, ans, combination, idx, target-candidates[idx]);
        combination.pop_back();
        csum(candidates, ans, combination, idx+1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        csum(candidates, ans, combination, 0, target);
        return ans;
    }
};