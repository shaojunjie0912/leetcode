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

// @leet start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;  // 元素值:出现次数
        int max_cnt = 0;              // 最大出现次数
        for (auto& x : nums) {
            ++cnt[x];
            max_cnt = max(max_cnt, cnt[x]);
        }

        // 桶的索引就是出现次数, 桶个数是 max_cnt + 1
        vector<vector<int>> buckets(max_cnt + 1);
        for (auto& [x, c] : cnt) {    // [元素值, 出现次数]
            buckets[c].push_back(x);  // NOTE: 将出现次数相同的元素放到一个桶中
        }

        vector<int> ans;
        // NOTE: 倒序遍历 + 退出条件很妙! ans.size()
        for (int i = max_cnt; i >= 0 && ans.size() < k; --i) {
            ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        }
        return ans;
    }
};
// @leet end
