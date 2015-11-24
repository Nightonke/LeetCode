//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0025_REVERSE_NODES_IN_K_GROUP_H
#define LEETCODE__0025_REVERSE_NODES_IN_K_GROUP_H


class _0025_Reverse_Nodes_in_k_Group {

    class Solution {
    public:
        ListNode *reverseKGroup(ListNode *head, int k) {
            if (head == NULL || k < 2) return head;
            ListNode * originalHead = head;
            ListNode * lastTail = NULL;
            while (1) {
                int counter = 1;
                ListNode * temp = originalHead;
                while (temp && counter < k) {
                    counter++;
                    temp = temp->next;
                }
                if (counter == k && temp) {
                    ListNode * subHead = originalHead;
                    ListNode * nextNode = (subHead ? subHead->next : NULL);
                    ListNode * nextNext = (nextNode ? nextNode->next : NULL);
                    int times = k - 1;
                    while (times--) {
                        nextNode->next = subHead;
                        subHead = nextNode;
                        nextNode = nextNext;
                        nextNext = (nextNode ? nextNode->next : NULL);
                    }
                    if (lastTail == NULL) {
                        head = subHead;
                        lastTail = originalHead;
                    } else {
                        lastTail->next = subHead;
                        lastTail = originalHead;
                    }
                    originalHead->next = nextNode;
                    originalHead = originalHead->next;
                } else {
                    break;
                }
            }
            return head;
        }
    };

};


#endif //LEETCODE__0025_REVERSE_NODES_IN_K_GROUP_H
