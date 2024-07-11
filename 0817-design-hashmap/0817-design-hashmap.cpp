class node {
public:
    int key,value;
    node* next;
    node(int key ,int value){
    this->key=key;
    this->value=value;
    this->next=NULL;

    }
};
 
class MyHashMap{
    int N=100,M;
    double l =0.7;
    node** a;
    
    int hashfn(int key){
        int hid =key%N;
        return hid;
    }

    void transfer(node* head){
        node* temp=head;

        while(temp!=NULL){
            put(temp->key,temp->value);
            temp=temp->next;
        }
        while(head!=NULL){
            node* nxt=temp->next;
            delete temp;
            temp=nxt;

        }
    }
    void rehash(){
        node** oldA=a;
        int oldN=N;

        N=2*N;
        node** a= new node*[N];
        for(int i=0;i<oldN/2;i++){
            transfer(oldA[i]);
        }
        delete [] oldA;
    }

public:
    MyHashMap(){
        a=new node* [N];
        for(int i=0;i<N;i++){
            a[i]=NULL;
        }
    }
    
    void put(int key, int value) {
        int hid=hashfn(key);
        node* x=new node(key,value);
        x->next=a[hid];
        a[hid]=x;
        M++;

        //Rehashing
        int lf=(M * 1.0)/N;
        if(lf>l){
            rehash();
        }
    }
    
    int get(int key) {
        int hid =hashfn(key);
        node* head=a[hid];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hid=hashfn(key);
        node* head=a[hid];
        while(head!=NULL and head->key==key){
            node* temp=head->next;
            delete head;
            M--;
            head=temp;
            a[hid]=head;
        }
        node* prev=NULL;
        node* temp=head;
        while(temp!=NULL){
            if(temp->key==key){
                prev->next=temp->next;
                delete temp;
                temp=prev->next;
                M--;
            }else{
                prev=temp;
                temp=temp->next;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */