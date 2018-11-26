#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* createNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}


void insert(int data){
    struct Node* node = createNode(data);
    if (head==NULL){
        head = node;
    } else{
        head->prev = node;
        node->next = head;
        head  = node;
    }

}


void delete(struct Node* node){
    if (node->next ==NULL){
        (node->prev)->next = NULL;
    }else{
        (node->prev)->next = node->next;
    }

}


void printList(){
    //FILE *output;
    //char *mode = "w";
    //output = fopen("../myoutput.txt",mode);
    struct Node* temp;
    temp = head;
    int a = 1;
    while (temp!= NULL){
        printf("%10d", temp->data);
        if (a%8==0){
            printf("\n");
        }
        temp = temp->next;
        a++;
    }
    //fclose(output);


}

int main(int argc,char* argv[]) {
    int input = atoi(argv[1]);
    head = NULL;
    for (int i = input; i >=8; --i) {
        if (i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0){
            insert(i);
        }
    }

    insert(7);


    struct Node* curr = head;

    while ((curr->data) <= sqrt(input)){
        struct Node* ptr = curr->next;
        while (ptr!=NULL){
            struct Node* temp = ptr;
            if ((temp->data)%(curr->data)==0){
                struct Node* tmp = temp->next;
                delete(temp);
                ptr = tmp;
            }else{
                ptr = ptr->next;
            }
        }

        curr = curr->next;
    }

    insert(5);
    insert(3);
    insert(2);

    printList();

}