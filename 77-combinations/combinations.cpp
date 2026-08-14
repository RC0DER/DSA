class Solution {
public:
    void check(int n, vector<vector<int>>& res,vector<int>& rows, int idx, int k){
        if(rows.size() == k){
            res.push_back(rows);
            return;
        }
        if(idx > n) return;
        // include element
        rows.push_back(idx);
        check(n, res, rows, idx+1, k);
        rows.pop_back(); // backtrack
        // exclude element
        check(n, res, rows, idx+1, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> rows;
        int idx = 1;
        check(n, res, rows, idx, k);
        return res;
    }
};