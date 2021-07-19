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

struct listnode *remove_node(struct listnode *node, struct listnode *head){
	if(node->prev != NULL){
		node->prev->next = node->next;
	}
	else{
		head = node->next;
	}
	if(node->next != NULL){
		node->next->prev = node->prev;
	}
	node->next = NULL;
	node->prev = NULL;
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

struct listnode *check_dup(struct listnode *slow, struct listnode *fast, struct listnode *head){
	if(fast->data == slow->data){
		struct listnode *temp = fast;
		fast = fast->next;
		head = remove_node(temp, head);
	}
  else{
	  fast = fast->next;
	}
  return fast;
}

void remove_dup_linked_list(struct listnode *list){
	if(list == NULL || list->next == NULL){
		return;
	}
	struct listnode *slow = list;
	struct listnode *fast = list->next;
	while(slow->next->next != NULL){
    while(fast->next != NULL){
      fast = check_dup(slow, fast, list);
    }
    fast = check_dup(slow, fast, list);
		slow = slow->next;
    fast = slow->next;
  }
  fast = check_dup(slow, fast, list);
}

struct listnode *create_list(int length, int range){
  struct listnode *head = NULL;
  for(int i = 0; i<length; i++){
    struct listnode *new = create_node(rand() % range);
    head = prepend(new, head);
  }
  return head;
}

int main(){
  struct listnode *list = create_list(20, 10);
  print_int_list(list);
  remove_dup_linked_list(list);
  print_int_list(list);

  struct listnode *list2 = create_list(20, 10);
  print_int_list(list2);
  remove_dup_linked_list(list2);
  print_int_list(list2);
  return 0;
}