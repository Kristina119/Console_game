#include <iostream>
using namespace std;

void paint(int n)
{
	cout << "\t_______\n\t|        |\n";
	switch (n)
	{
	case 1: {cout << "|         |";cout << "|    ○    |";cout << "|         |";break;}
	case 2: {cout << "|  ○      |";cout << "|         |";cout << "|      ○  |";break;}
	case 3: {cout << "|  ○      |";cout << "|    ○    |";cout << "|      ○  |";break;}
	case 4: {cout << "|  ○   ○  |";cout << "|         |";cout << "|  ○   ○  |";break;}
	case 5: {cout << "|  ○   ○  |";cout << "|    ○    |";cout << "|  ○   ○  |";break;}
	case 6: {cout << "|  ○   ○  |";cout << "|  ○   ○  |";cout << "|  ○   ○  |";break;}
	}
	cout << "\n\t|        |\n\t-------\n";
}

void kombination(int kolvo,int znach, int& result,int new_try)
{
	if (kolvo == 3) { result = znach * 10; new_try -= 3; }
	if (kolvo == 4) { result = znach * 20; new_try -= 4; }
	if (kolvo == 5) { result = znach * 100; new_try == 5;}
}

void sum(int *count,int &result,int &new_try)
{
	int check_result = result;
	int k1=0, k2=0, k3=0, k4=0, k5=0, k6=0;
	for (int i = 0;i < 5;i++)
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
	kombination(k1, 10,result, new_try); 
	kombination(k2, 2, result, new_try);
	kombination(k3, 3, result, new_try);
	kombination(k4, 4, result, new_try);
	kombination(k5, 5, result, new_try);
	kombination(k6, 6, result, new_try);
	if (k1 < 3) { result += k1 * 10; new_try -= k1; }
	if (k5 < 3) { result += k5 * 5; new_try -= k5; }
	if (result == check_result) new_try = 5;
}

void samosval_obgon(int& player, int & another_player, string name1,string name2,int check1, int check2)
{
	if (player == 555) { cout << "*********************" << "\nCчет 555 - САМОСВАЛ (обнуление счета "<<name1<<")\n*********************"; player = 0; }
	if (another_player == 555) { cout << "*********************" << "\nCчет 555 - САМОСВАЛ (обнуление счета "<<name2<<")\n*********************"; another_player = 0; }
	if (check1 == 1 && another_player > player) { cout << "*********************\n" <<name2<< " обогнал "<<name1<<" - ОБГОН(минус 50 очков)\n*********************"; player -= 50; }
	else
	{
		if (check2 == 1 && another_player < player) { cout << "*********************\n" << name2<<"\n обогнал "<<name2<<" - ОБГОН(минус 50 очков)\n*********************"; another_player -= 50; }
	}
}
void tern(int &result,int &bolt)
{
	int numbers[5];
	int i_new=0,check_result = result,check_result2=0;
	for (int i = 0;i < 5;i++)
	{
		numbers[i] << rand() % 5 + 1;paint(numbers[i]);
	}
	sum(numbers, result, i_new);
	check_result2 = result;

	for (int i = 0;i < i_new;i++)
	{
		numbers[i] << rand() % 5 + 1;paint(numbers[i]);
	}
	sum(numbers, result, i_new);
	if (result == check_result2) bolt += 1;
	if (bolt == 3) { cout << "\nСобрано 3 болта (минус 100 очков)\n"; result -= 100; bolt == 0; }
}

