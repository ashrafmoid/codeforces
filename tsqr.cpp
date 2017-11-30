#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
  long long int n,m,a;
  cin>>n>>m>>a;
  long long int r,c,ans;
//  r=ceil(double (n/a));
  //c=ceil(double (m/a));
  r=n/a;c=m/a;
  if(n%a>0)r++;if(m%a>0)c++;
  cout<<r*c;
  return 0;
}
