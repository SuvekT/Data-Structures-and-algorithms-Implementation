#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
                  
                  /********** Using singly linklist *************/
                  
class CLL{
    private:
    struct node{
    int item;
    node *next;
    };
    node *last;


public:
     CLL(){      
        last=NULL;
    } 
    ~CLL(){
        while(last!=NULL)
        deletefirst(); // loop will run upto last me null nahi ata
    }

    void insertAtfirst(int data){
        node *t=new node;
        t->item=data;
        if(last==NULL){
            t->next=t;
            last =t;
        }
        else{
            t->next=last->next;
            last->next=t;
            last=t;
        }
    }

    void insertAtLast(int data){
        node *t=new node;
        t->item=data;
        node *temp;
        temp=last->next;
        if(last==NULL){
            t->next=t;
            last=t;
        }
        else{
            t->next=last->next;
            last->next=t;
            last=t;
        }
    }

    node* search(int element){
        if(last==NULL){
            return NULL;
        }
        else{
            node *t;
            t=last->next;
            while(t!=last){
                if(t->item==element)
                return t;
                t=t->next;
            }
            return NULL;
        }
    }

    void deletefirst(){
        if(last==NULL){
            cout<<"\n empty list";
        }
        else{
            if(last->next==NULL){
                delete last;
                last=NULL;
            }
            else{
                node *t;
                t=last->next;
                last->next=t->next;
                delete t;
            }
        }
    }

    void deleteLast(){
        if(last==NULL){
            cout<<"\n empty list";
        }
        else{
            if(last->next==last){ // condition for single node
                delete last;
                last==NULL;
            }
            else{   // for more than two nodes
                node *temp;
                temp=last->next;
            while(temp->next!=last){
               temp=temp->next;
            }
            temp->next=last->next; 
            delete last;
            last=temp; 
            }
        }
    }

    void insertAfter(int element,int data){
        if(last==NULL){
          cout<<"/n underflow";
        }
        else{
            node *temp=search(element);
            node *n=new node;
             n->item=data;
             if(temp!=NULL){
             n->next=temp->next;
             temp->next=n;
             }
             else{
                 cout<<"\n Element search failed!! ";
             }
        }
    }

    void deleteParticularNode(int element){
        if(last==NULL){
            cout<<"\n Underflow";
        }
        else{
            node *t,*n;
            t=last->next;
            while(t->item!=element){
                n=t;
                t=t->next;
            }
            n->next=t->next;
            delete t;

        }
    }

    void view(){
        if(last==NULL){
            cout<<"\n Underflow";
        }
        else{
            node *temp;
            temp=last->next;
            while(temp!=last){
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
    cout<<"\n Enter the choice";
    cin>>choice;
    return choice;
}

int main(){
    int Data,element;
    CLL obj;
    while(1) 
    {
        switch (driver())
        {
         case 1:
         cout<<"\n enter data";
         cin>>Data;
         obj.insertAtfirst(Data);
         break;
  
         case 2:
         cout<<"\n enter data";
         cin>>Data;
         obj.insertAtLast(Data);
         break;

         case 3:
         obj.deletefirst();
         break;

         case 4:
         obj.deleteLast();
         break; 

         case 5:
         cout<<"\n enter element";
         cin>>element;
         cout<< "\n enter data";
         cin>>Data;
         obj.insertAfter(Data,element);
         break;

   case 6:
   cout<<"\n enter element";
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
  cout<<"\n enter valid choice for operation";
      break;
        }
    }

return 0;
}