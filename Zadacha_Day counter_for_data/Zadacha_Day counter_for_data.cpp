#include <iostream>
using namespace std;

int proverca_coerctnosti(int, int, int); // Проверка на корректность дат
int proverca_sled(int, int, int, int, int, int); // Проверка на последовательность дат
int fevral_edit(int); //Определение февраля даты
int day_date_couter(int, int, int); //Счетчик дня для даты в году
long year_data_couter(int, int); //Счетчик дней между годами

int main()
{

	setlocale(0, "");
	int konez = 1;
	// ввод данных о датах	
	do 
	{
		int d0, d1, m0, m1, y0, y1;
		cout << "Введите через пробел число месяц и год первой даты => ";
		cin >> d0 >> m0 >> y0;
		if (proverca_coerctnosti(d0, m0, y0)) {
			cout << "Введите через пробел число месяц и год второй даты => ";
			cin >> d1 >> m1 >> y1;

			if (proverca_coerctnosti(d1, m1, y1) && proverca_sled(d0, d1, m0, m1, y0, y1))
			{	// Дни между годами + (Индекс второй даты - Индекс первой даты)				
				cout << "\nКоличество дней между введёнными датами: " <<
					year_data_couter(y0, y1) + (day_date_couter(d1, m1, y1) -
						day_date_couter(d0, m0, y0)) << endl << endl;
			}
		}
		cout << endl << "Хотите повторить?\n"
			"Введите в консоль число: 1 - если ДА, 0 - если НЕТ -> ";
		cin >> konez;
		system("cls"); // Стереть консоль
	} while (konez != 0);
	cout << "СПАСИБО ЧТО ВОСПОЛЬЗОВАЛИСЬ НАШЕЙ ПРОГРАММОЙ\n\n";
	system("pause");
}

int proverca_coerctnosti(int day, int month, int year)
{
	switch (month) {
	case 1:	case 3:	case 5:	case 7:	case 8:	case 10: case 12:
		// Январь, Март, Май, Июль, Август, Октябрь, Декабрь (7 месяцев)
		if (day <= 31 && day > 0)
			return true;
		else
		{
			cout << "Дата не корректна!\n";
			cout << "Максимальное количество дней для этого месяца 31\n";
			return false;
		}
		break;
	case 4:	case 6:	case 9: case 11:
		// апрель, июнь, сентябрь, ноябрь имеют по 30 дней (4 месяца)
		if (day <= 30 && day > 0)
			return true;
		else
		{
			cout << "Дата не корректна!\n";
			cout << "Максимальное количество дней для этого месяца 30\n";
			return false;
		}
		break;
	case 2:
		// отдельная проверка для февраля в зависимости от года
		if (day <= fevral_edit(year) && day > 0)
			return true;
		else
		{
			cout << "Дата не корректна!\n";
			cout << "В феврале " << year << " года возможно только "
				<< fevral_edit(year) << " дней \n";
			return false;
			break;
	default:
		cout << "Дата не корректна! В году только 12 месяцев!\n";
		return false;
		}
	}
	// Год вполне может быть и отрицательным (до р.х.)
}

int proverca_sled(int day1, int day2, int month1, int month2, int god1, int god2) {
	// Если хотя бы одно из трех условий верное даты последовательны!
	if (god2 <= god1 || god2 == god1 && month2 <= month1 || god2 == god1 && month2 == month1 && day2 <= day1) {
		cout << "Вторая дата не может быть раньше первой!\n";
		return false;
	}
	else
		return true;
}

int fevral_edit(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 29; //высокосный
	else
		return 28; //невыскосный
}

int day_date_couter(int day, int month, int year) {
	if (month == 1) { return day; }
	else if (month == 2) { return 31 + day; }
	else if (month == 3) { return 31 + day + fevral_edit(year); }
	else if (month == 4) { return 62 + day + fevral_edit(year); }
	else if (month == 5) { return 92 + day + fevral_edit(year); }
	else if (month == 6) { return 123 + day + fevral_edit(year); }
	else if (month == 7) { return 153 + day + fevral_edit(year); }
	else if (month == 8) { return 184 + day + fevral_edit(year); }
	else if (month == 9) { return 215 + day + fevral_edit(year); }
	else if (month == 10) { return 245 + day + fevral_edit(year); }
	else if (month == 11) { return 276 + day + fevral_edit(year); }
	else if (month == 12) { return 306 + day + fevral_edit(year); }
}

long year_data_couter(int god1, int god2) {

	long couter_day = 0, temp;
	for (int i = god1; i < god2; i++) {
		/*		Если проверяемый год делятся на 4
		И при этом НЕ делится на 100 - Год високосный (366),
Если два первых условия невыполненные проверяется третья
которое делит год на 400, если третье условие выполняется,
то год все равно високосный (366) */
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
		{
			temp = 366; // високосный 
		}
		else
		{
			temp = 365; // не високосный
		}
		/* Последовательно идем по каждому году проверяя его
		на условие значение проверки добавляем к счетчику*/
		couter_day += temp;
	}
	return couter_day;
}

