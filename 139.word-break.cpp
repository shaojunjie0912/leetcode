#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// HACK: 把 s 划分为若干段, 是否每段都在 wordDict 中

// 枚举最后一段的长度, 如果子串在 wordDict 中, 则递归

// dfs(i) = dfs()

// @leet start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // wordDict 中单词的最大长度, 枚举不能超过此长度
        int max_len = ranges::max(wordDict, {}, &string::length).length();
        int n = s.length();
        unordered_set<string> word_set{wordDict.begin(), wordDict.end()};
        if (word_set.contains(s)) {
            return true;
        }
        vector<int> memo(n, -1);  // 记忆数组, 初值 -1
        // NOTE: 新写法, 匿名 lambda 无法直接递归调用, 可以用 function
        function<bool(int)> dfs = [&](int i) -> bool {
            if (i < 0) {  // NOTE: == 0 成功拆分
                return true;
            }
            auto& res{memo[i]};
            if (res != -1) {
                return res;
            }
            for (int j{i}; j >= max(i - max_len + 1, 0); --j) {
                if (word_set.contains(s.substr(j, i - j + 1)) && dfs(j - 1)) {
                    return res = true;  // 记忆化
                }
            }
            return res = false;
        };
        return dfs(n - 1);
    }
};
// @leet end

int main() { return 0; }
