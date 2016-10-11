#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *next; };

void print_list (struct node *n){
  while(n){//keep going as long as n isnt null
    printf("[%d], ",n->i);
    n=n->next;
  }   
  printf("\n");
}

struct node* insert_front(struct node * _node, int n){
  struct node * ans=(struct node *) malloc(sizeof(struct node));// new node
  ans->i=n;//add stuff
  ans->next=_node;
  return ans;//return it
}


struct node* free_list(struct node *_node){
  struct node *ans= _node;
  struct node *nextnode=(struct node *)malloc(sizeof(struct node));
  while (_node){
    nextnode=_node->next;
    free(_node);
    _node=nextnode;
  }
  return ans;
}

  
int main(){
  struct node *test = (struct node *)malloc(sizeof(struct node));
  test-> i=13;
  test-> next=0;
  printf("\t testing printf \n");
  printf("test: ");
  print_list(test);
  
  printf("\n");
  printf("\n");

  printf("\t testing insert_front \n");
  printf("adding 20\n");
  struct node *a=insert_front(test, 20);
  print_list(a);
  printf("adding 30\n");
  struct node *b=insert_front(a, 33);
  print_list(b);

  printf("\n");
  printf("\n");

  printf("\t test for free_list \n");
  free_list(b);
  return 0;

}
  

