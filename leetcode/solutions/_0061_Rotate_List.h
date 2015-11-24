//
// Created by 伟平 on 2015/11/25.
//

#ifndef LEETCODE__0061_ROTATE_LIST_H
#define LEETCODE__0061_ROTATE_LIST_H


class _0061_Rotate_List {

    class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if (head == NULL || head->next == NULL || k == 0) return head;
            int counter = 0;
            ListNode *move = head;
            while (move) {
                counter++;
                move = move->next;
            }
            k %= counter;
            if (k == 0) return head;
            move = head;
            counter -= k + 1;
            while (counter) {
                counter--;
                move = move->next;
            }
            ListNode *break_point = move->next;
            move->next = NULL;
            move = break_point;
            while (move->next) {
                move = move->next;
            }
            move->next = head;
            return break_point;
        }
    };

};


#endif //LEETCODE__0061_ROTATE_LIST_H
