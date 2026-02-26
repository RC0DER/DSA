class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> zero_loss;
        vector<int> one_loss;
        unordered_map<int, int> loss;
        for(int i=0; i<matches.size(); i++){
            if(loss.find(matches[i][0]) == loss.end()){
                loss[matches[i][0]] = 0;
            }
            loss[matches[i][1]]++;
        }
        for(auto &el: loss){
            if(el.second == 0){
                zero_loss.push_back(el.first);
            }
            if(el.second == 1){
                one_loss.push_back(el.first);
            }
        }
        sort(zero_loss.begin(), zero_loss.end());
        sort(one_loss.begin(), one_loss.end());
        return {zero_loss, one_loss};
    }
};