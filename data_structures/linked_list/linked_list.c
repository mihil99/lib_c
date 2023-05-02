#include <stdlib.h>

#include "linked_list.h"

Linked_List *ll_insert(Linked_List *list, void *value) {
  Linked_List *head = malloc(sizeof(Linked_List));
  head->next = list;
  head->value = value;
  return head;
}

// returns inserted element, not head
Linked_List *ll_insert_before(Linked_List *list, Linked_List *pointer,
                              void *value) {
  Linked_List *previous = NULL;
  while (list != pointer && list->next != NULL) {
    previous = list;
    list = list->next;
  }
  if (list == pointer) {
    Linked_List *insert = ll_insert(list, value);
    previous->next = insert;
    return insert;
  }
  return NULL;
}
