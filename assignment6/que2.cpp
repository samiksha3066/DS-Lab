#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
void display(Node* head){
    Node* temp=head;
    if(head==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    do{
        cout<<temp->val<<"->";
        temp=temp->next;
    }while(temp!=head);
    cout<<head->val<<endl;
}
int main(){
    Node* a=new Node(20);
    Node* b=new Node(100);
    Node* c=new Node(40);
    Node* d=new Node(80);
    Node* e=new Node(60);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=a;
    display(a);
    return 0;
}
