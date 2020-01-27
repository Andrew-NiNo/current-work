//
// 		List.c		19.01.2020  Andrew M.
//
//	List implementation.


#include <stdio.h>
#include <stdlib.h>

 typedef struct Node {										//Создаем структуру с новым типом Node

	int value;
	struct Node* next;										//Она содержит значение  и указатель на следующий узел

} Node;

//Для добавления значения создаем функцию push, которая принимает указатель на указатель начала списка и значение
void push(Node** head, int data) {

	Node* tmp = (Node*) malloc(sizeof(Node));				//Выделяем память под новый узел
	tmp-> value = data;
	printf("\n 	Value  %d\n", data);
	tmp-> next = (*head);									//Указателю на следующий узел присваиваем адрес указателя на указатель начла списка
	(*head) = tmp;											//Указателю на указатель присваиваем адрес узла tmp
}

//Для вывода значения и удаления узла списка из стека используем функцию pop, которая принимает указатель на указатель начала списка
int pop(Node** head) {

		Node* prev = NULL;									//Создаем временный узел
		int val;

	if ((*head) == NULL) {									//Проверяем, не является ли список пустым.

		printf("\n 		The list is empty\n");
		return -1;
	}

	prev = (*head);											//Адрес указателя на указатель присваиваем адресу узла tmp
	val = prev-> value;										//Передаем значение из узла переменнной val
	printf("\n 	Present value  %d\n", val);
	(*head) = prev-> next;									//Присваиваем адрес из узла указателю на указатель начала списка
	free(prev);												//Освобождаем память от адреса временнного узла

return val;													//Возвращаем значение
}

//Для вывода на печать используем функцию printLinkedList, которая принимает указатель начала списка
void printLinkedList(const Node* head) {

	while(head) {

		printf("%d  ", head-> value);
		head = head-> next;
	}
	 printf("\n");
}

//void insert(Node* head, int n,  int data) {
void insert(Node* head) {							//Функция insert добавляет новый узел в список

	int n, data;

	Node* tmp = (Node*)malloc(sizeof(Node));		//Выделяем память под новый узел

	if(!tmp) {										//Проверяем что память выделена

		printf("\n 		No memory allocated\n"); exit(-1);
	}

	printf("\n 		Enter number node\n");			//Вводим номер узла, после которого будет вставлен новый узел
	scanf("%d", &n);

	for( int i = 1; i < n; i++) {					//Ищем этот узел и его адрес становится для нас head

		head = head-> next;
	}

	printf("\n 		Enter value\n");				//Вводим значение для нового узла
	scanf("%d", &data);

	tmp->value = data;								//Присваиваем это значение в узел
	tmp->next = head->next;							//Переносим адрес на следующий узел с head на tmp
	head->next = tmp;								//Адрес tmp переносим на указатель следующего узла в head
}



//Для удаления списка используем функцию deleteList которая принимает указатель на указатель начала списка
void deleteList(Node **head) {

	Node* tmp = NULL;										//Создаем временный узел

	while((*head)-> next) {									//В цикле, пока есть указатель на указатель на следующицй узел

	tmp = (*head);											//Адрес указателя на указатель присваиваем адресу узла tmp
	(*head) = (*head)-> next;								//Переносим адрес следующего узла на указатель *head
	free(tmp);												//Освобождаем из памяти адрес узла tmp
	}
	free(*head);											//После всего свобождаем память указателя на список
}


 int main(void) {

	char c;

	Node* head = NULL;										//Создаем указатель на первый элемент списка

	printf("\n\n	Enter :  '+' - to add ;\n 	    	 '-' - for output;\n 		 'i' - to insert a new node;\n\
	         'p' - to display the values in the list;\n                 'd' - to delete list and exit;\n");

	for(;;) {

		c = getchar();

		switch (c) {

			case '+': push(&head,rand()); break;
			case '-': pop(&head); break;
			case 'i': insert(head); break;
			case 'p': printLinkedList(head); break;
			case 'd': deleteList(&head); printf("\n Ok"); return 0;
		}
	}
 }







