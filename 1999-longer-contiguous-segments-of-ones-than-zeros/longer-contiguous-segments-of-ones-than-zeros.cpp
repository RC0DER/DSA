class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();
        int max1 = 0;
        int max0 = 0;
        int i = 0;
        int j = 0;
        while(j<s.size()){
            if(s[i] == s[j]) j++;
            else{
                if(s[j] == '1') max0 = max(max0, j-i);
                else max1 = max(max1, j-i);
                i = j;
            }
        }
        if(s[n-1] == '1') max1 = max(max1, n-i);
        else max0 = max(max0, n-i);
        if(max1 > max0) return true;
        return false;
    }
};