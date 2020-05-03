#include<iostream>
using namespace std;
template<typename T>
// sorted arr
int binarySearch(T arr[],int n,T target){

	int l=0,r=n-1;//arr[l...r]
	while(l<=r){
		//int mid=(l+r)/2;
		int mid=l+(r-l)/2;
		if(arr[mid]==target)
			return mid;
		if(target<arr[mid])
			r=mid-1;
		else
			l=mid+1;
	}
	return -1;

}// 如果递归会有一些差异
int main(){
	return 0;
}
