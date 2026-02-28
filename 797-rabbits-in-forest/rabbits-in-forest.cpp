class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int,int> ans;
        for(int i=0; i<answers.size(); i++){
            ans[answers[i]]++;
        }
        for(auto &el : ans){
            int x = el.first;
            int f = el.second;
            int grpsize = x+1;
            int group = (f + grpsize-1)/grpsize;
            res += group*grpsize; 
        }
        return res;
    }
};