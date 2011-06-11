#include <linkedlist.h>

LinkedList * create_list()
{
	LinkedList * list = new LinkedList;

	list->next = NULL;
	list->prev = NULL;
	list->data = NULL;

	return list;
}

void delete_list(LinkedList * list)
{
	if(list == NULL)
		return;

	LinkedList * next;

	do
	{
		next = list->next;
		delete_list_element(list);
		list = next;
	}
	while (list != NULL);
}

void add_list_element(LinkedList * list, void * data)
{
	list = get_last_list_element(list);
	list->next = create_list();
	list->next->prev = list;
	list->next->data = data;
}

void remove_list_element(LinkedList * list, void * data)
{
	do
	{
		if(list->data == data)
		{
			list->prev->next = list->next;

			if(list->next != NULL)
				list->next->prev = list->prev;

			delete_list_element(list);
		}

		list = list->next;
	}
	while(list != NULL);
}

void delete_list_element(LinkedList * list)
{
	delete list;
}

LinkedList * get_last_list_element(LinkedList * list)
{
	while (list->next != NULL)
		list = list->next;

	return list;
}
