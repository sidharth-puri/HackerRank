#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode listnode;

listnode* listnode_new(int val) {
	listnode* node = (listnode *) malloc(sizeof(listnode));
	node->val = val;
	node->next = NULL;
	return node;
}

void addNode(listnode* A, int i){
	listnode* temp = listnode_new(i);
	listnode* t = A;
	while(t->next != NULL){
		t = t->next;
	}
	t->next = temp;
}

/*
 * Complete the function below.
 */
int isPalin(listnode* A){
listnode* current=A;
int size=0;
while(current){
    current=current->next;
    size++;
}

int arr[size],i=0;
current=A;
while(current){
    arr[i]=current->val;
    i++;
    current=current->next;
}
i=size-1;
current=A;
while(current){
    if(current->val==arr[i]){
        current=current->next;
        i--;
    }
    else {
        return 0;
    }
}
return 1;

}
int main(){
	int count = 0;
	int i;
	int v;
	scanf("%d",&count);
	scanf("%d",&v);
	listnode* A = listnode_new(v);
	for(i=0;i<count-1;i++){
		scanf("%d",&v);
		addNode(A,v);
	}
	if(isPalin(A) == 1) printf("true");
	else printf("false");
}
