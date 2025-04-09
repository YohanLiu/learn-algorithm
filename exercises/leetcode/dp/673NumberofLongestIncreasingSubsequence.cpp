/**
* @author yohan
* @Date 2025/03/02 
*/

#include <bits/stdc++.h>

using namespace std;

// 673. 最长递增子序列的个数
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n + 1, 0);

        // 用一个数组记录到下标i的子序列的最长长度次数
        vector<int> num(n + 1, 0);
        int maxlen = 0;
        int res = 0;

        for (int i = 0; i < n; i++) {
            // 初始是1
            dp[i] = 1;
            num[i] = 1;
            // j下标从0到i把情况都枚举一遍
            for (int j = 0; j < i; j++) {

                // nums[j]比nums[i]小说明出现子序列，更新
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;

                        // 重置记录的次数，因为都是从下标j过来的序列
                        num[i] = num[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        num[i] += num[j];
                    }
                }
            }

            if (dp[i] > maxlen) {
                maxlen = dp[i];
                res = num[i];
            } else if (dp[i] == maxlen) {
                res += num[i];
            }

        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,4,3,5,4,7,2};
    int result = solution.findNumberOfLIS(nums);
    cout << "result:" << result << endl;
    return 0;
}