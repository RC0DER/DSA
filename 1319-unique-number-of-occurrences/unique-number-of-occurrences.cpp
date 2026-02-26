class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        set<int> check;
        for(int i=0; i<arr.size(); i++){
            freq[arr[i]]++;
        }
        for(auto &it:freq){
            if(check.find(it.second) != check.end()) return false;
            check.insert(it.second);
        }
        return true;
    }
};