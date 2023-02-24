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
	if (k1 == 1 && k2 == 1 && k3 == 1 && k4 == 1 && k5 == 1) { result += 125; new_try == 5; cout << "\n\tМалый стрит +125 очков.\n"; return; }
	if (k6 == 1 && k2 == 1 && k3 == 1 && k4 == 1 && k5 == 1) { result += 250; new_try == 5; cout << "\n\tБольшой стрит +250 очков.\n"; return; }
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
	if (player == 555 || another_player == 555)
	{
		if (player == 555) { cout << "\n*****************************" << "\nCчет 555 - САМОСВАЛ (обнуление счета " << name1 << ")\n****************************\n"; player = 0; }
		if (another_player == 555) { cout << "\n****************************" << "\nCчет 555 - САМОСВАЛ (обнуление счета " << name2 << ")\n****************************\n"; another_player = 0; }
		return;
	}
	if (check1 == 1 && another_player > player)
	{
		cout << "\n****************************\n" << name2 << " обогнал " << name1 << " - ОБГОН (минус 50 очков)\n****************************\n";
		if (player <= 50) player = 0;
		if (player > 50) player = player - 50;
	}
	if (check2 == 1 && another_player < player)
	{
		cout << "\n****************************\n" << name1 << " обогнал " << name2 << " - ОБГОН (минус 50 очков)\n****************************\n";
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
	if (i_new > 0) {
		cout << "\n\tБросок оставшихся кубиков\n";
		for (int i = 0;i < i_new;i++)
		{
			numbers[i] = rand() % 5 + 1;
			paint(numbers[i]);
		}
		sum(numbers, result, i_new);
	}
	if (result == check_result2) bolt += 1;
	if (bolt == 3) 
	{ 
		bolt = 0;
		cout << "\nСобрано 3 болта (минус 100 очков)\n"; 
		if (result > 100)  result -= 100; 
		if (result < 100) result = 0;
	}
}

void bochka(int& result, int& another_result, int& bolt1, int& bolt2, int check_player1,int check_player2, string name1, string name2)//880
{
	int mis = 0; int check_res = result;
	while (result < 1000 && mis < 3)
	{
		cout << "\n\t~~~Ход " << name2 << "~~~" << endl;
		if (name2 != "Computer")
		{
			cout << "\nЧтобы походить нажмите ENTER\n";
			cin.get();
		}
		tern(another_result, bolt2);

		cout << "\n\t~~~Ход " << name1 << "~~~" << endl;
		if (name1 != "Computer")
		{
			cout << "\nЧтобы походить нажмите ENTER\n";
			cin.get();
		}
		tern(result, bolt1);

		if (result < 1000) 
		{
			result = check_res;
			mis += 1;
			cout << "\nПотрачено " << mis << " попытки усидеть на бочке. Осталось " <<  3 - mis << " попыток";
		}

		samosval_obgon(result, another_result, name1, name2, check_player1, check_player2);


		if (mis == 3) 
		{ 
			cout << "\nВы не смогли набрать 1000 очков в третий раз. Вы теряете сто очков.\n";
			result-=100;
			return; }
		if (another_result >= 880)
		{
			cout << "\nОппонент сбил Вас с бочки, Вы теряете все очки.\n";
			result = 0;
			bochka(another_result, result, bolt2, bolt1, check_player2, check_player1, name2, name1);
		}
		if (result < 1000)
		{
			cout << "\nСЧЕТ ПОСЛЕ ЭТОГО ХОДА:\n";
			cout << "Счет " << name1 << ": " << result << "   Количество болтов " << bolt1 << endl;
			cout << "Счет " << name2 << ": " << another_result << "   Количество болтов " << bolt2 << endl;
			cin.get();
			check_player2 = 0; check_player1 = 0;
		}
		else return;
	}
}

void first_tern(int player1,int player2,string& name1,string &name2,int flag)
{
	string name;
	int player1_bolt = 0, player2_bolt = 0;
	cout << "Чтобы выяснить, кто ходит первым, будет почитан первый бросок. У кого будет больше очков (подсчет вечется по правилам игры) - ходит первый.";
	while (player1 == player2)
	{
		cout << "\n\t~~~Ход " << name1 << "~~~" << endl;
		cin.get();
		tern(player1, player1_bolt);

		cout << "\n\t~~~Ход " << name2 << "~~~" << endl;
		if (name2 != "Computer") cin.get();
		tern(player2, player2_bolt);

		cout << "\nСЧЕТ ПОСЛЕ ЭТОГО ХОДА:\n";
		cout << "Счет " << name1 << ": " << player1 << endl;
		cout << "Счет " << name2 << ": " << player2 << endl;

		if (player1 > player2) { cout << "\nПервым будет ходить " << name1 << "\nДля продолжения нажмите ENTER";flag = 1; cin.get(); }
		if (player2 > player1) { cout << "\nПервым будет ходить " << name2 << "\nДля продолжения нажмите ENTER"; name = name1; name1 = name2;name2 = name;cin.get(); }
		if (player1 == player2) { cout << "\nНабран равный счет, повторный бросок.\n"; }
	}
}

