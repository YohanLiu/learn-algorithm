/**
* @author yohan
* @Date 2025/10/13 
*/
//
// 72 给你两个单词 word1 和 word2，请返回将 word1 转换成 word2 所使用的最少操作数。你可以对一个单词进行如下三种操作：
//     1、插入一个字符
//     2、删除一个字符
//     3、替换一个字符
// horse
// ros
// 示例1：
// 输入：word1 = "horse", word2 = "ros"
// 输出：3
// 解释：
//     horse -> rorse (将 'h' 替换为 'r')
//     rorse -> rose (删除 'r')
//     rose -> ros (删除 'e')
// 示例2：
// 输入：word1 = "intention", word2 = "execution"
// 输出：5
// 解释：
//     intention -> inention (删除 't')
//     inention -> enention (将 'i' 替换为 'e')
//     enention -> exention (将 'n' 替换为 'x')
//     exention -> exection (将 'n' 替换为 'c')
//     exection -> execution (插入 'u')


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // word1 前 i 个到 word2 前 j 个
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        if (word1.at(0) != word2.at(0)) {
            dp[0][0] = 1;
        }

        for (int i = 1; i < m; i++) {
            dp[0][i] = dp[0][i - 1] + 1;
            if (word1.at(0) == word2.at(i)) {
                dp[0][i] = min(dp[0][i], dp[0][i - 1]);
            }
        }

        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + 1;
            if (word1.at(i) == word2.at(0)) {
                dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;

                if (word1.at(i) == word2.at(j)) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main() {
    Solution solution;
    int n = 4; // 你可以更改这个值来测试不同的输入
    int result = solution.minDistance("intention", "execution");
    cout << "result:" << result << endl;
    return 0;
}