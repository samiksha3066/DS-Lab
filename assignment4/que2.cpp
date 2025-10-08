#include<iostream>
using namespace std;
#define size 6
class Queue{
    int front;
    int queue[size];
    int rear;
    public:
    Queue(){
        front=rear=-1;
    }

    bool isEmpty(){
        return ((front==rear) && (rear==-1));
    }
    bool isFull(){
        return (front==(rear+1)%size);
    }
    void enqueue(int item){
        if(isFull()) {
            cout<<"Queue is full!"<<endl;
            return;
        }
        if(isEmpty()){
            front=0;
        }
        rear=(rear+1) % size;
        queue[rear]=item;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return;
        }
        int value = queue[front];
        if(front==rear){
            front=rear=-1;
        }
        else front=(front+1) % size;
        cout<<"Dequeued: "<<value<<endl;
    }
    void peek(){
        if(isEmpty()){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        cout<<"Front element is : "<<queue[front]<<endl;
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is Empty!!";
            return;
        }
        cout<<"The elements of queue are: ";
        int i=front;
        while(true){
            cout<<queue[i]<<" ";
            if(i==rear) break;
            i=(i+1)%size;
        }
        cout<<endl;
    }
};
int main(){
    Queue q;
    int choice,item;
    do{
        cout<<"-----Queue Operations-----"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. To check if queue is empty"<<endl;
        cout<<"5. To check if queue is full"<<endl;
        cout<<"6. Displaying the queue"<<endl;
        cout<<"0. exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter item to enqueue : ";
            cin>>item;
            q.enqueue(item);
            break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                if (q.isEmpty())
                    cout << "Queue is Empty."<<endl;
                else
                    cout << "Queue is Not Empty.\n";
                break;
            case 5:
                if (q.isFull())
                    cout << "Queue is Full."<<endl;
                else
                    cout << "Queue is Not Full."<<endl;
                break;
            case 6:
                q.display();
                break;
            case 7:
                cout << "Exiting program."<<endl;
                break;
            default:
                cout << "Invalid choice! Please enter between 1 and 7."<<endl;
        }

    }while(choice != 7);

    return 0;
}
