/**
* @author yinhou.liu
* @Date 2024/12/07 
*/

#include <bits/stdc++.h>

using namespace std;

// 198. 打家劫舍
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        if (size == 2) return max(nums[0], nums[1]);

        int dp[size + 1];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            // dp[i]表示走到当前房间获取最大金额
            // 如果盗取相邻房间就不能拿去当前房间的钱
            // 所以就是比相邻房间和前两个房间+现在房间钱之和，谁更大
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[size - 1];
    }
};

int main() {
    Solution solution;
    vector<int> inputTest = {2,7,9,3,1};
    int result = solution.rob(inputTest);
    cout << "result:" << result << endl;
    return 0;
}