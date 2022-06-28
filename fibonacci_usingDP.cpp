#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;


  int fib(int n,int* F){
        if(F[n]!=-1){
            return F[n];
        }
        if(n==0 || n==1)
        return n;
        else{
            F[n]=fib(n-1,F)+fib(n-2,F);
        }
        return F[n];
  }

int main(){
    int *F=new int[10];
    for(int i=0;i<10;i++){
        F[i]=-1;
    }
    
     cout<<fib(7,F);

    return 0;
}