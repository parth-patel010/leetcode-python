// Problem 2: Add Two Numbers

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
 class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int n1 = 0, n2 = 0;
            for (auto p = l1; p; p = p->next) ++n1;
            for (auto p = l2; p; p = p->next) ++n2;
            if (n1 < n2) std::swap(l1, l2);
    
            ListNode *p1 = l1, *p2 = l2, *prev = nullptr;
            int carry = 0;
            while (p1) {
                int sum = p1->val + (p2 ? p2->val : 0) + carry;
                p1->val = sum % 10;
                carry = sum / 10;
    
                prev = p1;
                p1  = p1->next;
                if (p2) p2 = p2->next;
            }
            if (carry) {
                prev->next = new ListNode(carry);
            }
            return l1;
        }
    };
    