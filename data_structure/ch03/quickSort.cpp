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
// 对arr[l...r]部分进行partition 操作
// 返回p, 使得arr[l...p-1] < arr[p]; arr[p+1...r]>arr[p]
template<typename T>
int __partition(T arr[],int l,int r){
	// optimize 随机的算法
	swap(arr[l],arr[rand()%(r-l+1)+l]);
	
	T v=arr[l];
	int j=l;
	// arr[l+1...j]<v; arr[j+1...i]
	for(int i=l+1;i<=r;i++){
		if(arr[i]<v){
			swap(arr[j+1],arr[i]);
			j++; 
		}
	}
	swap(arr[l],arr[j]);
	return j;

}
template<typename T>
void __quickSort(T arr[],int l,int r){
	if (l>r)
		return;
	int p=__partition(arr,l,r);
	__quickSort(arr,l,p-1);
	__quickSort(arr,p+1,r);
}
template<typename T>
void quickSort(T arr[],int n){
	__quickSort(arr,0,n-1);

}



int main(int argc, char const *argv[])
{
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	// 在随机数组上，比归并排序快一点
	SortTestHelper::testSort("quickSort",quickSort,arr,n);

	// 优化1 
	// 但数据有序，退化为n^2 的算法。// 如果开始选择的时候为第一位置。最好用随机初始
	int *arr1=SortTestHelper::generateNearlyOrderedArray(n,2);
	SortTestHelper::testSort("quickSort order",quickSort,arr1,n);

	// 优化2
	// 对于重复出现的数据速度比较慢
	int *arr2 = SortTestHelper::generateRandomArray(n, 0, 10);// 重复的数据比较多
	SortTestHelper::testSort("quickSort chongfu",quickSort,arr2,n);


	delete[] arr;
	return 0;
}
