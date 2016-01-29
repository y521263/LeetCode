//https://leetcode.com/problems/add-two-numbers/

#include<iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
void printlist(ListNode* l1)
{
	ListNode* pl1 = l1;
	while (pl1!= NULL)
	{
		std::cout << pl1->val << " -> ";
		pl1 = pl1->next;
	}
	std::cout << std::endl;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* pl1 = l1;
	ListNode* pl2 = l2;
	ListNode* ret = new ListNode(0);
	ListNode* pret = ret;
	int step = 0;
	while (pl1 != NULL || pl2 != NULL)
	{
		int tmp = 0;
		if (pl1 != NULL)
		{
			tmp += pl1->val;
			pl1 = pl1->next;
		}
		if (pl2 != NULL)
		{
			tmp += pl2->val;
			pl2 = pl2->next;
		}
		ListNode* node = new ListNode((tmp + step) % 10);
		step = (tmp + step) / 10;
		pret->next = node;
		pret = pret->next;
	}
	if (step != 0)
	{
		ListNode* node = new ListNode(step);
		pret->next = node;
	}
	pret = ret->next;
	delete ret;
	return pret;
}
int main()
{
	ListNode* l1 = new ListNode(1);

	ListNode* l2 = new ListNode(9);
	l2->next = new ListNode(9);
	auto ll = addTwoNumbers(l1, l2);
	printlist(ll);
}