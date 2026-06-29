class WordDictionary {
public:
class Node
{
public:
Node *arr[26];
int pc;
bool flag;
Node()
{
for(int i=0;i<26;i++) this->arr[i]=NULL;
this->pc=0;
this->flag=false;
}
};
	Node *root;

    WordDictionary() {
        root=new Node();
    }
bool dfs(Node *node,string word,int ii)
{
Node *t=node;
for(int i=ii;i<word.size();i++)
{
int index=word[i]-'a';
if(word[i]=='.') 
{
bool found=false;
for(int j=0;j<26;j++)
{
if(t->arr[j]!=NULL && dfs(t->arr[j],word,i+1))  return true;
}
return false;
}
else
{
if(t->arr[index]==NULL) return false;
t=t->arr[index];
}
}
return t->flag;
}

void addWord(string word) {
Node *t=root;
for(char c:word)
{
int index=c-'a';
if(t->arr[index]==NULL) t->arr[index]=new Node();
t=t->arr[index];
t->pc++;
}
t->flag=true;
}

bool search(string word) {
return dfs(root,word,0);
}
};
