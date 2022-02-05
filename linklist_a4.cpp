#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class linklist{
    private:
    
    struct node{
        node *next;
        int item;
    };
    node *start;
public:
linklist(){
     start=NULL;
}

void insertatfisrt(int data){
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
}

void insertatlast(int data){
    node *t;
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL){
        start=n;
    }
    else{
t=start;
while(t->next!=NULL)
t=t->next;
t->next=n;
    }
}

void insertAfternode(int data,int element){ //insertAfternode(node *m,int data)  -->wrong , because we cant pass node when we r going to use this function in main function
node *n;
node *temp=search(element);
if(temp!=NULL){
n=new node;
n->item=data;
n->next=temp->next;
temp->next=n;
}
else{
    cout<<"\n Element Search failed !";
}
}

node* search(int data){  //int* p(): Here “p” is a function that has no arguments and returns an integer pointer.
node *t;
t=start;
while(t!=NULL){
    if(t->item==data){
        return t;
        t=t->next;
    }
        return NULL;
}
}


void deletefirst(){
    node *n;
    if(start==NULL)
    cout<<"empty list/ underflow";
else  
  n=start;
    start=n->next;
    delete n;
}


void deletelast(){
node *t,*n;

if(start==NULL){
    cout<<"empty list";

}
else{
    t=start;
    n=NULL;
while(t->next!=NULL){
    n=t;
    t=t->next;
}
if(n==NULL)
start=n;
else
n->next=NULL;
delete t;
}
}

void deleteparticularitem(int data){
    if(start==NULL){
        cout<<"\n Underflow";
    }
    else{
        node *t,*n;
        t=search(data);
        if(t->next==NULL){
            deletelast();
        }
        else{
            n=start;
            while(n->next!=t){
                n=n->next;
            }
            n->next=t->next;
            delete t;
        }
    }
}

 void view(){
     if(start==NULL){
         cout<<"\n empty list";
     }
     else{
         node *temp;
         temp=start;
         while(temp->next!=NULL){
             cout<<temp->item<<"-->";
             temp=temp->next;
         }
         cout<<temp->item;
     }
 }

};

int driver(){
int choice;
cout<<"\n operation that you want to perform : ";
cout<<"\n 1.insertAtStart";
cout<<"\n 2.insertAtLast";
cout<<"\n 3.deletefirst";
cout<<"\n 4.deletelast";
cout<<"\n 5.insertAfterNode";
cout<<"\n 6.deleteParticulanode";
cout<<"\n 7.display list";
cout<<"\n 0.for exit";
cout<<"\n enter your choice : ";
cin>>choice;
return choice;;
}


int main(){
    int data,element;
    linklist obj;
while(1){
  switch (driver())
  {
  case 1:
  cout<<"\nenter data";
  cin>>data;
     obj.insertatfisrt(data);
      break;
  
  case 2:
  cout<<"\nenter data";
  cin>>data;
  obj.insertatlast(data);
  break;

   case 3:
   obj.deletefirst();
   break;

   case 4:
   obj.deletelast();

   case 5:
   cout<<"\nenter element";
   cin>>element;
   cout<< "\nenter data";
   cin>>data;
   obj.insertAfternode(data,element);
   break;

   case 6:
   cout<<"enter data of that node : ";
   cin>>element;
   obj.deleteparticularitem(element);
   break;

   case 7:
   obj.view();
   break;


  default:
  cout<<"enter valid choice for operation";
      break;
  }
}
return 0;
}
