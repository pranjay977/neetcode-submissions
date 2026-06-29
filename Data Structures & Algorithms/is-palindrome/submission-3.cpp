class Solution {
public:
    bool   isPalindrome(string s) {
        string str="";
        for(char c:s)
        {
        if(c>='A' && c<='Z') str+=c+' ';
        if(c>='a' && c<='z') str+=c;
        if(c>='0' && c<='9') str+=c;
        }
        string aa=str;
        reverse(str.begin(),str.end());
        return aa==str;
    }
};
