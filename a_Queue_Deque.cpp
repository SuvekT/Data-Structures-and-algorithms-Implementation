#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
 //using array
class Deque{
    private:
    int capacity;
    int *ptr;
    int rear,front;

    public:
    Deque(){
        capacity=0;
        rear=-1;
        front=-1;
        ptr=NULL;
    }

    void CreateDeque(int cap){
        capacity=cap;
        ptr=new int[cap];
    }

    void Insertatrear(int data){
        if(ptr==NULL){
            cout<<"\n Array does not exists ! ";
        }
        else if(front==0 && rear+1==capacity || rear+1==front){
            cout<<"\n Overflow ";
        }
        else if(rear==-1){ // for empty queue
           rear=0;
           ptr[rear]=data;
        }
        else{
            rear++;
            ptr[rear]=data;
        }
    }

    void Insertatfront(int data){
        if(ptr==NULL){
            cout<<"\n Deque does not exists !";
        }
        else if(front==0 && rear+1==capacity || rear+1==front){
            cout<<"\n Overflow !";
        }
        else if(rear==-1){
            rear=0;
            front=0;
            ptr[front]=data;
        }
        else{
           for(int i=rear;i>=front;i--){
               ptr[i+1]=ptr[i];
           }
           ptr[front]=data;
           rear++;
        }
    }

    void deletionatfront(){
        if(ptr==NULL){
            cout<<"\n Deque does not exists ! ";
        }
        else if(front == rear){
            front =-1;
            rear=-1;
        }
        else if(front ==capacity-1){
            front=0;
        }
        else{
            front ++;
        }
    }

    void deletionatrear(){
          if(ptr==NULL){
              cout<<"\n Deque does not exists ! ";
          }
          else if(front == rear){ // when only one element is present 
              front =-1;
              rear=-1;
          }
          else if(rear==0){
              rear=capacity-1;
          }
          else{
              rear--;
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

    ~Deque(){
        while(front!=-1){
            deletionatfront();
        }
    }
};


int driver(){
    int choice;
    cout<<"\n OPERATIONS : ";
    cout<<"\n 1.Create a queue ";
    cout<<"\n 2.Insertion from Rear ";
    cout<<"\n 3. Deletion from front ";
    cout<<"\n 4.Insertion from front ";
    cout<<"\n 5. Deletion from Rear ";
    cout<<"\n 6. To view Front Element in Deque";
    cout<<"\n 7. To view Last Element in Deque";
    cout<<"\n Press 0 for exit ";
    cout<<"\n Please Enter your choice : ";
    cin>>choice;
    return choice;
}

int main(){
    int capacity,data;
    Deque obj;
    while(1){
        switch (driver())
        {
        case 1:
            cout<<"\n Enter capacity : ";
            cin>>capacity;
            obj.CreateDeque(capacity);
            break;

        case 2:
        cout<<"\n Enter data : ";
        cin>>data;
        obj.Insertatrear(data);
        break;

        case 3:
        obj.deletionatfront();
        break;

        case 4:
        cout<<"\n Enter data : ";
        cin>>data;
        obj.Insertatfront(data);    
        break;

        case 5:
        obj.deletionatrear();
        break;

        case 6:
        cout<<obj.frontElementView();
        break;

        case 7:
        cout<<obj.frontElementView();
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