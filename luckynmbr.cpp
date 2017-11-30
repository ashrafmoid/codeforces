#include<iostream>
#include<algorithm>
using namespace std;
long int* a;
void make_num(long int sum,int no4,int no7,int* index){
  if(no4==0&&no7==0){
    a[*index]=sum;*index=*index+1;
    return;
  }
  if(no4>0){
     make_num(sum*10+4,no4-1,no7,index);
  }
  if(no7>0){
    make_num(sum*10+7,no4,no7-1,index);
  }
  return ;
}
int main(){
  long int num;
  cin>>num;
  int len=0,len1=0;
  long int temp=num;
  while(temp>0){
    temp=temp/10;len++;
  }
  a=(long int*)malloc(500*sizeof(long int));
  for(int i=0;i<500;i++)a[i]=0;
  int index=0;
  if(len%2!=0)len++;
  len1=len+2;
  long int sum=0;
  make_num(sum,len/2,len/2,&index);
  make_num(sum,len1/2,len1/2,&index);
  /*now find min no greater than n*/
  sort(a,a+index);
  for(int i=0;i<index;i++){
    if(a[i]>=num){
      cout<<a[i];break;
    }
  }
  return 0;
}
