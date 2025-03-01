/**
* @author yohan
* @Date 2025/01/02
*/

#include <bits/stdc++.h>

using namespace std;

// 139. 单词拆分
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> wordDictSet;
        wordDictSet.insert(wordDict.begin(), wordDict.end());

        // 表示字符串 s 的前 i 个字符能否由字典里的字符串组成
        vector<bool>dp(s.size() + 1);
        dp[0] = true;

        // 将前 i 个字符组成的字符串根据下标 j 分为两部分，前部分 s1 和后部分 s2. 此步就是为了分割子字符串
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                // 如果不由 j 分割整个字符串在字典中，直接就是 true
                if (wordDictSet.find(s.substr(0, i)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }

                // 由 j 分割的 s1 和 s2 去判断是不是都能由字典组成
                // 前半部分是一路判断过来的，所以直接取 dp 中的值，后半部分要去字典中去判断
                // 这里需要思路注意下，dp[i]表示前 i 个字符串能否由字典表示，字符串截取[j,i-j]是从 j 号下标截取长度 i-j 长度字符
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    Solution solution;
    vector<string> wordDict = {"leet","code"};
    bool result = solution.wordBreak("leetcode", wordDict);
    cout << "result:" << result << endl;
    return 0;
}
