/**
* @author yohan
* @Date 2025/04/16 
*/

#include <bits/stdc++.h>

using namespace std;

// 27. 移除元素
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;

        // 双指针的快慢指针，如果一直不等，那左右指针相等
        // 出现相等，那右指针就快了，在不等的时候。左指针值等于右指针就可以把不等的元素都移到前面
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }

        return left;
    }
};

int main() {
    Solution solution;
    int n = 4; // 你可以更改这个值来测试不同的输入
    vector<vector<int>> inputTest = {{1,2},{2,3},{3,4}};
    vector<int> inputTest1 = {4,5};
    int result = solution.removeElement(inputTest1, 5);

    cout << "result:" << result << endl;
    return 0;
}