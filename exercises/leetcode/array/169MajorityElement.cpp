/**
* @author yohan
* @Date 2025/09/29 
*/

#include <bits/stdc++.h>

using namespace std;

// 169. 多数元素
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int num = 0;

        // 不同的数字做抵消，剩下的一定是结果
        for (int temp : nums) {
            if (count == 0) {
                num = temp;
                count = 1;
                continue;
            }

            if (num != temp) {
                count--;
            } else {
                count++;
            }
        }
        return num;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1,2,3,4,4,4,4,4}; // 你可以更改这个值来测试不同的输入
    int result = solution.majorityElement(nums);
    cout << "result:" << result << endl;
    return 0;
}