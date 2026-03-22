/**
* @author yohan
* @Date 2025/09/29 
*/

#include <bits/stdc++.h>

using namespace std;

// 71. 简化路径
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string temp;
        // 路径根据 / 拆分然后加到集合中
        for (char c : path) {
            if (c == '/') {
                if (temp.size() != 0) {
                    if (temp == "..") {
                        if (stack.size() != 0) {
                            stack.pop_back();
                        }

                        temp.clear();
                    } else if (temp == ".") {
                        temp.clear();
                    } else {
                        stack.push_back(temp);
                        temp.clear();
                    }

                }
            } else {
                temp.push_back(c);
            }
        }

        // 末尾路径处理
        if (temp.size() != 0) {
            if (temp == "..") {
                if (stack.size() != 0) {
                    stack.pop_back();
                }

                temp.clear();
            } else if (temp == ".") {
                temp.clear();
            } else {
                stack.push_back(temp);
                temp.clear();
            }
        }

        if (stack.size() == 0) {
            return "/";
        }

        string res;
        for (string s : stack) {
            res = res + "/";
            res = res + s;
        }
        return res;
    }
};

int main() {
    Solution solution;
    int n = 4; // 你可以更改这个值来测试不同的输入
    string result = solution.simplifyPath("/../");
    cout << "result:" << result << endl;
    return 0;
}