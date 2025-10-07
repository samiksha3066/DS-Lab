#include<iostream>
using namespace std;
#define maxlength 100
class Queue{
    int front;
    int queue[maxlength];
    int capacity;
    int rear;
    public:
    Queue(int size){
        capacity=size;
        front=rear=-1;
    }

    bool isEmpty(){
        return (front==-1 || front>rear);
    }
    bool isFull(){
        return (rear==capacity-1);
    }
    void enqueue(int item){
        if(isFull()) {
            cout<<"Queue is full!";
            return;
        }
        if(isEmpty()){
            front=0;
        }
        rear++;
        queue[rear]=item;
        //cout<<"Enqueued item : "<<item<<endl;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty!";
            return;
        }
        //cout<<"Dequeued: "<<queue[front]<<endl;
        front++;
    }
    void peek(){
        if(isEmpty()){
            cout<<"Queue is empty!";
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
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    int size;
    cout<<"Enter the size of queue: ";
    cin>>size;
    if(size>maxlength){
        cout<<"Size exceeds the limit of "<<maxlength;
        return 1;
    }
    Queue q(size);
    int choice,item;
    do{
        cout<<"-----Queue Operations-----"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. To check if queue is empty"<<endl;
        cout<<"5. To check if queue is full"<<endl;
        cout<<"6. Displaying the queue"<<endl;
        cout<<"7. exit"<<endl;

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