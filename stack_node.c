//
// 		stack_node.c		19.01.2020  Andrew M.
//
//	Stack implementation on a list.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 10

int counter = 0;

typedef struct stack {										//Создаем структуру с новым типом Stack
	
	int value;												//Она содержит значение  и указатель на следующий узел
	struct stack* next;
} Stack;

//Для добавления значения создаем функцию push, которая принимает указатель на указатель начала списка
void push(Stack** head) {									
	
	Stack* tmp = (Stack*) malloc(sizeof(Stack));		//Выделяем память под новый узел
	
	int val;
	
	if(STACK_MAX_SIZE == counter && !tmp) {				//Проверяем стек на переполнение и на выделение памяти под узел tmp
		
		printf("\n 		Stack overflow\n"); exit(-1);
	}
	
	printf("\n 		Enter value\n");
	
	scanf("%d", &val); 									//Считываем значение
	
	tmp-> value = val;									//Заносим его в узел
	tmp-> next = (*head);								//указателю на следующий узел присваиваем адрес указателя на указатель начла списка
	(*head) = tmp;										//Самому указателю на указатель присваиваем адрес узла tmp
	counter++;											//увеличиваем значение счетчика
}

//Для вывода значения и удаления узла списка из стека используем функцию pop, которая принимает указатель на указатель начала списка 
int pop(Stack** head) {							
	
	int val;
	
	Stack* tmp = NULL;									//Создаем временный узел
	
	if((*head) == NULL) {								//Проверяем, не является ли стек пустым.
		
		printf("\n 		Stack underflow\n"); return -2;
	}
	
	tmp = (*head);										//Адрес указателя на указатель присваиваем адресу узла tmp
	val = tmp-> value;									//Передаем значение переменнной val из узла
	(*head) = tmp-> next;								//Присваиваем адрес из узла указателю на указатель начала списка
	
	free(tmp);											//Освобождаем память от адреса временнного узла
	
	counter--;											//Уменьшаем значение счетчика
	
	return val;											//Возвращаем значение
}

//Для вывода на печать используем функцию printLinkedList, которая принимает указатель начала списка
void printLinkedList(const Stack *head) {
	
    while (head) {										//В цикле - пока есть указатель..
		
        printf("%d ", head->value);						//Печатаем значения
		
        head = head->next;								//Передаем указателю адрес следующего узла
    }
    printf("\n");
}

//В функции main в бесконечном цикле работаем с данными - добавляя их, выводим или смотрим на список значений в стеке.
int main(void) {
	
	char c;
		
	Stack* head = NULL;									//Создаем указатель на первый элемент списка
	
	printf("\n\n	Enter :  '+' - to add ;\n 	    	 '-' - for output;\n 		 'p' - to display the values in the stack;\n\
		 'q' - to exit;\n");
	
	for(;;) {
		
		c = getchar();
		
		switch (c) {
			
			case '+': push(&head); break;
			case '-': printf("\n 	Present value  %d\n", pop(&head)); break;
			case 'p': printLinkedList(head); break;
			case 'q': return 0;
		}
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
	
	

