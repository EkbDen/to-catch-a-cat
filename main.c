#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

struct animal { int x, y; } dog, cat, prev_dog;

int main()
{
	char map[10][21];
	char key;
	int score = 0;
	
	dog.x = 10, dog.y = 5;
	cat.x = 3, cat.y = 3;	
	
	
	// Рандомность чисел
	srand(time(NULL));
		
	while (1)
	{	
		// Создаем карту
		sprintf(map[0], "####################");
		for (int i = 1; i < 9; i++) { sprintf(map[i], "#                  #"); }
		sprintf(map[9], "####################");
		
		// Рисуем собаку и кошку
		map[dog.y][dog.x] = '@';
		map[cat.y][cat.x] = 'c';
		
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
		prev_dog.x = dog.x;
		prev_dog.y = dog.y;		
		
		// Проверяем нажатие клавиши
		key = getch();
		if (key == 'w') { dog.y--; }
		if (key == 's') { dog.y++; }
		if (key == 'a') { dog.x--; }
		if (key == 'd') { dog.x++; }
		
		// Проверяем коллизию со стенами
		if ( map[dog.y][dog.x] == '#' ) { dog.x = prev_dog.x; dog.y = prev_dog.y; }
		
		// Проверяем коллизию с котом
		if ( (dog.x == cat.x) && (dog.y == cat.y) ) { cat.x = rand() % 18 + 1; cat.y = rand() % 8 + 1; score++; }
	}	
	
	return 0;
}