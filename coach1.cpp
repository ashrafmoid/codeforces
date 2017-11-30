#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
typedef struct node{
  int a,b;
}node;
bool cmp(node x,node y){
  if(x.a!=y.a)return x.a<y.a;
  else return x.b<y.b;
}
int main(){
  int n,m;
  cin>>n>>m;
  vector< vector<int> > lst(n+1,vector<int>());
  node* q=(node*)malloc(m*sizeof(node));
  for(int i=0;i<m;i++){
    cin>>q[i].a>>q[i].b;
  }
  sort(q,q+m,cmp);
  int match[n+1];
  vector<int> unused;
  for(int i=0;i<=n;i++)match[i]=0;
  for(int i=0;i<m;i++){
    if(match[q[i].a]!=0&&match[q[i].b]!=0)continue;
    else if(match[q[i].a]==0&&match[q[i].b]==0){
      lst[q[i].a].push_back(q[i].b);match[q[i].b]=q[i].a;
      match[q[i].a]=q[i].a;
    }
    else if(match[q[i].a]==0&&match[q[i].b]!=0){
      lst[match[q[i].b]].push_back(q[i].a);match[q[i].a]=match[q[i].b];
    }
    else {
      lst[match[q[i].a]].push_back(q[i].b);match[q[i].b]=match[q[i].a];
    }
  }
  /*print the list*/
  /*cout<<"list is:\n";
  for(int i=1;i<=n;i++){
    int j=0;
    while(j<lst[i].size()){
      cout<<lst[i][j]<<" ";j++;
    }
    cout<<"\n";
  }*/
  int count2=0;int flag=0;
  for(int i=1;i<=n;i++){
    if(match[i]==0){
      unused.push_back(i);
    }
    else if(lst[i].size()==1)count2++;
    else if(lst[i].size()>2){
      flag=1;break;
    }
  }
  if(flag){
    cout<<"-1";return 0;
  }
  int len=unused.size();
  if(count2>len){
    cout<<"-1";return 0;
  }
  int index=0;
  for(int i=1;i<=n;i++){
    if(lst[i].size()==0)continue;
    if(lst[i].size()==2){
      cout<<i<<" "<<lst[i][0]<<" "<<lst[i][1]<<"\n";
    }
    else {
      cout<<i<<" "<<lst[i][0]<<" "<<unused[index]<<"\n";
      index++;
    }
  }
  while(index!=len){
    cout<<unused[index]<<" "<<unused[index+1]<<" "<<unused[index+2]<<"\n";
    index=index+3;
  }
  return 0;
}
