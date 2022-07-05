#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;

class BST{
    private:
     struct node{
         node *left;
         int item;
         node *right;
     };
     node *root;

    public:
    ~BST(){
        root=NULL;
    }

    node* getrootAddress(){
        return root;
    }


    void Insertion(int data){
        node *t=new node;
        t->item=data;
        t->left=NULL;
        t->right=NULL;
        node *n=root;

        if(root==NULL){
             root=t; 
        }

        else{
            while(1){
             if(data==n->item)
               delete t;
                  
            else if(data<n->item){
                if(n->left==NULL){
                    n->left=t;
                    break;
                }
                else{
                        n=n->left; 
                }

            }
            else{
                if(n->right==NULL){
                    n->right=t;
                    break;
                }
                else{
                        n=n->right;
                }
                
            }
        }
        }
        
    }

   void preorder(node* ptr);
   void inorder(node* ptr);
   void postorder(node* ptr);
   void deletion(int data,node* ptr);

/*
   node *minvaluenode(node *n){
       node *curr=n;
       while(curr->left!=NULL)
            curr=curr->left;
        return curr;    
   }

   node* deletion(int data,node *r){
       node *temp;
       if (r==NULL)
       {
           return r;
       }
       else if(data<r->item){
         r->left=deletion(data,r->left);
       }
       else if(data>r->item){
           r->right=deletion(data,r->right);
       }

       else{
           if(r->left==NULL){
               temp=r->right;
               delete r;
               return temp;
           }
           else if(r->right==NULL){
               temp=r->left;
               delete r;
               return temp;
           }
           else{
               temp=minvaluenode(r->right);
               r->item=temp->item;
               r->right=deletion(temp->item,r->right);
           }
       }
       return r;
       
   } */
};

void BST::preorder(node *ptr){
  if(ptr!=NULL){
      cout<<ptr->item<<" ";
      preorder(ptr->left);
      preorder(ptr->right);
  }

}

void BST::inorder(node *ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
        cout<<ptr->item<<" ";
        inorder(ptr->right);
    }
}

void BST::postorder(node *ptr){
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->item<<" ";
    }
}



 void BST::deletion(int data,node *ptr){
    ptr=root;
   node *parptr=NULL; //(*parptr means parent pointer which act as tail pointer to traversing pointer i.e. *ptr)
   if(ptr==NULL){
       cout<<"\n NULL TREE !";
   }
   else{
      // node *suc;  // succesor pointer
       // node *parsuc=NULL; // tail pointer to succesor pointer
       int temp;

       while(1){
           if(data==ptr->item){
               break;
           }
           else if(data<ptr->item){
               parptr=ptr;
               ptr=ptr->left;
           }
           else{
               parptr=ptr;
               ptr=ptr->right;
           }
       }

       if(ptr->left==NULL && ptr->right ==NULL){
         if(data<parptr->item){
         parptr->left==NULL;
         delete ptr;
         }
         else{
             parptr->right==NULL;
             delete ptr;
         }
       }

       else if(ptr->left){
           
       }

       while (1)
       {
         if(suc->left==NULL){
         break;
         }
         parsuc=suc;
         suc=suc->left;
       }
       temp=ptr->item;
       ptr->item=suc->item;
       suc->item=temp;


       if(suc->right!=NULL){
       while(1){
           if(suc->right==NULL && suc->left==NULL)
           break;
             parsuc=suc;
             suc=suc->right;
       }
       
       }
   }
}         






int main(){
    BST obj;
    obj.Insertion(50);
    obj.Insertion(30);
    obj.Insertion(20);
    obj.Insertion(40);
    obj.Insertion(80);
    obj.Insertion(70);
    obj.Insertion(60);
   obj.inorder(obj.getrootAddress());
  
    return 0;
}