class Solution {
public:
    int rev(int digit){
        int res = 0;
        while(digit > 0){
            res = res*10 + (digit%10);
            digit /= 10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        long long res = 0;
        int mod = 1e9 + 7;
        unordered_map<int,long long> check;
        for(int i=0; i<nums.size(); i++){
            if(check.find(nums[i]-rev(nums[i])) != check.end()){
                res += check[nums[i]-rev(nums[i])];
            }
            check[nums[i]-rev(nums[i])]++;
        }
        return res % mod;
    }
};