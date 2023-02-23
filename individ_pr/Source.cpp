#include <iostream>
using namespace std;

void paint(int n)
{
	cout << "\t=============\n\t|           |\n";
	switch (n)
	{
	case 1: {cout << "\t|           |\n";cout << "\t|     *     |\n";cout << "\t|           |\n";break;}
	case 2: {cout << "\t|  *        |\n";cout << "\t|           |\n";cout << "\t|        *  |\n";break;}
	case 3: {cout << "\t|  *        |\n";cout << "\t|     *     |\n";cout << "\t|        *  |\n";break;}
	case 4: {cout << "\t|  *     *  |\n";cout << "\t|           |\n";cout << "\t|  *     *  |\n";break;}
	case 5: {cout << "\t|  *     *  |\n";cout << "\t|     *     |\n";cout << "\t|  *     *  |\n";break;}
	case 6: {cout << "\t|  *     *  |\n";cout << "\t|  *     *  |\n";cout << "\t|  *     *  |\n";break;}
	}
	cout << "\t|           |\n\t=============\n";
}

void kombination(int kolvo, int znach, int& result, int & new_try)
{
	if (kolvo == 3) { result += znach * 10; new_try -= 3; }
	if (kolvo == 4) { result += znach * 20; new_try -= 4; }
	if (kolvo == 5) { result += znach * 100; new_try == 5; }
}

void sum(int* count, int& result, int& new_try)
{
	int check_result = result;
	int k1 = 0, k2 = 0, k3 = 0, k4 = 0, k5 = 0, k6 = 0;
	for (int i = 0;i < new_try;i++)
	{
		if (count[i] == 1) k1 += 1;
		if (count[i] == 2) k2 += 1;
		if (count[i] == 3) k3 += 1;
		if (count[i] == 4) k4 += 1;
		if (count[i] == 5) k5 += 1;
		if (count[i] == 6) k6 += 1;
	}
	if (k1 == 1 && k2 == 1 && k3 == 1 && k4 == 1 && k5 == 1) { result += 125; new_try == 5; return; }
	if (k6 == 1 && k2 == 1 && k3 == 1 && k4 == 1 && k5 == 1) { result += 250; new_try == 5; return; }
	kombination(k1, 10, result, new_try);
	kombination(k2, 2, result, new_try);
	kombination(k3, 3, result, new_try);
	kombination(k4, 4, result, new_try);
	kombination(k5, 5, result, new_try);
	kombination(k6, 6, result, new_try);
	if (k1 < 3) { result += k1 * 10; new_try -= k1; }
	if (k5 < 3) { result += k5 * 5; new_try -= k5; }
	if (result == check_result) new_try = 5;
}

void samosval_obgon(int& player, int& another_player, string name1, string name2, int check1, int check2)
{
	if (player == 555) { cout << "*********************" << "\nCчет 555 - САМОСВАЛ (обнуление счета " << name1 << ")\n*********************"; player = 0; }
	if (another_player == 555) { cout << "*********************" << "\nCчет 555 - САМОСВАЛ (обнуление счета " << name2 << ")\n*********************"; another_player = 0; }
	
	if (check1 == 1 && another_player > player)
	{
		cout << "*********************\n" << name2 << " обогнал " << name1 << " - ОБГОН (минус 50 очков)\n*********************";
		if (player <= 50) player = 0;
		if (player > 50) player = player - 50;
	}
	if (check2 == 1 && another_player < player)
	{
		cout << "*********************\n" << name1 << " обогнал " << name2 << " - ОБГОН (минус 50 очков)\n*********************";
		if (another_player <= 50) another_player = 0;
		if (another_player > 50) another_player -= 50;
	}
}

