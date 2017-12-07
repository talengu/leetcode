// question: https://leetcode.com/problems/add-two-numbers/#/description
/*
   You are given two non-empty linked lists representing two non-negative integers.
   The digits are stored in reverse order and each of their nodes contain a single
   digit. Add the two numbers and return it as a linked list.

   You may assume the two numbers do not contain any leading zero, except the number 0 itself.

   Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
   Output: 7 -> 0 -> 8 */
// talen Test_OK
#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
		int val;
		struct ListNode *next;
};


struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
		struct ListNode *t1 = l1, *t2 = l2, *l = NULL, *tmp = NULL;
		int c = 0;
		while (t1 != NULL || t2 != NULL) {
				//加数，被加数
				int a = 0, b = 0;
				//声明空间
				struct ListNode *p = (struct ListNode *) malloc(sizeof(struct ListNode));
				p->next = NULL;

				if (t1 != NULL) {
						a = t1->val;
						t1 = t1->next;
				}
				if (t2 != NULL) {
						b = t2->val;
						t2 = t2->next;
				}

				p->val = (a + b + c) % 10;
				c = (a + b + c) / 10;
				l == NULL ? (l = p, tmp = p) : (tmp->next = p, tmp = p);
		}
		if (c == 1) {
				struct ListNode *p = (struct ListNode *) malloc(sizeof(struct ListNode));
				p->next = NULL, p->val = 1;
				tmp->next = p, tmp = p;
		}
		return l;

}
//打印
void listPrint(struct ListNode *l) {
		struct ListNode *tmp = l;

		while (tmp != NULL) {
				tmp->next != NULL ? printf("%d->", tmp->val) : printf("%d", tmp->val);
				tmp = tmp->next;
		}
		printf("\n");

}

int main() {
		struct ListNode *l1 = NULL, l1_n1, l1_n2, l1_n3;
		struct ListNode *l2 = NULL, l2_n1, l2_n2, l2_n3;

		l1_n1.val = 2;
		l1_n2.val = 4;
		l1_n3.val = 5;
		l1 = &l1_n1;
		l1_n1.next = &l1_n2;
		l1_n2.next = &l1_n3;
		l1_n3.next = NULL;

		l2_n1.val = 5;
		l2_n2.val = 6;
		l2_n3.val = 4;
		l2 = &l2_n1;
		l2_n1.next = &l2_n2;
		l2_n2.next = &l2_n3;
		l2_n3.next = NULL;


		listPrint(l1);
		listPrint(l2);
		listPrint(addTwoNumbers(l1, l2));
		return 0;
}
