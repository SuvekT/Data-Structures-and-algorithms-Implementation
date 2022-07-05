#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class Heap{
private:
int capacity;
int lastindex;
int *ptr;

protected:

void doubleArray(){
int *temp;
temp=new int[capacity*2];
for(int i=0;i<=lastindex;i++)
temp[i]=ptr[i];
delete []ptr; // only deleting array that were pointed by ptr
ptr=temp;
temp=NULL;
capacity*=2;
}

void halfarray(){
    int *temp;
    temp=new int[capacity/2];
    for(int i=0;i<=lastindex;i++)
    temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    temp=NULL;
    capacity/=2;
}

public:
Heap(){
    capacity=10;
    lastindex=-1;
    ptr=new int[capacity];
}


void insertion(int data);
int deletion();
void PrintArray();
void Heap_sort();

};

void Heap::insertion(int data){
 
    int parindex,index;
    if(lastindex+1==capacity)
    {
    doubleArray();
    }
       lastindex++;
    index=lastindex;

    while(index>0){
    parindex=(index-1)/2;

    if(ptr[parindex]<data){
        ptr[index]=ptr[parindex];
    }
    else{
        break;
    }
    index=parindex;
    }
    ptr[index]=data;
}

int Heap::deletion(){
int temp;
int data,index,lindex,rindex;
if(lastindex>=0){
    data=ptr[0];
    temp=ptr[lastindex];
    lastindex--;
    index=0;
    rindex=2;
    lindex=1;

    while(rindex<=lastindex){

        if(ptr[lindex]<ptr[rindex]){
            if(temp<ptr[rindex]){
                ptr[index]=ptr[rindex];
                index=rindex;
            }
            else{
                ptr[index]=temp;
                break;
            }
        }

        else{
            if(temp<ptr[lindex]){
                ptr[index]=ptr[lindex];
                index=lindex;
            }
            else{
                ptr[index]=temp;
                break;
            }
        }
        lindex=2*index+1;
        rindex=2*index+2;
    }

    if(lindex==lastindex){
        if(ptr[lindex]>temp){
           ptr[index]=ptr[lindex];
           ptr[lindex]=temp;
        }
        else{
            ptr[index]=temp;
        }
    }
    else{
        ptr[index]=temp;
    }
    return data;
}
}


void Heap::PrintArray(){
    for(int i=0;i<=lastindex;i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
}

void Heap::Heap_sort(){
   for(int i=lastindex;i>=0;i--){
       cout<<deletion()<<" ";
   }
}

int main(){
    Heap obj;
    obj.insertion(100);
    obj.insertion(90);
    obj.insertion(80);
    obj.insertion(60);
    //obj.PrintArray();
    obj.insertion(70);
    obj.insertion(50);
    obj.insertion(40);
    obj.insertion(20);
    obj.insertion(30);
    obj.insertion(10); 
    //cout<<obj.deletion()<<endl;
    obj.PrintArray();
    obj.Heap_sort();

    return 0;
}