#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class CLL_doubly{
    private:
    struct node{
    int item;
    node *next;
    node *prev;
    };
    node *start;

    public:
    CLL_doubly(){ // constructor
        start=NULL;
    }

    ~CLL_doubly(){ // destructor
        while(start!=NULL){
        deletelast();
        }
    }
    

    void insertatfirst(int data){
        node *t=new node;
        t->item=data;
      if(start==NULL){
       t->next=t;
       t->prev=t;
       start=t;
      }
      else{
          t->prev=start->prev;
          t->next=start->next;
          node *n=start->prev;
          start->prev=t;
          n->next=t;
          start=t;
      }
    }

    void insertatlast(int data){
        node *t=new node;
        t->item=data;
        if(start==NULL){
            t->next=t;
            t->prev=t;
            start=t;
        }
        else{
            node *n;
            n=start->prev;
            t->prev=n;
            t->next=start;
            start->prev=t;
            n->next=t;
        }
    }

    void deleteFirst(){
        if(start==NULL){
            cout<<"\n Underflow";
        }
        else{
            node *t,*n;
            t=start;
            n=start->prev;
            n->next=t->next;
            start=t->next;
            start->prev=n;
            delete t;
        }
    }
    void deletelast(){
        if(start==NULL){
            cout<<"\n UNderflow";
        }
        else{
            node *n,*t;
            n=start->prev;
            t=n->prev;
            t->next=start;
            start->prev=t;
            delete n;
        }
    }
    void view(){
        if(start==NULL){
            cout<<"\n Empty list";
        }
        else{
            node *t;
            t=start;
            while(t->next!=start){
                cout<<t->item<<"-->";
                t=t->next;
            }
            cout<<t->item;
        }
    }

    node* search(int element){
        if(start==NULL){
            cout<<"\n Underflow";
        }
        else{
            node *t;
            t=start;
            while(t->item!=element){
            t=t->next;
            }
            return t;
        }
    }

    void insertAfterNode(int element,int data){
        if(start==NULL){
            cout<<"\n Underflow";
        }
        else{
            node *t=new node;
            t->item=data;
            node *n=search(element);
            if(n->next==start){
                insertatlast(data);
            }
            else{
            t->prev=n;
            t->next=n->next;
            n->next=t;
            }
        }
    }

    void deleteParticularNode(int element){
        node *t,*n,*x;
        t=search(element);
        if(t==start){
            deleteFirst();
        }
        else if(t->next==start){
            deletelast();
        }
        else{
        n=t->prev;
        x=t->next;
        n->next=t->next;
        x->prev=t->prev;
        delete t;
        }
    }
};
 int driver(){
     int choice;
     cout<<"\n Operations : ";
     cout<<"\n 1)Insert at start ";
     cout<<"\n 2)Insert at last  ";
     cout<<"\n 3)delete first ";
     cout<<"\n 4)view list";
     cout<<"\n 5)Delete last";
     cout<<"\n 6)Insert After Node";
     cout<<"\n 7)Delete Particular Node";
     cout<<"\n 0)exit";
     cout<<"\n Enter your choice : ";
     cin>>choice;
     return choice;
 }
int main(){
    int data,element;
    CLL_doubly obj;
    while(1){
        switch (driver())
        {
        case 1:
        cout<<"\n Enter data : ";
        cin>>data;
        obj.insertatfirst(data);
        break;

        case 2:
        cout<<"\n Enter data : ";
        cin>>data;
        obj.insertatlast(data);
        break;

        case 3:
        obj.deleteFirst();
        break;

        case 4:
        obj.view();
        break;     

        case 5:
        obj.deletelast();
        break;

        case 6:
        cout<<"\n After which element you want to insert: ";
        cin>>element;
        cout<<"\n enter data: ";
        cin>>data;
        obj.insertAfterNode(element,data);
        break;

        case 7:
        cout<<"\n Enter element of the node : ";
        cin>>element;
        obj.deleteParticularNode(element);
        break;
         
         case 0:
         getch();
         exit(0);
         break;

        default:
        cout<<"Please enter valid choice , Thank you! ";
            break;
        }
    }

return 0;
}
