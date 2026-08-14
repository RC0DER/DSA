class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int res = 0;
        int start = 0;
        int end = 0;
        while(end < s.size()){
            freq[s[end]]++;
            while(freq[s[end]] > 2){
                res = max(res, end-start);
                freq[s[start]]--;
                start++;
            }
            end++;
        }
        res = max(res, end-start);
        return res;
    }
};