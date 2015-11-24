//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
#define LEETCODE__0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_H


class _0019_Remove_Nth_Node_From_End_of_List {

    class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            if (head == NULL) return head;
            int counter = 0;
            ListNode *temp[10000];
            ListNode *move = head;
            while (move) {
                temp[counter++] = move;
                move = move->next;
            }
            temp[counter] = NULL;
            if (counter == n) {
                delete head;
                return temp[1];
            }
            temp[counter - n - 1]->next = temp[counter - n + 1];
            return temp[0];
        }
    };

};


#endif //LEETCODE__0019_REMOVE_NTH_NODE_FROM_END_OF_LIST_H
