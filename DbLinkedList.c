#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    void* value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DbLinkedList{
    size_t size;
    Node* head;
    Node* tail;
} DbLinkedList;

DbLinkedList* createDbLinkedList(){

    DbLinkedList* tmp = (DbLinkedList*)malloc(sizeof(DbLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

void deleteDbLinkedList(DbLinkedList** list){

    Node* tmp = (*list)->head;
    Node* next = NULL;

    while(tmp){

        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}

void pushFront(DbLinkedList* list, void* data){

    Node* tmp = (Node*)malloc(sizeof(Node));

    if(tmp == NULL){
        exit (1);
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = NULL;

    if(list->head){
        list->head->prev = tmp;
    }
    list->head = tmp;

    if(list->tail == NULL){

        list->tail = tmp;
    }

    list->size++;
}

void* popFront(DbLinkedList* list){

    Node* tmp;
    void* data;

    if(list->head == NULL){
        exit (2);
    }

    tmp = list->head;
    list->head = list->head->next;

    if(list->head){

        list->head->prev = NULL;
    }

    if(tmp == list->tail){

        list->tail == NULL;
    }

    data = tmp->value;
    free(tmp);

    list->size--;

    return data;
}

void* getN(DbLinkedList* list, size_t index){

    Node* tmp = NULL;
    size_t  i;

    if(index < list->size/2){

        i = 0;
        tmp = list->head;

        while(tmp && i < index){

            tmp = tmp->next;
            i++;
        }
    } else {

        i = list->size - 1;
        tmp = list->tail;

        while(tmp && i > index){

            tmp = tmp->prev;
            i--;
        }
    }
    return tmp;
}

void insertDb(DbLinkedList* list,size_t index, void* value){

    Node* elm = NULL;
    Node* ins = NULL;

    elm = getN(list,index);

    if(elm == NULL){
        exit(3);
    }
    ins = (Node*)malloc(sizeof(Node));
    ins->value = value;
    ins->prev = elm;
    ins->next = elm->next;

    if(elm->next){
        elm->next->prev = ins;
    }
    elm->next = ins;

    if( !elm->prev ){
        list->head = elm;
    }
    if( !elm->next){
        list->tail = elm;
    }
    list->size++;
}

void printDbLinkedList(DbLinkedList* list,void (*fun)(void*)){
    Node* tmp = list->head;

    while(tmp){

        fun(tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void printInt(void *value){
    printf("%d  ", *((int*)value));
}

int main(void) {

	char c;
	int i = 2 ;
	int* q ;

	DbLinkedList* list = createDbLinkedList();										//Создаем указатель на первый элемент списка

	printf("\n\n	Enter :  '+' - to add ;\n 	    	 '-' - for output;\n 		 'i' - to insert a new node;\n\
	         'p' - to display the values in the list;\n                 'd' - to delete list and exit;\n");

	for(;;) {
        *q = rand();
		c = getchar();


		switch (c) {

			case '+': pushFront(list,q++); break;
			case '-': printf("%d  ", (void*)popFront(list)); break;
			case 'i': insertDb(list, i++, q++); break;
			case 'p': printDbLinkedList(list, printInt); break;
			case 'd': deleteDbLinkedList(&list); printf("\n Ok"); return 0;
		}
	}

}


