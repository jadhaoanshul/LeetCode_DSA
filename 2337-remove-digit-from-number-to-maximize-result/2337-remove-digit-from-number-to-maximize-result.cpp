class Solution {
public:
    string removeDigit(string number, char digit) {
        number += '0';
        string s = "";
        bool b = 0;
        int j;
        for (j = number.size() - 1; j >= 0; j--) 
            if (number[j] == digit) break;
        for (int i = 0; i < number.size() - 1; i++)
            if (number[i] == digit && (number[i] - '0') < (number[i + 1] - '0') && b == 0 || b == 0 && i == j) b = 1;
            else s += number[i];
        return s;
    }
};