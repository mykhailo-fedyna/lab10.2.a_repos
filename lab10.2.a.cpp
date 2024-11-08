#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

// Перелік спеціальностей
enum Specialization { COMPUTER_SCIENCE, MATHEMATICS, PHYSICS, ENGINEERING, BIOLOGY };
string specializationStr[] = { "Комп'ютерні науки", "Математика", "Фізика", "Інженерія", "Біологія" };

// Структура для представлення студента
struct Student {
    string surname;
    unsigned course;
    Specialization specialization;
    int physics;
    int mathematics;
    int informatics;
};

// Функції для введення, виведення, сортування та обчислення середнього балу
void InputStudents(Student* students, int N);
void PrintStudents(const Student* students, int N);
double CalculateAverage(const Student& student);
void SortStudents(Student* students, int N);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int numStudents;
    cout << "Введіть кількість студентів: ";
    cin >> numStudents;

    Student* students = new Student[numStudents];

    int menuItem;
    do {
        cout << "\nМеню:\n";
        cout << "1 - Введення даних студентів\n";
        cout << "2 - Вивід даних студентів\n";
        cout << "3 - Фізичне сортування студентів\n";
        cout << "0 - Вихід\n";
        cout << "Виберіть дію: ";
        cin >> menuItem;

        switch (menuItem) {
        case 1:
            InputStudents(students, numStudents);
            break;
        case 2:
            PrintStudents(students, numStudents);
            break;
        case 3:
            SortStudents(students, numStudents);
            cout << "Список студентів відсортовано.\n";
            break;
        case 0:
            break;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз.\n";
        }
    } while (menuItem != 0);

    delete[] students; // Звільнення пам'яті
    return 0;
}

void InputStudents(Student* students, int N) {
    int spec;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":\n";
        cin.ignore();
        cout << " Прізвище: "; getline(cin, students[i].surname);
        cout << " Курс: "; cin >> students[i].course;
        cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Математика, 2 - Фізика, 3 - Інженерія, 4 - Біологія): ";
        cin >> spec;
        students[i].specialization = static_cast<Specialization>(spec);
        cout << " Оцінка з фізики: "; cin >> students[i].physics;
        cout << " Оцінка з математики: "; cin >> students[i].mathematics;
        cout << " Оцінка з інформатики: "; cin >> students[i].informatics;
    }
}

void PrintStudents(const Student* students, int N) {
    cout << "=============================================================================================\n";
    cout << "| № | Прізвище         | Курс | Спеціальність           | Фізика | Математика | Інформатика |\n";
    cout << "---------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << i + 1 << "| ";
        cout << setw(15) << left << students[i].surname;
        cout << "  | " << setw(4) << right << students[i].course;
        cout << " | " << setw(21) << left << specializationStr[students[i].specialization];
        cout << "   | " << setw(6) << right << students[i].physics;
        cout << " | " << setw(10) << right << students[i].mathematics;
        cout << " | " << setw(11) << right << students[i].informatics << " |\n";
    }

    cout << "=============================================================================================\n";
}

double CalculateAverage(const Student& student) {
    return (student.physics + student.mathematics + student.informatics) / 3.0;
}

void SortStudents(Student* students, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            bool swapNeeded = false;

            // Сортування за оцінкою з інформатики (третій предмет)
            if (students[j].informatics < students[j + 1].informatics) {
                swapNeeded = true;
            }
            // Якщо оцінки з інформатики однакові, сортування за середнім балом
            else if (students[j].informatics == students[j + 1].informatics) {
                if (CalculateAverage(students[j]) < CalculateAverage(students[j + 1])) {
                    swapNeeded = true;
                }
                // Якщо середні бали теж однакові, сортування за прізвищем
                else if (CalculateAverage(students[j]) == CalculateAverage(students[j + 1])) {
                    if (students[j].surname > students[j + 1].surname) {
                        swapNeeded = true;
                    }
                }
            }

            if (swapNeeded) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
