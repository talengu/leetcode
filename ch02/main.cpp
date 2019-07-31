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

using namespace SortTestHelper;// 生成测试数据

/******************************************************************************
* Function:         
* Description:      
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

int main(int argc, char const *argv[])
{
	int n = 100;
	int *arr = generateRandomArray(n, 0, n);

	float a[5]={1,2,3.2,5,4};
	Student d[4]={{"A",12},{"c",14},{"C",14},{"D",9}};


	selectionSort(d,4);

	printArray(d, 4);

	delete[] arr;
	return 0;
}
