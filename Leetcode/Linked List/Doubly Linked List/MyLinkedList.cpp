// https://leetcode.com/explore/learn/card/linked-list/210/doubly-linked-list/1294/

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct Node{
        int data;
        Node* next;
        Node* prev;
        Node(){
            next = NULL;
            prev = NULL;
        }
        Node(int x){
            data = x;
            next = NULL;
            prev = NULL;
        }
    };
    Node* head;
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(!head)
            return -1;
        Node* curr = head;
        while(index--)
            curr = curr -> next;
        if(!curr && index>0)
            return -1;
        if(!curr)
            return -1;
        return curr->data;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(!head){
            head = new Node(val);
            return;
        }
        Node* temp = new Node(val);
        temp -> next =head;
        head -> prev = temp;
        head = temp;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(!head){
            head = new Node(val);
            return;
        }
        Node *curr = head;
        while(curr->next){
            curr = curr-> next;
        }
        Node* temp = new Node(val);
        curr -> next = temp;
        temp -> prev = curr;
        return;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(!head){
            head = new Node(val);
            return;
        }
        if(index == 0){
            addAtHead(val);
            return;
        }
        Node* curr = head;
        while(--index)
            curr = curr -> next;
        if(!curr && index>0)
            return;
        if(!curr->next){
            addAtTail(val);
            return;
        }
        Node* temp= new Node(val);
        temp -> next = curr -> next;
        temp -> next ->prev = temp;
        temp ->prev = curr;
        curr->next = temp;   
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0) return;
        if(index ==0){
            if(!head)return;
            head = head -> next;
            return;
        }
        Node* curr = head;
        while(--index){
            curr = curr -> next;
        }
        if(!curr && index>0)
            return;
        if(curr->next == NULL)
            return;
        Node *temp = curr->next;
        curr-> next = temp->next;
        if(temp -> next != NULL)
            temp->next->prev = curr;
        delete temp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
