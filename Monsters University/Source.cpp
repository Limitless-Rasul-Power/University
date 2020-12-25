#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Base
{

private:
	unsigned short id;

public:

	Base() :id(0)
	{}

	Base(const short& id)
		:id(id)
	{}

	unsigned short Get_id() const
	{
		return id;
	}

};

class Lesson : public Base
{

private:
	string name;

public:
	static unsigned short lesson_id;

	Lesson() :name("")
	{}

	Lesson(const string& name)
		:Base(++lesson_id)
	{
		Set_name(name);
	}

	void Set_name(const string& name)
	{
		if (name.empty())
			throw "Name is Empty!";

		this->name = name;
	}

	string Get_name() const
	{
		return name;
	}

	static unsigned short Get_current_id()
	{
		return lesson_id;
	}

	void Show() const
	{
		cout << "Lesson ID: " << Get_id() << '\n';
		cout << "Lesson Name: " << Get_name() << '\n';
	}

};

class Exam : public Base
{

private:
	Lesson lesson;
	unsigned short point;

public:

	static unsigned short exam_id;

	Exam() :point(0U)
	{}

	Exam(const Lesson& lesson, const short& point)
		:Base(++exam_id)
	{
		Set_lesson(lesson);
		Set_point(point);
	}

	void Set_lesson(const Lesson& lesson)
	{	
		this->lesson = lesson;
	}
	Lesson Get_lesson() const
	{
		return lesson;
	}

	void Set_point(const short& point)
	{

		if (point <= 0)
			throw "Point must be more than 0!";

		this->point = point;
	}
	unsigned short Get_point() const
	{
		return point;
	}

	void Show() const
	{
		cout << "Exam ID: " << Get_id() << '\n';
		cout << "Exam Lesson: " << Get_lesson().Get_name() << '\n';
		cout << "Exam Point: " << Get_point() << "\n\n";
	}

};

class BankCard : public Base
{

private:
	string code;
	string password;
	float balance;
	string expired_month;
	string expired_year;

public:

	static unsigned short bank_card_id;

	BankCard() :code(""), password(""), balance(0.0f), expired_month(""), expired_year("")
	{}

	BankCard(const string& code, const string& password, const float& balance, const string& expired_month, const string&
		expired_year)
		:Base(++bank_card_id)
	{
		Set_code(code);
		Set_password(password);
		Set_balance(balance);
		Set_expired_month(expired_month);
		Set_expired_year(expired_year);
	}

	void Set_code(const string& code)
	{
		if (code.length() < 16)
			throw "Code Lenght must be more than 16!";

		this->code = code;
	}
	string Get_code() const
	{
		return code;
	}

	void Set_password(const string& password)
	{
		if (password.length() < 4)
			throw "Password Length must be more thann 4";

		this->password = password;
	}
	string Get_password() const
	{
		return password;
	}

	void Set_balance(const float& balance)
	{
		if (balance < 0.0f)
			throw "Balance must be more than 0!";

		this->balance = balance;
	}
	float Get_balance() const
	{
		return balance;
	}

	void Set_expired_month(const string& expired_month)
	{
		if (expired_month.empty())
			throw "Expire month is empty!";

		this->expired_month = expired_month;
	}
	string Get_expired_month() const
	{
		return expired_month;
	}

	void Set_expired_year(const string& expired_year)
	{
		if (expired_year.length() < 4)
			throw "Expire year length must be more than 4!";

		this->expired_year = expired_year;
	}
	string Get_expired_year() const
	{
		return expired_year;
	}

	static unsigned short Get_current_id()
	{
		return bank_card_id;
	}

	void Show() const
	{
		cout << "Bank Card ID: " << Get_id() << '\n';
		cout << "Bank Card Code: " << Get_code() << '\n';
		string x(password.length() + 9, '*');
		cout << "Bank Card Password: " << x << '\n';
		cout << "Bank Card Balance: " << Get_balance() << " $\n";
		cout << "Bank Card Expired Month: " << Get_expired_month() << '\n';
		cout << "Bank Card Expired Year: " << Get_expired_year() << "\n\n";
	}

};

class Bank : public Base
{

private:
	string name;
	list<BankCard> b_cards;

public:

	static unsigned short bank_id;

	Bank() :name("")
	{}

	Bank(const string& name, const list<BankCard>& b_cards)
		:Base(++bank_id)
	{
		Set_name(name);
		Set_bank_cards(b_cards);
	}

	void Set_name(const string& name)
	{
		if (name.empty())
			throw "Name is Empty!";

		this->name = name;
	}
	string Get_name() const
	{
		return name;
	}

	void Set_bank_cards(const list<BankCard>& b_cards)
	{
		this->b_cards = b_cards;
	}
	list<BankCard>& Get_bank_cards()
	{
		return b_cards;
	}

