#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	char map[10][21];
	char key;
	int dog_x = 10, dog_y = 5;
	int dog_x_prev, dog_y_prev;
	int cat_x = 3, cat_y = 3;
	int score = 0;
	
	// Рандомность чисел
	srand(time(NULL));
		
	while (1)
	{	
		// Создаем карту
		sprintf(map[0], "####################");
		for (int i = 1; i < 9; i++) { sprintf(map[i], "#                  #"); }
		sprintf(map[9], "####################");
		
		// Рисуем собаку и кошку
		map[dog_y][dog_x] = '@';
		map[cat_y][cat_x] = 'c';
		
		// Очищаем экран
		system("cls");	
		
		// Шапка игры
		printf("####### =^_^= ######\n");
		printf("## TO CATCH A CAT ##\n");
		
		// Рисуем игру
		for (int i = 0; i < 10; i++) { printf("%s\n", map[i]); }
		
		// Рисуем счет
		printf("Score: %d\n", score);
				
		// Предыдущее местоположение равно нынешнему положению
		dog_x_prev = dog_x;
		dog_y_prev = dog_y;		
		
		// Проверяем нажатие клавиши
		key = getch();
		if (key == 'w') { dog_y--; }
		if (key == 's') { dog_y++; }
		if (key == 'a') { dog_x--; }
		if (key == 'd') { dog_x++; }
		
		// Проверяем коллизию со стенами
		if ( map[dog_y][dog_x] == '#' ) { dog_x = dog_x_prev; dog_y = dog_y_prev; }
		
		// Проверяем коллизию с котом
		if ( (dog_x == cat_x) && (dog_y == cat_y) ) { cat_x = rand() % 18 + 1; cat_y = rand() % 8 + 1; score++; }
	}	
	
	return 0;
}