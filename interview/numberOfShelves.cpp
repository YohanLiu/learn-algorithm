/**
* @author yohan
* @Date 2025/09/12 
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numberOfShelves(int N) {
        // 螺旋等腰直角三角形，左上角为直角边
        vector<vector<int>> num = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
        int total = 0;
        for (int i = 1; i <= N; i++) {
            total += i;
        }

        int col = 0;
        int row = -1;

        int rowMax = N - 1;
        int colMax = N - 1;

        for (int i = 1; i <= total; ) {
            // 可以往下走的情况
            while (row + 1 <= rowMax && num[row + 1][col] == 0 && i <= total) {
                num[++row][col] = i++;
            }

            // 此时不能往下走了，就要像斜边走
            while (row - 1 >= 0 && col + 1 <= colMax && i <= total && num[row - 1][col + 1] == 0) {
                num[--row][++col] = i++;
            }

            // 左边走
            while (col - 1 >= 0 && num[row][col - 1] == 0 && i <= total) {
                num[row][--col] = i++;
            }
        }


        vector<int> result;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (num[i][j] == 0 || num[i][j] > total) {
                    continue;
                } else {
                    result.push_back(num[i][j]);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    int n = 7; // 你可以更改这个值来测试不同的输入
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> inputTest = {{10,-98,44},{-20,65,34},{-100,-1,74}};
    vector<int> number_of_shelves = solution.numberOfShelves(n);
    for (int num : number_of_shelves) {
        cout << num;
    }

    return 0;
}