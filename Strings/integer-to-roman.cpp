// https://www.interviewbit.com/problems/integer-to-roman/

string Solution::intToRoman(int A) {
    vector<string> I  = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
    vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
    vector<string> C  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"};
    vector<string> M = {"", "M", "MM", "MMM"};
    
    return M[A / 1000] + C[(A % 1000) / 100] + X[(A % 100) / 10] + I[A % 10];
}