	const float Get_all_bank_money()
	{
		float all_bank_money = 0.0f;

		for (auto i = Get_bank_cards().begin(); i != Get_bank_cards().end(); i++)
			all_bank_money += i->Get_balance();

		return all_bank_money;
	}

	void Show()
	{
		cout << "Bank ID: " << Get_id() << '\n';
		cout << "Bank Name: " << Get_name() << '\n';
		cout << "Bank Cards Informations\n\n";

		for (auto i = Get_bank_cards().begin(); i != Get_bank_cards().end(); i++)
			i->Show();

		cout << "Total Bank Money: " << Get_all_bank_money() << " $\n\n";
	}

};

class Student : public Base
{

private:
	string name;
	string surname;
	string special;
	unsigned short score;

	BankCard b_card;
	float money;

	list<Exam> exams;

public:

	static unsigned short student_id;

	Student() :name(""), surname(""), special(""), score(0U), money(0.0f)
	{}

	Student(const string& name, const string& surname, const string& special, const short& score, const BankCard& b_card,
		const float& money, const list<Exam>& exams)
		:Base(++student_id)
	{
		Set_name(name);
		Set_surname(surname);
		Set_special(special);
		Set_score(score);
		Set_bank_card(b_card);
		Set_money(money);
		Set_exams(exams);
	}

	void Set_name(const string& name)
	{
		if (name.empty())
			throw "Name is Empty!";

		this->name = name;
	}
	string Get_name() const
	{
		return name;
	}

	void Set_surname(const string& surname)
	{
		if (surname.empty())
			throw "Surame is Empty!";

		this->surname = surname;
	}
	string Get_surname() const
	{
		return surname;
	}

	void Set_special(const string& special)
	{
		if (special.empty())
			throw "Special is Empty!";

		this->special = special;
	}
	string Get_special() const
	{
		return special;
	}

	void Set_score(const short& score)
	{
		if (score < 0)
			throw "Score must be more than 0!";

		this->score = score;
	}
	unsigned short Get_score() const
	{
		return score;
	}

	void Set_bank_card(const BankCard& b_card)
	{
		this->b_card = b_card;
	}
	BankCard Get_bank_card() const
	{
		return b_card;
	}

	void Set_money(const float& money)
	{
		if (money < 0.0f)
			throw "Money must be more than 0!";

		this->money = money;
	}
	float Get_money() const
	{
		return money;
	}

	void Set_exams(const list<Exam>& exams)
	{
		this->exams = exams;
	}
	list<Exam>& Get_exams()
	{
		return exams;
	}

	unsigned short Get_average_point()
	{
		unsigned short avg_point = 0U;
		unsigned short count = 0U;
		for (auto i = Get_exams().begin(); i != Get_exams().end(); i++)
		{
			avg_point += i->Get_point();
			++count;
		}

		return avg_point / count;
	}

	void Show()
	{
		cout << "Student ID: " << Get_id() << '\n';
		cout << "Student Name: " << Get_name() << '\n';
		cout << "Student Surname: " << Get_surname() << '\n';
		cout << "Student Money: " << Get_money() << '\n';
		cout << "Student Speciality: " << Get_special() << '\n';

		cout << "\nStudent Bank Card Information\n\n";
		Get_bank_card().Show();

		cout << "Student Exam Informations\n\n";

		for (auto i = Get_exams().begin(); i != Get_exams().end(); i++)
			i->Show();

		cout << "Average Exam Point: " << Get_average_point() << "\n\n\n";

	}

};

class Group : public Base
{

private:
	string name;
	list<Student> students;
	list<Lesson> lessons;

public:

	static unsigned short group_id;

	Group() :name("")
	{}

	Group(const string& name, const list<Student>& students, const list<Lesson>& lessons)
		:Base(++group_id)
	{
		Set_name(name);
		Set_students(students);
		Set_lessons(lessons);
	}

	void Set_name(const string& name)
	{
		if (name.empty())
			throw "Name is Empty!";

		this->name = name;
	}
	string Get_name() const
	{
		return name;
	}

	void Set_students(const list<Student>& students)
	{
		this->students = students;
	}
	list<Student>& Get_students()
	{
		return students;
	}

	void Set_lessons(const list<Lesson>& lessons)
	{
		this->lessons = lessons;
	}
	list<Lesson>& Get_lessons()
	{
		return lessons;
	}

	void Show()
	{
		cout << "Group ID: " << Get_id() << '\n';
		cout << "Group NO_" << Get_name() << '\n';
		cout << "\nGroup Lessons\n\n";

		for (auto i = Get_lessons().begin(); i != Get_lessons().end(); i++)
			i->Show();

		cout << "\nGroup Students\n\n";

		for (auto i = Get_students().begin(); i != Get_students().end(); i++)
			i->Show();

	}
};

