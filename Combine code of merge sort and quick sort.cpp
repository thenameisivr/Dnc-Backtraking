#include <iostream>
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

  int leftindex = 0;
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

  delete[] left;
  delete[] right;
}
void mergesort(int arr[],int s,int e,int size){
  if(s>e) return;
  if(s==e) return;

  int m = s+(e-s)/2;

  mergesort(arr,s,m,size);

  mergesort(arr,m+1,e,size);

  merge(arr,s,e);
}
void quicksort(int arr[],int s,int e){
  if(s>e) return;

  int j = s;
  int i = s-1;
  int pivot = e;
  while(j<pivot){
    if(arr[j]<arr[pivot]){
      i++;
      swap(arr[i],arr[j]);
    }
    j++;
  }

  i++;
  swap(arr[pivot],arr[i]);

  quicksort(arr,s,i-1);
  quicksort(arr,i+1,e);
}
int main() {
  int size = 6;
  int arr[10] = {6,5,4,3,2,1};
  cout<<"Original Array: ";
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
  cout<<"Array sorted by quick sort: ";
  int s = 0;
  int e = size-1;
  quicksort(arr,s,e);

  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
  cout<<"Array sorted by merge sort: ";
  mergesort(arr,s,e,size);
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}