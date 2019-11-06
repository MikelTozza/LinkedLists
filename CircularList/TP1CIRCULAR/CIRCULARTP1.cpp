#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;
// inserer(DONE), supprimer, afficher(done) REGARDER LE CODE feedback svp

struct Node {
	int data;
	int key;
	struct Node* next;
	struct Node* prev;
};
struct node*head = NULL;

struct Node *addToEmpty(struct Node *last, int data) // INSERT INTO EMPTY LIST
{
	// This function is only for empty list 
	if (last != NULL)
		return last;

	// Creating a node dynamically. 
	struct Node *last =
		(struct Node*)malloc(sizeof(struct Node));

	// Assigning the data. 
	last->data = data;

	// Note : list was empty. We link single node 
	// to itself. 
	last->next = last;

	return last;
}

struct Node *addBegin(struct Node *last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);

	// Creating a node dynamically. 
	struct Node *temp
		= (struct Node *)malloc(sizeof(struct Node));

	// Assigning the data. 
	temp->data = data;

	// Adjusting the links. 
	temp->next = last->next;
	last->next = temp;

	return last;
}// INSERT INTO BEGENNING OF LIST

void traverse(struct Node *last)
{
	struct Node *p;

	// If list is empty, return. 
	if (last == NULL)
	{
		printf("List is empty.");
		return;
	}

	// Pointing to first Node of the list. 
	p = last->next;

	// Traversing the list. 
	do
	{
		printf("" + p->data);
		p = p->next;

	} while (p != last->next);

} // traverse the circular formation

void deleteNode(Node** head, int key)
{

	// If linked list is empty 
	if (*head == NULL)
		return;

	// If the list contains only a single node 
	if ((*head)->data == key && (*head)->next == *head)
	{
		free(*head);
		*head = NULL;
	}

	Node *last = *head, *d;

	// If head is to be deleted 
	if ((*head)->data == key) {

		// Find the last node of the list 
		while (last->next != *head)
			last = last->next;

		// Point last node to the next of head i.e.  
		// the second node of the list 
		last->next = (*head)->next;
		free(*head);
		*head = last->next;
	}

	// Either the node to be deleted is not found  
	// or the end of list is not reached 
	while (last->next != *head&&last->next->data != key) {
		last = last->next;
	}

	// If node to be deleted was found 
	if (last->next->data == key) {
		d = last->next;
		last->next = d->next;
		free(d);
	}
	else
		printf( "no such keyfound")
;
}
void printList(Node* head)
{
	Node* temp = head;
	if (head != NULL) {
		do {
			printf(""+ temp->data);
			temp = temp->next;
		} while (temp != head);
	}
	printf("----------");
}

int main() {
	struct Node *last = NULL;
	last = addToEmpty(last, 1);
	last = addBegin(last, 2);
	traverse(last);
	//printList(head);
	//deleteNode(&head, 2); &head fonctionne pas
	printf("list apres le delete :");
}