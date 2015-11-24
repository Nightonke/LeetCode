//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0015_3SUM_H
#define LEETCODE__0015_3SUM_H


class _0015_3Sum {

    class Solution {
    public:

        int search(vector<int> & num, int target, int l, int r) {
            while (l <= r) {
                int m = (l + r) / 2;
                if (num[m] == target) return m;
                else if (num[m] < target) l = m + 1;
                else r = m - 1;
            }
            return -1;
        }

        vector<vector<int> > threeSum(vector<int> &num) {
            vector<vector<int> > ans;
            sort(num.begin(), num.end());
            int lastI, lastJ, lastK;
            lastI = lastJ = lastK = 123456789;  // to judge the duplicate triplets
            for (int i = 0; i < num.size(); i++) {
                if (i >= 1 && num[i] == num[i - 1]) continue;
                for (int j = i + 1; j < num.size(); j++) {
                    int pos = search(num, 0 - num[i] - num[j], j + 1, num.size() - 1);  // search the third data
                    if (pos != -1) {
                        if (num[i] == lastI && num[j] == lastJ && num[pos] == lastK) continue;
                        vector<int> a;
                        a.push_back(num[i]);
                        a.push_back(num[j]);
                        a.push_back(num[pos]);
                        ans.push_back(a);
                        lastI = num[i];
                        lastJ = num[j];
                        lastK = num[pos];
                    }
                }
            }
            return ans;
        }
    };

};


#endif //LEETCODE__0015_3SUM_H
