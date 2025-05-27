#include <bits/stdc++.h>

#include "include/list_node.hpp"
#include "include/node.hpp"
#include "include/tree_node.hpp"

using namespace std;

// NOTE:
// key: 按<字典序排序>后的单词
// value: vector<string>

// @leet start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key: 排序后字符串 (string)
        // value: 字符串数组 (vector<string>)
        std::unordered_map<string, vector<string>> map;
        for (auto& str : strs) {
            auto key{str};
            ranges::sort(key);
            map[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto& [_, v] : map) {
            ans.push_back(std::move(v));
        }
        return ans;
    }
};
// @leet end

int main() { return 0; }
