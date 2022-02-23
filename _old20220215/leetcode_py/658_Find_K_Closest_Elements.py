class Solution:
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        print(arr)
        mid_index = 0
        for i, item in enumerate(arr):
            if item > x:
                mid_index = i
                break
            if item == x:
                mid_index = i
                k -= 1
                break
        print(mid_index)


arr = [1, 2, 3, 4, 5]
k = 4
x = 2
n = Solution()
n.findClosestElements(arr, k, x)
