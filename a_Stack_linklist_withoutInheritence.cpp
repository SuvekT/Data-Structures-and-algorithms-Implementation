#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class Stack{
    private:
    struct node{
     int item;
     node *next;
    };
    node *top;

    public:
    Stack(){
        top=NULL;
    }

    void push(int data){
        node *t=new node;
        t->item=data;
        t->next=top;
        top=t;
    }

    void pop(){
        if(top==NULL){
            cout<<"\n Underflow";
        }
        else{
            node *t;
            t=top;
            top=t->next;
            delete t;
        }
    }

    int peek(){
        if(top==NULL){
            cout<<"\n Empty Stack";
            return -1;
        }
        else{
            return top->item;
        }
    }

    ~Stack(){
        while(top!=NULL){
            pop();
        }
    }
};

int driver(){
    int choice;
    cout<<"\n OPERATIONS : ";
    cout<<"\n 1. PUSH " ;
    cout<<"\n 2. POP ";
    cout<<"\n 3. PEEK / to see topmost element ";
    cout<<"\n PRESS ZERP FOR EXIST ";
    cout<<"\n Enter your choice : ";
    cin>>choice;
    return choice;
}


int main(){
    int data;
    Stack obj;
    while(1){
        switch(driver()){
            case 1:
            cout<<"\n enter data : ";
            cin>>data;
            obj.push(data);
            break;

            case 2:
            obj.pop();
            break;

            case 3:
            cout<<obj.peek();
            break;

            case 0:
            exit(0);
            break;

            default:
            cout<<"Please enter valid choice , Thank you !";
            break;
        }
    }
    return 0;
}