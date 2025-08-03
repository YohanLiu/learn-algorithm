/**
* @author yohan
* @Date 2025/07/26 
*/

#include <bits/stdc++.h>

using namespace std;


// 1027 最长等差数列
class Solution {
public:
    // dp[i][d]代表以nums[i]结尾，公差为d的最长子序列
    // dp[i][d]=max【dp[i][d],(dp[j][d])+1】,where nums[i]-nums[j]=d
    // d:-500~500,共1001个，添加偏移量500保证非负
    int longestArithSeqLength(vector<int>& nums) {
        int size = nums.size();
        int result = 0;
        vector<vector<int>> dp(size + 1, vector<int>(1001, 1));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                // 添加偏移量500保证非负
                int d = nums[i] - nums[j] + 500;
                dp[i][d] = max(dp[i][d], dp[j][d] + 1);
                result = max(result, dp[i][d]);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    int n = 4; // 你可以更改这个值来测试不同的输入
    vector<int> nums = {20,1,15,3,10,5,8};
    int result = solution.longestArithSeqLength(nums);
    cout << "result:" << result << endl;
    return 0;
}