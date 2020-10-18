// Implementation of Circular Singly Linked List
#include<stdio.h>
#include<stdlib.h>

struct node {
  int info;
  struct node *next;  
};

typedef struct node* nodeptr;

nodeptr list1=NULL;
nodeptr list2=NULL;

nodeptr getnode() {
	
	nodeptr p=(nodeptr)malloc(sizeof(struct node));
	if(p==NULL) {
		printf("Could not create node\n");
	}
	else {
	p->next=NULL;
	return p;
   }
}

void insempty(nodeptr *list,int x) {
   nodeptr p=getnode();
   p->info=x;
   *list=p;
   p->next=p; // first node should point itself on creation
}

void insbegin(nodeptr *list,int x) {
	
   if(*list==NULL) {
	   insempty(list,x); 
   } 
   else {
	   nodeptr p=getnode();
	   p->info=x;
	   p->next=(*list)->next;
	   (*list)->next=p;
   }
}

void insend(nodeptr *list,int x) {
	
	if(*list==NULL) {
		insempty(list,x);
	}
	else {
		nodeptr p=getnode();
	    p->info=x;
		p->next=(*list)->next;
		(*list)->next=p;
		(*list)=p;
	}
}

void view(nodeptr list) {
	
	if(list==NULL) {
	 printf("List is Empty\n");
	 return;
	}
	
	nodeptr p=list->next;
	do {
		printf("%d ",p->info);
		p=p->next;
	}while(p!=list->next);
	printf("\n");
}


int main() {
   insend(&list1,5);
   insbegin(&list1,4);
   insbegin(&list1,3);
   insbegin(&list1,2);
   insbegin(&list1,1);
   insend(&list1,6);
   view(list1);
   insbegin(&list2,10);
   insbegin(&list2,9);
   insbegin(&list2,8);
   insbegin(&list2,7);
   view(list2);
   return 0;
}
