class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rich = 0;
        for(int i=0; i<accounts.size(); i++){
            int check = 0;
            for(int j=0; j<accounts[i].size(); j++){
                check += accounts[i][j];
            }
            rich = max(rich, check);
        }
        return rich;
    }
};