//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0002_ADD_TWO_NUMBERS_H
#define LEETCODE__0002_ADD_TWO_NUMBERS_H

class _0002_Add_Two_Numbers {

    class Solution {
    public:
        ListNode * addTwoNumbers(ListNode *l1, ListNode *l2) {
            if (l1 == NULL) return l2;
            if (l2 == NULL) return l1;
            ListNode *move_1 = l1;
            ListNode *move_2 = l2;
            ListNode *ans;
            ListNode *move_3;
            bool is_head = true;
            int carry = 0;
            while (move_1 || move_2) {
                if (is_head) {
                    is_head = false;
                    ans = new ListNode((move_1->val + move_2->val) % 10);
                    move_3 = ans;
                    carry = ((move_1->val + move_2->val) / 10);
                    move_1 = move_1->next;
                    move_2 = move_2->next;
                } else {
                    int temp_1 = 0;
                    int temp_2 = 0;
                    if (move_1) {
                        temp_1 = move_1->val;
                        move_1 = move_1->next;
                    }
                    if (move_2) {
                        temp_2 = move_2->val;
                        move_2 = move_2->next;
                    }
                    move_3->next = new ListNode((temp_1 + temp_2 + carry) % 10);
                    move_3 = move_3->next;
                    carry = (temp_1 + temp_2 + carry) / 10;
                }
            }
            if (carry) move_3->next = new ListNode(carry);
            return ans;
        }
    };

};

#endif //LEETCODE__0002_ADD_TWO_NUMBERS_H
