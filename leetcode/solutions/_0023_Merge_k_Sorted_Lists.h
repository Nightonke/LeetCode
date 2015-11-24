//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0023_MERGE_K_SORTED_LISTS_H
#define LEETCODE__0023_MERGE_K_SORTED_LISTS_H


class _0023_Merge_k_Sorted_Lists {

    class Solution {
    public:
        ListNode *mergeKLists(vector<ListNode *> & lists) {
            if (lists.size() == 0) return NULL;
            if (lists.size() == 1) return lists[0];
            vector<ListNode * > v;
            for (int i = 0; i < lists.size(); i++) {
                v.push_back(lists[i]);
            }
            int size = lists.size();
            int start = 0;
            while (1) {
                v.push_back(mergeTwoLists(v[start], v[start + 1]));
                size--;
                start += 2;
                if (size == 1) return v[start];
            }
        }
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


#endif //LEETCODE__0023_MERGE_K_SORTED_LISTS_H
