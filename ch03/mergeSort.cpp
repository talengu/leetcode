/******************************************************************************
 * File:             main.cpp
 *
 * Author:           talen  
 * Created:          07/31/19 
 * Description:      
 *****************************************************************************/

#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"

using namespace std;

template<typename T>
void insertionSort(T arr[],int l,int r){
	for (int i=l+1;i<=r;i++){
		T e=arr[i];
		int j;
		for(j=i;j>l&&arr[j-1]>e;j--)
			arr[j]=arr[j-1];
		arr[j]=e;
	}
	return;
}
/******************************************************************************
 * Function:         mergeSort
 * Description:      
 * Where:
 * Return:           
 * Error:            
 *****************************************************************************/

template<typename T>
void merge(T arr[], int l,int mid,int r){
	T aux[r-l+1];
	for (int i=l;i<=r;i++)
		aux[i-l]=arr[i];
	int i=l,j=mid+1;
	for (int k=l;k<=r;k++){
		if(i>mid){
			arr[k]=aux[j-l];
			j++;
		}
		else if(j>r){
			arr[k]=aux[i-l];
			i++;
		}
		else if(aux[i-l]<aux[j-l]){
			arr[k]=aux[i-l];
			i++;
		}
		else{
			arr[k]=aux[j-l];
			j++;
		}
	}
}

template<typename T>
// sort in arr[l...r]
void _mergeSort(T arr[], int l, int r){
	// 优化2 对于数据少的情况下可以采用插入排序，这样的数据近乎有序所以会快一点。
	if((r-l)<=15){
		insertionSort(arr,l,r);
		return;
	}

	//if (l>=r)
	//	return;
	int mid =(l+r)/2; // 有可能有溢出的风险
	_mergeSort(arr,l,mid);
	_mergeSort(arr,mid+1,r);

	//优化1 
	if (arr[mid]>arr[mid+1])//如果处理的数据近乎有序的数据的话可以加上这句话。
		merge(arr,l,mid,r);// 由于_mergeSort对其中的数据都有序了，所以只对大小不对的进行排序。
	//对于很有序的数据，归并排序不能退化成o（N）的算法，还是插入排序快。
}	

template<typename T>
void mergeSort(T arr[],int n){
	_mergeSort(arr,0,n-1);	
}

template<typename T>
// 自底向上，对链表比较好，没有使用index
void mergeSortBU(T arr[],int n){
	for (int sz=1;sz<=n;sz+=sz)
		for(int i=0;i+sz<n;i+=sz+sz)
			merge(arr,i,i+sz-1,min(i+sz+sz-1,n-1));
}

int main(int argc, char const *argv[])
{
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	SortTestHelper::testSort("mergeSortBU",mergeSortBU,arr,n);


	delete[] arr;
	return 0;
}
