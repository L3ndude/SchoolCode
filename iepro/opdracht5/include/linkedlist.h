#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <nds.h>

/*
Het onderstaande komt uit de ndslib...

typedef struct LinkedList{
	struct LinkedList *next;	//!< A pointer to the next node.
	struct LinkedList *prev;	//!< A pointer to the previous node.
	void *data;					//!< A pointer to some data.
}LinkedList;
*/

LinkedList * create_list();
void delete_list(LinkedList * list);
void add_list_element(LinkedList * list, void * data);
void remove_list_element(LinkedList * list, void * data);
void delete_list_element(LinkedList * list);
LinkedList* get_last_list_element(LinkedList * list);

#endif
