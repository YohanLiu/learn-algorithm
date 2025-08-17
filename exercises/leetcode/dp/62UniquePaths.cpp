/**
* @author yohan
* @Date 2024/12/08 
*/

#include <bits/stdc++.h>

using namespace std;

// 62. 不同路径
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        dp[0][0] = 1;

        // 只能向右或者向下，所以第一行和第一列的格子都是一种方式到达
        for (int i = 1; i < n; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            dp[i][0] = 1;
        }

        // 到达除了第一行第一列以外的格子的方式就是从上或者左边的格子来的
        // 所以总的路径方式就是 到达左边格子和上面格子的路径之和
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    Solution solution;
    int result = solution.uniquePaths(51, 9);
    cout << "result:" << result << endl;
    return 0;
}