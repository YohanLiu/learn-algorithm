/**
* @author yohan
* @Date 2025/04/17 
*/

#include <bits/stdc++.h>

using namespace std;

// 518. 零钱兑换II
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 先用 0 和 1 判断下是否有答案，防止计算过程超过 int 类型最大值
        vector<int> vaild(amount + 1, 0);
        vaild[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (vaild[j] + vaild[j - coins[i]] == 1) {
                    vaild[j] = 1;
                }
            }
        }

        if (vaild[amount] == 0) {
            return 0;
        }


        // 边界值 0，怎么都无法组成
        // 表示组成 i 元最多有几种组合方式
        vector<int> dp(amount + 1, 0);
        // 0 元只有一种组合
        dp[0] = 1;

        // 遍历所有钱，用前 i 个钱依次去组成总金额
        for (int i = 0; i < coins.size(); i++) {

            // 大于等于当前钱才能用上此面额
            for (int j = coins[i]; j <= amount; j++) {

                // 之前没用此面额的组合数+用上此面额的组合数
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};

int main() {
    Solution solution;
    vector<int> inputTest = {1,2,5};
    int result = solution.change(5, inputTest);
    cout << "result:" << result << endl;
    return 0;
}