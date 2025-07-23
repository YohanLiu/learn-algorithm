/**
* @author yohan
* @Date 2025/04/18 
*/

#include <bits/stdc++.h>

using namespace std;

// 279. 完全平方数
class Solution {
public:
    int numSquares(int n) {
        // 表示组成和为 i 所需最少完全平方数
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;

        // 所有数字从小到大遍历一遍
        for (int i = 1; i <= n; i++) {
            // 遍历所有小于等于 i 的，大于 i 的肯定没法用
            // 只用完全平方数，所以 j*j
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

int main() {
    Solution solution;
    int n = 4; // 你可以更改这个值来测试不同的输入
    int result = solution.numSquares(12);
    cout << "result:" << result << endl;
    return 0;
}