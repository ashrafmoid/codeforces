#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int r3,r1;cin>>r3>>r1;
    r1=r3-r1;
    int count=0;
    int n;cin>>n;
    int x,y,r2;
    long int d=0;
    for(int i=0;i<n;i++){
      cin>>x>>y>>r2;
      d=(x*x+y*y);
      if(d>=(r1+r2)*(r1+r2)&&(r3>r2)&&d<=(r3-r2)*(r3-r2))count++;
    }
    cout<<count;
return 0;

}
