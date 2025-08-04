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

using namespace std;

// 26 叉树, 记录路径

// @leet start

// 26 叉数的节点
struct Node {
    Node* son[26]{};  // 26 个子节点 (代表 26 字母)
    bool end{false};  // 是否为终止节点
};

class Trie {
    Node* root{new Node};

    int Find(string word) {
        auto curr{root};
        for (auto ch : word) {
            ch -= 'a';
            if (!curr->son[ch]) {
                return 0;  // 没有这个字符直接提前返回 0
            }
            curr = curr->son[ch];
        }
        // curr->end 判断单词是否终止
        // 如果正好终止: search 成功
        // 如果没有终止: startsWith 成功
        return curr->end ? 2 : 1;
    }

public:
    void insert(string word) {
        auto curr{root};
        // 单词中每个字符组成了路径
        for (auto ch : word) {
            ch -= 'a';  // 缩到 26 范围
            if (!curr->son[ch]) {
                curr->son[ch] = new Node;
            }
            curr = curr->son[ch];
        }
        curr->end = true;  // 标记终止
    }

    bool search(string word) { return Find(std::move(word)) == 2; }

    bool startsWith(string prefix) { return Find(std::move(prefix)) != 0; }

private:
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @leet end
