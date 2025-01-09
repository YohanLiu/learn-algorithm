/**
* @author yohan
* @Date 2025/01/07 
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // 针对某个字符串万一为空的情况做处理
        for (int i = 0; i <= word1.size(); ++i) {
            dp[i][0] = i;
        }

        for (int i = 0; i <= word2.size(); ++i) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                // 表示 word1 的前 i 个字符到 word2 的前 j 个字符所需要的操作步数
                // 是从 i 的前 1 位开始到 j 的所有，所以有如下的解释：
                // [i - 1][j]表示删
                // [i][j - 1]表示增
                // [i - 1][j - 1]表示改
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;

                // 当 当前位置两个字符相等，说明不用操作，直接复用前两个字符的步数就可以
                if (word1.at(i - 1) == word2.at(j - 1)) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};

int main() {
    Solution solution;
    int result = solution.minDistance("", "s");
    cout << "result:" << result << endl;
    return 0;
}