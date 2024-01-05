// QUESTION
// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence
// .

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 1e5);
        
        for(int i = 0; i < n; i++){
            int p = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            
            if(p < n)
                dp[p] = min(dp[p], nums[i]);
        }
        
        for(int i = n - 1; i > -1; i--){
            if(dp[i] < 1e5)
                return i + 1;
        }
        
        return 0;
    }
};
