// QUESTION
// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.
// Example 2:

// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 2 * 109
// All the integers in nums are unique.
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
public:
    
    void generate(int idx, vector<int>& nums, vector<int>& result, vector<int>& temp, int prev) {
        if(idx >= nums.size()) {
            if(temp.size() > result.size()) {
                result = temp;
            }
            return;
        }
        
        if(prev == -1 || nums[idx] % prev == 0) {
            temp.push_back(nums[idx]);
            generate(idx+1, nums, result, temp, nums[idx]);
            temp.pop_back();
        }
        
        generate(idx+1, nums, result, temp, prev);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        
        vector<int> result;
        vector<int> temp;
        generate(0, nums, result, temp, -1);
        
        return result;
    }
};
