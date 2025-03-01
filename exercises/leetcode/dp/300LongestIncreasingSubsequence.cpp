/**
* @author yohan
* @Date 2025/03/01 
*/

#include <bits/stdc++.h>

using namespace std;

//300. 最长递增子序列
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // 从0到下标为i的最长递增子序列
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            // 初始是1
            dp[i] = 1;

            // j下标从0到i把情况都枚举一遍
            for (int j = 0; j < i; j++) {

                // nums[j]比nums[i]小说明出现子序列，更新
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution solution;
    vector<int> nums = {7,7,7,7,7,7,7};
    int result = solution.lengthOfLIS(nums);
    cout << "result:" << result << endl;
    return 0;
}