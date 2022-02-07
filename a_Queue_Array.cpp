#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class Queue{
    private:
    int capacity;
    int front,rear;
    int *ptr;

    public:
    Queue(){
        capacity=0;
        front=-1;
        rear=-1;
        ptr=NULL;
    }

    void createQueue(int cap){
        capacity=cap;
        front=-1;
        rear=-1;
        ptr=new int[cap];
    }

    void Insertion(int data){
        if(ptr==NULL){
            cout<<"\n Invalid Operation ";
        }
        else if(front==0 && rear==capacity-1 || rear+1==front){ // when queue is full
            cout<<"\n Overflow or Queue if Full";
        }

        else if(rear+1==capacity){  // when rear is at lastindex but front is not at 0
            rear=0;
            ptr[rear]=data;
        }
        else{
            rear++;
            ptr[rear]=data;
        }
    }

    void Deletion(){
        if(ptr==NULL){
            cout<<"\n Queue does not exits or Invalid Operation ";
        }
        else if(rear==-1){
            cout<<"\n Empty Queue !";
        }
        else if(front==rear){ // when queue having only one item in it
             front=-1;
             rear=-1;
             // delete  []ptr; --> no need of this
        }
        else if(front==capacity-1){
            front=0;
        }
        else{
            front++;
        }
    }

    int frontElementView(){
        if(rear==-1){
               cout<<"\n UnderFlow ! ";
        }
        return ptr[front]; 
    }

     int RearElementView(){
        if(rear==-1){
               cout<<"\n UnderFlow ! ";
        }
        return ptr[rear]; 
    }

    ~Queue(){
        while(front!=-1){
            Deletion();
        }
    }
};

int driver(){
    int choice;
    cout<<"\n OPERATIONS : ";
    cout<<"\n 1.Create a queue ";
    cout<<"\n 2.Insertion ";
    cout<<"\n 3. Deletion";
    cout<<"\n 4. To view Front Element in Queue";
    cout<<"\n 5. To view Last Element in Queue";
    cout<<"\n Press 0 for exit ";
    cout<<"\n Please Enter your choice : ";
    cin>>choice;
    return choice;
}

int main(){
    int capacity,data;
    Queue obj;
    while(1){
        switch (driver())
        {
        case 1:
            cout<<"\n Enter capacity : ";
            cin>>capacity;
            obj.createQueue(capacity);
            break;

        case 2:
        cout<<"\n Enter data : ";
        cin>>data;
        obj.Insertion(data);
        break;

        case 3:
        obj.Deletion();
        break;

        case 4:
        cout<<obj.frontElementView();    
        break;

        case 5:
        cout<<obj.RearElementView();
        break;

        case 0:
        exit(0);
        break;

        
        default:
        cout<<"Please enter valid choice ,thank you !";
            break;
        }
    }
    return 0;
}