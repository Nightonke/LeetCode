//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0024_SWAP_NODES_IN_PAIRS_H
#define LEETCODE__0024_SWAP_NODES_IN_PAIRS_H


class _0024_Swap_Nodes_in_Pairs {

    class Solution {
    public:
        ListNode *swapPairs(ListNode *head) {
            if (head == NULL) return head;
            ListNode * temp = head;
            ListNode * beforeTemp = NULL;
            if (head->next != NULL) head = head->next;
            while (temp != NULL && temp->next != NULL) {
                ListNode * afterTemp = temp->next;
                if (beforeTemp != NULL) beforeTemp->next = afterTemp;
                temp->next = afterTemp->next;
                afterTemp->next = temp;
                beforeTemp = temp;
                temp = temp->next;
            }
            return head;
        }
    };

};


#endif //LEETCODE__0024_SWAP_NODES_IN_PAIRS_H