void tern(int& result, int& bolt)
{
	int numbers[5];
	int i_new = 5, check_result = result, check_result2 = 0;
	for (int i = 0;i < 5;i++)
	{
		numbers[i] = rand() % 5 + 1;
		paint(numbers[i]);
	}
	sum(numbers, result, i_new);
	check_result2 = result;
	if (result == check_result) bolt += 1;
	if (bolt == 3)
	{
		bolt = 0;
		cout << "\nСобрано 3 болта (минус 100 очков)\n";
		if (result > 100)  result -= 100;
		if (result < 100) result = 0;
	}
	if (i_new>0) cout << "\n\tБросок оставшихся кубиков\n";
	for (int i = 0;i < i_new;i++)
	{
		numbers[i] = rand() % 5 + 1;
		paint(numbers[i]);
	}
	sum(numbers, result, i_new);
	if (result == check_result2) bolt += 1;
	if (bolt == 3) 
	{ 
		bolt = 0;
		cout << "\nСобрано 3 болта (минус 100 очков)\n"; 
		if (result > 100)  result -= 100; 
		if (result < 100) result = 0;
	}
}

void bochka(int& result, int& another_result, int& bolt1, int& bolt2)//880
{
	int mis = 0;
	while (result < 1000 || mis < 3)
	{
		tern(result, bolt1); mis += 1;
		tern(another_result, bolt2);
		if (mis == 3) { result -= 100; return; }
		if (another_result >= 880)
		{
			result -= 100;
			bochka(another_result, result, bolt2, bolt1);
		}
	}
}


