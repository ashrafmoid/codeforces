#include <iostream>
#include<algorithm>
using namespace std;
int get_sum(int* a,int be,int en){
    if(be==en)return a[be];
    int left=0,right=0,sum_mid=0;
    int temp=(be+en)/2;
    left=get_sum(a,be,temp);
    right=get_sum(a,temp+1,en);
     int mleft=a[temp],mrght=0;int maxx1=a[temp];int maxx2=0;
    for(int i=temp-1;i>=be;i--){
        mleft+=a[i];
        maxx1=max(mleft,maxx1);
    }
    for(int i=temp+1;i<=en;i++){
        mrght+=a[i];
        maxx2=max(maxx2,mrght);
    }
    return max(max(left,right),(maxx1+maxx2));

}
int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    cout<<get_sum(a,0,n-1)<<"\n";
	}
	return 0;
}
