//
// Created by Weiping Huang on 2015/11/25.
//

#ifndef LEETCODE__0268_MISSING_NUMBER_H
#define LEETCODE__0268_MISSING_NUMBER_H


class _0268_Missing_Number {

    class Solution {
    public:
        int missingNumber(vector<int> & nums) {
            int XOR = 0;
            XOR ^= nums.size();
            for (int i = nums.size() - 1; i >= 0; i--) {
                XOR ^= nums[i];  // XOR ^ nums[0, 1, 2, ... n - 1]
                XOR ^= i;  // XOR ^ 0, 1, 2, ... n
            }
            return XOR;
        }
    };

};


#endif // LEETCODE__0268_MISSING_NUMBER_H
