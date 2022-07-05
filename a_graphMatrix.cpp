#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

 /*******************By Adjacency Matrix *****************/

class GraphMatrix{
private:
int vcount;  // number of nodes present in it
int ecount;  // numer of edges present in it
int **adj;

public:
void createGraph(int vcount,int ecount){
   int i,j;
   this->vcount=vcount;
   this->ecount=ecount;
   adj=new int*[vcount];   //*****************  made array of pointers
   
   for(int v=0;v<vcount;v++){
      adj[v]=new int[vcount];
      for(int k=0;k<vcount;k++){
         adj[v][k]=0;
      }
   }

   for(int e=1;e<=ecount;e++)
   {
      cout<<"\n Enter vertex number by this edge: ";
      cin>>i>>j;
      adj[i-1][j-1]=1;
      adj[j-1][i-1]=1;
   }  
}

void printMatrix(){
   for(int i=0;i<vcount;i++){
      for(int j=0;j<vcount;j++){
         cout<<adj[i][j]<<"  ";
      }
      cout<<endl;
   }
}
};

int main(){
      GraphMatrix G;
      G.createGraph(4,4);
      G.printMatrix();
   return 0;
}