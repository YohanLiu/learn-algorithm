/**
* @author yohan
* @Date 2025/03/03 
*/

#include <bits/stdc++.h>

using namespace std;

// 646. 最长数对链
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int size = pairs.size();
        if (size == 0) {
            return 0;
        }

        // 排序保证顺序
        sort(pairs.begin(), pairs.end());

        // 从0到下标为i的最长递增数对链
        vector<int> dp(size + 1, 0);
        for (int i = 0; i < size; ++i) {
            dp[i] = 1;
            // j下标从0到i把情况都枚举一遍
            for (int j = 0; j < i; ++j) {

                // 前一个的尾部元素比后一个的头部元素小，即出现数对链
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution solution;
    vector<vector<int>> inputTest = {{1,2},{2,3},{3,4}};
    int result = solution.findLongestChain(inputTest);
    cout << "result:" << result << endl;
    return 0;
}