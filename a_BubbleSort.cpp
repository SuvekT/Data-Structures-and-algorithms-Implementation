#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

void BubbleSort(int capacity,int *arr){ 
    while(capacity>0){
for(int i=0;i<capacity;i++){
    if(arr[i]>arr[i+1]){
    int temp=arr[i];
    arr[i]=arr[i+1];
    arr[i+1]=temp;
    }
}
capacity--;
    }
}

int main(){
    int cap;
    cout<<"\n Enter capacity for array ";
    cin>>cap;
    int a[cap];
    cout<<"\n Enter elements in array "<<endl;
    for(int i=0;i<cap;i++){
        cin>>a[i];
    }
    BubbleSort(cap,a);  //*********** 
    cout<<"\n Sorted array : ";
    for(int i=0;i<cap;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
