/**
* @author yohan
* @Date 2024/12/11 
*/

#include <bits/stdc++.h>

using namespace std;

// 5. 最长回文子串
class Solution {
public:
    string longestPalindrome(string s) {
        auto length = s.length();
        if (length < 2) {
            return s;
        }

        // dp[i][j]表示子字符串 i-j 是否为回文串
        vector<vector<long>>dp(length + 5, vector<long>(length + 5, 0));

        // 每个单独的字符串都是回文串
        for (int i = 0; i < length; i++) {
            dp[i][i] = 1;
        }

        // 最长的回文串的长度及开始下标
        long len = 1;
        long startIndex = 0;

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
                    dp[i][j] = 0;
                } else {
                    if (l <= 3) {
                        // 如果首尾相等长度小于等于 3 的字符串一定是回文串
                        dp[i][j] = 1;
                    } else {
                        if (i + 1 < length && j - 1 >= 0) {
                            // 回文串等于子串是回文串并且加上首尾的字符串，要是首尾相等的两个字符
                            dp[i][j] = dp[i + 1][j - 1];
                        }
                    }
                }

                // 记录最大回文串长度及启示下标
                if (dp[i][j] == 1 && len < j - i + 1) {
                    len = j - i + 1;
                    startIndex = i;
                }
            }
        }

        // 字符串截取
        return s.substr(startIndex, len);
    }
};

int main() {
    Solution solution;
    vector<string> inputTest = {"s", "ss", "babad", "cbbd", "1aaaaa1","abcdefg"};
    for (int k = 0; k < inputTest.size(); k++) {
        string result = solution.longestPalindrome(inputTest.at(k));
        cout << "result:" << result << endl;
    }
    return 0;
}