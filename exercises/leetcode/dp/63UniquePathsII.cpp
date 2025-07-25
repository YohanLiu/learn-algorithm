/**
* @author yohan
* @Date 2024/12/09
*/

#include <bits/stdc++.h>

using namespace std;

// 63. 不同路径 II
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;

        // 只能向右或者向下，所以第一行和第一列的格子都是一种方式到达
        // 如果有石头，那石头及右边或下面的都无法到达
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 1) {
                dp[0][i] = 0;
                continue;
            }
            dp[0][i] = dp[0][i - 1];
        }

        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
                continue;
            }
            dp[i][0] = dp[i - 1][0];
        }

        // 到达除了第一行第一列以外的格子的方式就是从上或者左边的格子来的
        // 所以总的路径方式就是 到达左边格子和上面格子的路径之和
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // 特殊情况，遇到石头的格子，等于重置了路径的次数，所以到石头的格子路线数量是 0
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution solution;

    // {{0,1},{0,0}}，{{0,0,0},{0,1,0},{0,0,0}}
    vector<vector<int>> inputTest = {{0},{1}};
    int result = solution.uniquePathsWithObstacles(inputTest);
    cout << "result:" << result << endl;
    return 0;
}