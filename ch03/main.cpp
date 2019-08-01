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
		aux[i-1]=arr[i];
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

	if (l>=r)
		return;
	int mid =(l+r)/2; // 有可能有溢出的风险
	_mergeSort(arr,l,mid);
	_mergeSort(arr,mid+1,r);
	merge(arr,l,mid,r);
}	

template<typename T>
void mergeSort(T arr[],int n){
	_mergeSort(arr,0,n-1);	
}
int main(int argc, char const *argv[])
{
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArray(n, 0, n);
	mergeSort(arr,n);


	delete[] arr;
	return 0;
}
