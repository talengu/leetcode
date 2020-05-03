// question: https://leetcode.com/problems/two-sum/#/description
/*
   Given an array of integers, return indices of the two numbers such that
   they add up to a specific target. You may assume that each input would have
   exactly one solution, and you may not use the same element twice.

   Example: Given nums = [2, 7, 11, 15], target = 9, Because nums[0] + nums[1]
   = 2 + 7 = 9, return [0, 1]. */
// talen
//Test_OK 2017/3/18

#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target)
{
		int i, j;
		int * indices = (int *)malloc(sizeof(int) * 2);
		for (i = 0; i < numsSize; i++)
		{
				for (j = i+1; j < numsSize; j++)
				{
						if (target  == (nums[j]+nums[i]) )
						{
								indices[0] = i;
								indices[1] = j;
								break;
						}
				}
		}
		return indices;
}


int main(int argc, char const *argv[])
{
		printf("%s\n", "start");
		int nums[5] = { -1,-2,-3,-4,-5 };

		int *arr=twoSum(nums, 5,-8);
		printf("%d %d\n",arr[0],arr[1] );
		return 0;











}
