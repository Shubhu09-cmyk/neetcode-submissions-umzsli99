


class LRUCache {
public:
    class Node{
        public:
        int key,val;
        Node* prev;
        Node* next;

       
         Node(int k,int v){
            key=k;
            val=v;
            prev=next=nullptr;
         }


    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    unordered_map<int,Node*> mp;

    void add(Node* newNode){
        Node* oldNext=head->next;

        head->next=newNode;
        oldNext->prev=newNode;

        newNode->next=oldNext;
        newNode->prev=head;
    }

    void del(Node* oldNode){
        Node* oldPrev=oldNode->prev;
        Node* oldNext=oldNode->next;

        oldPrev->next=oldNext;
        oldNext->prev=oldPrev;
    }

    int limit;
    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    
    int get(int key) {
        //if key not in map
        if(!mp.count(key)){
            return -1;
        }
        Node* ansNode=mp[key];
        int ans=ansNode->val;

        
        del(ansNode);
        add(ansNode);
        mp[key]=ansNode;

        

        return ans;
    }
    
    void put(int key, int value) {

        //if key of map is duplicate
        if(mp.count(key)){
            Node* oldNode=mp[key];
            del(oldNode);
            mp.erase(key);
            delete oldNode;
        }

        //if size ==capacity
        if(mp.size()==limit){
                        
                        Node* lru=tail->prev;
            del(lru);
                        mp.erase(lru->key);

            delete lru;
            
        }
        Node* newNode= new Node(key,value);
        add(newNode);
        mp[key]=newNode;
        
    }
};
