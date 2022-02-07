#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class Queue{
    private:
    struct node{
       int item;
       node *next;
    };
    node *front,*rear;

    public:
    Queue(){
        front=NULL;
        rear=NULL;
    }

    void insertion(int data){
        node *t=new node;
        t->item=data;
        if(front==NULL){  // list/queue is empty
         front=t;
         t->next=NULL;
         rear=t;
        }
        else{
      t->next=NULL;
      rear->next=t;
      rear=t;
        }
    }

    void deletion(){
        if(front==NULL){
            cout<<"\n Empty Queue / Underflow !";
        }
        else{
            node *t=front;
            front=front->next;
            delete t;
        }
    }

    int ViewFront(){
        if(front==NULL){
            cout<<"\n Underflow ! ";
        }
        else{
            return front->item;
        }
    }

    int ViewRear(){
        if(front==NULL){
            cout<<"\n Underflow ! ";
        }
        else{
            return rear->item;
        }
    }

    ~Queue(){
        while(front!=NULL){
            deletion();
        }
    }
};


int driver(){
    int choice;
    cout<<"\n OPERATIONS : ";
    cout<<"\n 1.Insertion ";
    cout<<"\n 2. Deletion";
    cout<<"\n 3. To view Front Element in Queue";
    cout<<"\n 4. To view Last Element in Queue";
    cout<<"\n Press 0 for exit ";
    cout<<"\n Please Enter your choice : ";
    cin>>choice;
    return choice;
}

int main(){
    int data;
    Queue obj;
    while(1){
        switch (driver())
        {
        case 1:
            cout<<"\n Enter data : ";
            cin>>data;
            obj.insertion(data);
            break;

        case 2:
        obj.deletion();
        break;

        case 3:
        cout<<obj.ViewFront();    
        break;

        case 4:
        cout<<obj.ViewRear();
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


