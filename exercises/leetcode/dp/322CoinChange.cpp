/**
* @author yohan
* @Date 2025/04/16 
*/

#include <bits/stdc++.h>

using namespace std;

// 322. 零钱兑换
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 硬币面额最小一块钱，所以最多也是 amount 个硬币
        // 边界值
        int max = amount + 1;

        // 表示组成 i 元所需最少硬币数
        vector<int> dp(max, max);

        //  0 元不用硬币
        dp[0] = 0;

        // 所有钱遍历一遍
        for (int i = 1; i < max; ++i) {

            // 遍历所有金额
            for (int j = 0; j < coins.size(); j++) {

                // 钱大于等于金额才醒
                if (i >= coins[j]) {

                    // 自最少硬币数和选择当前硬币+减去面值最小组成硬币数，二者比较取最小
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] >= max ? -1 : dp[amount];
    }
};

int main() {
    Solution solution;
    vector<int> inputTest = {1};
    int result = solution.coinChange(inputTest, 0);
    cout << "result:" << result << endl;
    return 0;
}