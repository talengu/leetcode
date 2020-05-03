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
int __partition2(T arr[],int l,int r){
	// optimize 随机的算法
	swap(arr[l],arr[rand()%(r-l+1)+l]);

	T v=arr[l];
	int i =l+1,j=r;
	while(true){
		while(i<=r&&arr[i]<v)i++;
		while(j>=l+1 && arr[j]>v) j--;
		if (i>j)break;
		swap(arr[i],arr[j]);
		i++;
		j--;
	}
	swap(arr[l],arr[j]);
	return j;

}

template<typename T>
void __quickSort2(T arr[],int l,int r){
	if (r-l<=15){
		insertionSort(arr,l,r);
		return;
	}
	int p=__partition2(arr,l,r);
	__quickSort2(arr,l,p-1);
	__quickSort2(arr,p+1,r);
}
template<typename T>
void quickSort2(T arr[],int n){
	__quickSort2(arr,0,n-1);

}
int main(int argc, char const *argv[])
{
	int n = 10000;
	// 优化2
	// 对于重复出现的数据速度比较慢
	int *arr2 = SortTestHelper::generateRandomArray(n, 0, 10);// 重复的数据比较多
	SortTestHelper::testSort("quickSort chongfu",quickSort2,arr2,n);


	delete[] arr2;
	return 0;
}
