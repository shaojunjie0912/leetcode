#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <cstdint>
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

// 双向链表节点 DNode (包含 key, value,  *prev, *next)
// dummy 哨兵节点, 初始化时 prev 和 next 均指向自身
// 哈希表保存 key 和 DNode 映射, 方便快速查询是否存在
// 辅助函数:
// 1. Remove(DNode* x): (抽出) 删除一个节点
// 2. PushFront(DNode* x): (放在最上面) 在头部添加一个节点
// 3. GetNode(int key): (抽出并放在最上面) 获取 key 对应的节点, 并将节点移动到链表头部
// 重点关注 <放在最上面> 这个操作!

// @leet start
struct DNode {
    int key;
    int value;
    DNode* prev;
    DNode* next;

    DNode(int k = 0, int v = 0) : key(k), value(v) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), dummy(new DNode{}) {
        // NOTE: 初始 dummy 的 prev 和 next 均指向自身
        // 后面插入会形成一个环
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    int get(int key) {
        auto node{GetNode(key)};
        return node ? node->value : -1;
    }

    void put(int key, int value) {
        auto node{GetNode(key)};  // 如果有, 则内部会将其放在最上面
        if (node) {               // 如果有就更新值
            node->value = value;
            return;
        }

        // 准备放新书, 在此之前先检查容量
        // 如果当前容量已经最大则去除最后一本书 (dummy -> prev)
        if (key2node.size() == capacity) {
            auto back_node{dummy->prev};
            key2node.erase(back_node->key);
            Remove(back_node);  // 抽出最后一本
            delete back_node;   // 释放内存
        }

        // 如果没有就创建并添加到哈希表
        node = new DNode{key, value};
        key2node[key] = node;
        PushFront(node);  // 放在最上面
    }

private:
    // 在双向链表中删除一个节点
    void Remove(DNode* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    // 在双向链表的头部添加一个节点
    void PushFront(DNode* x) {
        x->prev = dummy;
        x->next = dummy->next;
        dummy->next = x;
        x->next->prev = x;
    }

    // 获取 key 对应的节点, 并将节点移动到链表头部
    // 即将书放在最上面
    DNode* GetNode(int key) {
        auto it{key2node.find(key)};
        if (it == key2node.end()) {
            return nullptr;
        }
        auto node{it->second};
        Remove(node);     // NOTE: 相当于把书抽出来 (并不是释放内存)
        PushFront(node);  // 放在最上面
        return node;
    }

private:
    int capacity;
    DNode* dummy;                         // 哨兵节点
    unordered_map<int, DNode*> key2node;  // key 和 DNode 映射 (快速判断是否存在 node)
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @leet end
