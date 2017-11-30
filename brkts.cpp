#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
int *tree;int* o;int* c;
/*typedef struct node{
  int len,op,c;
}*/
typedef struct node{
  int t,o,c;
}node;
void build_tree(string& s,int be,int en,int indx){
    if(be>en)return ;
    if(be==en){
      if(s[be]=='('){o[indx]=1;c[indx]=0;}
      else {c[indx]=1;o[indx]=0;}
      tree[indx]=0;
      return ;
    }
    int mid=(be+en)/2;
    build_tree(s,be,mid,2*indx+1);
    build_tree(s,mid+1,en,2*indx+2);
    int temp=min(o[2*indx+1],c[2*indx+2]);
    tree[indx]=tree[2*indx+1]+tree[2*indx+2]+temp;
    o[indx]=o[2*indx+1]+o[2*indx+2]-temp;
    c[indx]=c[2*indx+1]+c[2*indx+2]-temp;
  //    cout<<"indx="<<indx<<" "<<tree[indx]<<"\n";
    return ;
}
node* get_ans(int l,int r,int be,int en,int indx){
    if(be>en){
        //tmp->t=0;tmp->o=0;tmp->c=0;
        return NULL;
    };
    if(be>r||en<l)return NULL;
    if(be>=l&&en<=r){
      node* tmp=(node*)malloc(sizeof(node));
      tmp->t=tree[indx];tmp->o=o[indx];tmp->c=c[indx];
      return tmp;
    }
    int mid=(be+en)/2;
    node* left=get_ans(l,r,be,mid,2*indx+1);
    node* rght=get_ans(l,r,mid+1,en,2*indx+2);
      //return (get_ans(l,r,be,mid,2*indx+1)+get_ans(l,r,mid+1,en,2*indx+2));
      node* tmp=(node*)malloc(sizeof(node));
      if(left!=NULL&&rght!=NULL){
        int temp=min(left->o,rght->c);
        tmp->t=left->t+rght->t+temp;
        tmp->o=left->o+rght->o -temp;
        tmp->c=left->c+rght->c -temp;
        return tmp;
      }
      if(left!=NULL)
      return left;
      return rght;
}
int main(){
  string s;
  cin>>s;
  long int len=s.size();
  int k;cin>>k;
  int l,r;
  long  int cap=ceil(log2(len));
//  cout<<cap<<"\n";
    cap=2*pow(2,cap)-1;
  //  cout<<cap<<"\n";
  tree=(int*)malloc(cap*sizeof(int));
   o=(int*)malloc(cap*sizeof(int));
   c=(int*)malloc(cap*sizeof(int));
  // cout<<"yes\n";
  build_tree(s,0,len-1,0);
  for(int i=0;i<k;i++){
    cin>>l>>r;
    //node* temp=(node*)malloc(sizeof(node));
    cout<<2*get_ans(l-1,r-1,0,len-1,0)->t<<"\n";
    //call function to get ans
  }
  return 0;
}
