// QUESTION
// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

// Example 1:

// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]
 

// Constraints:

// 10 <= low <= high <= 10^9
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for(int start = 1; start < 10; start++){
            int cur = start + 1;
            int val = start;

            if(val >= low and val <= high)
                ans.push_back(val);

            for(; cur < 10; cur++){
                val *= 10;
                val += cur;


                if(val >= low and val <= high)
                    ans.push_back(val);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
