/**
* @author yohan
* @Date 2025/09/02 
*/

#include <bits/stdc++.h>

using namespace std;

// 714. 买卖股票的最佳时机含手续费
class Solution {
public:
    // 309变化下，有手续费以及没冷冻期
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 1) {
            return 0;
        }

        // dp[i][0], 第i天【持有股票】所得的最大利润;dp[i][1], 第i天【不持有股票】所得的最大利润
        vector<vector<int> > dp(n + 1, vector<int>(3, 0));
        // 边界条件
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        // 第二天买股票和第一天买股票的最大值
        dp[1][0] = max(dp[0][0],-prices[1]);

        // 当天卖股票和不作操作的最大值,两天的话，买股票前一天肯定买了，不操作就是 0 元，就是比较一买一卖和不操作哪个最大
        dp[1][1] = max(dp[0][0] + prices[1] - fee,dp[0][1]);

        for (int i = 2; i <= n - 1; i++) {
            // 第i天想持有股票必须是i-1 不持有 + 当天持有，或者前一天持有，二者取最大
            dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);

            // 第 i 天不持有股票可以是i-1 买了，i 天卖；或者 i-1 天卖了股票
            dp[i][1] = max(dp[i - 1][0] + prices[i] - fee, dp[i - 1][1]);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

int main() {
    Solution solution;
    int n = 4; // 你可以更改这个值来测试不同的输入
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> inputTest = {{10,-98,44},{-20,65,34},{-100,-1,74}};
    int result = solution.maxProfit(nums, 2);
    cout << "result:" << result << endl;
    return 0;
}