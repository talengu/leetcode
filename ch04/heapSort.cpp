/******************************************************************************
* File:             heapSort.cpp
*
* Author:           talen  
* Created:          08/12/19 
* Description:      这里包括 两个heap的优化，一个是使用insert方法的，另个直接使用
* 数组进行排序。
*****************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
#include<cmath>
#include<cassert>
#include<typeinfo>
#include"../ch03/SortTestHelper.h"
#include"heap.h"
using namespace std;

template<typename T>
void heapSort1(T arr[],int n){
	MaxHeap<T> maxheap=MaxHeap<T>(n);
	for(int i=0;i<n;i++)
		maxheap.insert(arr[i]);
	for(int i=n-1;i>=0;i--)
		arr[i]=maxheap.extractMax();

}
// heap 的优化
// heapify将数组变成二叉堆
template<typename T>
void heapSort2(T arr[],int n){
	MaxHeap<T> maxheap=MaxHeap<T>(arr,n);
	for(int i=n-1;i>=0;i--)
		arr[i]=maxheap.extractMax();

}

// result: 不同建立heap的效果，总是heap 2 优于 heap2.
//  但是还是比mergeSort 和 quickSort 慢，heapSort 主要用在动态数据上。
int main(){
	int n = 1000000;
	int *arr=SortTestHelper::generateRandomArray(n,0,n);
	int *arr1=SortTestHelper::copyIntArray(arr,n);

	SortTestHelper::testSort("Heap Sort 1",heapSort1,arr,n);
	SortTestHelper::testSort("Heap Sort 2",heapSort2,arr1,n);

	delete[] arr;
	delete[] arr1;
	
	return 0;
}
