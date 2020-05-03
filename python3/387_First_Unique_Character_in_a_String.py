# question https://leetcode.com/problems/first-unique-character-in-a-string/description/
'''
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
'''
# talen
# spend a lot time
# class Solution:
#     def firstUniqChar(self, s):
#         """
#         :type s: str
#         :rtype: int
#         """
#         flag=-1
#         for i in range(len(s)):
#             #print(s[:i]+s[i+1:])
#             if s[i] not in s[:i]+s[i+1:]:
#                #print(s[i],s[i+1:])
#                flag=i
#                return i
#         return flag

# TODO: 2020/05/03 need to optimized
class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        flag=-1
        for i in range(len(s)):
            #print(s[:i]+s[i+1:])
            if s[i] not in s[:i]+s[i+1:]:
               #print(s[i],s[i+1:])
               flag=i
               return i
        return flag

m=Solution()
s_list = ["loveleetcode","z","","aaaa","aadadaad"]
for s in s_list:
    print(m.firstUniqChar(s))
