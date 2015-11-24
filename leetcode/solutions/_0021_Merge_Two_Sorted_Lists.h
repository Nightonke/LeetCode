//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0021_MERGE_TWO_SORTED_LISTS_H
#define LEETCODE__0021_MERGE_TWO_SORTED_LISTS_H


class _0021_Merge_Two_Sorted_Lists {

    class Solution {
    public:
        ListNode * mergeTwoLists(ListNode *l1, ListNode *l2) {
            if (l1 == NULL) {
                return l2;
            }
            if (l2 == NULL) {
                return l1;
            }
            if (l1->val < l2->val) {
                ListNode * head = new ListNode(l1->val);
                head->next = mergeTwoLists(l1->next, l2);
                return head;
            } else {
                ListNode * head = new ListNode(l2->val);
                head->next = mergeTwoLists(l1, l2->next);
                return head;
            }
        }
    };

};


#endif //LEETCODE__0021_MERGE_TWO_SORTED_LISTS_H
