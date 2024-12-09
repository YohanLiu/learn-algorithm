/**
* @author yinhou.liu
* @Date 2024/12/09
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        dp[0][0] = grid[0][0];

        // 只能向右或者向下，所以第一行和第一列的格子都是左边或者上面到达之和
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // 到达除了第一行第一列以外的格子的方式就是从上或者左边的格子来的
        // 所以总的路径和就是 到达左边格子和上面格子的路径和的最小值 + 当前格子的值
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> inputTest = {
        {1, 2},
        {1, 1}
    };
    int result = solution.minPathSum(inputTest);
    cout << "result:" << result << endl;
    return 0;
}