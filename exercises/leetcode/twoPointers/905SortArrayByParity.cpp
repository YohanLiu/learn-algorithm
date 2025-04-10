/**
* @author yohan
* @Date 2025/04/10 
*/

#include <bits/stdc++.h>

using namespace std;

// 905. 按奇偶排序数组
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return nums;
        }

        int left = 0;
        int right = size - 1;

        while (left < right) {
            while (left < size && nums[left] % 2 == 0) {
                left++;
            }

            while (right >= 0 && nums[right] % 2 == 1) {
                right--;
            }

            if (left >= right) {
                break;
            }

            // 上面步骤通过双指针的移动已经定位到两个需要交换的数
            // 进行交换
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
        return nums;
    }
};

int main() {
    Solution solution;
    vector<int> inputTest = {0,2};
    vector<int> res = solution.sortArrayByParity(inputTest);
    for (int a : res)
    cout << a << ' ';
    return 0;
}