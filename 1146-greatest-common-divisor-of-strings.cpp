class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1){
            return "";
        }
        string output = "";
        int len = __gcd(str1.size(), str2.size());
        for(int i = 0; i < len; i++){
            output += str1[i];
        }
        return output;
    }
};