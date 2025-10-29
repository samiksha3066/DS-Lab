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
bool check(Node* head){
    if(head==NULL) return false;
    Node* temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    return (temp==head);

}
int main(){
    Node* a=new Node(2);
    Node* b=new Node(4);
    Node* c=new Node(6);
    Node* d=new Node(7);
    Node* e=new Node(5);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=a;
    if(check(a)) cout<<"The list is circular"<<endl;
    else cout<<"The list is not circular!"<<endl;
    return 0;
}