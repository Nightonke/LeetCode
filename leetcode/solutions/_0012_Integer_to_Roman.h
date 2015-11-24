//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0012_INTEGER_TO_ROMAN_H
#define LEETCODE__0012_INTEGER_TO_ROMAN_H


class _0012_Integer_to_Roman {

    class Solution {
    public:
        string intToRoman(int num) {
            vector<string> R;
            R.push_back("");  // 0
            R.push_back("I");  // 1
            R.push_back("II");  // 2
            R.push_back("III");  // 3
            R.push_back("IV");  // 4
            R.push_back("V");  // 5
            R.push_back("VI");  // 6
            R.push_back("VII");  // 7
            R.push_back("VIII");  // 8
            R.push_back("IX");  // 9
            R.push_back("");  // 0
            R.push_back("X");  // 10
            R.push_back("XX");  // 20
            R.push_back("XXX");  // 30
            R.push_back("XL");  // 40
            R.push_back("L");  // 50
            R.push_back("LX");  // 60
            R.push_back("LXX");  // 70
            R.push_back("LXXX");  // 80
            R.push_back("XC");  // 90
            R.push_back("");  // 0
            R.push_back("C");  // 100
            R.push_back("CC");  // 200
            R.push_back("CCC");  // 300
            R.push_back("CD");  // 400
            R.push_back("D");  // 500
            R.push_back("DC");  // 600
            R.push_back("DCC");  // 700
            R.push_back("DCCC");  // 800
            R.push_back("CM");  // 900
            R.push_back("");  // 0
            R.push_back("M");  // 1000
            R.push_back("MM");  // 2000
            R.push_back("MMM");  // 3000
            string ans;
            ans += R[(num % 10000) / 1000 + 30];  // for N000
            ans += R[(num % 1000) / 100 + 20];  // for N00
            ans += R[(num % 100) / 10 + 10];  // for N0
            ans += R[(num % 10) / 1 + 0];  // for N
            return ans;
        }
    };

};


#endif //LEETCODE__0012_INTEGER_TO_ROMAN_H
