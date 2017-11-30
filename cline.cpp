#include<iostream>
#include<algorithm>
using namespace std;
typedef struct node{
  long int left,right;
}node;
bool cmp(node x,node y){
    if(x.left!=y.left)return x.left<y.left;
    return x.right<y.right;
}
int main(){
  int n;cin>>n;
    node* q=(node*)malloc((n-1)*sizeof(node));
    long int a[n];
    for(int i=0;i<n;i++){
      cin>>a[i];
      if(i>0){
          q[i-1].left=min(a[i-1],a[i]);
          q[i-1].right=max(a[i-1],a[i]);
      }
    }
    sort(q,q+n-1,cmp);
  //  for(int i=0;i<n-1;i++){cout<<q[i].left<<" "<<q[i].right<<"\n";}
    int flag=0;
    for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n-1;j++){
        if(q[j].left<q[i].right&&q[j].right>q[i].right&&q[j].left!=q[i].left){
          //cout<<i<<" "<<j;
          //cout<<" "<<q[j].left<<" "<<q[i].left;
          //cout<"YES";return 0;
          flag=1;break;
        }
      }
      if(flag)break;
    }
    if(flag)cout<<"yes";
    else cout<<"no";
    return 0;
}
