/**
 * 61. Rotate List
 * https://leetcode.com/problems/rotate-list/
 * 
 * Given the head of a linked list, rotate the list to the right by k places.
 * 
 * Example 1:
 *     Input: head = [1,2,3,4,5], k = 2
 *     Output: [4,5,1,2,3]
 *     Explanation:
 *     rotate 1 steps to the right: 5->1->2->3->4
 *     rotate 2 steps to the right: 4->5->1->2->3
 * 
 * Example 2:
 *     Input: head = [0,1,2], k = 4
 *     Output: [2,0,1]
 *     Explanation:
 *     rotate 1 steps to the right: 2->0->1
 *     rotate 2 steps to the right: 1->2->0
 *     rotate 3 steps to the right: 0->1->2
 *     rotate 4 steps to the right: 2->0->1
 * 
 * Constraints:
 *     The number of nodes in the list is in the range [0, 500].
 *     -100 <= Node.val <= 100
 *     0 <= k <= 2 * 10^9
 */

 #include <cassert>
#include <vector>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Базовые случаи
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        // 1. Ищем хвост и считаем длину списка
        ListNode* tail = head;
        int node_count = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            ++node_count;
        }

        // 2. Оптимизируем k
        k %= node_count;
        if (k == 0) {
            return head;
        }

        // 3. Замыкаем список в кольцо
        tail->next = head;

        // 4. Идем до нового хвоста
        const int steps_to_new_tail = node_count - k;
        for (int i = 0; i < steps_to_new_tail; ++i) {
            tail = tail->next;
        }

        // 5. Разрываем кольцо
        head = tail->next;
        tail->next = nullptr;
        
        return head;
    }
};

ListNode* CreateList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

std::vector<int> ListToVector(ListNode* head) {
    std::vector<int> result;
    while (head != nullptr) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

void FreeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void Test1() {
    ListNode* head = CreateList({1, 2, 3, 4, 5});
    ListNode* result_head = Solution().rotateRight(head, 2);
    std::vector<int> result = ListToVector(result_head);
    std::vector<int> expected = {4, 5, 1, 2, 3};
    assert(result == expected);
    FreeList(result_head);
}

void Test2() {
    ListNode* head = CreateList({0, 1, 2});
    ListNode* result_head = Solution().rotateRight(head, 4);
    std::vector<int> result = ListToVector(result_head);
    std::vector<int> expected = {2, 0, 1};
    assert(result == expected);
    FreeList(result_head);
}

void Test3_EmptyList() {
    ListNode* head = CreateList({});
    ListNode* result_head = Solution().rotateRight(head, 1);
    std::vector<int> result = ListToVector(result_head);
    std::vector<int> expected = {};
    assert(result == expected);
    FreeList(result_head);
}

void Test4_SingleNode() {
    ListNode* head = CreateList({1});
    ListNode* result_head = Solution().rotateRight(head, 99);
    std::vector<int> result = ListToVector(result_head);
    std::vector<int> expected = {1};
    assert(result == expected);
    FreeList(result_head);
}

void Test5_K_Multiple_Of_Length() {
    ListNode* head = CreateList({1, 2, 3});
    ListNode* result_head = Solution().rotateRight(head, 9);
    std::vector<int> result = ListToVector(result_head);
    std::vector<int> expected = {1, 2, 3};
    assert(result == expected);
    FreeList(result_head);
}

int main() {
    Test1();
    Test2();
    Test3_EmptyList();
    Test4_SingleNode();
    Test5_K_Multiple_Of_Length();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}