class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,long long> freq;
        long long res = 0;
        int right = 0; 
        int left = 0;
        int pairs = 0;
        while(right < nums.size()){
            pairs += freq[nums[right]];
            freq[nums[right]]++;

            while(pairs >= k){
                res += nums.size() - right;
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
            right++;
        }
        return res;
    }
};