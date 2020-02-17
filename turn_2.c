//
// 		turn_2.c		18.01.2020  Andrew M.
//
//	Implementation of a queue on an array.

														//Миль пардон за (пока еще) русский)
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 10											//Ставим на 10 для наглядности примера


int in = 0;
int out = 0;
int array[MAX] = {0};

 void t_in(void) {										//Функция t_in просит ввести значение

	int val;

	 printf("\n Enter value  \n");

	 scanf("%d", &val);

	if (in == MAX) {									//И  при условии что массив не полный

		printf("\n Queue overflow\n"); return;
	}

	array[in++] = val;  								//Ставит значение в массив array
 }

 int t_out(void) {										//Функция t_out возвращает значение первого в очереди значения

	int value;
	int i = 1;

	if (in == out) {									//Проверяет что массив не пустой

		printf("\n The queue is empty\n"); return 1;
	}

		value = array[0];								//Копирует значение

		printf("\n Present value %d\n", value);

	while(out < in) {									//Совершает сдвиг массива влево на одно значение

		array[out++] = array[ i++ ];
	}

	in --; 												//Уменьшаем индекс массива на единицу

	out = 0; i = 1;										//Возвращаем исходные значения

 return value;
}

 void t_disp(void) {									// Функция t_disp при условии что массив не пустой

	if(in == out) {

		printf("\n The queue is empty\n"); return;
	}

	puts("\n	Values in queue:  \n");					//Отправляет на экран список значений стоящих в очереди

	for(int i = 0; i < in; i++)

	printf("\n	  %d\n", array[i]);

 }

 int main(void) {

	char c;
	int counter = 0;

	printf("\n\n	Enter :  N - to add ;\n 	    	 O - for output;\n 		 D - to display the values in the queue;\n\
		 C - to display counter;\n		 E - to exit;\n");


	for( ;; ) {																	// В бесконечном цикле ждем ввода команд

		c = getchar();

		c = toupper(c);

			switch (c) {

			case 'N': t_in(); counter++; break;									//Вызываем функцию t_in и увеличиваем счетчик

			case 'O': t_out(); break;											//Вызываем функцию t_out

			case 'D': t_disp(); break;											//Вызываем функцию t_disp

			case 'C': printf("\n 	%d\n", counter); break;						//Печатаем счетчик ввода значений

			case 'E': return 0;													//Выходим из программы
			}
	}
		
  }