class Teacher : public Base
{

private:
	string name;
	string surname;
	string department;
	unsigned short age;
	list<Group> groups;
	float salary;
	BankCard b_card;

public:

	static unsigned short teacher_id;

	Teacher() :name(""), surname(""), department(""), age(0U), salary(0.0f)
	{}

	Teacher(const string& name, const string& surname, const short& age, const string& department, const float& salary,
		const list<Group>& groups, const BankCard& b_card)
		:Base(++teacher_id)
	{
		Set_name(name);
		Set_surname(surname);
		Set_age(age);
		Set_department(department);
		Set_salary(salary);
		Set_groups(groups);
		Set_bank_card(b_card);
	}

	void Set_name(const string& name)
	{
		if (name.empty())
			throw "Name is Empty!";

		this->name = name;
	}
	string Get_name() const
	{
		return name;
	}

	void Set_surname(const string& surname)
	{
		if (surname.empty())
			throw "Surame is Empty!";

		this->surname = surname;
	}
	string Get_surname() const
	{
		return surname;
	}

	void Set_age(const short& age)
	{
		if (age < 18)
			throw "Age must be more than 17";

		this->age = age;
	}
	unsigned short Get_age() const
	{
		return age;
	}

	void Set_department(const string& department)
	{
		if (department.empty())
			throw "Department is Empty!";

		this->department = department;
	}
	string Get_department() const
	{
		return department;
	}

	void Set_salary(const float& salary)
	{
		if (salary < 0.0f)
			throw "Salary must be more than 0!";

		this->salary = salary;
	}
	float Get_salary() const
	{
		return salary;
	}

	void Set_groups(const list<Group>& groups)
	{
		this->groups = groups;
	}
	list<Group>& Get_groups()
	{
		return groups;
	}

	void Set_bank_card(const BankCard& b_card)
	{
		this->b_card = b_card;
	}
	BankCard Get_bank_card() const
	{
		return b_card;
	}

	void Show()
	{
		cout << "Teacher ID: " << Get_id() << '\n';
		cout << "Teacher Name: " << Get_name() << '\n';
		cout << "Teacher Surname: " << Get_surname() << '\n';
		cout << "Teacher Age: " << Get_age() << '\n';
		cout << "Teacher Department: " << Get_department() << '\n';
		cout << "Teacher Salary: " << Get_salary() << " $\n";

		cout << "Teacher's Group Information\n\n";
		for (auto i = Get_groups().begin(); i != Get_groups().end(); i++)
			i->Show();

		cout << "Teacher's Bank Card Information\n\n";
		Get_bank_card().Show();
		cout << "\n\n\n\=================================================================================\n\n\n";
	}
};

class University : public Base
{

private:
	string name;
	list<Teacher> teachers;
	list<Student> students;

public:

	static unsigned short university_id;

	University() :name("")
	{}

	University(const string& name, const list<Teacher>& teachers, const list<Student>& students)
		:Base(++university_id)
	{
		Set_name(name);
		Set_teachers(teachers);
		Set_students(students);
	}

	void Set_name(const string& name)
	{
		if (name.empty())
			throw "Name is Empty!";

		this->name = name;
	}
	string Get_name() const
	{
		return name;
	}

	void Set_teachers(const list<Teacher>& teachers)
	{
		this->teachers = teachers;
	}
	list<Teacher>& Get_teachers()
	{
		return teachers;
	}

	void Set_students(const list<Student>& students)
	{
		this->students = students;
	}
	list<Student>& Get_students()
	{
		return students;
	}

	void Show_all_students()
	{
		for (auto i = Get_students().begin(); i != Get_students().end(); i++)
			i->Show();
	}

	void Show_all_teachers()
	{
		for (auto i = teachers.begin(); i != teachers.end(); i++)
			i->Show();
	}

	float Get_payment() const
	{
		float all_money = 0.0f;

		for (auto i = students.begin(); i != students.end(); i++)
			all_money += i->Get_money();

		for (auto i = teachers.begin(); i != teachers.end(); i++)
			all_money += i->Get_salary();

		return all_money;
	}

	void Show_university()
	{
		cout << "University ID: " << Get_id() << '\n';
		cout << "University Name: " << Get_name() << '\n';
		cout << "University's all teachers\n\n";
		Show_all_teachers();
		cout << "\n\n\nUniversity's all students\n\n";
		Show_all_students();
		cout << "University Payment: " << Get_payment() << " $\n";
	}

};

