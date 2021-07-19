#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listnode{
  struct listnode *next;
  int data;
};

struct listnode *create_node(int data){
  struct listnode *new = malloc(sizeof(struct listnode));
  new->next = NULL;
  new->data = data;
  return new;
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
    new->next = head;
    head = new;
  }
  return head;
}

struct listnode *partition(struct listnode *list, int x){
	struct listnode *curr = list;
	while(curr->next != NULL){
		if(curr->next->data < x){
			struct listnode *temp = curr->next;
			curr->next = temp->next;
			temp->next = list;
			list = temp;
		}
		curr = curr->next;
    if(curr == NULL){
      break;
    }
	}
	return list;
}

int main(){
  struct listnode *list = create_list(10, 10);
  print_int_list(list);
  list = partition(list, 5);
  print_int_list(list);
}