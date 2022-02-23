"""
# 791. Custom Sort String
`S` and `T` are strings composed of lowercase letters. In `S`, no letter occurs more than once.

`S` was sorted in some custom order previously. We want to permute the characters of `T` so that they match the order that `S` was sorted. More specifically, if `x` occurs before `y` in `S`, then `x` should occur before `y` in the returned string.

Return any permutation of `T` (as a string) that satisfies this property.
"""

class Solution:
    def customSortString(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        chars=[0]*26
        for i,c in enumerate(S):
            chars[ord(c)-ord('a')]=len(S)-i
            #print(ord(c)-ord('a'))
        lis=[]
        for i,c in enumerate(T):
            lis.append([c,chars[ord(c)-ord('a')]])
        rstr=''
        for item in sorted(lis, key=lambda x:x[1],reverse=True):
            rstr+=item[0]
        return rstr
        
n = Solution()
S = "cba"
T = "abcd"
print(n.customSortString(S,T))