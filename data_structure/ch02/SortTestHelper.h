/******************************************************************************
 * File:             SortTestHelper.h
 *
 * Author:             talen
 * Created:          07/31/19 
 * Description:      generateRandomArray
 *                   printArray
 *****************************************************************************/

#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;
namespace SortTestHelper
{
	int *generateRandomArray(int n, int rangeL, int rangeR)
	{
		assert(rangeL <= rangeR);
		int *arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}
	// generate little random array
	int *generateNearlyOrderedArray(int n,int swapTimes){
		int *arr=new int[n];
		for(int i=0;i<n;i++)
			arr[i]=i;
		srand(time(NULL));
		for(int i =0;i<swapTimes;i++){
			int posx=rand()%n;
			int posy=rand()%n;
			swap(arr[posx],arr[posy]);

		}
		return arr;
	}
		
	 
	// print function
	template <typename T>
		void printArray(T arr[], int n)
		{
			for (int i= 0; i< n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	template<typename T>
		bool isSorted(T arr[],int n){
			for (int i=0;i<n-1;i++)
				if (arr[i]>arr[i+1])
					return false;
						return true;
		}
	template<typename T>
		void testSort(string sortName,void(*sort)(T[],int),T arr[],int n){
			// void(*sort)(T[],int) 这个是排序函数， 然后后面这个是测试用例和元素个数
			clock_t startTime=clock();
			sort(arr,n);
				clock_t endTime=clock();
			assert(isSorted(arr,n));
			cout<<sortName<<" : " <<double(endTime-startTime)/CLOCKS_PER_SEC<<" s"<<endl;
			return;
		}
// 如果变成模板函数，这里需要一个深拷贝的问题。当输入为一个函数列表的时候。
	int* copyIntArray(int a[],int n){
		int* arr=new int[n];
		copy(a,a+n,arr);
		return arr;
	}

} // namespace SortTestHelper

#endif // SORTTESTHELPER_H
