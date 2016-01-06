//
// Created by Weiping Huang on 2015/11/25.
//

#ifndef LEETCODE__0273_INTEGER_TO_ENGLISH_WORDS_H
#define LEETCODE__0273_INTEGER_TO_ENGLISH_WORDS_H


class _0273_Integer_to_English_Words {

    const string threeDigits[5] = { "", " Thousand", " Million", " Billion", " Trillion" };
    const string units[20] = { "", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen" };
    const string tens[10] = { "", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety" };

    class Solution {
    public:
        string numberToWords(int num) {
            if (num == 0) return "Zero";
            string answer = "";
            int threeDigitsCounter = 0;
            while (num) {
                answer = getThreeDigits(num % 1000) + (num % 1000 ? threeDigits[threeDigitsCounter] : "") + answer;
                num /= 1000;
                threeDigitsCounter++;
            }
            return answer.substr(1, answer.length() - 1);
        }
    private:
        string getThreeDigits(int num) {
            if (num == 0) return "";
            string answer = "";
            int hundred = num / 100;
            if (hundred != 0) answer += units[hundred] + " " + "Hundred";
            int ten = num % 100;
            if (ten != 0) {
                if (ten >= 20) {
                    answer += tens[ten / 10] + units[ten % 10];
                }
                else {
                    answer += units[ten];
                }
            }
            return answer;
        }
    };

};


#endif // LEETCODE__0273_INTEGER_TO_ENGLISH_WORDS_H