void whole_game(int& player1, int& player2, string name1, string name2)
{
	{
		string name;
		int variant_play = -1, flag = 0, check_player2 = -1, check_player1 = -1, player2_bolt = 0, player1_bolt = 0, point1 = 0, point2 = 0, bochka_try1 = 0, bochka_try2 = 0;
		while (variant_play < 1 || variant_play>3)
		{
			cout << "\nВыберите режим игры:\n";
			cout << "1) Игра без бочек\n2) Игра с бочкой по очкам\n3) Игра с открытой бочкой\n";
			cout << "Введите нужный вариант: ";
			cin >> variant_play;
			if (variant_play < 1 || variant_play>3) cout << "\nВведено недопустимое значение, попробуйте еще раз.\n\n";
		}

		switch (variant_play)//режимы игры
		{
		case 1://без бочек
		{
			srand(time(NULL));
			first_tern(player1, player2, name1, name2, flag);
			while (player1 < 1000 && player2 < 1000)
			{
				if (player2 > player1) check_player2 = 1;
				if (player1 > player2) check_player1 = 1;

				cout << "\n\t\t~~~Ход "<<name1<<"~~~" << endl;
				if (name1 != "Computer")
				{
					cout << "\nЧтобы походить нажмите ENTER\n";
					cin.get();
				}
				tern(player1, player1_bolt);

				cout << "\n\t\t~~~Ход " << name2<<"~~~" << endl;
				if (name2 != "Computer")
				{
					cout << "\nЧтобы походить нажмите ENTER\n";
					cin.get();
				}
				tern(player2, player2_bolt);
				samosval_obgon(player1, player2, name1, name2, check_player1, check_player2);

				cout << "\nСЧЕТ ПОСЛЕ ЭТОГО ХОДА:\n";
				cout << "Счет " << name1 << ": " << player1 << "   Количество болтов " << player1_bolt << endl;
				cout << "Счет " << name2 << ": " << player2 << "   Количество болтов " << player2_bolt << endl;
				if (flag != 1 && player1<1000 && player2<1000)
				{
					cout << "\nСледующий ход (нажмите ENTER)\n";
					cin.get();
				}
				check_player2 = 0; check_player1 = 0;
			}
			if (player1 >= 1000) cout << "\n\t**********************************" << "\n\t   Победил " << name1 <<"  cо счетом "<<player1<<"\n\t**********************************";
			else cout << "\n\t**********************************" << "\n\t   Победил " << name2 <<"  cо счетом "<< player2 << "\n\t**********************************";
			break;
		}
		case 2://бочка по очкам
		{
			srand(time(NULL));
			first_tern(player1, player2, name1, name2,flag);
			while (player1 < 1000 && player2 < 1000)
			{
				if (player2 > player1) check_player2 = 1;
				if (player1 > player2) check_player1 = 1;

				cout << "\n\t\t~~~Ход " << name1 << "~~~" << endl;
				if (name1 != "Computer") 
				{
					cout << "\nЧтобы походить нажмите ENTER\n";
					cin.get();
				}
				tern(player1, player1_bolt);

				cout << "\n\t\t~~~Ход " << name2 << "~~~" << endl;
				if (name2 != "Computer")
				{
					cout << "\nЧтобы походить нажмите ENTER\n";
					cin.get();
				}
				tern(player2, player2_bolt);
				samosval_obgon(player1, player2, name1, name2, check_player1, check_player2);

				if (player1 >= 880 && player1<1000)//бочки
				{
					while (bochka_try1 < 3 && player1 < 1000 && player1>=880)
					{
						cout << "\n" << name1 << " сел на бочку. Требуется достичь 1000 очков за один ход. Есть три попытки. (Текущий счет равен "<<player1<<")\n";
						cout << "Нажмите ENTER, чтобы продолжить.";
						cin.get();
						bochka_try1 += 1;
						bochka(player1, player2, player1_bolt, player2_bolt, check_player1, check_player2, name1, name2);
						if (player1 >= 1000) break;
					}
					if (bochka_try1 == 3) { cout << name1 << " трижды не смог взять бочку. (Будут списаны все очки)"; player1 = 0; }
				}

				if (player2 >= 880 && player2<1000 && player1<1000)
				{
					while (bochka_try2 < 3 && player2 < 1000 && player2 >= 880)
					{
						cout << "\n" << name2 << " сел на бочку. Требуется достичь 1000 очков за один ход. Есть три попытки. (Текущий счет равен " << player2 << ")\n";
						cout << "Нажмите ENTER, чтобы продолжить.";
						cin.get();
						bochka_try2 += 1;
						bochka(player2, player1, player2_bolt, player1_bolt, check_player2, check_player1, name2, name1);
						if (player2 >= 1000) break;
					}
					if (bochka_try2 == 3) { cout << name2 << " трижды не смог взять бочку. (Будут списаны все очки)"; player2 = 0; }
				}
				
				cout << "\nСЧЕТ ПОСЛЕ ЭТОГО ХОДА:\n";
				cout << "Счет " << name1 << ": " << player1 << "   Количество болтов " << player1_bolt << endl;
				cout << "Счет " << name2 << ": " << player2 << "   Количество болтов " << player2_bolt << endl;
				if (flag != 1 && player1 < 1000 && player2 < 1000)
				{
					cout << "\nСледующий ход (нажмите ENTER)\n";
					cin.get();
				}
				check_player2 = 0; check_player1 = 0;
			}
			if (player1 >= 1000) {
				cout << "\n\t*********************************" << "\n\t   Победил " << name1 << "  cо счетом " << player1 << "\n\t**********************************"; break;
			}
			else {
				cout << "\n\t**********************************" << "\n\t   Победил " << name2 << "  cо счетом " << player2 << "\n\t**********************************";
				break;
			}
		}
		case 3: //с открытой бочкой
		{
			srand(time(NULL));
			first_tern(player1, player2, name1, name2, flag);
			while (player1 != 1000 && player2 != 1000)
			{
				if (player2 > player1) check_player2 = 1;
				if (player1 > player2) check_player1 = 1;

				cout << "\n\t\t~~~Ход " << name1 << "~~~" << endl;
				if (name1 != "Computer")
				{
					cout << "\nЧтобы походить нажмите ENTER\n";
					cin.get();
				}
				tern(player1, player1_bolt);

				cout << "\n\t\t~~~Ход " << name2 << "~~~" << endl;
				if (name2 != "Computer")
				{
					cout << "\nЧтобы походить нажмите ENTER\n";
					cin.get();
				}
				tern(player2, player2_bolt);
				samosval_obgon(player1, player2, name1, name2, check_player1, check_player2);

				if (player1 >= 1000) point1 += 1;
				if (point1 == 6)
				{
					cout << "\nНабрано 6 точек (обнуление счета) ";
					player1 = 0;
					point1 = 0;
				}
				if (player2 >= 1000) point2 += 1;
				if (point2 == 6)
				{
					cout << "\nНабрано 6 точек (обнуление счета) ";
					player2 = 0;
					point2 = 0;
				}
				cout << "\nСЧЕТ ПОСЛЕ ЭТОГО ХОДА:\n";
				cout << "Счет " << name1 << ": " << player1 << "   Количество болтов " << player1_bolt << "   Количество точек " << point1 << endl;
				cout << "Счет " << name2 << ": " << player2 << "   Количество болтов " << player2_bolt << "   Количество точек " << point2 << endl;
				if (flag != 1 && player1 != 1000 && player2 != 1000)
				{
					cout << "\nСледующий ход (нажмите ENTER)\n";
					cin.get();
				}
				check_player2 = 0; check_player1 = 0;
			}
			if (player1 == 1000) cout << "\n\t**********************************" << "\n\t   Победил " << name1 << "  cо счетом " << player1 << "\n\t**********************************";
			else cout << "\n\t**********************************" << "\n\t   Победил " << name2 << "  cо счетом " << player2 << "\n\t**********************************";
			break;
		}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int player1, player2, computer, who_play, menu,igra=0;
	string name1, name2;
	do
	{
		menu = -1;who_play = -1; player1 = 0; player2 = 0; computer = 0;
		while (menu < 1 || menu>2)
		{
			cout << "\n\n\t~~~~~~МЕНЮ~~~~~~\n";
			cout << "\t 1) Новая игра\n\t 2) Правила\n\t~~~~~~~~~~~~~~~~\n";
			cout << "Введите нужный вариант: ";
			cin >> menu;
			if (menu < 1 || menu>2) cout << "\nВведено недопустимое значение, попробуйте еще раз.\n\n";
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
				if (who_play < 1 || who_play>2) cout << "\nВведено недопустимое значение, попробуйте еще раз.\n\n";
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
		case 2://Правила
		{
			cout << "\n\n\t~~~~ПРАВИЛА~~~~\n";
			cout << "* Каждый ход начинается с броска сразу 5 кубиков.\nПосле того, как кубики упадут, бросок анализируется на наличие очковых комбинаций.\nОчки приносят кубики достоинством 1 (10 очков) и 5 (5 очков),\nа также 3 и более кубика одного достоинства, выпавшие в текущем броске.\n";
			cout << "\t~~~~~~~~~~~~~";
			cout << "\n* При этом 3 кубика дают очки по номиналу кубика умноженного на 10, четыре на 20, пять на 100\n";
			cout << "\t~~~~~~~~~~~~~";
			cout << "\n* Если бросок принес игроку хотя бы 5 очков (т.е. выпала не нулевая комбинация),\n то все кубики, которые принесли очки откладываются, а оставшиеся кубики игрок может бросать повторно.\n";
			cout << "\t~~~~~~~~~~~~~";
			cout << "\n* Обратите внимание, что если все пять кубиков участвовали в комбинации, \nто к броску становятся доступны снова все пять кубиков\n";
			cout << "\t~~~~~~~~~~~~~";
			cout << "\n* Если при очередном броске выпадает нулевая комбинация, то игрок получает 0 очков и ему вписывается БОЛТ \n(когда накапливается 3 болта, списывается 100 очков)\n";
			cout << "\t~~~~~~~~~~~~~";
			cout << "\n* ПРАВИЛО ОБГОНА: Если один из игроков обгоняет другого, \nт.е. до хода он имел меньшую сумму очков, а после хода большую,\nто с игрока, которого он обгоняет списывается 50 очков.\n";
			cout << "\t~~~~~~~~~~~~~";
			cout << "\n* САМОСВАЛ: В игре существует самосвал. Если игрок набирает 555 очков, \nто он попадает на самосвал и с него списываются все очки\n";
			cout << "\t~~~~~~~~~~~~~\n";
			cout << "\t~~~~~~~~~~~~~";
			cout << "\n* БОЧКИ: В игре существует три вида бочек. Чаще всего выигрыш игры, так или иначе связан\nс обязательной перспективой пройти через процедуру сидения на бочке и неприятности связанные с падением с бочки.\n";
			cout << "\t~~~~~~~~~~~~~";
			cout << "\n\t** ИГРА БЕЗ БОЧЕК: Для выигрыша игры достаточно набрать сумму в 1000 или более очков.\n";
			cout << "\t~~~~~~~~~~~~~";
			cout << "\n\t** БОЧКА ПО ОЧКАМ: В этом случае для выигрыша игры игрок должен сначала сесть на бочку \n(т.е. набрать сумму очков большую заданной - по умолчанию это 880). \nА затем за один раз набрать сразу всю сумму, которая ему требуется до 1000. \nПри этом побеить можно и набрав 1000, до этого имея менее 880 очков (например из 870 получить 1000)\n";
			cout << "\nПри этом игрок не может сидеть на бочке бесконечно долго - для выигрыша игры у него есть 3 попытки. \nПосле того, как он их использует он падает с бочки, при этом с него списывается 100 очков.\n";
			cout << "\nНо количество раз, которые игрок может падать с бочки, также ограничено. \nВсего можно упасть 3 раза, при этом на 3-й раз вы теряете все заработанные очки\nЕще одним способом сбросить игрока с бочки, можно если самому залезть на нее. \nВ этом случае игрок сразу падает, даже если он не исчерпал лимита попыток и теряет все очки.\n";
			cout << "\t~~~~~~~~~~~~~";
			cout << "\n\t** ОТКРЫТАЯ БОЧКА: для выигрыша игрок должен набрать точно 1000 очков и не больше. \nЕсли очередным своим ходом игрок набирает сумму большую 1000, то ему зачисляется Точка.\nКогда игрок исчерпывает лимит точек (шесть), то с игрока списывается 100 очков.\nа если при этом исчерпан и лимит возможностей упасть с бочки (три), то у игрока списываются все очки.\n";
			cout << "\t~~~~~~~~~~~~~";
			cout << "\n\n\tПРИЯТНОЙ ИГРЫ\n";
			cout << "\t~~~~~~~~~~~~~";
			break;
		}
		}
		while (igra < 1 || igra>2) 
		{
			cout << "\nЖелаете сыграть?";
			cout << "\n1)ДА (начать заново)\n2)НЕТ (завершение программы)\n";
			cin >> igra;
			if (igra < 1 || igra>2) cout << "\nВведено недопустимое значение, попробуйте еще раз.\n\n";
		}
	} while (igra != 2);
	return 0;
}