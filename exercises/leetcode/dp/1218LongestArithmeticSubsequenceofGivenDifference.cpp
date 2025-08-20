/**
* @author yohan
* @Date 2025/03/03 
*/

#include <bits/stdc++.h>

using namespace std;

// 1218. 最长定差子序列
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int size = arr.size();
        if (size == 0) {
            return 0;
        }

        // 记录了arr[i]值的最长序列
        map<int, int> dp;

        // 结果最大值
        int res = 0;

        // 因为差值减法，减法结果的值如果在 num前面已经算出来可以用，如果在 num 后面构不成子序列也用不到
        // 所以从头到尾遍历，就是找寻此位置之前的符合差值的那个最长序列
        for (int num : arr) {
            dp[num] = dp[num - difference] + 1;
            res = max(res, dp[num]);
        }

        return res;
    }
};

int main() {
    Solution solution;
    int n = 1; // 你可以更改这个值来测试不同的输入
    vector<int> nums = {1,2,3,4};
    int result = solution.longestSubsequence(nums, n);
    cout << "result:" << result << endl;
    return 0;
}