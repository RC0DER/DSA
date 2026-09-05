class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int first = 0,second = 0;
        // for (int i=0; i<nums.size()-1; i++){
        //     for (int j=i+1; j<nums.size(); j++){
        //         if (nums[i]+nums[j]==target){
        //             first = i;
        //             second = j;
        //             break;
        //         }
        //     }
        // }
        // return {first,second};
        unordered_map<int, int> check;  
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (check.find(complement) != check.end()) {
                return {check[complement], i};
            }
            check[nums[i]] = i;
        }
        return {};
        }
};