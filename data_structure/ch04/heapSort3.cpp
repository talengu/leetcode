#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
#include<cmath>
#include<cassert>
#include<typeinfo>
#include"../ch03/SortTestHelper.h"
using namespace std;

template<typename T>
void __shiftDown(T arr[],int n,int k){
	while(2*k+1<n){ 
		int j =2*k+1;
		if(j+1<n && arr[j+1]>arr[j])
			j+=1;
		if (arr[k]>=arr[j])
			break;
		swap(arr[k],arr[j]);
		k=j;
	}
}
template<typename T>
// 仅使用数组空间进行 heap排序
void heapSort(T arr[],int n){
	//heapify
	for(int i=(n-1)/2;i>=0;i--)
	{
		__shiftDown(arr,n,i);
	}
	for(int i=n-1;i>0;i--){
		swap(arr[0],arr[i]);
		__shiftDown(arr,i,0);
	}

}
int main(){
	int n = 1000000;
	int *arr=SortTestHelper::generateRandomArray(n,0,n);

	SortTestHelper::testSort("Heap Sort 3",heapSort,arr,n);

	delete[] arr;
	
	return 0;
}
