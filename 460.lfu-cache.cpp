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

// dummy

// @leet start
struct DNode {
    int key{0};
    int val{0};
    int freq{1};  // NOTE: LFU 多出 LRU 一个 freq, 初始值为 1
    DNode* pre{nullptr};
    DNode* nxt{nullptr};
};

class LFUCache {
private:
    int min_freq;                           // 最左边那摞书的索引
    int capacity;                           // 容量
    unordered_map<int, DNode*> key2node;    // key 和 DNode* 映射 (找到一摞书中一本书)
    unordered_map<int, DNode*> freq2dummy;  // key 和 dummy 映射 (找到哪一摞书)

private:
    // 删除一个节点 (抽出一本书)
    void Remove(DNode* x) {
        x->pre->nxt = x->nxt;
        x->nxt->pre = x->pre;
    }

    // 在链表头部添加一个节点 (把一本书放最上面)
    // 指定 freq 用来找哪一摞书 (dummy)
    void PushFront(int freq, DNode* x) {
        auto it{freq2dummy.find(freq)};
        if (it == freq2dummy.end()) {  // 这摞书是空的
        }
    }

public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {}

    void put(int key, int value) {}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @leet end
