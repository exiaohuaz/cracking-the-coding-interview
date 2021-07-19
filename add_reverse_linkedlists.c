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

struct listnode *create_list_from_array(int *arr, int size){
  struct listnode *head = NULL;
  for(int i = 0; i<size; i++){
    struct listnode *new = create_node(arr[i]);
    new->next = head;
    head = new;
  }
  return head;
}

struct listnode *add(struct listnode *l1, struct listnode *l2){
	struct listnode *head = NULL;
	struct listnode *curr = head;
	int carry = 0;
	while(l1 != NULL || l2 != NULL || carry != 0){
		int sum = 0;
		if(l1 != NULL){
			sum += l1->data;
			l1 = l1->next;
		}
		if(l2 != NULL){
		  sum += l2->data;
			l2 = l2->next;
		}
		sum += carry;
		struct listnode *new = create_node(sum % 10);
		if(curr == NULL){
			head = new;
			curr = new;
		}
		else{
			curr->next = new;
      curr = curr->next;
		}
		carry = sum / 10;
	}
	return head;
}




int main(){
  struct listnode *l1 = create_list(5, 10);
  struct listnode *l2 = create_list(9, 10);
  print_int_list(l1);
  print_int_list(l2);
  print_int_list(add(l1, l2));
  printf("\n");
  int arr[] = {9, 9, 9, 9, 9};
  struct listnode *l3 = create_list_from_array(arr, 5);
  struct listnode *l4 = create_list_from_array(arr, 5);
  print_int_list(l3);
  print_int_list(l4);
  print_int_list(add(l3, l4));
}