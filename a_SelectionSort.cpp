#include<iostream>
using namespace std;

void SelectionSort(int cap,int *arr){
int min,temp;
int k;
for(k=0;k<cap;k++){

    min=arr[k];

for(int i=k+1;i<cap;i++){
 if(min>arr[i]){
  min=arr[i];
 }
}
int j=0;
while(arr[j]!=min){
    j++;
}
arr[j]=arr[k];
arr[k]=min;
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
    SelectionSort(cap,a);  //*********** 
    cout<<"\n Sorted array : ";
    for(int i=0;i<cap;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
