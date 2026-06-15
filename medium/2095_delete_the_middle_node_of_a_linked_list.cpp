/**
 * 2095. Delete the Middle Node of a Linked List
 * https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
 * 
 * You are given the head of a linked list. Delete the middle node, and return 
 * the head of the modified linked list.
 * 
 * The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start 
 * using 0-based indexing.
 * 
 * Example 1:
 *     Input: head = [1,3,4,7,1,2,6]
 *     Output: [1,3,4,1,2,6]
 * 
 * Example 2:
 *     Input: head = [1,2,3,4]
 *     Output: [1,2,4]
 * 
 * Example 3:
 *     Input: head = [2,1]
 *     Output: [2]
 * 
 * Constraints:
 *     The number of nodes in the list is in the range [1, 10^5].
 *     1 <= Node.val <= 10^5
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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }

        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;
        while (fast_ptr->next != nullptr)

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
    ListNode* head = CreateList({1, 3, 4, 7, 1, 2, 6});
    ListNode* result_head = Solution().deleteMiddle(head);
    std::vector<int> result = ListToVector(result_head);
    std::vector<int> expected = {1, 3, 4, 1, 2, 6};
    assert(result == expected);
    FreeList(result_head);
}

void Test2() {
    ListNode* head = CreateList({1, 2, 3, 4});
    ListNode* result_head = Solution().deleteMiddle(head);
    std::vector<int> result = ListToVector(result_head);
    std::vector<int> expected = {1, 2, 4};
    assert(result == expected);
    FreeList(result_head);
}

void Test3() {
    ListNode* head = CreateList({2, 1});
    ListNode* result_head = Solution().deleteMiddle(head);
    std::vector<int> result = ListToVector(result_head);
    std::vector<int> expected = {2};
    assert(result == expected);
    FreeList(result_head);
}

void Test4_SingleNode() {
    ListNode* head = CreateList({1});
    ListNode* result_head = Solution().deleteMiddle(head);
    std::vector<int> result = ListToVector(result_head);
    std::vector<int> expected = {};
    assert(result == expected);
    FreeList(result_head);
}

int main() {
    Test1();
    Test2();
    Test3();
    Test4_SingleNode();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}