#include<iostream>
using namespace std;
void quicksort(int arr[],int s,int e,int size){
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
  swap(arr[i],arr[pivot]);

  quicksort(arr,s,i-1,size);

  quicksort(arr,i+1,e,size);
}
int main(){
  int size = 10;
  int arr[] = {10,9,8,7,6,5,4,3,2,1};
  int s = 0;
  int e = size-1;
  quicksort(arr,s,e,size);
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
}