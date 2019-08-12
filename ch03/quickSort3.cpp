#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"
// quick sort 3 ways 
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
void __quickSort3(T arr[],int l,int r){
	if (r-l<=15){
		insertionSort(arr,l,r);
		return;
	}

	//partition
	swap(arr[l],arr[rand()%(r-l+1)+l]);
	T v =arr[l];

	int lt=l;
	int gt=r+1;
	
	int i =l+1;
	while(i<gt){
		if(arr[i]<v){
			swap(arr[i],arr[lt+1]);
			lt++;
			i++;
		}else if(arr[i]>v){
			swap(arr[i],arr[gt-1]);
			gt--;
		}
		else{
			i++;
		}
	}
	swap(arr[l],arr[lt]);

	__quickSort3(arr,l,lt-1);
	__quickSort3(arr,gt,r);
}
template<typename T>
void quickSort3(T arr[],int n){
	srand(time(NULL));
	__quickSort3(arr,0,n-1);

}
int main(int argc, char const *argv[])
{
	int n = 10000;
	int *arr2 = SortTestHelper::generateRandomArray(n, 0, 10);// 重复的数据比较多
	// 对于多重复数据
	SortTestHelper::testSort("quickSort chongfu",quickSort3,arr2,n);


	delete[] arr2;
	return 0;
}
