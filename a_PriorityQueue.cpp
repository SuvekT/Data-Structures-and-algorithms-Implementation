#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

  //using element's value as it's priority

  class P_queue{
      private:
       int capacity,front,rear;
       int *ptr;
    public:
      P_queue(){
          front=-1;
          rear=-1;
          ptr=NULL;
          capacity=0;
      }
      void Create_P_queue(int cap){
          capacity=cap;
          ptr=new int[cap];
          front=-1;
          rear=-1;
      }

      void insertion(int item){
          if(ptr==NULL){
              cout<<"\n Underflow ";
          }
          else if(front ==0 && rear==capacity-1 || rear+1==front){
              cout<<"\n Full !";
          }
          else if(rear+1==capacity){
              rear=0;
              ptr[rear]=item;
          }
          else{
              rear++;
              ptr[rear]=item;
          }
      }

      int deletion(){
          if(ptr==NULL){
              cout<<"\n does not exists  ! ";
          }
          else if(rear==-1){
              cout<<"\n Underflow ! ";
          }
          
          else if(rear==front){
              rear=-1;
              front=-1;
          }

        else{
          int min=ptr[0];
          int j=0;
          for(int i=1;i<capacity;i++){
             if(min>ptr[i]){
                 min=ptr[i];
                 j=i;
             }
          }
        //   while(j<rear){
        //       ptr[j]=ptr[j+1];
        //       j++;
        //   }
        //   front++;
        //   return min;
        int temp;
        temp=ptr[j];
        ptr[j]=ptr[front];
        ptr[front]=temp;

        if(front == capacity-1){
              front =0;
          }
          else{
              front ++;
          } 
           }
      }

       int frontElementView(){
        if(rear==-1){
               cout<<"\n UnderFlow ! ";
        }
        return ptr[front]; 
    }

        ~P_queue(){
        while(rear!=-1){
            deletion();
        }
        }

  };

  int main(){
      P_queue obj;
      obj.Create_P_queue(6);
      obj.insertion(4);
      obj.insertion(6);
      obj.insertion(2);
      obj.insertion(3);
      obj.insertion(5);
      obj.insertion(8);
      cout<<obj.frontElementView();
    //  cout<<obj.deletion();
   return 0;
  }