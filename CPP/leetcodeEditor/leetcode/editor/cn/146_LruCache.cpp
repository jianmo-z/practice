//运用你所掌握的数据结构，设计和实现一个 LRU (最近最少使用) 缓存机制 。 
//
// 
// 
// 实现 LRUCache 类： 
//
// 
// LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存 
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
// void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上
//限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。 
// 
//
// 
// 
// 
//
// 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？ 
//
// 
//
// 示例： 
//
// 
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= capacity <= 3000 
// 0 <= key <= 3000 
// 0 <= value <= 104 
// 最多调用 3 * 104 次 get 和 put 
// 
// Related Topics 设计 
// 👍 1055 👎 0


#include <bits/stdc++.h>
#include "../googletest/include/gtest/gtest.h"

namespace LruCache {
    using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
    class LinkedNode{
    public:
        LinkedNode(int key = 0, int value = 0): pre(nullptr), next(nullptr),key(key), value(value) {
        }

        LinkedNode *pre;
        LinkedNode *next;
        int key, value;
    };

    class LRUCache {
    public:
        LRUCache(int capacity):capacity(capacity) {
            head = new LinkedNode();
            tail = new LinkedNode();
            head->next = tail;
            tail->pre = head;
        }

        int get(int key) {
            if (hashMap.find(key) == hashMap.end()) {
                return -1;
            }

            move2Head(hashMap.find(key)->second);
            return hashMap.find(key)->second->value;
        }

        void put(int key, int value) {
            if (hashMap.find(key) == hashMap.end()) {
                hashMap[key] = new LinkedNode(key, value);
            } else {
                hashMap[key]->value = value;
                move2Head(hashMap[key]);
                return;
            }

            insert2Head(hashMap[key]);

            if (hashMap.size() > this->capacity) {
                 auto node = removeTail();
                 hashMap.erase(node->key);
                 delete node;
            }
        }

    private:
        void insert2Head(LinkedNode * node) {
            head->next->pre = node;
            node->next = head->next;
            head->next = node;
            node->pre = head;
        }


        LinkedNode* removeNode(LinkedNode * node) {
            node->next->pre = node->pre;
            node->pre->next = node->next;
            return node;
        }

        void move2Head(LinkedNode * node) {
            insert2Head(removeNode(node));
        }

        LinkedNode* removeTail() {
            if (hashMap.empty()) {
                return nullptr;
            }
            LinkedNode * tmp = tail->pre;
            tmp->pre->next = tail;
            tail->pre = tmp->pre;
            return tmp;
        }


        int capacity;
        unordered_map<int, LinkedNode *> hashMap;
        list<pair<int, int>> record;
        LinkedNode * head;
        LinkedNode * tail;
    };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)


    TEST(LruCache, test01) {
        LRUCache lru(2);

        lru.put(1, 1); // 缓存是 {1=1}
        lru.put(2, 2); // 缓存是 {1=1, 2=2}
        ASSERT_EQ(lru.get(1), 1);    // 返回 1
        lru.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
        ASSERT_EQ(lru.get(2), -1);    // 返回 -1 (未找到)
        lru.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
        ASSERT_EQ(lru.get(1), -1);    // 返回 -1 (未找到)
        ASSERT_EQ(lru.get(3), 3);    // 返回 3
        ASSERT_EQ(lru.get(4), 4);    // 返回 4
    }

    TEST(LruCache, test02) {
        LRUCache lru(1);

        lru.put(2, 1); // 缓存是 {1=1}
        ASSERT_EQ(lru.get(2), 1);    // 返回 1
    }


    TEST(LruCache, test03) {
        LRUCache lru(2);

        lru.put(2, 1);
        lru.put(2, 2);
        ASSERT_EQ(lru.get(2), 2);
        lru.put(3, 3);
        ASSERT_EQ(lru.get(2), 2);
        lru.put(4, 4);
        ASSERT_EQ(lru.get(1), -1);
        ASSERT_EQ(lru.get(3), -1);
        ASSERT_EQ(lru.get(4), 4);
    }

    TEST(LruCache, test04) {
        LRUCache lru(2);

        lru.put(2, 1);
        lru.put(1, 1);
        lru.put(2, 3);
        lru.put(4, 1);
        ASSERT_EQ(lru.get(1), -1);
        ASSERT_EQ(lru.get(2), 3);
    }
}