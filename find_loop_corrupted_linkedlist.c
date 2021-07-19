#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listnode{
  struct listnode *next;
  struct listnode *prev;
  int data;
};

struct listnode *create_node(int data){
  struct listnode *new = malloc(sizeof(struct listnode));
  new->next = NULL;
  new->prev = NULL;
  new->data = data;
  return new;
}

struct listnode *prepend(struct listnode *node, struct listnode *head){
  if(head != NULL){
    head->prev = node;
    node->next = head;
  }
  head = node;
  return head;
}

void print_int_list(struct listnode *list){
  if(list == NULL){
    return;
  }
  else{
    struct listnode *node = list;
    while(node->next != NULL){
      printf("%d, ", node->data);
      node = node->next;
    }
    printf("%d\n", node->data);
  }
}

struct listnode *create_list(int length, int range){
  struct listnode *head = NULL;
  for(int i = 0; i<length; i++){
    struct listnode *new = create_node(rand() % range);
    head = prepend(new, head);
  }
  return head;
}

struct listnode *create_list_from_array(int *arr, int size){
  struct listnode *head = NULL;
  for(int i = size-1; i>=0; i--){
    struct listnode *new = create_node(arr[i]);
    new->next = head;
    head = new;
  }
  return head;
}

struct listnode *is_loop(struct listnode *list, int length, struct listnode *curr){
	struct listnode *pointer = list;
	for(int i = 0; i<length; i++){
		if(pointer == curr){
			return pointer;
    }
		else{
			pointer = pointer->next;
		}
	}
	return NULL;
}

int find_beginning_of_loop(struct listnode *list){
	if(list->next == NULL){
		printf("doesn’t have loop\n");
	}
	int length = 1;
	struct listnode *curr = list->next;
  struct listnode *result;
	while((result = is_loop(list, length, curr)) == NULL){
    printf("curr data is %d\n", curr->data);
    curr = curr->next;
		length++;
	}
	return result->data;
}

int main(){
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  struct listnode *head = create_list_from_array(arr, 9);
  print_int_list(head);
  struct listnode *tail = head;
  while(tail->next != NULL){
    tail = tail->next;
  }
  tail->next = head->next->next->next; //4
  printf("set up list \n");
  int result = find_beginning_of_loop(head);
  printf("result is %d \n", result);
  return 0;
}