//
// Created by 伟平 on 2015/11/25.
//

#ifndef LEETCODE__0068_TEXT_JUSTIFICATION_H
#define LEETCODE__0068_TEXT_JUSTIFICATION_H


class _0068_Text_Justification {

    class Solution {
        //try insert as many as words in a line(here a line means a L string of an element of the vector)
        //insert blank to the line
    public:
        vector<string> fullJustify(vector<string> &words, int L) {

            vector<string> ans;
            vector<string> a_line;
            int pos = 0;

            while (pos < words.size()) {

                a_line.clear();
                a_line.push_back(words[pos]);
                int word_num = 1;
                int sum_word_length = words[pos].size();
                int sum_line_length = words[pos++].size();
                while (1) {
                    if ((pos >= words.size()) || (sum_line_length + words[pos].size() + 1 > L)) {
                        break;
                    } else {
                        word_num++;
                        sum_word_length += words[pos].size();
                        sum_line_length += words[pos].size() + 1;
                        a_line.push_back(words[pos++]);
                    }
                }

                if (pos == words.size()) {
                    string line_str = a_line[0];
                    for (int i = 1; i < a_line.size(); i++) {
                        line_str += " " + a_line[i];
                    }
                    for (int i = line_str.size(); i < L; i++) {
                        line_str += " ";
                    }
                    ans.push_back(line_str);
                    break;
                }

                string line_str = a_line[0];
                string blank;
                int evenly_blank_num;
                int remind_blank_num;
                if (word_num == 1) {
                    for (int i = line_str.size(); i < L; i++) {
                        line_str += " ";
                    }
                } else {
                    evenly_blank_num = (L - sum_word_length) / (word_num - 1);
                    remind_blank_num = (L - sum_word_length) % (word_num - 1);
                    for (int i = 0; i < evenly_blank_num; i++) {
                        blank += " ";
                    }
                    for (int i = 1; i < a_line.size(); i++) {
                        line_str += blank;
                        if (remind_blank_num) {
                            line_str += " ";
                            remind_blank_num--;
                        }
                        line_str += a_line[i];
                    }
                }
                ans.push_back(line_str);
            }
            return ans;
        }
    };

};


#endif //LEETCODE__0068_TEXT_JUSTIFICATION_H
