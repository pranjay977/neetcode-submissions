#include<stdlib.h>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr) {
map<int,set<int>> rmp;  // row map
map<int,set<int>> cmp;	// col map
map<int,set<int>> bmp;	// box map (3 X 3) 
for(int i=0;i<arr.size();++i)
{
for(int j=0;j<arr[0].size();++j)
{
if(arr[i][j]=='.') continue;
if(rmp[i].insert(arr[i][j]-'0').second==false) return false;
if(cmp[j].insert(arr[i][j]-'0').second==false) return false;
if(bmp[((i/3)*3)+(j/3)].insert(arr[i][j]-'0').second==false) return false;
}
}
return true;
}
};



// 6,0
// 6*3+0=18/3=6;