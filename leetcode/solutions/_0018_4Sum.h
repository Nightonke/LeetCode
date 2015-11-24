//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0018_4SUM_H
#define LEETCODE__0018_4SUM_H


class _0018_4Sum {

    struct S2 {
        int sum, p1, p2;
        S2(int sum = 0, int p1 = 0, int p2 = 0) {
            this->sum = sum;
            this->p1 = p1;
            this->p2 = p2;
        }
    };

    bool cmp(const S2 & s1, const S2 & s2) {
        return s1.sum < s2.sum;
    }

    class Solution {
    public:
        vector<S2> sum2;
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int> > ans;
            if (num.size() < 4) return ans;
            set<vector<int> > exist;
            sum2.clear();
            int s = num.size();
            for (int i = 0; i < s; i++) {
                for (int j = i + 1; j < s; j++) {
                    sum2.push_back(S2(num[i] + num[j], i, j));
                }
            }
            sort(sum2.begin(), sum2.end(), cmp);
            int ss = sum2.size();
            for (int i = 0; i < ss; i++) {
                int t = target - sum2[i].sum;
                int pos = BSearch(0, ss - 1, t);
                if (pos == -1) continue;
                while (pos < ss && sum2[pos].sum == t) {
                    if (pos != i && (sum2[pos].p1 != sum2[i].p1 && sum2[pos].p1 != sum2[i].p2 && sum2[pos].p2 != sum2[i].p1 && sum2[pos].p2 != sum2[i].p2)) {
                        vector<int> in;
                        in.push_back(num[sum2[i].p1]);
                        in.push_back(num[sum2[i].p2]);
                        in.push_back(num[sum2[pos].p1]);
                        in.push_back(num[sum2[pos].p2]);
                        sort(in.begin(), in.end());
                        if (exist.find(in) == exist.end()) {
                            exist.insert(in);
                            ans.push_back(in);
                        }
                    }
                    pos++;
                }
            }
            return ans;
        }
        int BSearch(int l, int r, int target) {
            if (sum2.size() == 0) return -1;
            while (l < r) {
                int m = l + ((r - l) >> 1);
                if (sum2[m].sum < target) l = m + 1;
                else r = m;
            }
            if (sum2[l].sum == target) return l;
            else return -1;
        }
    };

};


#endif //LEETCODE__0018_4SUM_H
