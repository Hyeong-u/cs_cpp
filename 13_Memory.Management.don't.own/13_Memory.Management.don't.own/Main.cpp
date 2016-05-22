#include <iostream>
typedef struct node NODE;

struct node {
	NODE *next;
	int val;
};

int findLastNodeValue(NODE *head)
{
	while (head->next != nullptr)
	{
		head = head->next;
	}
	return head->val;
}

int main()
{
	NODE *head = (NODE *)malloc(sizeof(NODE));
	memset(head, 0x00, sizeof(NODE));
	findLastNodeValue(head);

}