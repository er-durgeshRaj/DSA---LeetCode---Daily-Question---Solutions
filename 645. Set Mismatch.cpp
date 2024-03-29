/*QUESTION
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
 

Constraints:

2 <= nums.length <= 104
1 <= nums[i] <= 104
///////////////////////////////////////////////////////////////////////////////////////////////////
SOLUTION*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup=-1,missing=1;
        vector<int>result;

        // find the duplicate.
        for(auto x:nums){
            // duplicate.
            if(nums[abs(x)-1]<0){
                dup =abs(x);
            }else{
                nums[abs(x)-1] *=-1;
            }

        }
        result.push_back(dup);

        // find the missing..
        for(int i=1;i<nums.size();i++){

            if(nums[i]>0){
                 // missing.
                missing = i+1;
            }

        }
        result.push_back(missing);
        return result;
    }
};
