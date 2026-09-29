#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <windows.h>
#include <unordered_set>
#include "structfortask.h"
#include "task2_table.h"
#include "tasks.h"

using namespace std;

// =========================================== ПЕРВОЕ ЗАДАНИЕ ===========================================

int Task1::max_element_value(const int a[], int n) {
    int biggest = a[0];
    for (int i = 1; i < n; i++) {
        cmp++;
        if (a[i] > biggest) biggest = a[i];
    }
    return biggest;
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
        bool swapped = false;
        for (int j = 0; j + 1 < n - i; j++) {
            cmp++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                writes += 2;
                swapped = true;
            }
        }
        if (!swapped) break;
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
string Task3::second_largest(istream& in, int n) {
    string largest = "";
    string second_largest = "";

    for (int i = 0; i < n; i++) {
        string s;
        in >> s;

        if (s > largest) {
            second_largest = largest;
            largest = s;
        }
        else if (s != largest && s > second_largest) {
            second_largest = s;
        }
    }

    return second_largest.empty() ? "NONE" : second_largest;
}

// сортировкой
string Task3::second_largest_sort(istream& in, int n) {
    vector<string> a(n);
    for (int i = 0; i < n; i++) in >> a[i];

    sort(a.begin(), a.end());

    const string& largest = a.back();
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != largest) return a[i];
    }
    return "NONE";
}

// =========================================== ЧЕТВЕРТОЕ ЗАДАНИЕ ===========================================

bool Task4::is_palindrome_approach1(const string& s) {
    string t;
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

bool Task4::is_palindrome_approach2(const string& s) {
    int l = 0; int r = static_cast<int>(s.size()) - 1;
    while (l < r) {
        while (l < r && !isalnum(static_cast<unsigned char>(s[l]))) ++l;
        while (l < r && !isalnum(static_cast<unsigned char>(s[r]))) --r;
        if (tolower(static_cast<unsigned char>(s[l])) != tolower(static_cast<unsigned char>(s[r]))) return false;
        ++l;
        --r;
    }
    return true;
}

// =========================================== ПЯТОЕ ЗАДАНИЕ ===========================================

// прямой проход
int Task5::count_unique_bruteforce(const int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool already_seen = false;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                already_seen = true;
                break;
            }
        }
        if (!already_seen) count++;
    }
    return count;
}

// с помощью сортировки
int Task5::count_unique_sort(int a[], int n) {
    if (n == 0) return 0;
    sort(a, a + n);
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) count++;
    }
    return count;
}

// хэш таблицей
int Task5::count_unique_hash(const int a[], int n) {
    unordered_set<int> elements;
    for (int i = 0; i < n; i++) {
        elements.insert(a[i]);
    }
    return static_cast<int>(elements.size());
}

// =========================================== ШЕСТОЕ ЗАДАНИЯ ===========================================

// полный проход для каждого
int Task6::find_native_miss(int a[], int n) {
    int candidate = 1;
    while(count(a, a + n, candidate) > 0) {
        ++candidate;
    }
    return candidate;
}

int Task6::find_missing_mark(int a[], int n) {
    vector<bool> seen(n + 2, false);

    for (int i = 0; i < n; i++) {
        if (a[i] >= 1 && a[i] <= n + 1) {
            seen[a[i]] = true;
        }
    }

    for (int candidate = 1; candidate <= n + 1; candidate++) {
        if (!seen[candidate]) {
            return candidate;
        }
    }

    return n + 1;
}

// через хэш 
int Task6::find_hash_miss(int a[], int n) {
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 1 && a[i] <= n + 1) {
            seen.insert(a[i]);
        }
    }
    for (int candidate = 1; candidate <= n + 1; candidate++) {
        if (seen.find(candidate) == seen.end()) return candidate;
    }
    return n + 2;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
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
