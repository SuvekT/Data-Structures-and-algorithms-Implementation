#include<iostream>
#include<conio.h>
using namespace std;

int quick(int a[],int l,int u){
    int loc,left,right,temp;
    left=l;
    loc=l;
    right=u;
    while(left<right){
        while(a[loc]<=a[right] && left<right){
            right--;
        }
            if(left==right){
                break;
            }
            else{
                temp=a[loc];
                a[loc]=a[right];
                a[right]=temp;
                loc=right;
            }
         while(a[loc]>a[left] && left<right)  {
             left++;
         } 
         if(left==right)
             break;
         else{
             temp=a[left];
             a[left]=a[loc];
             a[loc]=temp;
             loc=left;             
         }        
    }
    return loc;
}

void Quick_sort(int A[],int l,int u){
    int loc;
    loc=quick(A,l,u);
    if(l+1<loc){
        Quick_sort(A,l,loc-1);  // using recursion
    }
    if(u-1>loc){
        Quick_sort(A,loc+1,u);
    }
}

int main(){
    int Q[14]={50,23,81,11,90,100,66,72,14,31,44,75,29,13};
    Quick_sort(Q,0,13);
    for(int i=0;i<14;i++){
        cout<<Q[i]<<" ";
    }
    return 0;
}