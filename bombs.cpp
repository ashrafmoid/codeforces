#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef struct node {
  long long int x,y;
}point;
bool cmp(point a,point b){
      /*if(a.x<0&&b.x<0){
        return a.x>b.x;
      }*/
      if(a.x==b.x){
        /*if(a.y<0&&b.y<0)return a.y>b.y;
        else if(a.y==0&&b.y<0)return a.y>b.y;
        else if(a.y<0&&b.y==0)return a.y>b.y;
        return a.y<b.y;*/
        return (abs(a.y)<abs(b.y));
      }
    /*  else if(a.x<0&&b.x<0){
        return a.x>b.x;
      }*/
      else if(a.x<0&&b.x<0)
        return (abs(a.x)<abs(b.x));
      return a.x<b.x;
}
int main(){
  int n;cin>>n;
  int count=0;
  point* q=(point*)malloc(n*sizeof(point));
  for(int i=0;i<n;i++){cin>>q[i].x>>q[i].y;if(q[i].y==0||q[i].x==0)count++;}
  sort(q,q+n,cmp);
  cout<<(6*n-2*count)<<"\n";
  for(int i=0;i<n;i++){
    if(q[i].x<0){
      if(q[i].y==0){
        cout<<"1 "<<abs(q[i].x)<<" L\n";cout<<"2\n";
        cout<<"1 "<<abs(q[i].x)<<" R\n";cout<<"3\n";
      }
    //  else if(q[i].x<0){
        else if(q[i].y<0){cout<<"1 "<<abs(q[i].x)<<" L\n";cout<<"1 "<<abs(q[i].y)<<" D\n";cout<<"2\n";cout<<"1 "<<abs(q[i].y)<<" U\n";
        cout<<"1 "<<abs(q[i].x)<<" R\n";
        cout<<"3\n";}
        else {cout<<"1 "<<abs(q[i].x)<<" L\n";cout<<"1 "<<abs(q[i].y)<<" U\n";cout<<"2\n";cout<<"1 "<<abs(q[i].y)<<" D\n";cout<<"1 "<<abs(q[i].x)<<" R\n";
        cout<<"3\n";}
      //}
    }
    /*else if(q[i].x<0){
      if(q[i].y<0){cout<<"1 "<<abs(q[i].x)<<" L\n";cout<<"1 "<<abs(q[i].y)<<" D\n";cout<<"2\n";cout<<"1 "<<abs(q[i].y)<<" U\n";
      cout<<"1 "<<abs(q[i].x)<<" R\n";
      cout<<"3\n";}
      else {cout<<"1 "<<abs(q[i].x)<<" L\n";cout<<"1 "<<abs(q[i].y)<<" U\n";cout<<"2\n";cout<<"1 "<<abs(q[i].y)<<" D\n";cout<<"1 "<<abs(q[i].x)<<" R\n";
      cout<<"3\n";}
    }*/
    else if(q[i].x>0){
      if(q[i].y==0){
        cout<<"1 "<<abs(q[i].x)<<" R\n";cout<<"2\n";cout<<"1 "<<abs(q[i].x)<<" L\n";
        cout<<"3\n";
      }
      else if(q[i].y<0){
        cout<<"1 "<<abs(q[i].x)<<" R\n";cout<<"1 "<<abs(q[i].y)<<" D\n";cout<<"2\n";cout<<"1 "<<abs(q[i].y)<<" U\n";cout<<"1 "<<abs(q[i].x)<<" L\n";
        cout<<"3\n";
      }
      else {
        cout<<"1 "<<abs(q[i].x)<<" R\n";cout<<"1 "<<abs(q[i].y)<<" U\n";cout<<"2\n";cout<<"1 "<<abs(q[i].y)<<" D\n";cout<<"1 "<<abs(q[i].x)<<" L\n";
        cout<<"3\n";
      }
    }
    else if(q[i].x==0){
      if(q[i].y<0){
        cout<<"1 "<<abs(q[i].y)<<" D\n";cout<<"2\n";cout<<"1 "<<abs(q[i].y)<<" U\n3\n";
      }
      else {
        cout<<"1 "<<abs(q[i].y)<<" U\n";cout<<"2\n";cout<<"1 "<<abs(q[i].y)<<" D\n3\n";
      }
    }
  }
  return 0;
}
