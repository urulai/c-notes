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

Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method.
	if(head == NULL || head->next == NULL)
		return head;

	Node *temp = head, *tail;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	//save tail.
	tail = temp;
	// reassign head back to temp
	temp = head;

	// printf("taildata :%d, headdata: %d\n", tail->data, temp->data);	

	while(temp != tail)
	{
		if(tail->next == temp)
			break;
		
		int data;
		data = temp->data;
		temp->data = tail->data;
		tail->data = data;

		tail = tail->prev;
		temp = temp->next;
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

	swap = Reverse(head);
	printf("Reverse order\n");
	
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