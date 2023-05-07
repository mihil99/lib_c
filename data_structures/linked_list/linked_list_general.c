#include <stdio.h>
#include <stdlib.h>

#include "linked_list_general.h"

Linked_List_General *ll_insert(Linked_List_General *list, void *value) {
  Linked_List_General *head = malloc(sizeof(Linked_List_General));
  if (head == NULL) {
    printf("Something went wrong inserting in linked list.\n");
  }
  head->next = list;
  head->value = value;
  return head;
}

// inserts before element found
// returns inserted element, not head
Linked_List_General *ll_insert_before(Linked_List_General *list,
                                      void *insert_at, void *value) {
  Linked_List_General *current = list;
  Linked_List_General *prev = NULL;

  while (current->next != NULL) {
    if (current->next->compare(current->next->value, value)) {
      // match found
      Linked_List_General *new = malloc(sizeof(Linked_List_General));
      new->compare = current->compare;
      new->value = value;
      new->next = current->next;
      current->next = new;
      return new;
    }
    current = current->next;
  }
  return NULL;
}

Linked_List_General *ll_append(Linked_List_General *list, void *value) {
  Linked_List_General *current = list;
  Linked_List_General *new = malloc(sizeof(Linked_List_General));
  new->compare = list->compare;
  new->value = value;
  new->next = NULL;
  if (new == NULL) {
    printf("Something failed appending to linked list.\n");
  }
  while (current->next != NULL)
    current = current->next;
  current->next = new;
  return new;
}

int ll_delete_element(Linked_List_General *list, void *value) {
  Linked_List_General *current = list;
  while (!current->next->compare(current->next->value, value)) {
    current->next = current->next->next;
    free(current->next);
    return 1;
  }
  return 0;
}
