# questions https://leetcode.com/problems/contains-duplicate-ii/description/
'''
Given an array of integers and an integer k, find out whether there are two distinct
indices i and j in the array such that nums[i] = nums[j] and the absolute difference
between i and j is at most k.

test ok
'''
class Solution:
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if nums==[]:
            return False
        lis = sorted([(i, x) for i, x in enumerate(nums)], key=lambda x: x[1])
        #print(lis)
        one_index = lis[0][0]
        value = lis[0][1]

        for item in lis[1:]:
            #print(item)
            if item[1] == value:
                #print('equal')
                #print(item[0] - one_index + 1)
                if (item[0] - one_index) <= k:
                    #print(item[0] - one_index)
                    return True
                one_index=item[0]
            else:
                one_index=item[0]
                value = item[1]
        return False