void whole_game(int& player1, int& player2, string name1, string name2)
{
	{
		int pupu,variant_play = -1, check_player2 = -1, check_player1 = -1, player2_bolt = 0, player1_bolt = 0, point1 = 0, point2 = 0;
		while (variant_play < 1 || variant_play>3)
		{
			cout << "\nВыберите режим игры:\n";
			cout << "1) Игра без бочек\n2) Игра с бочкой по очкам\n3) Игра с открытой бочкой\n";
			cout << "Введите нужный вариант: ";
			cin >> variant_play;
		}

		switch (variant_play)//режимы игры
		{
		case 1://без бочек
		{
			srand(time(NULL));
			while (player1 < 1000 && player2 < 1000)
			{
				if (player2 > player1) check_player2 = 1;
				if (player1 > player2) check_player1 = 1;

				cout << "\n\t~~~Ход "<<name1<<"~~~" << endl;
				cin.get();
				tern(player1, player1_bolt);

				cout << "\n\t~~~Ход " << name2<<"~~~" << endl;
				if (name2!="Computer") cin.get();
				tern(player2, player2_bolt);
				samosval_obgon(player1, player2, name1, name2, check_player1, check_player2);

				cout << "\nСЧЕТ ПОСЛЕ ЭТОГО ХОДА:\n";
				cout << "Счет " << name1 << ": " << player1 << "   Количество болтов " << player1_bolt << endl;
				cout << "Счет " << name2 << ": " << player2 << "   Количество болтов " << player2_bolt << endl;
				check_player2 = 0; check_player1 = 0;
			}
			if (player1 >= 1000) cout << "\n\t************************" << "\n\t   Победил " << name1 <<"  cо счетом "<<player1<<"\n\t************************";
			else cout << "\n\t************************" << "\n\t   Победил " << name2 <<"  cо счетом "<< player2 << "\n\t************************";
			break;
		}
		case 2://бочка по очкам
		{
			srand(time(NULL));
			while (player1 < 1000 && player2 < 1000)
			{
				if (player2 > player1) check_player2 = 1;
				if (player1 > player2) check_player1 = 1;

				cout << "\n\t~~~Ход " << name1 << "~~~" << endl;
				cin.get();
				tern(player1, player1_bolt);

				cout << "\n\t~~~Ход " << name2 << "~~~" << endl;
				if (name2 != "Computer") cin.get();
				tern(player2, player2_bolt);
				samosval_obgon(player1, player2, name1, name2, check_player1, check_player2);

				if (player2 >= 880) bochka(player2, player1, player2_bolt, player1_bolt);//бочки
				if (player1 >= 880) bochka(player1, player2, player1_bolt, player2_bolt);

				cout << "\nСЧЕТ ПОСЛЕ ЭТОГО ХОДА:\n";
				cout << "Счет " << name1 << ": " << player1 << "   Количество болтов " << player1_bolt << endl;
				cout << "Счет " << name2 << ": " << player2 << "   Количество болтов " << player2_bolt << endl;
				check_player2 = 0; check_player1 = 0;
			}
			if (player1 >= 1000) cout << "\n\t************************" << "\n\t   Победил " << name1 << "  cо счетом " << player1 << "\n\t************************";
			else cout << "\n\t************************" << "\n\t   Победил " << name2 << "  cо счетом " << player2 << "\n\t************************";
			break;
		}
		case 3: //с открытой бочкой
		{
			srand(time(NULL));
			while (player1 != 1000 && player2 != 1000)
			{
				if (player2 > player1) check_player2 = 1;
				if (player1 > player2) check_player1 = 1;

				cout << "\n\t~~~Ход " << name1 << "~~~" << endl;
				cin.get();
				tern(player1, player1_bolt);

				cout << "\n\t~~~Ход " << name2 << "~~~" << endl;
				if (name2 != "Computer") cin.get();
				tern(player2, player2_bolt);
				samosval_obgon(player1, player2, name1, name2, check_player1, check_player2);

				if (player1 == 1000) point1 += 1;
				if (point1 == 6)
				{
					cout << "\nНабрано 6 точек (обнуление счета) ";
					player1 = 0;
				}
				if (player2 == 1000) point2 += 1;
				if (point2 == 6)
				{
					cout << "\nНабрано 6 точек (обнуление счета) ";
					player2 = 0;
				}
				cout << "\nСЧЕТ ПОСЛЕ ЭТОГО ХОДА:\n";
				cout << "Счет " << name1 << ": " << player1 << "   Количество болтов " << player1_bolt << "   Количество точек " << point1 << endl;
				cout << "Счет " << name2 << ": " << player2 << "   Количество болтов " << player2_bolt << "   Количество точек " << point2 << endl;
				check_player2 = 0; check_player1 = 0;
			}
			if (player1 == 1000) cout << "\n\t************************" << "\n\t   Победил " << name1 << "  cо счетом " << player1 << "\n\t************************";
			else cout << "\n\t************************" << "\n\t   Победил " << name2 << "  cо счетом " << player2 << "\n\t************************";
			break;
		}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int player1 = 0, player2 = 0, computer = 0, who_play = -1, variant_play = -1, menu = -1;
	string name1, name2;
	while (menu < 1 || menu>2)
	{
		cout << "\t~~~МЕНЮ~~~\n";
		cout << "\t1) Новая игра\n\t2) Правила\n\t~~~~~~~~~~\n";
		cout << "Введите нужный вариант: ";
		cin >> menu;
	}
	switch (menu)
	{
	case 1: 
	{
		while (who_play < 1 || who_play>2)
		{
			cout << "\n\nВыберите с кем хотите играть:\n";
			cout << "1) С компьютером\n2) С игроком с одного устройства\n";
			cout << "Введите нужный вариант: ";
			cin >> who_play;
		}
		switch (who_play)
		{
		case 1: //с компьютером
		{
			cout << "\nВведите имя игрока: ";
			cin >> name1;
			name2 = "Computer";
			whole_game(player1, computer, name1, name2);
			break;
		}
		case 2: //с другим игроком
		{
			cout << "\nВведите имя первого игрока: ";
			cin >> name1;
			cout << "\nВведите имя второго игрока: ";
			cin >> name2;
			whole_game(player1, player2, name1, name2);
			break;
		}

		}
		break;
	}
	case 2:////Правила
	{
		cout << "ПРАВИЛА";
		break;
	}
	}
	return 0;
}