
#include<iostream>
using namespace std;
void merge(int arr[],int s,int e){
  int m = s+(e-s)/2;

  int lenleft = m-s+1;
  int lenright = e-m;

  int *left = new int[lenleft];
  int *right = new int[lenright];

  int k = s;
  for(int i=0;i<lenleft;i++){
    left[i] = arr[k];
    k++;

  }
  k = m+1;
  for(int i=0;i<lenright;i++){
    right[i] = arr[k];
    k++;
  }

  int leftindex  = 0;
  int rightindex = 0;
  int mainindex = s;

  while(leftindex<lenleft&&rightindex<lenright){
    if(left[leftindex]<right[rightindex]){
      arr[mainindex] = left[leftindex];
      mainindex++;
      leftindex++;
    }
    else{
      arr[mainindex] = right[rightindex];
      mainindex++;
      rightindex++;
    }
  }

  while(leftindex<lenleft){
    arr[mainindex] = left[leftindex];
      mainindex++;
      leftindex++;
  }
  while(rightindex<lenright){
    arr[mainindex] = right[rightindex];
      mainindex++;
      rightindex++;
  }


}
void mergesort(int arr[],int s,int e,int size){
  if(s>e) return;
  if(s==e) return;

  int m = s+(e-s)/2;

  mergesort(arr,s,m,size);

  mergesort(arr,m+1,e,size);

  merge(arr,s,e);

}
int main(){
  int size = 6;
  int arr[10] = {10,6,5,4,2,1};
  int s = 0;
  int e = size-1;
  mergesort(arr,s,e,size);
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
}



