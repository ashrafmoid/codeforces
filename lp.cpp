#include<iostream>
#include<algorithm>
using namespace std;
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int indx,count=0;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            count++;indx=i;
        }
    }
    if(count==0)
        cout<<"0";
    else if(count==1){
        if(a[n-1]<=a[0])
        cout<<(n-1-indx);
        else cout<<"-1";
    }
    else cout<<"-1";
    return 0;
}
