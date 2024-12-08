/**
* @author yinhou.liu
* @Date 2024/12/07 
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int arrs[10005];
        memset(arrs, 0, sizeof(int) * 10005);
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            // 相同的值进行累加存储
            // 用下标表示nums[i] - 1 和 nums[i] + 1 的相邻关系,就是不能选取相邻的
            arrs[num] = arrs[num] + num;
        }

        int dp[10005];
        memset(dp, 0, sizeof(int) * 10005);
        dp[0] = arrs[0];
        dp[1] = max(arrs[0], arrs[1]);
        for (int i = 2; i < 10005; i++) {
            // 题目经过上方的处理，就跟198打家劫舍差不多，转换成了不能选取相邻的，来获取最大值之和
            dp[i] = max(dp[i - 1], dp[i - 2] + arrs[i]);
        }
        return dp[10004];
    }
};

int main() {
    Solution solution;
    vector<int> inputTest = {3,4,2};
    int result = solution.deleteAndEarn(inputTest);
    cout << "result:" << result << endl;
    return 0;
}