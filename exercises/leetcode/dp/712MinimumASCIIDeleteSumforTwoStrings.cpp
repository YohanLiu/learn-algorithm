/**
* @author yohan
* @Date 2025/01/08 
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        // 针对某个字符串万一为空的情况做处理
        for (int i = 1; i <= s1.size(); ++i) {
            dp[i][0] = dp[i - 1][0] + (int)s1.at(i - 1);
        }

        for (int i = 1; i <= s2.size(); ++i) {
            dp[0][i] = dp[0][i - 1] + (int)s2.at(i - 1);
        }

        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (s1.at(i - 1) != s2.at(j - 1)) {
                    // dp[i][j]表示从字符串 1 的 0 下标到 i，以及字符串 2 的 0 下标到 j 的删除后字符串相等所需的最小 ASCII 值之和
                    // 因为从小往后推演，所以dp[i - 1][j] + (int)s1.at(i - 1)意思是【i-1,j】最小和+删除新加字符(i-1)，另外同理
                    dp[i][j] = min(dp[i - 1][j] + (int)s1.at(i - 1), dp[i][j - 1] + (int)s2.at(j - 1));
                } else {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

int main() {
    Solution solution;
    int n = 4; // 你可以更改这个值来测试不同的输入
    int result = solution.minimumDeleteSum("sea", "eat");
    cout << "result:" << result << endl;
    return 0;
}