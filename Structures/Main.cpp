#include <iostream>
#include <string>


struct Date { // �������� �������� �� ���������
	int day = 01;
	int month = 01;
	int year = 1970;
	std::string note = "empty";
};
void print_date(const Date& D) { //�������� ������� ��� ������ ������� �������
	std::cout << D.day << '.' << D.month << '.' << D.year << " - " << D.note << std::endl;
}

Date input_date() {
	Date tmp;

	std::cout << "������� ���� -> ";
	std::cin >> tmp.day;
	std::cout << "������� ����� -> ";
	std::cin >> tmp.month;
	std::cout << "������� ��� -> ";
	std::cin >> tmp.year;
	std::cin.ignore();
	std::cout << "������� ������ -> ";
	std::getline(std::cin, tmp.note);

	return tmp;
}

void fill_date(Date& D) {
	std::cout << "������� ���� -> ";
	std::cin >> D.day;
	std::cout << "������� ����� -> ";
	std::cin >> D.month;
	std::cout << "������� ��� -> ";
	std::cin >> D.year;
	std::cin.ignore();
	std::cout << "������� ������ -> ";
	std::getline(std::cin, D.note);
}

//������ 1.
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
	std::cout << "���: " << CK.name << std::endl;
	std::cout << "���� ��������: " << CK.birthday.day << '.' << CK.birthday.month << '.' << CK.birthday.year << std::endl;
	std::cout << "������: ";
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

//������ 2.
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

		//���������: ��������, ���������� �������������, ������ � ������
		struct Person { // �������� ���������, �������� ��������� � ������� �����
			std::string name;
			int age;
			std::string job;
			double salary;
		} p3, p4{ "Unlnow person", 18 };

		Person p1; // �������� ������� �� ������ ��������� Person
		// ������������� ����� ������� p1
		p1.name = "Tom Smith"; 
		p1.age = 27;
		p1.job = "programer";
		p1.salary = 80000;
		// ���� ������� - �������� ���������
		// ����� ����� ������� p1
		std::cout << "���: " << p1.name << std::endl;
		std::cout << "�������: " << p1.age << std::endl;
		std::cout << "���������: " << p1.job << std::endl;
		std::cout << "��������: " << p1.salary << std::endl;

		std::cout << "_______________________________________" << std::endl << std::endl;

		Person p2{ // ������������� ����� ������� p2
			"Bob Thomas",
			32,
			"director",
			120000
		};
		// ����� ����� ������� p2
		std::cout << "���: " << p2.name << std::endl;
		std::cout << "�������: " << p2.age << std::endl;
		std::cout << "���������: " << p2.job << std::endl;
		std::cout << "��������: " << p2.salary << std::endl;


		p3 = p1; // ����������� �������� ����� ������� p1 � ���� ������� p3

		//��������� � ������� ��� ������ �� �����������
		Date d1;
		print_date(d1); //�������� �������� � �������


		Date* pd1 = &d1; // �������� ��������� �������
	
		std::cout << std::endl;
		std::cout << "���� ������ � ������\n\n";
	//	Date d2 = input_date(); //������ ������� � ������ d2
	//	print_date(d2);
		Date d2;
		fill_date(d2); //������ ������� � ������ d2
		print_date(d2);

		//������ 1. ��������� ����� 
		std::cout << "������ 1.\n";
		CoinKeeper ck{
			"Robert Poson",
			{ 11, 12, 2003 },
			5,
			new int [5] { 2, 10, 4, 5, 1}
		};
		print_keeper(ck);
		std::cout << "�������: " << age(ck, 2023) << std::endl;
		std::cout << "����� ����� = " << cash(ck) << std::endl;
		delete[] ck.coins;
		
		//������ 2. ����� � ���������
		std::cout << "������ 2.\n";
		Point A{ 2.2, 5.0 }, B{ 7.1, 6.8 };
		std::cout << compare_distance(A, B) << std::endl;
		std::cout << compare_distance({5.5, 1.1}, {3.3, 0.77}) << std::endl;
		std::cout << compare_distance({ 5.5, 1.1 }, { -5.5, -1.1 }) << std::endl;


		
		return 0;
}