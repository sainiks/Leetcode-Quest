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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sums = carry;
            if (l1) {
                sums += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sums += l2->val;
                l2 = l2->next;
            }
            carry = sums / 10;
            ListNode* newNode = new ListNode(sums % 10);
            if (!result) {
                result = newNode;
                tail = result;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        return result;
    }
};