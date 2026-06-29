bool isOperand(string &e)
{
if(e=="+") return true;
if(e=="-") return true;
if(e=="*") return true;
if(e=="/") return true;
return false;
}
int solve(int left,int right,string &e)
{
if(e=="+") return left+right;
if(e=="-") return left-right;
if(e=="*") return left*right;
if(e=="/") return left/right;
return 0;
}
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     stack<int> stck;
     for(auto e:tokens)
     {
        if(isOperand(e)) 
        {
        int right=stck.top();
        stck.pop();
        int left=stck.top();
        stck.pop();
        stck.push(solve(left,right,e));
        } 
        else stck.push(atoi(e.c_str()));
     }   
     return stck.top();
    }
};
