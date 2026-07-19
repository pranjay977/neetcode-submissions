class Node
{
public:
Node *next,*prev;
int val;
int key;
Node(int key,int val)
{
this->val=val;
this->key=key;
this->next=NULL;
this->prev=NULL;
}
};


class LRUCache {
public:
	map<int,Node *> mp;
	Node *start;
	Node *end;
    int cap;
    LRUCache(int capacity) {
        start=NULL;
		end=NULL;
		this->cap=capacity;
    }
    void replace(int key)
    {
		Node *n=mp[key];
		if(start==end || n==end) return;
        if(n==start)
        {
        start=start->next;
        start->prev=NULL;
		}
        else
        {
		Node *prev=n->prev;
		Node *next=n->next;
        if(prev) prev->next=next;
		if(next) next->prev=prev;
        }
        end->next=n;
        n->prev=end;
		end=n;
        end->next=NULL;
    }    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        replace(key);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
        mp[key]->val=value;
        replace(key);
        return;
        }		
        if(this->cap==0)
		{
        // for(Node *t=start;t;t=t->next) cout<<t->key<<" ";
        // cout<<endl;
		int kk=start->key;
		mp.erase(kk);
		start=start->next;
        this->cap++;
		}
		Node *newNode=new Node(key,value);
		mp[key]=newNode;
		if(start==NULL) start=end=newNode;
		else
		{
        newNode->prev=end;
		end->next=newNode;
		end=newNode;
		}
        cout<<"add:"<<start->key<<" "<<end->key<<endl;
		this->cap--;
	   
    }
};
