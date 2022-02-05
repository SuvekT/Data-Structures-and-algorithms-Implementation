#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

class DLL{
    private:
    struct node{
        int item;
        node *next;
        node *prev;
    };
node *start;
public:
    DLL(){
        start=NULL;
    }


    void insertAtStart(int data){
         node *t=new node;
         t->item=data;
         t->next=start;
         t->prev=NULL;
        if(start==NULL){
            start=t;
        }
        else{
            start->prev=t;
            start=t;
        }
    }


    void insertAtLast(int data){
        node *t=new node;
        node *n;
        t->item=data;
        t->next=NULL;

       if(start==NULL){
           start=t;
           t->prev=NULL;
       }
       else{
         n=start;
         while(n->next!=NULL){
             n=n->next;
         }
         n->next=t;
         t->prev=n;
       }
    }


    void deletefirst(){
node *t;
if(start==NULL){
    cout<<"underflow/ empty list";
}
else{
    t=start;
    if(t->next==NULL){
        start=NULL;
        delete t;
    }
    else{
     start=t->next;
     start->prev=NULL;
     delete t;
    }
}
}

void deleteLast(){
    node *t,*n;
    if(start==NULL){
        cout<<"underflow/ empty list";
    }
    else{
     if(start->next==NULL){
         t=start;
         delete t;
     }
     else{
         n=start;
         while(n->next!=NULL){
             t=n;
             n=n->next;
         }
         t->next=NULL;
         delete n;
     }
    }
}

node* search(int data){  //node* fun() --> returning node pointer
    node *t;
    if(start==NULL){
        cout<<"underflow";
    }
    else{
    t=start;
    while(t->item!=data){
        t=t->next;
    }
    return t;
    }
}

void insertAfterNode(int data,int element){ //inserting node after node having 'element'  with 'data'
    node *t,*n;
    t=new node;
    if(start==NULL){
        cout<<"underflow";
    }
    else{
        t->item=data;
        n=start;
        while(n->item!=element){
            n=n->next;
        }
        t->next=n->next;
        n->next=t;
    }
}


void deleteParticularNode(int element) { //that particular node has 'element' as data in it
      node *t,*n;
      if(start==NULL){
          cout<<"underflow";
      }
      else{
          t=start;
          while (t->item!=element){
              n=t;
              t=t->next;
          }
          n->next=t->next;
          t->prev=NULL;
      }
}

 void view(){
     if(start==NULL){
         cout<<"\n empty list";
     }
     else{
         node *temp;
         temp=start;
         while(temp!=NULL){
             cout<<temp->item<<"-->";
             temp=temp->next;
         }
         cout<<temp->item;
     }
 }
};

int driver(){
int choice;
cout<<"\noperation that you want to perform : ";
cout<<"\n1.insertAtStart";
cout<<"\n2.insertAtLast";
cout<<"\n3.deletefirst";
cout<<"\n4.deletelast";
cout<<"\n5.insertAfterNode";
cout<<"\n6.deleteParticulanode";
cout<<"\n7.display list";
cout<<"\n0.for exit";
cout<<"\nenter your choice : ";
cin>>choice;
return choice;;
}

int main(){
    int data,element;
    DLL obj;

while(1){
  switch (driver())
  {
  case 1:
  cout<<"\nenter data";
  cin>>data;
     obj.insertAtStart(data);
      break;
  
  case 2:
  cout<<"\nenter data";
  cin>>data;
  obj.insertAtLast(data);
  break;

   case 3:
   obj.deletefirst();
   break;

   case 4:
   obj.deleteLast();

   case 5:
   cout<<"\nenter element";
   cin>>element;
   cout<< "\nenter data";
   cin>>data;
   obj.insertAfterNode(data,element);
   break;

   case 6:
   cout<<"enter element";
   cin>>element;
   obj.deleteParticularNode(element);
   break;

   case 7:
   obj.view();
   break;

   case 0:
   exit(0);
   break;

  default:
  cout<<"enter valid choice for operation";
      break;
  }
}
return 0;
}