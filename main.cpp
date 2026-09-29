#include <iostream>
#include <string>
#include <windows.h>
#include <unordered_set>
#include "structfortask.h"
#include "task2_table.h"
#include "tasks.h"

using namespace std;

// =========================================== ПЕРВОЕ ЗАДАНИЕ ===========================================

int Task1::max_element_value(const int a[], int n) {
    int bigest = a[0];
    for (int i = 1; i < n; i++) {
        cmp++;
        if (a[i] > bigest) bigest = a[i];
    }
    return bigest;
}

long long Task1::sum_elements(const int a[], int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        add++;
        sum += a[i];
    }
    return sum;
}

bool Task1::contains(const int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        cmp++;
        if (a[i] == x) return true;
    }
    return false;
}

// =========================================== ВТОРОЕ ЗАДАНИЕ ===========================================

void Task2::bubble_sort(int a[], int n) {
    for (int i = 0; i + 1 < n; i++) {
        int swapped = 0;
        for (int j = 0; j + 1 < n - i; j++) {
            cmp++;
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                writes += 2;
                swapped = 1;
            }
        }
        if (swapped == 0) break;
    }
}

void Task2::insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0) {
            cmp++;
            if (a[j] <= key) break;
            a[j + 1] = a[j];
            writes++;
            j--;
        }
        a[j + 1] = key;
        writes++;
    }
}

// =========================================== ТРЕТЬЕ ЗАДАНИЕ ===========================================

// один проход
std::string Task3::second_largest(std::istream& in, int n) {
    std::string mx1 = "";
    std::string mx2 = "";

    for (int i = 0; i < n; i++) {
        std::string s;
        in >> s;

        if (s > mx1) {
            mx2 = mx1;
            mx1 = s;
        }
        else if (s != mx1 && s > mx2) {
            mx2 = s;
        }
    }

    return mx2.empty() ? "NONE" : mx2;
}

// сортировкой
std::string Task3::second_largest_sort(std::istream& in, int n) {
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++) in >> a[i];

    std::sort(a.begin(), a.end());

    const std::string& mx = a.back();
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != mx) return a[i];
    }
    return "NONE";
}

// =========================================== ЧЕТВЕРТОЕ ЗАДАНИЕ ===========================================

bool Task4::is_palindrom_approach1(const std::string& s) {
    std::string t;
    t.reserve(s.size());

    for (char c : s) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (isalnum(uc)) {
            t.push_back(static_cast<char>(tolower(uc)));
        }
    }
    int l = 0; int r = static_cast<int>(t.size()) - 1;
    while (l < r) {
        if (t[l] != t[r]) return false;
        ++l;
        --r;
    }
    return true;
}

bool Task4::is_palindrom_approach2(const std::string& s) {
    int l = 0; int r = static_cast<int>(s.size()) - 1;
    while (l < r) {
        while (l < r && !std::isalnum(static_cast<unsigned char>(s[l]))) ++l;
        while (l < r && !std::isalnum(static_cast<unsigned char>(s[r]))) --r;
        if (std::tolower(static_cast<unsigned char>(s[l])) != std::tolower(static_cast<unsigned char>(s[r]))) return false;
        ++l;
        --r;
    }
    return true;
}

// =========================================== ПЯТОЕ ЗАДАНИЕ ===========================================

// прямой проход
int Task5::count_long(int a[], int n) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        bool yes = false;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                yes = true;
                break;
            }
        }
        if (!yes) c++;
    }
    return c;
}

// с помощью сортировки
int Task5::count_sort(int a[], int n) {
    if (n == 0) return 0;
    sort(a, a + n);
    int c = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) c++;
    }
    return c;
}

// хэш таблицей
int Task5::count_xash(int a[], int n) {
    std::unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
    }
    return static_cast<int>(s.size());
}

// =========================================== ШЕСТОЕ ЗАДАНИЯ ===========================================

// полный проход для каждого
int Task6::native_miss(int a[], int n) {
    int c = 1;
    while (std::count(a, a + n, c) > 0) {
        ++c;
    }
    return c;
}

// через хэш 
int Task6::mark_miss(int a[], int n) {
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 1 && a[i] <= n + 1) {
            seen.insert(a[i]);
        }
    }
    for (int i = 1; i <= n + 1; i++) {
        if (seen.find(i) == seen.end()) return i;
    }
    return n + 2;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    do {
        cout << "\nВыберите задачу:\n";
        cout << "(1) Задание 1. Операции с массивом\n";
        cout << "(2) Задание 2. Сравнение сортировок\n";
        cout << "(3) Задание 3. Вторая строка\n";
        cout << "(4) Задание 4. Палиндром\n";
        cout << "(5) Задание 5. Количество различных элементов\n";
        cout << "(6) Задание 6. Первое отсутствующее положительное число\n";
        cout << "(0) Выход\n> ";

        int mode;
        cin >> mode;

        switch (mode) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 6: task6(); break;
        case 0: return 0;
        default: cout << "Неверный ввод.\n";
        }
    } while (true);

    return 0;
}
