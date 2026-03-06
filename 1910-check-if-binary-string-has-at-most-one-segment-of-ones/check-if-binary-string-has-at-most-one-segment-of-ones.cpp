class Solution {
public:
    bool checkOnesSegment(string s) {
        bool check = true;
        for(int i=1; i<s.size(); i++){
            if(s[i] == '0') check = false;
            else if(s[i] == '1' && check == false) return false;
        }
        return true;
    }
};