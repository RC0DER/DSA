class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = 0;
        vector<bool> arr(candies.size());
        for(int i =0; i<candies.size();i++)
        {
            if(candies[i]>maxi) maxi= max(candies[i],maxi);
        }
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies >= maxi) arr[i]=true;
            else arr[i] = false;
        }
        return arr;
    }
};