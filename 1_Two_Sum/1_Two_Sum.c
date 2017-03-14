// question: https://leetcode.com/problems/two-sum/#/description
/* 
   Given an array of integers, return indices of the two numbers such that
   they add up to a specific target. You may assume that each input would have 
   exactly one solution, and you may not use the same element twice.

   Example: Given nums = [2, 7, 11, 15], target = 9, Because nums[0] + nums[1] 
   = 2 + 7 = 9, return [0, 1]. */
// talen

#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target)
{
	int i, j, indices[2];
	for (i = 0; i < numsSize; i++)
	{
		if (target > nums[i])
		{
			for (j = 0; j < numsSize; j++)
			{
				if (i!=j &&(target - nums[i]) == nums[j] )
				{
					indices[0] = i + 1;
					indices[1] = j + 1;
					  printf("%d %d",indices[0],indices[1]);
					return indices;
				}
			}
		}
	}
}













int main(int argc, char const *argv[])
{
	printf("%s\n", "start");
	int nums[6] = { 1, 1, 2, 5, 6, 9 };
	twoSum(nums, 6, 15);
	return 0;











}