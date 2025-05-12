#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) {
  struct list_node * new = malloc(sizeof(struct list_node));
  new->value = value; 
  return new; 
}

void insert_at_head(struct linked_list *list, size_t value) {
  struct list_node * new = new_node(value);
  new->next = list->head;
  list->head = new;
}

void insert_at_tail(struct linked_list *list, size_t value) {
  struct list_node * new = new_node(value);
  new->next = NULL;
  if(list->head == NULL) {
    list->head = new;
    return;
  }
  struct list_node * cur = list->head;
  while(cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = new;

}

size_t remove_from_head(struct linked_list *list) { 
  size_t cur_value = list->head->value;
  list->head = list->head->next;
  return cur_value; 
}

size_t remove_from_tail(struct linked_list *list) { 
  struct list_node * cur = list->head;
  while(cur->next != NULL) {
    cur = cur->next;
  }
  size_t cur_value = cur_value;
  cur->next = NULL;
  return cur_value; 
}

void free_list(struct linked_list list) {
  struct list_node * cur = list.head;
  struct list_node * next;
  while (cur != NULL) {
    next = cur->next;
    free(cur);
    cur = next;
  }
}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
