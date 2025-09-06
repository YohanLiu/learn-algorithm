/**
* @author yohan
* @Date 2025/09/04 
*/

#include <bits/stdc++.h>

using namespace std;

// 983. 最低票价
class Solution {
    // 缓存曾经算出来的结果
    int memary[366];
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(memary, -1, sizeof(memary));

        return digui(days, costs, 0);
    }

    int digui(vector<int>& days, vector<int>& costs, int day) {
        if (memary[day] != -1) return memary[day];
        if (day >= days.size()) {
            return 0;
        }

        // 一天票递归计算
        int first = costs[0] + digui(days, costs, day + 1);

        // 七天的票能旅行到的天数
        int day1 = days[day] + 7 - 1;
        // 找到大于天数的下标
        int index = day + 1;

        // 买了七天票，能旅行到的天数都跳过，然后再从后继续递归
        for (int i = day + 1; i < days.size(); i++) {
            if (days[i] <= day1) {
                index = i + 1;
            }
            if (days[i] > day1) {
                index = i;
                break;
            }
        }

        int second = costs[1] + digui(days, costs, index);

        // 30天票同样如此
        int day2 = days[day] + 30 - 1;
        int index2 = day + 1;
        for (int i = day + 1; i < days.size(); i++) {
            if (days[i] <= day2) {
                index2 = i + 1;
            }
            if (days[i] > day2) {
                index2 = i;
                break;
            }
        }

        int third = costs[2] + digui(days, costs, index2);

        int min1 = min(min(first, second), third);
        memary[day] = min1;
        return min1;
    }
};

int main() {
    Solution solution;
    vector<int> days = {1,30,60,365};
    vector<int> costs = {2,7,15};
    int result = solution.mincostTickets(days, costs);
    cout << "result:" << result << endl;
    return 0;
}