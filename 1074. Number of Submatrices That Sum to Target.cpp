// QUESTION
// Given a matrix and a target, return the number of non-empty submatrices that sum to target.

// A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

// Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

 

// Example 1:


// Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
// Output: 4
// Explanation: The four 1x1 submatrices that only contain 0.
// Example 2:

// Input: matrix = [[1,-1],[-1,1]], target = 0
// Output: 5
// Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
// Example 3:

// Input: matrix = [[904]], target = 0
// Output: 0
 

// Constraints:

// 1 <= matrix.length <= 100
// 1 <= matrix[0].length <= 100
// -1000 <= matrix[i] <= 1000
// -10^8 <= target <= 10^8
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> pre(n, vector<int> (m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                pre[i][j] = matrix[i][j];

                if(i > 0)
                    pre[i][j] += pre[i - 1][j];
                if(j > 0)
                    pre[i][j] += pre[i][j - 1];
                if(i > 0 and j > 0)
                    pre[i][j] -= pre[i - 1][j - 1];
            }
        }

        int ans = 0;

        for(int sx = 0; sx < n; sx++){
            for(int ex = sx; ex < n; ex++){
                for(int sy = 0; sy < m; sy++){
                    for(int ey = sy; ey < m; ey++){
                        int cur = pre[ex][ey];

                        if(sy > 0)
                            cur -= pre[ex][sy - 1];
                        if(sx > 0)
                            cur -= pre[sx - 1][ey];
                        if(sx > 0 and sy > 0)
                            cur += pre[sx - 1][sy - 1];

                        ans += cur == target;
                    }
                }
            }
        }

        return ans;
    }
};
