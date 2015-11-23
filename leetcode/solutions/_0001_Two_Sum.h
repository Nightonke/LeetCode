//
// Created by 伟平 on 2015/11/23.
//

#ifndef LEETCODE__0001_TWO_SUM_H
#define LEETCODE__0001_TWO_SUM_H


class _0001_Two_Sum {

    class Solution {
    public:
        vector<int> twoSum(vector<int> & nums, int target) {
            unordered_map<int, int> m;
            int size = nums.size();
            for (int i = 0; i < size; i++) {
                unordered_map<int, int>::iterator j = m.find(target - nums[i]);
                if (j != m.end()) {
                    vector<int> answer;
                    answer.push_back(j->second + 1);
                    answer.push_back(i + 1);
                    return answer;
                }
                else {
                    m[nums[i]] = i;
                }
            }
        }
    };

};


#endif //LEETCODE__0001_TWO_SUM_H