void bochka(int& result, int &another_result,int &bolt1, int &bolt2)//880
{
	int mis=0;
	while (result < 1000 || mis<3)
	{
		tern(result, bolt1); mis += 1;
		tern(another_result, bolt2);
		if (mis == 3) { result -= 100; return; }
		if (another_result >= 880)
		{
			bochka(another_result, result, bolt2, bolt1);
			result -= 100;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int player1 = 0, player2 = 0, computer = 0, who_play = -1, variant_play = -1, menu = -1, i_new = 0, check_computer,check_player1;
	int computer_bolt = 0, player1_bolt = 0;
	string name1,name2;
	while (menu < 1 || menu>2)
	{
		cout << "\tМЕНЮ";
		cout << "1) Новая игра\n2) Правила\n";
		cout << "Введите нужный вариант: ";
		cin >> menu;
	}
	switch (menu)
	{
	case 1: {
		while (who_play < 1 || who_play>2)
		{
			cout << "Выберите с кем хотите играть:\n";
			cout << "1) С компьютером\n2) С игроком с одного устройства\n";
			cout << "Введите нужный вариант: ";
			cin >> who_play;
		}
		switch (who_play)
		{
		case 1:
		{
			cout << "Введите имя игрока: ";
			cin >> name1;
			name2 = "Computer";

			while (variant_play < 1 || variant_play>3)
			{
				cout << "Выберите режим игры:\n";
				cout << "1) Игра без бочек\n2) Игра с бочкой по очкам\n3) Игра с открытой бочкой\n";
				cout << "Введите нужный вариант: ";
				cin >> variant_play;
			}

			switch (variant_play)
			{
			case 1://без бочек
			{
				srand(time(NULL));
				while (player1 < 1000 || computer<1000)
				{	/*for (int i = 0;i < 5;i++)
					{
						count_player1[i] << rand() % 5 + 1;paint(count_player1[i]);
					}
					sum(count_player1, player1, i_new);
					for (int i = 0;i < i_new;i++)
					{
						count_player1[i] << rand() % 5 + 1;paint(count_player1[i]);
					}

					for (int i = 0;i < 5;i++)
					{
						count_computer[i] = rand() % 5 + 1; paint(count_computer[i]);
					}
					sum(count_computer, computer, i_new);
					for (int i = 0;i < i_new;i++)
					{
						count_computer[i] = rand() % 5 + 1; paint(count_computer[i]);
					}*/
					if (computer > player1) check_computer = 1;
					if (player1 > computer) check_player1 = 1;
					tern(player1,player1_bolt);
					tern(computer, computer_bolt);
					samosval_obgon(player1, computer, name1, name2, check_player1, check_computer);

					cout << "\nСЧЕТ ПОСЛЕ ЭТОГО ХОДА:\n";
					cout << "Счет игрока: " << player1<<"\tСчет компьютера: "<<computer<<"\n";
					check_computer = 0; check_player1 = 0;
				}
				if (player1 >= 1000) cout << "\n*********************" << "\nПобедил\n*********************" << name1;
				else cout << "\n*********************" << "\nПобедил компьютер\n*********************";
			}
			case 2://бочка по очкам
			{
				srand(time(NULL));
				while (player1 < 1000 || computer < 1000)
				{	/*for (int i = 0;i < 5;i++)
					{
						count_player1[i] << rand() % 5 + 1;paint(count_player1[i]);
					}
					sum(count_player1, player1, i_new);
					for (int i = 0;i < i_new;i++)
					{
						count_player1[i] << rand() % 5 + 1;paint(count_player1[i]);
					}

					for (int i = 0;i < 5;i++)
					{
						count_computer[i] = rand() % 5 + 1; paint(count_computer[i]);
					}
					sum(count_computer, computer, i_new);
					for (int i = 0;i < i_new;i++)
					{
						count_computer[i] = rand() % 5 + 1; paint(count_computer[i]);
					}*/
					if (computer > player1) check_computer = 1;
					if (player1 > computer) check_player1 = 1;
					tern(player1, player1_bolt);
					tern(computer, computer_bolt);
					samosval_obgon(player1, computer, name1, name2, check_player1, check_computer);
					if (computer >= 880) 
					{
						bochka(computer, player1, computer_bolt, player1_bolt);
					}
					if (player1 >= 880)
					{
						bochka(player1,computer, player1_bolt, computer_bolt);
					}
					cout << "\nСЧЕТ ПОСЛЕ ЭТОГО ХОДА:\n";
					cout << "Счет игрока: " << player1 << "\tСчет компьютера: " << computer << "\n";
					check_computer = 0; check_player1 = 0;
				}
				if (player1 >= 1000) cout << "\n*********************" << "\nПобедил\n*********************" << name1;
				else cout << "\n*********************" << "\nПобедил компьютер\n*********************";
			}
			}
		}
		case 2:
		{
			while (variant_play < 1 || variant_play>3)
			{
				cout << "Выберите режим игры:\n";
				cout << "1) Игра без бочек\n2) Игра с бочкой по очкам\n3) Игра с открытой бочкой\n";
				cout << "Введите нужный вариант: ";
				cin >> variant_play;
			}
		}

		}
	}
		  case 2:////Правила
		  {

		  }
	}
}