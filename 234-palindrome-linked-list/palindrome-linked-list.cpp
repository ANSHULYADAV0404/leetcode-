/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        // 1. Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next; // Fast moves 2 steps
        }

        // 2. Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow->next; // Start reversing right after middle
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // 3. Compare the first half and the reversed second half
        ListNode* c1 = head;
        ListNode* c2 = prev; // Head of the reversed second half
        while (c2 != nullptr) {
            if (c1->val != c2->val) {
                return false;
            }
            c1 = c1->next;
            c2 = c2->next;
        }

        return true;
    }
};