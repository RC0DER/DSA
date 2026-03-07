class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s+s;
        int ans = INT_MAX;
        int diff1 = 0;
        int diff2 = 0;
        for(int i=0; i<ss.size(); i++){
            char alt1 = (i%2) ? '1': '0';
            char alt2 = (i%2) ? '0': '1';

            if(alt1 != ss[i]) diff2++;
            if(alt2 != ss[i]) diff1++;

            if(i >= n){
                char prev_alt1 = ((i-n)%2) ? '1': '0';
                char prev_alt2 = ((i-n)%2) ? '0': '1';

                if(ss[i-n] != prev_alt1) diff2--;
                if(ss[i-n] != prev_alt2) diff1--; 
            }
            if(i >= n-1){
                ans = min(ans, min(diff1, diff2));
            }
        }
        return ans;
    }
};