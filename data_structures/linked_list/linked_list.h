#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Linked_List {
  void *value;
  struct Linked_List *next;
} Linked_List;

Linked_List *ll_insert(Linked_List *list, void *value);
Linked_List *ll_insert_after(Linked_List *list, Linked_List *pointer,
                             void *value);
void ll_append(Linked_List *list, void *value);
void ll_delete_element(Linked_List *list, void *value);
void *ll_pop(Linked_List *list);
void *ll_find(Linked_List *list, void *value);
int ll_index(Linked_List *list, void *value);
void ll_print(Linked_List *list);

#endif
