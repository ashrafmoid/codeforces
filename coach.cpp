#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct node{
  int a,b;
}node;
bool cmp(node x,node y){
  if(x.a!=x.b)return x.a<y.b;
  else return x.b<y.b;
}
int main(){
  int n,m;
  cin>>n>>m;
  node* q=(node*)malloc(m*sizeof(node));
  for(int i=0;i<m;i++){
    cin>>q[i].a>>q[i].b;
  }
  //cout<<"input\n";
  sort(q,q+m,cmp);
  int flag=0;
  vector< vector<int> > team(n/3+1,vector<int>());
  //team.push_back(n/3,vector<int>());
  vector<int> unused;
  int f[n/3+1];
  int group[n+1];
  for(int i=0;i<=n;i++){
    group[i]=-1;
    if(i<n/3)f[i]=0;
  }
  int prev=0;
  //cout<<"loop begins\n";
  for(int i=0;i<m;i++){
    //cout<<"working ";
      if(group[q[i].a]!= -1 && group[q[i].b]!= -1 )continue;
      if(group[q[i].a]!= -1){
        group[q[i].b]=group[q[i].a];
        f[group[q[i].a]]++;
        if(f[group[q[i].a]]>3){
          flag=1;break;
        }
      //  cout<<"f[group[q[i].a]]="<<f[group[q[i].a]]<<"\n";
        //team[group[q[i].a]].push_back(q[i].a);
        team[group[q[i].a]].push_back(q[i].b);
        //cout<<"f[group[q[i].a]]="<<f[group[q[i].a]]<<"\n";
      }
      else if(group[q[i].b]!=-1){
        group[q[i].a]=group[q[i].b];
        f[group[q[i].a]]++;
        if(f[group[q[i].a]]>3){
          flag=1;break;
        }
        //cout<<"f[group[q[i].a]]="<<f[group[q[i].a]]<<"\n";
        team[group[q[i].a]].push_back(q[i].a);
        //team[group[q[i].a]].push_back(q[i].b);
        //cout<<"f[group[q[i].a]]="<<f[group[q[i].a]]<<"\n";
      }
      else{
        group[q[i].a]=group[q[i].b]=prev;prev++;
        f[group[q[i].a]]=f[group[q[i].a]]+2;
        //cout<<"1\n";
        if(f[group[q[i].a]]>3){
          flag=1;break;
        }
        //cout<<"f[group[q[i].a]]="<<f[group[q[i].a]]<<"\n";
        team[group[q[i].a]].push_back(q[i].a);
        team[group[q[i].a]].push_back(q[i].b);
        //cout<<"f[group[q[i].a]]="<<f[group[q[i].a]]<<"\n";
      }
      if(prev>n/3)break;
      if(flag==1)break;
  }
  //cout<<"worked\n";
  if(prev>n/3){
    cout<<"-1";
    //cout<<"prev";
    return 0;
  }
  //int prfct=0;
  int incmp=0;
  if(flag){
    cout<<"-1";
    //cout<<"flag";
    return 0;
  }
  for(int i=1;i<=n;i++){
    if(group[i]==-1){
      unused.push_back(i);//continue;
    }
    else if(f[group[i]]>3){
      flag=1;break;
    }
    else if(f[group[i]]==2)incmp++;
  }
  if(flag){
    cout<<"-1";
    //cout<<"flag";
    return 0;
  }
  int len;int index=0;
  if(unused.empty()){
    len=0;
  }
  else{
    len=unused.size();
  }
  //cout<<"len="<<len<<"\n";
  incmp=incmp/2;
  //cout<<"incmp="<<incmp<<"\n";
  if(incmp>len){
    cout<<"-1";
    //cout<<"len";
    return 0;
  }
  //int limit=team.size();
  for(int i=0;i<n/3;i++){
    if(team[i].size()==0)continue;
    if(team[i].size()==3){
      cout<<team[i][0]<<" "<<team[i][1]<<" "<<team[i][2]<<"\n";
    }
    else if(len){
      cout<<team[i][0]<<" "<<team[i][1]<<" "<<unused[index]<<"\n";
      index++;
    }
    /*else {
      flag=1;break;
    }*/
  }
  if(index!=len){
    for(int i=index;i<len;i=i+3){
      cout<<unused[i]<<" "<<unused[i+1]<<" "<<unused[i+2]<<"\n";
    }
  }
  return 0;
}
