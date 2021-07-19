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

struct listnode *kth_to_last(struct listnode *list, int k){
	struct listnode *fast = list;
	for(int i = 0; i<k; i++){
		if(fast == NULL){
			printf("list shorter than k");
			return NULL;
		}
		fast = fast->next;
	}
	struct listnode *slow = list;
	while(fast != NULL){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main(){
  struct listnode *list1 = create_list(7, 10);
  print_int_list(list1);
  struct listnode *k1 = kth_to_last(list1, 5);
  printf("5th node from end is %d \n", k1->data);
}