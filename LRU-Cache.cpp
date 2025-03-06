class LRUCache {
public:
    class node{
        public:
        int key,val;
        node*next;
        node*prev;

        node(int k,int v){
            key=k;
            val=v;
        }
    };

    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    unordered_map<int,node*>mpp;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node *newnode){
        node *temp;
        temp=head->next;
        head->next=newnode;
        newnode->next=temp;
        newnode->prev=head;
        temp->prev=newnode;
    }

    void deletenode(node *delnode){
        node* prevdel=delnode->prev;
        node* nextdel=delnode->next;

        prevdel->next=nextdel;
        nextdel->prev=prevdel;
    }
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            node*resnode=mpp[key];
            int res=resnode->val;
            mpp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mpp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            node*existingnode=mpp[key];
            deletenode(existingnode);
            mpp.erase(key);
        }
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */