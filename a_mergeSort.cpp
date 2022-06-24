#include<iostream>
#include<conio.h>
using namespace std;

// first we have to make fun for merge
void merge(int a[],int l,int m,int u){
   int L[m+1-l],R[u-m];
   int i,j,k;
   for(i=0;i<m+1-l;i++){
       L[i]=a[l+i];
   }
   for(j=0;j<u-m;j++){
       R[j]=a[m+1+j];
   }
   for(i=0,j=0,k=l;i<m-l+1 && j<u-m;k++){
          if(L[i]<R[j]){
              a[k]=L[i];
              i++;
          }
          else{
              a[k]=R[j];
              j++;
          }
   }
   while(i<m-l+1){
       a[k]=L[i];
       i++;
       k++;
   }
     while(j<u-m){
       a[k]=R[j];
       j++;
       k++;
   }
}

void merge_sort(int A[],int l,int u){
    int m;
   if(l<u){
       m=(l+u)/2;
       merge_sort(A,l,m);
       merge_sort(A,m+1,u);
       merge(A,l,m,u);
   }
}

int main(){
    
}