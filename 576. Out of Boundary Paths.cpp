// QUESTION
// There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

// Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

 

// Example 1:


// Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
// Output: 6
// Example 2:


// Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
// Output: 12
 

// Constraints:

// 1 <= m, n <= 50
// 0 <= maxMove <= 50
// 0 <= startRow < m
// 0 <= startColumn < n
// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
public:
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        long long dp[n][m][maxMove + 1];
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        const int mod = 1e9 + 7;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                dp[i][j][0] = 0;
        }

        auto inside = [&](int x, int y) -> bool {   
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
            
            return 1;
        };

        for(int k = 1; k < maxMove + 1; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    dp[i][j][k] = 0;

                    for(int d = 0; d < 4; d++){
                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if(inside(nx, ny)){
                            dp[i][j][k] = (dp[i][j][k] + dp[nx][ny][k - 1]) % mod;
                        }
                        else{
                            dp[i][j][k] = (dp[i][j][k] + 1) % mod;
                        }
                    }
                }
            }
        }

        return dp[startRow][startColumn][maxMove];
    }
};
