#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next= NULL;
    }
};
class LinkedList{
    Node* head;
    Node* tail;
    int size;
    public:
    LinkedList(){
        head=tail=NULL;
        size=0;
    }
    //(a)
    void insertAtBeginning(int val){
        Node* newNode = new Node(val);
        if(size==0) {
            head=newNode;
            size++;
            return;
        }
        else{
            newNode->next=head;
            head=newNode;
        }
        size++;
    }
    //(b)
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(size==0) {
            head=newNode;
            size++;
            return;
        }
        else{
            tail->next = newNode;
            tail=newNode;
        }
        size++;
    }
    //(c)
    void insertRelative(int target , int value , bool before = true){
        if(size==0){
            cout<<"List is empty!!"<<endl;
            return;
        }
        if(before){
            if(head->val == target){
                insertAtBeginning(value);
            }
            Node* prev = NULL;
            Node* curr = head;
            while(curr!=NULL && curr->val!=target){
                prev = curr;
                curr = curr->next;
            }
            if(curr==NULL){
                cout<<"Target not found"<<endl;
                return;
            }
            Node* newNode = new Node(value);
            newNode->next=curr->next;
            prev->next=newNode;
        }
        else{
            Node* curr = head;
            while(curr!=NULL && curr->val!=target){
                curr = curr->next;
            }
            if(curr == NULL){
                cout<<"target not found!!"<<endl;
                return;
            }
            Node* newNode = new Node(value);
            newNode->next = curr->next->next;
            curr->next =newNode;
        }
    }
    //(d)
    void deleteAtBeginning(){
        if(size==0){
            cout<<"List is empty!!"<<endl;
            return;
        }
        Node* temp = head;
        if(size==1) {
            head=tail=NULL;
        }
        if(size>1) {
            head=head->next;
        }
        delete temp;
        size--;
    }
    //(e)
    void deleteAtEnd(){
        if(size==0) {
            cout<<"List is empty!!"<<endl;
            return;
        }
        Node* temp = head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
        delete temp->next;
        size--;
    }
    //(f)
    void deleteNode(int data){
        if(size==0) {
            cout<<"List is empty!!"<<endl;
            return;
        }
        if(head->val==data){
            Node* temp = head;
            head=head->next;
            delete temp;
            size--;
            return;
        }
        Node* prev = NULL;
        Node* curr = head;
        while(curr!=NULL && curr->val!=data){
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL){
            cout<<"Node not found!!!"<<endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
        size--;
    }
    //(g)
    void search(int value){
        Node* temp = head;
        int pos = 1;
        while(temp!=NULL){
            if(temp->val == value){
                cout<<"Node found at position: "<<pos<<endl;
                return;
            }
            temp=temp->next;
            pos++;
        }
        cout<<"Node not found!!"<<endl;
    }
    //(h)
    void display(){
        if(size==0){
            cout<<"list is empty!!"<<endl;
            return;
        }
        Node* temp = head;
        cout<<"The linked list is :"<<endl;
        while(temp!=NULL){
            cout<<temp->val<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }

};
int main(){
    LinkedList ll;
    int choice,value,target;
    bool before;
    do{
        cout<<"-----MENU-----"<<endl;
        cout << "1. Insert at beginning"<<endl;
        cout << "2. Insert at end"<<endl;
        cout << "3. Insert before a node"<<endl;
        cout << "4. Insert after a node"<<endl;
        cout << "5. Delete from beginning"<<endl;
        cout << "6. Delete from end"<<endl;
        cout << "7. Delete specific node"<<endl;
        cout << "8. Search node"<<endl;
        cout << "9. Display list"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout<<"Enter value to insert at beginning : ";
                cin>>value;
                ll.insertAtBeginning(value);
                break;
            case 2:
                cout<<"Enter the value to insert at end: ";
                cin>>value;
                ll.insertAtEnd(value);
                break;
            case 3:
                cout<<"Enter target node value: ";
                cin>>target;
                cout<<"Enter value to insert before "<<target << ": ";
                cin>>value;
                ll.insertRelative(target, value, true);
                break;
            case 4:
                cout<<"Enter target Node: ";
                cin >>target;
                cout<<"Enter value to insert after: ";
                cin>>value;
                ll.insertRelative(target , value , false);
                break;
            case 5:
                ll.deleteAtBeginning();
                break;
            case 6:
                ll.deleteAtEnd();
                break;
            case 7:
                cout<<"Enter value to delete: ";
                cin>>value;
                ll.deleteNode(value);
                break;
            case 8:
                cout<<"enter the value to search : ";
                cin>>value;
                ll.search(value);
                break;
            case 9:
                ll.display();
                break;
            case 0:
                cout<<"Exiting program"<<endl;
                break;
            default:
                cout<<"Invalid choice "<<endl;
        }
    }while(choice!=0);

    return 0;
}