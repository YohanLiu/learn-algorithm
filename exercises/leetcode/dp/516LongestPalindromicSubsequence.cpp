/**
* @author yohan
* @Date 2025/01/04 
*/

#include <bits/stdc++.h>

using namespace std;

// 516. 最长回文子序列
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        auto length = s.length();
        if (length < 2) {
            return s.size();
        }

        // dp[i][j]表示子字符串 i-j 是否为回文串，初始为 0 表示不是。如果是则记录 i-j 的回文串的长度
        vector<vector<long>>dp(length + 5, vector<long>(length + 5, 0));

        // 每个单独的字符串都是回文串
        for (int i = 0; i < length; i++) {
            dp[i][i] = 1;
        }

        // 记录最长回文串长度
        long len = 1;

        // l 表示回文串的长度
        for (int l = 2; l <= length; l++) {
            for (int i = 0; i < length; i++) {
                //  i 和 j 分别是回文串的左侧下标和右侧下标
                int j = i + l - 1;

                if (j >= length) {
                    // 不可越界
                    continue;
                }

                if (s.at(i) != s.at(j)) {
                    if (i + 1 < length && j - 1 >= 0) {
                        // 因为是子序列，所以最长的判断，要算上单独去掉左侧或右侧字符后的字符串
                        dp[i][j] = max(dp[i + 1][j - 1], max(dp[i + 1][j], dp[i][j - 1]));
                    }
                } else {
                    if (l <= 3) {
                        // 如果首尾相等长度小于等于 3 的字符串一定是回文串
                        dp[i][j] = l;
                    } else {
                        if (i + 1 < length && j - 1 >= 0) {
                            // 回文串等于子串是回文串并且加上首尾的字符串，要是首尾相等的两个字符，所以长度+2
                            dp[i][j] = dp[i + 1][j - 1] + 2;
                        }
                    }
                }

                len = max(len, dp[i][j]);
            }
        }

        return len;
    }
};

int main() {
    Solution solution;
    vector<string> inputTest = {"s", "sas", "babad", "cbbd", "1aaaaa1","abcdefg", "bbbab", "cbbd"};
    //vector<string> inputTest = {"bbbab"};
    for (int k = 0; k < inputTest.size(); k++) {
        int result = solution.longestPalindromeSubseq(inputTest.at(k));
        cout << "result:" << result << endl;
    }
    return 0;
}