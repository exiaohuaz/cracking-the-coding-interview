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

struct listnode *reverse(struct listnode *list){
	struct listnode *head = NULL;
	while(list != NULL){
		struct listnode *new = malloc(sizeof(struct listnode));
    new->next = head;
    new->data = list->data;
		list = list->next;
		new->next = head;
		head = new;
	}
	return head;
}

bool is_palindrome(struct listnode *list){
	struct listnode *reversed = reverse(list);
  printf("reversed: ");
  print_int_list(reversed);
  printf("forward: ");
  print_int_list(list);
	
	while(list->next != NULL){
		if(list->data != reversed->data){
			return false;
		}
		list = list->next;
		reversed = reversed->next;
	}
  return true;
}

int main(){
  int arr[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
  struct listnode *pal = create_list_from_array(arr, 9);
  printf("palindrome?: %s\n", is_palindrome(pal) ? "true" : "false");
}

