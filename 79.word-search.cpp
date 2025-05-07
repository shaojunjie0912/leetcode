#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
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

// 思考: 不再像其它回溯一样只有一个入口 0/n
// 每一个格子都可以作为入口, 因此遍历整个网格做 dfs

// 采用 board[i][j] = -1 标记为已访问, 且必定不会跟 word 匹配,
// 达到不访问相同格子的效果

// 用哈希表记录字母出现次数
// 优化 1: board 中某个字母出现次数少于 word 中某个字母, 则直接返回 false
// 优化 2: 在 word 的第一个字母和最后一个字母中找在 board 中出现次数最少的那个, 从它开始搜索

// @leet start
class Solution {
    // 上下左右
    static constexpr int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    bool exist(vector<vector<char>>& board, string word) {
        // 哈希表 1 记录字母出现次数辅助优化:
        unordered_map<char, int> cnt;  // board 中字母出现次数
        for (auto const& row : board) {
            for (auto ch : row) {
                ++cnt[ch];
            }
        }
        // 优化 1
        unordered_map<char, int> word_cnt;  // word 中字母出现次数
        for (auto ch : word) {
            ++word_cnt[ch];
            if (word_cnt[ch] > cnt[ch]) {
                return false;
            }
        }

        // 优化 2
        if (cnt[word.back()] < cnt[word.front()]) {
            ranges::reverse(word);
        }

        int m = board.size();
        int n = board[0].size();

        // i: 行索引; j: 列索引; k: 单词 word 中的索引
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
            if (board[i][j] == word[k]) {  // 如果当前格子与 word 索引 k 对应的字母匹配成功
                // 匹配成功且索引已经是最后一个了, 则直接返回 true
                if (k == word.length() - 1) {
                    return true;
                }
                // 匹配成功但是索引还没到最后, 继续匹配四周的格子
                board[i][j] = -1;  // 标记为已访问
                for (auto& [dx, dy] : DIRS) {
                    int new_x = i + dx;
                    int new_y = j + dy;
                    // 如果相邻格子没越界, 且与 word[k+1] 相等, 则返回 true
                    if (0 <= new_x && new_x < m && 0 <= new_y && new_y < n &&
                        dfs(new_x, new_y, k + 1)) {
                        return true;
                    }
                }
                board[i][j] = word[k];  // 恢复现场 (因为相等所以就用 word[k])
                return false;
            } else {  // 匹配失败
                return false;
            }
        };

        // 网格中每个格子都可以作为 dfs 入口
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0)) {  // 如果找到则返回 true
                    return true;
                }
            }
        }
        return false;
    }
};
// @leet end

int main() { return 0; }
