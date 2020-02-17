//
// 		List.c		19.01.2020  Andrew M.
//
//	List implementation.


#include <stdio.h>
#include <stdlib.h>

 typedef struct Node {										//������� ��������� � ����� ����� Node

	int value;
	struct Node* next;										//��� �������� ��������  � ��������� �� ��������� ����

} Node;

//��� ���������� �������� ������� ������� push, ������� ��������� ��������� �� ��������� ������ ������ � ��������
void push(Node** head, int data) {

	Node* tmp = (Node*) malloc(sizeof(Node));				//�������� ������ ��� ����� ����
	tmp-> value = data;
	printf("\n 	Value  %d\n", data);
	tmp-> next = (*head);									//��������� �� ��������� ���� ����������� ����� ��������� �� ��������� ����� ������
	(*head) = tmp;											//��������� �� ��������� ����������� ����� ���� tmp
}

//��� ������ �������� � �������� ���� ������ �� ����� ���������� ������� pop, ������� ��������� ��������� �� ��������� ������ ������
int pop(Node** head) {

		Node* prev = NULL;									//������� ��������� ����
		int val;

	if ((*head) == NULL) {									//���������, �� �������� �� ������ ������.

		printf("\n 		The list is empty\n");
		return -1;
	}

	prev = (*head);											//����� ��������� �� ��������� ����������� ������ ���� tmp
	val = prev-> value;										//�������� �������� �� ���� ����������� val
	printf("\n 	Present value  %d\n", val);
	(*head) = prev-> next;									//����������� ����� �� ���� ��������� �� ��������� ������ ������
	free(prev);												//����������� ������ �� ������ ����������� ����

return val;													//���������� ��������
}

//��� ������ �� ������ ���������� ������� printLinkedList, ������� ��������� ��������� ������ ������
void printLinkedList(const Node* head) {

	while(head) {

		printf("%d  ", head-> value);
		head = head-> next;
	}
	 printf("\n");
}

//void insert(Node* head, int n,  int data) {
void insert(Node* head) {							//������� insert ��������� ����� ���� � ������

	int n, data;

	Node* tmp = (Node*)malloc(sizeof(Node));		//�������� ������ ��� ����� ����

	if(!tmp) {										//��������� ��� ������ ��������

		printf("\n 		No memory allocated\n"); exit(-1);
	}

	printf("\n 		Enter number node\n");			//������ ����� ����, ����� �������� ����� �������� ����� ����
	scanf("%d", &n);

	for( int i = 1; i < n; i++) {					//���� ���� ���� � ��� ����� ���������� ��� ��� head

		head = head-> next;
	}

	printf("\n 		Enter value\n");				//������ �������� ��� ������ ����
	scanf("%d", &data);

	tmp->value = data;								//����������� ��� �������� � ����
	tmp->next = head->next;							//��������� ����� �� ��������� ���� � head �� tmp
	head->next = tmp;								//����� tmp ��������� �� ��������� ���������� ���� � head
}



//��� �������� ������ ���������� ������� deleteList ������� ��������� ��������� �� ��������� ������ ������
void deleteList(Node **head) {

	Node* tmp = NULL;										//������� ��������� ����

	while((*head)-> next) {									//� �����, ���� ���� ��������� �� ��������� �� ���������� ����

	tmp = (*head);											//����� ��������� �� ��������� ����������� ������ ���� tmp
	(*head) = (*head)-> next;								//��������� ����� ���������� ���� �� ��������� *head
	free(tmp);												//����������� �� ������ ����� ���� tmp
	}
	free(*head);											//����� ����� ���������� ������ ��������� �� ������
}


 int main(void) {

	char c;

	Node* head = NULL;										//������� ��������� �� ������ ������� ������

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







