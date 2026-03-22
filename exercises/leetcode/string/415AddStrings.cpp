/**
* @author yohan
* @Date 2025/09/26 
*/

#include <bits/stdc++.h>

using namespace std;

// 415. 字符串相加
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";

        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int bit = 0;
        bool flag = false;
        while (i >= 0 || j >= 0) {
            flag = false;
            int a = 0;
            int b = 0;
            if (i >= 0) {
                a = num1[i--] - '0';
            }

            if (j >= 0) {
                b = num2[j--] - '0';
            }

            int sum = a + b + bit;
            bit = 0;
            if (sum >= 10) {
                bit = sum / 10;
                flag = true;
            }
            int temp = sum % 10;
            res.push_back (temp + '0');
        }

        if (flag) {
            res.push_back(bit + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution solution;
    int n = 4; // 你可以更改这个值来测试不同的输入
    vector<int> nums = {1,2,3,4};
    vector<vector<int>> inputTest = {{10,-98,44},{-20,65,34},{-100,-1,74}};
    string result = solution.addStrings("408", "5");
    cout << "result:" << result << endl;
    return 0;
}