class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> check;
        int currsum = 0;
        int res =0;
        for(int el:nums){
            currsum += el;
            if(currsum == k) res++;
            if(check.find(currsum-k) != check.end()){
                res += check[currsum-k];
            }
            check[currsum]++;
        }
        return res;
    }
};