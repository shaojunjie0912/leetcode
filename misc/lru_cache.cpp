#include <bits/stdc++.h>

using namespace std;

struct DNode {
    int key{0};
    int value{0};
    DNode* pre{nullptr};
    DNode* nxt{nullptr};
};

class LRUCache {
public:
    LRUCache(int c) : capacity(c), dummy(new DNode) {
        dummy->pre = dummy;
        dummy->nxt = dummy;
    }

    ~LRUCache() {
        if (dummy) {
            delete dummy;
            dummy = nullptr;
        }
    }

public:
    // 抽出并放在最上面
    int get(int key) {
        auto node{GetNode(key)};
        if (!node) {
            return -1;
        }
        return node->value;
    }

    // 1. 有, 抽出放到最上面, 替换值
    // 2. 没有, 放最上面, 超出 c 则去掉最后一本
    void put(int key, int val) {
        auto node{GetNode(key)};
        if (node) {
            node->value = val;
            return;
        }
        auto new_node{new DNode{key, val}};
        key2node[key] = new_node;
        PushFront(new_node);
        if (key2node.size() > capacity) {
            auto last{dummy->pre};
            Remove(last);
            key2node.erase(last->key);
            delete last;
        }
    }

private:
    void Remove(DNode* node) {
        node->nxt->pre = node->pre;
        node->pre->nxt = node->nxt;
    }

    void PushFront(DNode* node) {
        // dummy→ ←head
        //     ←node→
        node->nxt = dummy->nxt;
        dummy->nxt->pre = node;
        dummy->nxt = node;
        node->pre = dummy;
    }

    DNode* GetNode(int key) {
        auto it{key2node.find(key)};
        if (it == key2node.end()) {
            return nullptr;
        }
        auto node{it->second};
        Remove(node);
        PushFront(node);
        return node;
    }

private:
    int capacity;
    DNode* dummy;
    unordered_map<int, DNode*> key2node;
};