#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int value;
	const char *name;
	struct Node *next;
} node_t;



int init_node(node_t **n, int v, const char *name)
{
	node_t *thisnode = *n;
	
	thisnode = (node_t *)malloc(sizeof(node_t));
	
	if (thisnode != NULL) {
		printf("allocated %d bytes for node\n", sizeof(node_t));
		thisnode->value = v;
		thisnode->name = name;
		thisnode->next = (node_t *)malloc(sizeof(node_t));
		
		printf("init_node: val = %d, name = %s\n", thisnode->value, thisnode->name);	
		*n = thisnode;
		return 0;
	}
	
	return -1;
}


int insert_tail(node_t **list, int val, const char *name)
{
	node_t *thisnode = *list;
	
	while (thisnode != NULL) {		
		printf("insert_tail current value: %d, %s\n", thisnode->value, thisnode->name);	
		thisnode = thisnode->next;		
	}	
	
	init_node(&thisnode, val, name);	
	
	node_t *tmp = *list;
	while (tmp != NULL) {
		printf("%d, %s\n", tmp->value, tmp->name);
		tmp = tmp->next;
	}

	printf("XXX: %d, %s\n", thisnode->value, thisnode->name);
}

void print_list(node_t *list)
{
	node_t *thisnode = list;
	
	while (thisnode != NULL) {
		printf("node value: %d, %s\n", thisnode->value, thisnode->name);
		thisnode = thisnode->next;
	}
}

void dostuff(int *val)
{
	int x = 999;
	*val = x;
}

int main(int argc, char *argv[])
{
	int localvar = 51;
	printf("localvar = %d\n", localvar);
	int *intptr = &localvar;
	printf("*intptr = %d\n", *intptr);
	dostuff(intptr);
	printf("dostuff *intptr = %d\n", *intptr);
	
	const char myname[64] = "Paul Hindt";
	
	node_t *first;
	node_t *second;
	node_t *third;

	init_node(&first, 23, myname);	
	init_node(&second, 42, "Laura");
	init_node(&third, 99, "Foo");		
	first->next = second;
	second->next = third;
	third->next = NULL;
	
	insert_tail(&first, 111, "Danker");
	
	print_list(first);
	
	return 0;
}

