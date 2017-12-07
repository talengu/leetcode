// question: https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description
/*
   Given a string, find the length of the longest substring without repeating characters.
   Examples:

   Given "abcabcbb", the answer is "abc", which the length is 3.

   Given "bbbbb", the answer is "b", with the length of 1.

   Given "pwwkew", the answer is "wke", with the length of 3. Note that
   the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
// talen
//TODO:not ok

#include <stdio.h>

bool isRepeat(char *s, int offset) {
		static int value[26];
		int sum = 0;
		for (int k = 0; k < offset; ++k) {
				value[*s - 'a'] = 1;
				s++;
		}
		for (int i = 0; i < 26; ++i) {
				sum += value[i];
		}
		if (sum != offset)
				return true;
		else {
				return false;
		}
}

int lengthOfLongestSubstring(char *s) {
		char *ptr = s;
		int offset = 0, total = 0,flag=0;
		while (*ptr != '\0') {
				ptr++;
		}
		total = ptr - s;
		(total < 26) ? (offset = total) : (offset = 26);
		while(flag!=1)
		{
				ptr = s;
				//printf("offset: %d ",offset);
				for (int i = 0; i < total - offset+1; ++i) {;
						                                    //printf("%d ", isRepeat(ptr + i, offset));
						                                    if (isRepeat(ptr + i, offset)== false) flag=1; }
				//printf("\n");
				offset--;
		}
		return offset+1;
}

int main(int argc, char const *argv[]) {
		/* code */
		int a=lengthOfLongestSubstring("bbbbb");
		printf("len: %d",a);

		return 0;
}
