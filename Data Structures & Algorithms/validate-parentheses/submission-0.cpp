class Solution {
public:
    bool isValid(string s) {
    stack<char> stck;
    for(char c:s)
    {
    if(c=='(' || c=='[' || c=='{') stck.push(c);
    else
    {
    if(c==')' && (stck.empty() || stck.top()!='(')) return false;
    if(c==']' && (stck.empty() || stck.top()!='[')) return false;
    if(c=='}' && (stck.empty() || stck.top()!='{')) return false;
    stck.pop();
    }
    }
    return stck.empty();        
    }
};
