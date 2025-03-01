/**
* @author yinhou.liu
* @Date 2024/12/11
*/

#include <bits/stdc++.h>

using namespace std;

// 221. 最大正方形
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // 记录到 dp[i][j]的正方形边长
        vector<vector<int>> dp(301, vector<int>(301, 0));
        int row = matrix.size();
        int result = 0;

        for (int i = 0; i < row; i++) {
            int colSub = matrix[i].size();
            for (int j = 0; j < colSub; j++) {
                if (matrix[i][j] == '0') {
                    continue;
                }

                // 出现 1 就表示此方块独立是个小正方形
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                }

                result = max(dp[i][j], result);

                // 为了取下面的小正方形，做的边界校验
                if (i - 1 < 0 || i - 1 >= row) {
                    continue;
                }

                if (j - 1 < 0 || j - 1 >= colSub || j - 1 >= matrix[i - 1].size() || j >= matrix[i - 1].size()) {
                    continue;
                }

                // 大正方形一定是小正方形组成的，所以上边，左边，左上角一定要是小正方形
                int topLeftCorner = dp[i - 1][j - 1];
                int top = dp[i - 1][j];
                int left = dp[i][j - 1];
                if (topLeftCorner != 0 && top != 0 && left != 0) {
                    // 边长 + 1
                    // 边长要取最小的边长
                    dp[i][j] = min(topLeftCorner, min(top, left)) + 1;
                }
                result = max(dp[i][j], result);
            }
        }

        // 求面积
        return result * result;
    }
};

int main() {
    Solution solution;

    vector<vector<char>> inputTest = {{'1','1','1','1','0'},{'1','1','1','1','0'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'0','0','1','1','1'}};
    int result = solution.maximalSquare(inputTest);
    cout << "result:" << result << endl;
    return 0;
}