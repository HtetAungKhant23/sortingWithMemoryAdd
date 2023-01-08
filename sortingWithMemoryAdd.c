#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node* next;
};

void addingData(struct node* myNode, int data){
    myNode->data = data;
    myNode->next = NULL;
}

struct node* takeMal(struct node* newNode, int data){
    newNode = (struct node*) malloc(sizeof (struct node));
    addingData(newNode,data);
    return newNode;
}

void linkedList(struct node* myNode,struct node* newNode){
    struct node* pre = (struct node*) malloc(sizeof (struct node));
    while (1) {
        if(myNode == NULL) {
            pre->next = newNode;
            break;
        } else{
            pre = myNode;
            myNode = myNode->next;
        }
    }
}

struct node *tail(struct node *head,int i){
    int count = 0;
    if(head != NULL){
        while (head->next != NULL){
            if(count == i-1){
                break;
            }
            count++;
            head = head->next;
        }
    }
    return head;
}

void sortNodes(struct node **Node, struct node *current,int i){
    struct node* nodeList = *Node;

    if  (*Node == NULL) {
        nodeList = current;
    } else{
        tail(nodeList,i)->next = current;
    }

    *Node = nodeList;
}

int sizeOfLinkedList(struct node* mNode){
    int count = 0;
    while (mNode != NULL){
        count++;
        mNode = mNode->next;
    }
    return count;
}

void searchingSmallestNode(struct node** mNode){

    struct node* cur = *mNode;
    struct node* toDel = *mNode;
    struct node *Node = NULL;
    struct node *one;
    one = cur;
    int length = sizeOfLinkedList(*mNode);
    for (int i = 0; i < length; i++) {
        while (cur != NULL) {
            if(cur->next == NULL){
                break;
            }
            if (one->data > cur->next->data) {
                one = cur->next;
                cur = cur->next;

            } else {
                cur = cur->next;
            }
        }
        sortNodes(&Node,one,i);

        struct node *prev = toDel;
        int count = 0;
        while (toDel != NULL){
            if(toDel->data == one->data){
                if(count == 0){
                    toDel = toDel->next;
                    *mNode = toDel;
                    break;
                }else{
                    prev->next = toDel->next;
                    break;
                }
            }
            prev = toDel;
            toDel = toDel->next;
            count++;
        }

        cur = *mNode;
        toDel = *mNode;
        one = cur;
    }
    *mNode = Node;

}



int main(){

    int arr[9]={72,28,16,9,11,42,25,31,5};

    struct node* head = takeMal(head,20);

    for(int i=0; i<9; i++){
        struct node* one = takeMal(one,arr[i]);
        linkedList(head,one);
    }

    searchingSmallestNode(&head);
    return 0;
}
