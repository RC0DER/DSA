class Solution {
public:
    bool isPal(string s){
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void getallpart(string s, vector<vector<string>> &ans, vector<string> &part ){
        if(s.size() == 0){
            ans.push_back(part);
            return;
        }

        for(int i=0; i<s.size(); i++){
            string p = s.substr(0, i+1);
            if(isPal(p)){
                part.push_back(p);
                getallpart(s.substr(i+1), ans, part);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        getallpart(s, ans, part);
        return ans;
    }
};