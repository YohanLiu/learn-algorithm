/**
* @author yohan
* @Date 2025/08/25 
*/

#include <bits/stdc++.h>

using namespace std;

// 2140. 解决智力问题
class Solution {
public:
    // 从递归解法可以看出dp[i]=max(dp[i+1],dp[j]+points_i,其中 j = min(i+brainpower_i+1,n)
    // 计算dp[i]依赖 dp[i+1]所以要反着写递归求解
    long long mostPoints(vector<vector<int> > &questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            // 分解后子集合的下标
            int j = min(n, i + questions[i][1] + 1);
            dp[i] = max(dp[i + 1], dp[j] + questions[i][0]);
        }
        return *max_element(dp.begin(), dp.end());
    }

    // 递归解法超时了
    long long mostPoints_digui(vector<vector<int>>& questions) {
        vector<long long> cache(questions.size() + 1, 0);
        // 递归解法，选了当前的 i，就是当前 i 的分数 + 后面集合【i+1+brainpoweri, n】中的最大值
        // 没选当前的i，就是【i+1，n】的最大值
        return dfs(questions, 0, cache);
    }

    long long dfs(vector<vector<int>>& questions, int i, vector<long long>& cache) {
        if (i >= questions.size()) {
            return 0;
        }

        // cache用作缓存避免重复计算
        if (cache[i]) {
            return cache[i];
        }

        return max(dfs(questions, i + 1, cache), dfs(questions, i + questions[i][1] + 1, cache) + questions[i][0]);
    }
};

int main() {
    Solution solution;
    int n = 4; // 你可以更改这个值来测试不同的输入
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> inputTest = {{3,2},{4,3},{4,4},{2,5}};
    int result = solution.mostPoints(inputTest);
    cout << "result:" << result << endl;
    return 0;
}