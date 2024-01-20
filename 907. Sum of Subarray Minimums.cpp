// QUESTION
// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.
// Example 2:

// Input: arr = [11,81,94,43,3]
// Output: 444
 

// Constraints:

// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> order(n);
        long long ans = 0;
        const long long mod = 1e9 + 7;

        for(int i = 0; i < n; i++)
            order[i] = {arr[i], i};

        sort(order.begin(), order.end());

        function<void(int, int, int)> helper = [&](int low, int high, int pos) {
            int nextp = order[pos].second;

            while(nextp < low or nextp > high){
                nextp = order[++pos].second;
            }

            long long left = nextp - low + 1;
            long long right = high - nextp + 1;

            ans = (ans + (left * right * arr[nextp]) % mod) % mod;

            if(nextp > low)
                helper(low, nextp - 1, pos + 1);
            if(nextp < high)
                helper(nextp + 1, high, pos + 1);
        };

        helper(0, n - 1, 0);

        return ans;
    }
};
