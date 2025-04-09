/**
* @author yinhou.liu
* @Date 2024/12/07 
*/

#include <bits/stdc++.h>

using namespace std;

// 746. 使用最小花费爬楼梯
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if (size <= 2) return min(cost[0], cost[1]);

        int dp[size + 1];

        // dp下标表示走到这个下标花费的最少费用
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= size; i++) {
            // 计算到当前台阶所需费用
            // 当前台阶是从前一个或者前两个台阶过来的
            // 所以费用是【到前一或二台阶的费用】 + 【前一或二台阶跨步所需费用】的最小值
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[size];
    }
};

int main() {
    Solution solution;
    vector<int> inputTest = {1,100,1,1,1,100,1,1,100,1};
    int result = solution.minCostClimbingStairs(inputTest);
    cout << "result:" << result << endl;
    return 0;
}