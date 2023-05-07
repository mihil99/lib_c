#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Linked_List_General {
  void *value;
  struct Linked_List_General *next;
  int (*compare)(void *, void *);
} Linked_List_General;

Linked_List_General *ll_insert(Linked_List_General *list, void *value);
Linked_List_General *ll_insert_after(Linked_List_General *list, void *inser_at,
                                     void *value);
Linked_List_General *ll_append(Linked_List_General *list, void *value);
int ll_delete_element(Linked_List_General *list, void *value);
void *ll_pop(Linked_List_General *list);
void *ll_find(Linked_List_General *list, void *value);
int ll_index(Linked_List_General *list, void *value);
void ll_print(Linked_List_General *list);

#endif
