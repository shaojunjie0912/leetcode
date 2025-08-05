#include <unordered_map>

using namespace std;

// get: 把一本书抽出来, 放在它「右边这摞书」的最上面
// put: 放入一本新书
//    * 已有这本书: 把它抽出来放在它「右边这摞书」的最上面并替换 value
//    * 没有这本书: 把它放在「看过 1 次这摞书」的最上面, 放之前检查 capacity
//        - 放之前大小 < capacity: 直接放
//        - 放之前大小 = capacity: 移除「最左边那摞书」的最下面那本书后再放

// NOTE: 有一种情况: 所有书都看过 >=2 次, 因此最左边那一摞书的频次是 2 不是 1, 没有 1 次那摞书

// min_freq 更新:
//     * get: 如果一本书抽出后, 这摞书变空, 且这摞书在最左边(== min_freq), 则 min_freq++
//     * put: 如果没有这本书, 这在「频次=1」这摞书上加一本新书, min_freq 更新为 1

// TODO: dummy 的 freq 没有严格对应, 即不同 freq 的 dummy 都是 1(虽然里面的 nodes 的 freq 是对应的)

// key2node 对应的是所有书
// freq2dummy 是所有摞的 dummy

// key 可以判断最久没使用的, 因为 get/put 一次 key 就更新一次使用
// freq 是额外记录

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
    int min_freq;                           // 最左边那摞书的索引 (最小看过频次)
    int capacity;                           // 容量
    unordered_map<int, DNode*> key2node;    // key 和 DNode* 映射 (找到一摞书中一本书)
    unordered_map<int, DNode*> freq2dummy;  // freq 和 dummy 映射 (找到哪一摞书)

private:
    // 创建一个新双向链表(创建一摞书) 默认 freq = 1
    DNode* NewList() {
        DNode* dummy{new DNode};
        dummy->pre = dummy;
        dummy->nxt = dummy;
        return dummy;
    }

    // 删除一个节点 (抽出一本书)
    void Remove(DNode* x) {
        x->pre->nxt = x->nxt;
        x->nxt->pre = x->pre;
    }

    // 在链表头部添加一个节点 (把一本书放最上面)
    // 指定 freq 用来找哪一摞书 (dummy)
    void PushFront(int freq, DNode* x) {
        auto it{freq2dummy.find(freq)};
        // 有freq对应的那摞书就直接用
        // 没有就创建新一摞书 (新 dummy), dummy 的 freq 是 1 但不影响
        if (it == freq2dummy.end()) {  // 这摞书是空的, 就新建
            // emplace 返回 [iterator, bool]
            it = freq2dummy.emplace(freq, NewList()).first;  // NOTE: 这里 freq 可能是右边新一摞书
        }
        auto dummy{it->second};
        // 将 x 添加到头部 (即 dummy 后面)
        x->pre = dummy;
        x->nxt = dummy->nxt;
        x->nxt->pre = x;
        x->pre->nxt = x;
    }

    // 抽出一本书并放在右边那摞书的最上面
    DNode* GetNode(int key) {
        auto it{key2node.find(key)};
        if (it == key2node.end()) {  // 没有这本书
            return nullptr;
        }
        auto node{it->second};               // 有这本书
        Remove(node);                        // HACK: 1. 抽出这本书
        auto dummy{freq2dummy[node->freq]};  // 拿到这摞书对应的频次 (freq)
        if (dummy->pre == dummy) {           // 如果抽出来后这摞书是空
            freq2dummy.erase(node->freq);    // 移除空链表
            delete dummy;                    // 释放内存
            // NOTE: 如果这摞书是最左边的则更新 min_freq
            if (min_freq == node->freq) {
                ++min_freq;
            }
        }
        // HACK: 2. 放在「右边这摞书」的上面
        PushFront(++node->freq, node);  // NOTE: 前缀++: 1. 到右边这摞书 2. 更新node的freq
        return node;
    }

public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto node{GetNode(key)};
        return node ? node->val : -1;
    }

    void put(int key, int value) {
        auto node{GetNode(key)};
        // 有这本书就改值
        if (node) {
            node->val = value;
            return;
        }
        // 没有就放但是!
        // NOTE: 放之前检查 capacity
        // 如果当前容量已经最大则去除最左边哪一摞的最底下那本书
        // 最底下是 key 最久没使用的
        if (key2node.size() == capacity) {
            // 去除逻辑
            auto left_dummy{freq2dummy[min_freq]};  // 最左边那摞书 min_freq
            auto last_node{left_dummy->pre};        // 最下面那本书
            Remove(last_node);                      // 抽出
            key2node.erase(last_node->key);
            delete last_node;  // 释放内存
            // 如果这摞书变空了, 则移除空链表
            if (left_dummy->pre == left_dummy) {
                freq2dummy.erase(min_freq);
                delete left_dummy;
            }
        }
        // 新书
        auto new_node{new DNode{key, value}};
        key2node[key] = new_node;
        PushFront(1, new_node);  // 放在看过 1 次的上面
        min_freq = 1;            // 更新 min_freq
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @leet end
