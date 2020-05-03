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


/******************************************************************************
* Function:      selectionSort n^2   
* Description:  选择排序   找到后面的最大值与当前的位置进行交换，排序。 
* Where:
* Return:           
* Error:            
*****************************************************************************/
template<typename T>
void selectionSort(T arr[],int n){
	for (int i=0;i<n;i++)
	{
		int minIndex=i;
		for (int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[minIndex])
				minIndex=j;
		}
		swap(arr[i],arr[minIndex]);
	}
}
/******************************************************************************
* Function:         void bubbleSort
* Description:      
* Where:
* Return:           
* Error:            
* ref: 优化冒泡法，但是还是比较慢https://blog.csdn.net/ysunflower/article/details/80425788
*****************************************************************************/
template<typename T>
void bubbleSort(T arr[],int n){
	for (int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(arr[j+1]<arr[j]){
				swap(arr[j+1],arr[j]);
			}
		}
	}
	
}
/******************************************************************************
* Function:         void insertSort
* Description:      
* Where:
* Return:           
* Error:            
*****************************************************************************/
template<typename T>
void insertSort(T arr[],int n){
	for (int i=1;i<n;i++){
		for (int j=i;j>0&&arr[j]<arr[j-1]; j--) {
			swap(arr[j],arr[j-1]);
		}
	}
}
/******************************************************************************
* Function:         void insertSort2
* Description:     优化 不使用交换,提前终止,对于有序的数组有优势
* Where:
* Return:           
* Error:            
*****************************************************************************/
template<typename T>
void insertSort2(T arr[],int n){
	for(int i=0;i<n;i++){
		T e =arr[i];
		int j;// j 报错元素 e 应该插入的位置。
		for(j=i;j>0&&arr[j-1]>e;j--){
			arr[j]=arr[j-1];
		}
		arr[j]=e;
	}	
}
/******************************************************************************
* Function:         void shellSort
* Description:      
* Where:
* Return:           
* Error:            
*****************************************************************************/
template<typename T>
void shellSort(T arr[],int n){
	// 计算 increment sequence:1,4,40,121,364,1093...
	int h=1;
	while(h<n/3)
		h=3*h+1;

	while(h>=1){
		//h-sort the array
		for (int i = h;  i < n; i++) {
			// 对arr[i],arr[i-h],arr[i-2*h,arr[i-2*h]]使用插入排序	
			T e=arr[i];
			int j;
			for(j=i;j>=h&&e<arr[j-h];j-=h)
				arr[j]=arr[j-h];
			arr[j]=e;
		}
		h/=3;
}
	
}
int main(int argc, char const *argv[])
{
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2=SortTestHelper::copyIntArray(arr,n);
	int *arr3=SortTestHelper::copyIntArray(arr,n);
	int *arrNearlySorted=SortTestHelper::generateNearlyOrderedArray(n,100);

	float a[5]={1,2,3.2,5,4};
	Student d[4]={{"A",12},{"c",14},{"C",14},{"D",9}};
// 测试排序时间	
	SortTestHelper::testSort("Selection Sort",selectionSort,arr,n);

	SortTestHelper::testSort("Insert Sort",insertSort,arr2,n);

	SortTestHelper::testSort("Insert Sort2",insertSort2,arr3,n);
// 对于近乎有序的数据，插入排序，比后面的nlogn的算法会更好。比如服务器日志等的对时间排序。 它会变成O n 级别的算法。	
	SortTestHelper::testSort("Insert Sort2",insertSort2,arrNearlySorted,n);

	int *arrBubble=SortTestHelper::generateRandomArray(n,0,n);
	SortTestHelper::testSort("bubble Sort",bubbleSort,arrBubble,n);
	
	int *arrShell=SortTestHelper::generateRandomArray(n,0,n);
	SortTestHelper::testSort("shell Sort",shellSort,arrShell,n);
	


//	SortTestHelper::printArray(d, 4);

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	delete[] arrNearlySorted;
	return 0;
}
