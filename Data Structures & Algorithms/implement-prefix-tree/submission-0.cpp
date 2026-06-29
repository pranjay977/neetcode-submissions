class PrefixTree {
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

    PrefixTree() {
        root=new Node();
    }
    
    void insert(string word) {
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
Node *t=root;
for(char c:word)
{
int index=c-'a';
if(t->arr[index]==NULL) return false;
t=t->arr[index];
}        
return t->flag;
}
    
    bool startsWith(string prefix) {
	Node *t=root;
for(char c:prefix)
{
int index=c-'a';
if(t->arr[index]==NULL) return false;
t=t->arr[index];
}        
return true;
}
};
