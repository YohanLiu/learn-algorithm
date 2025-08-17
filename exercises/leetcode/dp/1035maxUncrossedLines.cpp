/**
* @author yohan
* @Date 2025/08/03 
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * 1035.不相交的线
 */
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = max(n1, n2);
        // dp[i][j]表示 i 和 j 结尾时的最大不想交的线
        int dp[n+1][n+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                // 相等的时候就是一条连线
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = 1;
                }

                // 两个边界0的条件
                if (i == 0 && j - 1 >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }

                if (j == 0 && i - 1 >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }

                // 防止越界后，就考虑如下三种情况的最大值
                // 1. (i-1,j-1) 加上当前（i.j）是否有连线
                // 2. (i-1,j)和（j-1，i)中的最大值，因为端点不能相交，所以不能带当前（i.j）
                if (i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j] = max(max(dp[i - 1][j - 1] + dp[i][j], dp[i][j - 1]),dp[i - 1][j]);
                }
            }
        }

        return dp[n1 - 1][n2 - 1];
    }
};

int main() {
    Solution solution;
    int n = 4; // 你可以更改这个值来测试不同的输入
    vector<int> nums = {1,2,4};
    vector<int> nums2 = {1,4,2};
    vector<vector<int>> inputTest = {{10,-98,44},{-20,65,34},{-100,-1,74}};
    int result = solution.maxUncrossedLines(nums, nums2);
    cout << "result:" << result << endl;
    return 0;
}