#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

Node *insert(Node *head, int data)
{
	Node *inode = (Node *)malloc(sizeof(Node));

	inode->data = data;
	inode->prev = inode->next = NULL;

	if(head == NULL)
		return inode;
	
	Node *swap = head;
	
	while(swap)
	{
		if(swap->data <= data)
		{
			if(swap->next)
				swap = swap->next;
			else{
				// insert at tail
				swap->next = inode;
				inode->prev = swap;
				break;
			}
		}
		else if(head == swap)
		{
			// insert at head
			inode->next = head;
			head->prev = inode;
			head = inode;
			break;
		}
		else {
			
			// printf("insert before %d ", swap->data);
			Node *temp = swap;
			swap = swap->prev;
			
			swap->next = inode;
			temp->prev= inode;
			inode->prev =swap;
			inode->next = temp;
			
			break;
			
		}
	}

	return head;
}

int main(int argc, char *argv[])
{
	if(argc < 2)
		exit(1);

	Node *head = NULL;

	int times = 0, N = atoi(argv[1]);

	while(times++ < N)
	{
		int data;
		scanf("%d", &data);
		head = insert(head, data);
	}

	Node *swap = head;
	while(swap)
	{
		printf("%d ",swap->data);
		if(swap->next)
			swap = swap->next;
		else
			break;
	}

	printf("\n");

	return 0;

}