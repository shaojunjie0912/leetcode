#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <list>
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

// 有向图判断是否有环

// 每个节点的三种状态值 (颜色)
// 0: 还没访问
// 1: 正在访问, dfs(x) 尚未结束
// 2. 访问完毕, dfs(x) 已经返回

// 在递归过程中, 如果下一个节点在递归栈中 (正在访问), 则有环
// 注意: 1. 下一个节点 2. 正在访问, 不是访问完毕

// @leet start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 构建一个有向图 prerequisites[i] = {a, b} 表示有向边 b -> a
        vector<vector<int>> g(numCourses);
        for (auto& p : prerequisites) {
            g[p[1]].push_back(p[0]);  // p[1] -> p[0]
        }

        vector<int> colors(numCourses);  // 初始都是 0, 还没访问

        // 递归返回值: 是否有环
        function<bool(int)> dfs = [&](int x) -> bool {
            colors[x] = 1;         // 在递归栈中标记正在访问
            for (auto y : g[x]) {  // 遍历 x 的邻居 y, 根据 g 二维数组可知这里 y 只有一个
                // 两种情况代表有环:
                // 1. 递归栈中出现了 y 正在访问!!!
                // 2. y 没被访问过但是 dfs(y) 是 true
                if (colors[y] == 1 || (colors[y] == 0 && dfs(y))) {
                    return true;
                }
            }
            colors[x] = 2;  // 访问完毕
            return false;
        };

        for (int i = 0; i < numCourses; ++i) {
            // 对还没访问的节点使用递归
            if (colors[i] == 0 && dfs(i)) {  // 有环
                return false;
            }
        }

        return true;
    }
};
// @leet end
