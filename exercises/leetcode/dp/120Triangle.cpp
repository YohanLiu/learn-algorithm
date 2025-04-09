/**
* @author yinhou.liu
* @Date 2024/12/10
*/

#include <bits/stdc++.h>

using namespace std;

// 120. 三角形最小路径和
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row - 1].size();
        vector<vector<long>> dp(row + 1, vector<long>(col + 1, 0));
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < row; i++) {
            int colSub = triangle[i].size();
            for (int j = 0; j < colSub; j++) {
                // 从上一行的【下标-1】来
                long left = j - 1 < 0 ? LONG_MAX : dp[i - 1][j - 1];
                // 从上一行的下标相等的来
                long right = j >= triangle[i - 1].size() ? LONG_MAX : dp[i - 1][j];
                dp[i][j] = min(left, right) + triangle[i][j];
            }
        }

        long res = dp[row - 1][0];
        for (int i = 0; i < col; i++) {
            res = min(res, dp[row - 1][i]);
        }
        return res;
    }
};

int main() {
    Solution solution;

    // {{2},{3,4},{6,5,7},{4,1,8,3}}
    vector<vector<int>> inputTest = {{-10}};
    int result = solution.minimumTotal(inputTest);
    cout << "result:" << result << endl;
    return 0;
}