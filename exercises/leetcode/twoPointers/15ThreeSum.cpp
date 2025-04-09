/**
* @author yohan
* @Date 2025/04/09 
*/

#include <bits/stdc++.h>

using namespace std;

// 15三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // 三指针提前排序方便指针移动
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            // 结果集去重
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                // 左指针移动使和变大
                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    // 右指针移动使和变小
                    right--;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // 结果集去重
                    while (left < right && nums[left] == nums[left - 1] && nums[right] == nums[right + 1]) {
                        left++;
                        right--;
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> inputTest = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    vector<vector<int>> result = solution.threeSum(inputTest);
    for (vector<int> result1 : result) {
        for (int result2 : result1) {
            cout << result2 << ' ';
        }
        cout << endl;
    }
    return 0;
}