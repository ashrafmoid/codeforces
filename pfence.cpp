#include<iostream>
#include<algorithm>
using namespace std;
long   int a[100000];
  long int maxint=2000000000;
  long int minH(long int L,long  int R){
    long int ret = maxint;
    for( long int i=L;i<=R;++i){
        ret = min(ret, a[i]);
    }
    return ret;
}

long int rec(long int L, long int R, long int H){
    long int MH = minH(L,R);
    long int ret = MH - H;
    long int prev, state = 0;
    for(long int i=L;i<=R;++i){
        if(a[i] > MH && state == 0){
            prev = i;
            state = 1;
        } else if( a[i] == MH && state  == 1){
            ret += rec(prev, i-1, MH);
            state = 0;
        }
    }
    if(state == 1) ret += rec(prev, R, MH);
    return min(R-L+1, ret);
}
int main(){
int n;cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  cout<<rec(0,n-1,0)<<"\n";
  return 0;
}
