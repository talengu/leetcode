# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

def guess(mid):
    set_num=103
    if mid>set_num:
        return -1
    elif mid<set_num:
        return 1
    else:
        return 0
class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        low = 1
        high = n
        while low <= high:
            mid = (low + high) // 2
            res = guess(mid)
            print(mid)
            if res == 0:
                return mid
            elif res == -1:
                high = mid - 1
            else:
                low = mid + 1

n=Solution()
n.guessNumber(200)
