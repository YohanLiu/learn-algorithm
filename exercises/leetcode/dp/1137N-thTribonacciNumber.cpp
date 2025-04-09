/**
* @author yinhou.liu
* @Date 2024/12/07 
*/

#include <bits/stdc++.h>

using namespace std;

// 1137. 第 N 个泰波那契数
class Solution {
public:
    int tribonacci(int n) {
        int dp[n + 5];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        if (n <= 2) return dp[n];

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    vector<int> inputTest = {0, 1, 2, 3, 4, 25};
    for (int i = 0; i < inputTest.size(); i++) {
        int n = inputTest.at(i);
        int result = solution.tribonacci(n);
        cout << "n = " << n << ",result:" << result << endl;
    }
    return 0;
}