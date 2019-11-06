#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int key;
	int data;
	struct node *next;
};

struct node*head = NULL;
struct node*current = NULL;

void insertFirst(int key, int data) {
	// creer un nouveau lien
	struct node *link = (struct node*)malloc(sizeof(struct node));
	link->key = key;
	link->data = data;
	//pointer vers l'ancien premier node
	link->next = head;
	//
	head = link;
} // puts the data in the list on position 1

void printList() {
	struct node *ptr = head;
	printf("[");
	while (ptr != NULL) {
		printf("(%d, %d)", ptr->key, ptr->data);
		ptr = ptr->next;
	}
	printf("]");
}

int lenght() {
	int l = 0;
	struct node *parcours;
	for (parcours = head; parcours != NULL; parcours = parcours->next) {
		l++;
	}
	return l;
}

void printNode(struct node *nd) {
	printf("Node deleted: (%d,%d)", nd->key, nd->data);
}

struct node *deleteALL() { // OR while (head!=NULL) {
						  // deleteFirst();
	struct node *tmp = head;
	head = NULL;
	return tmp;
}

struct node *deleteFirst() {

	struct node *tmp = head;
	head = head->next;
	//retourner le node a supprimer
	return tmp;
	free(tmp);

}

bool SEARCH(int key, int x) {
	struct node* current = head;
	while (current != NULL) {
		if (current->key == x)
			return true;
		current = current->next;
		printf("true");
	}
	return false;
	printf("false");
}

int main() {
	//inserer
	insertFirst(1, 45);
	printf("taille est %d: ", lenght());
	printList();
	printf("\n \n");

	insertFirst(3, 18);
	printf("taille est %d: ", lenght());
	printList();
	printf("\n \n");

	insertFirst(2, 78);
	printf("taille est %d: ", lenght());
	printList();
	printf("\n \n");

	insertFirst(5, 10);
	printf("taille est %d: ", lenght());
	printList();
	printf("\n \n");
	printNode(deleteFirst());
	printf("\n \n");
	printf("New list is : ");
	printList();
	deleteALL();
	printf("\n \n");
	printList();
	printf("\n \n");
	SEARCH(5, 10);

	system("pause");
	return 0;
}