/**
* @author yinhou.liu
* @Date 2024/12/10
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<long>> dp(n + 1, vector<long>(n + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 上一行的正上方
                int top = dp[i - 1][j];
                // 上一行的左斜角
                int left = j - 1 < 0 ? INT_MAX : dp[i - 1][j - 1];
                // 上一行的右斜角
                int right = j + 1 >= n ? INT_MAX : dp[i - 1][j + 1];
                dp[i][j] = min(top, min(left, right)) + matrix[i][j];
            }
        }

        long res = dp[n - 1][0];
        for (int i = 0; i < n; i++) {
            res = min(res, dp[n - 1][i]);
        }

        return res;
    }
};

int main() {
    Solution solution;

    // {{2,1,3},{6,5,4},{7,8,9}}
    vector<vector<int>> inputTest = {{10,-98,44},{-20,65,34},{-100,-1,74}};
    int result = solution.minFallingPathSum(inputTest);
    cout << "result:" << result << endl;
    return 0;
}