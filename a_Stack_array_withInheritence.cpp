#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

class Array{
    private:
    int capacity;
    int lastindex;
    int *ptr;

    public:
    Array();
   void createArray(int cap);
   void append(int data);
   void insert(int index, int data);
   void del(int index );
   int search(int data);
   int edit(int index,int data);
   int count();
   int getData(int index);
   void view();
   ~Array();
     
};
Array :: Array(){  // constructor
    capacity=0;
    lastindex=-1;
    ptr=NULL;
}


void Array:: createArray(int cap){
    capacity=cap;
    lastindex=-1;
    ptr =new int[cap]; // ptr pointing to new array formed of size 'cap'
}


void Array:: append(int data){
    if(lastindex+1==capacity){
        cout<<"\n overflow";
    }
    else {
        ++lastindex;
        ptr[lastindex]=data;
    }
}


void Array::insert(int index, int data){
    int i;
    if(index<0 || index>(lastindex+1)){
        cout<<"\n invalid index";
    }
    else if(lastindex+1==capacity){
        cout<<"\n overflow";
    }
    else{
        for(i=lastindex;i>=index;i--){
            ptr[i+1]=ptr[i];
        }
        ptr[index]=data;
        lastindex++;
    }

}


    void Array:: del(int index)
    {
    if(index<0 || index>lastindex){
        cout<<"\n invalid index";
    }
    else{
        for(int i=index;i<=lastindex;i++){
       ptr[i]=ptr[i+1];
       lastindex--;
        }
    }
    }

    int Array:: search(int data){
        for(int i=0;i<=lastindex;i++){
            if(ptr[i]==data){
                return i;
        }
        else {
            cout<<"not found ";
        }
    }
    }


     int Array:: getData(int index){
         if(index<0 || index>lastindex+1){
             cout<<"invalid index ";
         }
         else{
         return ptr[index];
         }
     }


     int Array:: count(){
         return (lastindex+1);
     }


     int Array::edit(int index,int newdata){
     
     if(index<=0 || index>=lastindex+1){
         cout<<"\n invalid index";
     }
     else if(lastindex+1==capacity){
        cout<<"\n overflow";
    }
    else{
        ptr[index]=newdata;
     
    }
     }

     void Array:: view(){
         for(int i=0;i>=lastindex;i++){
             cout<<ptr[i]<<" ";
         }
     }

     Array::~Array(){  // detsructor
         delete []ptr;
     }


class Stack:private Array{

    public:
    void createStack(int capacity){
        createArray(capacity);
    }
    
    void push(int data){
        append(data);
    }

    void pop(){
        del(count()-1);
    }

    int peek(){
        return getData(count()-1);
    }
};


int driver(){
    int choice;
    cout<<"\n Operations : ";
    cout<<"\n 1) Create Stack";
    cout<<"\n 2) Push data";
    cout<<"\n 3) Pop data";
    cout<<"\n 4)To see top element in Stack";
    cout<<"\n Press ZERO To exit";
    cout<<"\n Enter your Choice : ";
    cin>>choice;
    return choice;
}

int main(){
    int data,capacity;
    Stack obj;
    while(1){
        switch (driver())
        {
        case 1:
        cout<<"\n Enter Capacity for Stack :";
        cin>>capacity;
        obj.createStack(capacity);
            break;

        case 2:
        cout<<"\n Enter data to push : ";   
        cin>>data;
        obj.push(data);
        break;

        case 3:
        obj.pop();
        break;

        case 4:
        cout<<obj.peek();
        break;

        case 0:
        exit(0);
        break; 
        
        default:
        cout<<"\n Please enter valid choice , Thank you!";
            break;
        }

    }
    return 0;
}