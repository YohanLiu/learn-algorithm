/**
* @author yohan
* @Date 2025/04/16 
*/

#include <bits/stdc++.h>

using namespace std;

// 118. 杨辉三角
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 1; i <= numRows; i++) {
            vector<int> temp(i, 1);
            for (int j = 1; j < i - 1; j++) {
                temp[j] = res[i - 2][j - 1] + res[i - 2][j];
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main() {
    Solution solution;
    int n = 4; // 你可以更改这个值来测试不同的输入
    vector<vector<int>> result = solution.generate(n);
    return 0;
}