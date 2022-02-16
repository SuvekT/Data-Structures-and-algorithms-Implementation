#include<iostream>
using namespace std;


void InsertionSort(int cap,int *arr){
    int i,j,temp;
for(j=1;j<cap;j++){
     temp=arr[j];
    for( i=j-1;i>=0;i--){
        if(arr[i]>temp){
            arr[i+1]=arr[i];
        }
        else {
        break;
        }
    }
        arr[i+1]=temp;
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
    InsertionSort(cap,a);  //*********** 
    cout<<"\n Sorted array : ";
    for(int i=0;i<cap;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
