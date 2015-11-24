//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0060_PERMUTATION_SEQUENCE_H
#define LEETCODE__0060_PERMUTATION_SEQUENCE_H


class _0060_Permutation_Sequence {

    class Solution {
    public:
        string getPermutation(int n, int k) {

            string ans;

            int * a = new int[n];
            for (int i = 0; i < n; i++) a[i] = i + 1;

            int fac = 1;
            for (int i = 2; i < n; i++) fac *= i;
            k--;

            bool * used = new bool[n + 1];
            for (int i = 1; i <= n; i++) used[i] = false;

            for (int i = n - 1; i >= 1; i--) {

                int num = k / fac;
                k %= fac;
                fac /= i;
                int lessNum = 0;
                int nextNum = 1;

                for (; nextNum <= n && lessNum < num; nextNum++) {
                    if (!used[nextNum]) {
                        lessNum++;
                    }
                }
                while (used[nextNum]) nextNum++;

                used[nextNum] = true;
                ans.push_back(nextNum + '0');

            }

            for (int i = 1; i <= n; i++) {
                if (!used[i]) {
                    ans.push_back(i + '0');
                    break;
                }
            }

            return ans;
        }
    };

};


#endif //LEETCODE__0060_PERMUTATION_SEQUENCE_H
