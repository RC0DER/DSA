class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res = 0;
        unordered_map<long long,long long> check;
        for(int i=0; i<nums.size(); i++){
            long long el = (long long)nums[i]-i;
            res += i-check[el];
            check[el]++;
        }
        return res;
    }
};