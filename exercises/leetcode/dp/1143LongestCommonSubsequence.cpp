/**
* @author yohan
* @Date 2025/02/26 
*/

#include <bits/stdc++.h>

using namespace std;

// 1143. 最长公共子序列
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() == 0 || text2.size() == 0) {
            return 0;
        }

        // dp[i][j] 表示字符串 1 的前 i 个和字符串 2 前 j 个的最长子序列
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        if (text1.at(0) == text2.at(0)) {
            dp[0][0] = 1;
        }

        // 针对单个字符情况比较的处理
        for (int i = 1; i < text1.size(); i++) {
            if (text1.at(i) == text2.at(0)) {
                dp[i][0] = 1;
            } else {
                dp[i][0] = dp[i - 1][0];
            }
        }

        for (int i = 1; i < text2.size(); i++) {
            if (text2.at(i) == text1.at(0)) {
                dp[0][i] = 1;
            } else {
                dp[0][i] = dp[0][i - 1];
            }
        }

        for (int i = 1; i < text1.size(); i++) {
            for (int j = 1; j < text2.size(); j++) {
                if (text1.at(i) == text2.at(j)) {
                    // 字符串相等表示长度需要加 1
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // 不等表示字符串需要取前边的两种情况的最大值
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[text1.size() - 1][text2.size() - 1];
    }
};

int main() {
    Solution solution;
    int result = solution.longestCommonSubsequence("ace", "xyz");
    cout << "result:" << result << endl;
    return 0;
}