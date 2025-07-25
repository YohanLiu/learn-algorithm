/**
* @author yohan
* @Date 2024/12/07
*/

#include <bits/stdc++.h>

using namespace std;

// 70. 爬楼梯
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    int n = 5; // 你可以更改这个值来测试不同的输入
    int result = solution.climbStairs(n);
    cout << "Number of ways to climb " << n << " stairs: " << result << endl;
    return 0;
}