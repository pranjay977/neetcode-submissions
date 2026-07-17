typedef struct Trie
{
int wc;
int pc;
struct Trie *arr[26];
bool flag;
}Node;
Node *root;
Node *getNode()
{
Node *t=new Node;
for(int i=0;i<26;i++) t->arr[i]=NULL;
t->wc=0;
t->pc=0;
t->flag=false;
return t;
}
void insert(string str)
{
Node *t=root;
for(char c:str)
{
int index=c-'a';
if(t->arr[index]==NULL) 
{
t->arr[index]=getNode();
}
t->pc++;
t=t->arr[index];
}
t->wc++;
t->flag=true;
}
bool search(string str)
{
Node *t=root;
for(char c:str)
{
int index=c-'a';
if(t->arr[index]==NULL) return false;
t=t->arr[index];
}
return t->flag;
}



int n,m;
vector<string> ans;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
vector<vector<int>> vis;
void solve(vector<vector<char>> &board,int r,int c,Node *rr,string str)
{
if(rr->wc>0)
{
ans.push_back(str);
rr->wc=0;
}
vis[r][c]=1;
for(int i=0;i<4;++i)
{
int nr=dr[i]+r;
int nc=dc[i]+c;
if(nr<0 || nc<0 || nr>=n || nc>=m || vis[nr][nc]==1) continue;
int index=board[nr][nc]-'a';
if(rr->arr[index]!=NULL)
{
solve(board,nr,nc,rr->arr[index],str+board[nr][nc]);
}
}
vis[r][c]=0;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root=getNode();
        n=board.size();
        m=board[0].size();
        vis.clear();
        vis.assign(n,vector<int>(m,0));
        ans.clear();
        for(string str:words) insert(str);
        for(int i=0;i<n;++i)
        {
        for(int j=0;j<m;++j)
        {
        int index=board[i][j]-'a';
        if(root->arr[index]) solve(board,i,j,root->arr[index],string("")+board[i][j]);
        }
        }
    return ans;
    }
};
