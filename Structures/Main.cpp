#include <iostream>
#include <string>


struct Date { // Создание значений по умолчанию
	int day = 01;
	int month = 01;
	int year = 1970;
	std::string note = "empty";
};
void print_date(const Date& D) { //создание функции для вывода оъектов целиком
	std::cout << D.day << '.' << D.month << '.' << D.year << " - " << D.note << std::endl;
}

Date input_date() {
	Date tmp;

	std::cout << "Введите день -> ";
	std::cin >> tmp.day;
	std::cout << "Введите месяц -> ";
	std::cin >> tmp.month;
	std::cout << "Введите год -> ";
	std::cin >> tmp.year;
	std::cin.ignore();
	std::cout << "Введите запись -> ";
	std::getline(std::cin, tmp.note);

	return tmp;
}

void fill_date(Date& D) {
	std::cout << "Введите день -> ";
	std::cin >> D.day;
	std::cout << "Введите месяц -> ";
	std::cin >> D.month;
	std::cout << "Введите год -> ";
	std::cin >> D.year;
	std::cin.ignore();
	std::cout << "Введите запись -> ";
	std::getline(std::cin, D.note);
}

//Задача 1.
struct MyDate {
	int day = 1;
	int month = 1;
	int year = 1970;
};
struct CoinKeeper {
	std::string name = "noname";
	MyDate birthday;
	int coins_number = 0;
	int* coins = nullptr;
};
void print_keeper(const CoinKeeper& CK) {
	std::cout << "Имя: " << CK.name << std::endl;
	std::cout << "Дата рождения: " << CK.birthday.day << '.' << CK.birthday.month << '.' << CK.birthday.year << std::endl;
	std::cout << "Монеты: ";
	for (int i = 0; i < CK.coins_number; i++)
		std::cout << CK.coins[i] << ' ';
	std::cout << std::endl;

}
inline int age (const CoinKeeper& CK, int year){
	return (year - CK.birthday.year);
}
int cash(const CoinKeeper& CK) {
	int sum = 0;
	for (int i = 0; i < CK.coins_number; i++)
		sum += CK.coins[i];
	return sum;
}

//Задача 2.
struct Point {
	double X{};
	double Y{};
};
int compare_distance(Point P1, Point P2) {
	double dist1 = P1.X * P1.X + P1.Y * P1.Y;
	double dist2 = P2.X * P2.X + P2.Y * P2.Y;
	if (dist1 > dist2)
		return 1;
	if (dist1 < dist2)
		return -1;
	return 0;
}

int main () {
	setlocale(LC_ALL, "Russian");
		int n;

		//Структуры: создание, мнговенная инициализация, работа с полями
		struct Person { // Создание структуры, название структуры с большой буквы
			std::string name;
			int age;
			std::string job;
			double salary;
		} p3, p4{ "Unlnow person", 18 };

		Person p1; // Создание объекта на основе структуры Person
		// Инициализация полей объекта p1
		p1.name = "Tom Smith"; 
		p1.age = 27;
		p1.job = "programer";
		p1.salary = 80000;
		// Поля объекта - элементы структуры
		// Вывод полей объекта p1
		std::cout << "Имя: " << p1.name << std::endl;
		std::cout << "Возраст: " << p1.age << std::endl;
		std::cout << "Должность: " << p1.job << std::endl;
		std::cout << "Зарплата: " << p1.salary << std::endl;

		std::cout << "_______________________________________" << std::endl << std::endl;

		Person p2{ // Инициализация полей объекта p2
			"Bob Thomas",
			32,
			"director",
			120000
		};
		// Вывод полей объекта p2
		std::cout << "Имя: " << p2.name << std::endl;
		std::cout << "Возраст: " << p2.age << std::endl;
		std::cout << "Должность: " << p2.job << std::endl;
		std::cout << "Зарплата: " << p2.salary << std::endl;


		p3 = p1; // Копирование значение полей объекта p1 в поля объекта p3

		//Указатели и функции при работе со структурами
		Date d1;
		print_date(d1); //передача объектов в функцию


		Date* pd1 = &d1; // Создание указателя области
	
		std::cout << std::endl;
		std::cout << "Ввод данных в объект\n\n";
	//	Date d2 = input_date(); //запись функции в объект d2
	//	print_date(d2);
		Date d2;
		fill_date(d2); //запись функции в объект d2
		print_date(d2);

		//Задача 1. Хранитель монет 
		std::cout << "Задача 1.\n";
		CoinKeeper ck{
			"Robert Poson",
			{ 11, 12, 2003 },
			5,
			new int [5] { 2, 10, 4, 5, 1}
		};
		print_keeper(ck);
		std::cout << "Возраст: " << age(ck, 2023) << std::endl;
		std::cout << "Сумма монет = " << cash(ck) << std::endl;
		delete[] ck.coins;
		
		//Задача 2. Точки в плоскости
		std::cout << "Задача 2.\n";
		Point A{ 2.2, 5.0 }, B{ 7.1, 6.8 };
		std::cout << compare_distance(A, B) << std::endl;
		std::cout << compare_distance({5.5, 1.1}, {3.3, 0.77}) << std::endl;
		std::cout << compare_distance({ 5.5, 1.1 }, { -5.5, -1.1 }) << std::endl;


		
		return 0;
}