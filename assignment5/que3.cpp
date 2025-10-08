#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next = NULL;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head=NULL;
    }
    void insertAEnd(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
            temp->next = newNode;
    }

    Node* findMiddle(){
        if(head==NULL){
            cout<<"List is empty!!";
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" -> ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    LinkedList ll;
    ll.insertAEnd(10);
    ll.insertAEnd(20);
    ll.insertAEnd(30);
    ll.insertAEnd(40);
    ll.insertAEnd(50);

    cout<<"The linked list is : ";
    ll.display();
    Node* temp;
    temp=ll.findMiddle();
    cout<<"The middle node is : "<<temp->val;

    return 0;
}