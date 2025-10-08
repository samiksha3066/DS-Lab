#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head=NULL;
    }
    void insertAtEnd(int val){
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
    int countOccurances(int key){
        int count = 0;
        Node* temp = head;
        while(temp!=NULL){
            if(temp->val == key){
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
    void deleteOccurances(int key){
        while(head!=NULL && head->val==key){
            Node* todelete = head;
            head = head->next;
            delete todelete;
        }
        Node* current = head;
        Node* prev = NULL;
        while(current!=NULL){
            if(current->val == key){
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else{
                prev = current;
                current = current->next;
            }
        }
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(20);
    ll.insertAtEnd(50);
    ll.insertAtEnd(20);
    cout<<"The original linked list is: ";
    ll.display();

    int key = 20;

    int occurances = ll.countOccurances(key);
    cout<<"The number of occurances of "<<key<<" are : "<<occurances<<endl;
    
    ll.deleteOccurances(key);
    cout<<"The updated list is : ";
    ll.display();

    return 0;
}