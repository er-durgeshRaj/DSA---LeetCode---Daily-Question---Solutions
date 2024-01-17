/*QUESTION
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 SOLUTION*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<int> f(1001, 0);
        int count = 1;

        for(int i = 1; i < arr.size(); i++){
            if(arr[i] != arr[i - 1]){
                if(f[count])
                    return 0;

                f[count] = 1;
                count = 1;
            }
            else{
                ++count;
            }
        }

        return !f[count];
    }
};