void Start()
{
	list<Lesson> lessons;
	lessons.resize(7);
	lessons.erase(lessons.begin(), lessons.end());

	lessons.emplace_back(Lesson("Math"));
	lessons.emplace_back(Lesson("English"));
	lessons.emplace_back(Lesson("History"));
	lessons.emplace_back(Lesson("Biology"));
	lessons.emplace_back(Lesson("Anatomy"));
	lessons.emplace_back(Lesson("Algebra"));
	lessons.emplace_back(Lesson("Information Technology"));


	list<Exam> exams;
	exams.resize(7);
	exams.erase(exams.begin(), exams.end());

	unsigned short point = 30U;

	for (auto i = lessons.cbegin(); i != lessons.cend(); i++, point += 10)
		exams.emplace_back(Exam(*i, point));

	list<BankCard> b_cards;
	b_cards.resize(7);
	b_cards.erase(b_cards.begin(), b_cards.end());
	
	b_cards.emplace_back(BankCard("1234456734245234523", "than this there where what", 3000.12f, "December", "2020"));
	b_cards.emplace_back(BankCard("6754643654747456322", "is this all there is", 4000.0f, "December", "2021"));
	b_cards.emplace_back(BankCard("9897463422654778967", "i love you", 5000.0f, "December", "2022"));
	b_cards.emplace_back(BankCard("8752574564646863465", "santa claus where are you", 6000.0f, "December", "2023"));
	b_cards.emplace_back(BankCard("7775534536779632526", "i don't want  this present", 7000.0f, "December", "2024"));
	b_cards.emplace_back(BankCard("4474864623747756665", "what are you doing", 8000.0f, "December", "2025"));
	b_cards.emplace_back(BankCard("7687953254756877601", "forget IT", 9900.0f, "December", "2026"));

	unique_ptr<Bank> bank(new Bank("Bir Bank", b_cards));


	list<Student> students;
	students.resize(7);
	students.erase(students.begin(), students.end());



	students.emplace_back(Student("Mike", "Tyson", "Future Boxer", 50, *b_cards.begin(), 190.0f, exams));
	students.emplace_back(Student("John", "Cena", "Smacdown", 60, *(++b_cards.begin()), 200.0f, exams));
	students.emplace_back(Student("Rey", "Dal", "Programmer", 70, *(++++b_cards.begin()), 300.0f, exams));
	students.emplace_back(Student("Warren", "Buffett", "Invester", 80, *(++++++b_cards.begin()), 400.0f, exams));
	students.emplace_back(Student("Jim", "Rohn", "Life Changer", 90, *(++++++++b_cards.begin()), 500.0f, exams));
	students.emplace_back(Student("Simon", "Sinek", "Business Manager", 99, *(++++++++++b_cards.begin()), 600.0f, exams));
	students.emplace_back(Student("Anthony", "Robbins", "Date with Destiny", 100, *(++++++++++++b_cards.begin()), 700.0f, exams));

	list<Group> groups;
	groups.emplace_back(Group("My Team", students, lessons));


	list<Teacher> teachers;
	teachers.resize(7);
	teachers.erase(teachers.begin(), teachers.end());

	teachers.emplace_back(Teacher("Timothy", "Ferriss", 25, "Mezahir Office", 22222.22f, groups, *b_cards.begin()));
	teachers.emplace_back(Teacher("Master", "Guru", 26, "Mezahir Office", 6000.0f, groups, *(++b_cards.begin())));
	teachers.emplace_back(Teacher("Master", "Donald", 27, "Mezahir Office", 7000.0f, groups, *(++++b_cards.begin())));
	teachers.emplace_back(Teacher("Master", "Arthur", 28, "Mezahir Office", 8000.0f, groups, *(++++++b_cards.begin())));
	teachers.emplace_back(Teacher("Master", "Yohan", 29, "Mezahir Office", 9000.0f, groups, *(++++++++b_cards.begin())));
	teachers.emplace_back(Teacher("Master", "Poly", 30, "Mezahir Office", 10000.0f, groups, *(++++++++++b_cards.begin())));
	teachers.emplace_back(Teacher("Master", "Theodore", 31, "Mezahir Office", 5000.0f, groups, *(++++++++++++b_cards.begin())));

	unique_ptr<University> uni(new University("Oxford", teachers, students));

	uni->Show_university();
	//bank->Show();
}

unsigned short Lesson::lesson_id = NULL;	    unsigned short Exam::exam_id = NULL;              unsigned short BankCard::bank_card_id = NULL;
unsigned short Bank::bank_id = NULL;		    unsigned short Student::student_id = NULL;        unsigned short Group::group_id = NULL;
unsigned short Teacher::teacher_id = NULL;	    unsigned short University::university_id = NULL;

int main()
{
	try
	{
		Start();
	}
	catch (const char* exception)
	{
		cout << "Error: " << exception << '\n';
	}

	system("pause");
	return 0;
}