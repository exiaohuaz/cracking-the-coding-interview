#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//not done


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

int find_length(struct listnode *list){
  int length = 0;
  while(list != NULL){
    length++;
    list = list->next;
  }
  return length;
}

struct listnode *add_recursive(struct listnode *l1, struct listnode *l2, int *carry){
//base case
	if(l1== NULL && l2 == NULL){
		*carry = 0;
    return NULL;
	}

	else{
		int sum = 0;
		if(l1 != NULL){
			sum += l1->data;
		}
		if(l2 != NULL){
			sum += l2->data;
		}
		struct listnode *rhs = add_recursive(l1==NULL ? NULL : l1->next, l2==NULL ? NULL : l2->next, carry);
		sum += *carry;
		struct listnode *new = create_node(sum % 10);
    new->next = rhs;
		*carry = sum / 10;
    return new;
	}
}

struct listnode *add_single_recursive(struct listnode *lhs, struct listnode *rhs, int *carry){
  
}

struct listnode *add(struct listnode *l1, struct listnode *l2){
  int length1 = find_length(l1);
  int length2 = find_length(l2);

  struct listnode *newl1 = l1;
  struct listnode *newl2 = l2;

  if(length1 > length2){
    for(int i = 0; i<length1-length2; i++){
      newl1 = newl1->next;
    }
  }
  else{
    for(int i = 0; i<length2-length1; i++){
      newl2 = newl2->next;
    }
  }

	int *carry = malloc(sizeof(int));
	struct listnode *list = add_recursive(newl1, newl2, carry);

	if(*carry != 0){
		struct listnode *carrynode = create_node(*carry);
		carrynode->next = list;
		list = carrynode;
	}

	return list;
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