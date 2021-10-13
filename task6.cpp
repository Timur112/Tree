#include "Header.h"

void swap(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
void add(tree *&t,int x,int w)
{
    if (t==NULL){
        t= new tree;
        t->id=x;
        t->weight=w;
        t->left=NULL;
        t->right=NULL;
    }
    else
    {
        if(x < t->id){
            add(t->left,x,w);
        }
        else
        {
            add(t->right,x,w);
        }
    }
}
tree* build(){
    int i;
    tree* t=NULL;
    for(i=0;i<=10;i++){
    add(t,rand()%300,rand()%3-1);
    }
    return t;
}
void printpre(tree *t)
{
    if(t != NULL)
    {
        std::cout << t->id<<" ";
            printpre(t->left);
            printpre(t->right);
    }
}
int search(tree *t,tree *&par,tree *&ptr,int x,int &l)
{
    if(t != NULL){
        if(t->id==x){
            l=0;
            par=t;
            ptr=t;
            return 0;
        }
        if(t->left != NULL && t->left->id==x)
        {
            l=-1;
            //std::cout<<t<<" "<<t->id<<"\n";
            par=t;
            ptr=t->left;
            return 0;
        }
        if(t->right != NULL && t->right->id==x)
        {
            l=1;
            // std::cout<<t<<" "<<t->id<<"\n";
            par=t;
            ptr=t->right;
            return 0;
        }
        search(t->left,par,ptr,x,l);
        search(t->right,par,ptr,x,l);
    }
}
void Delete(tree *&t,int x)
{
    int l=2;
    tree   *ptr,*ptr2,*par;
    search(t,par,ptr,x,l);
    if(l!=2){
        if(ptr->left==NULL && ptr->right==NULL){
            //std::cout<<ptr->id<<"\n";
            delete(ptr);
            if(l==1){
                par->right=NULL;
            }
            if(l==-1){
                par->left=NULL;
            }
            if(l==0){
                //std::cout<<ptr->id<<"f2\n";
                t=NULL;
            }
        }
        else{
            if(ptr->left!=NULL && ptr->right!=NULL){
               ptr2=ptr->left;
               while(ptr2->right){
                    ptr2=ptr2->right;
               }
                swap(&(ptr2->id),&(ptr->id));
                swap(&(ptr2->weight),&(ptr->weight));
                //std::cout<<ptr->left->id<<x<<"\n";
                Delete(ptr->left,x);
                //std::cout<<ptr->left<<ptr2->id<<"f1\n";
                //std::cout<<ptr2<<ptr2->id<<"f3\n";
            }
            else{
                if(ptr->left!= NULL){
                    ptr2=ptr->left;
                }
                else{
                    ptr2=ptr->right;
                }
                delete(ptr);
                if(l==0){
                    t=ptr2;
                }
                else{
                    if(l==1){
                        par->right=ptr2;
                    }
                    else
                    {
                        par->left=ptr2;
                    }
                }
            }
        }
    }
}
void individual(tree *t,int w,int lev,int curlev)
{
    if(curlev==lev && t->weight==w){
        std::cout<<t->id<<" ";
    }
    else
    {
        if(t->left) individual(t->left,w,lev,curlev+1);
        if(t->right) individual(t->right,w,lev,curlev+1);
    }
}
void printin(tree *t,int n)
{
    if(t !=NULL){
      printin(t->left,n+1);
      std::cout<<setw(7*n)<<t->id<<"("<<t->weight<<")\n";
      printin(t->right,n+1);
    }
}
