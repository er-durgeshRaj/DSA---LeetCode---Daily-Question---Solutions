// QUESTION
// You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

// Return the maximum possible length of s.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All the valid concatenations are:
// - ""
// - "un"
// - "iq"
// - "ue"
// - "uniq" ("un" + "iq")
// - "ique" ("iq" + "ue")
// Maximum length is 4.
// Example 2:

// Input: arr = ["cha","r","act","ers"]
// Output: 6
// Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
// Example 3:

// Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
// Output: 26
// Explanation: The only string in arr has all 26 characters.
 

// Constraints:

// 1 <= arr.length <= 16
// 1 <= arr[i].length <= 26
// arr[i] contains only lowercase English letters.
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        int n = arr.size();

        for(int i = 0; i < (1 << n); i++){
            int cur_ans = 0;
            vector<int> f(26, 0);

            for(int j = 0; j < n; j++){
                if((i >> j) & 1){
                    cur_ans += arr[j].size();

                    for(auto x : arr[j])
                        ++f[x - 'a'];
                }
            }

            bool ok = 1;
            for(auto x : f){
                if(x > 1){
                    ok = 0;
                    break;
                }
            }

            if(ok)
                ans = max(ans, cur_ans);
        }

        return ans;
    }
};
