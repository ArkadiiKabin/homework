#pragma once
#include <iostream>
#include <algorithm>
#include <sstream> 
using namespace std;

// чтоб не путаться: структура, название теста, массив, длина, сумма, макс, искомое, успех поиска искомого
void check_task1(Task1& t, const char* name, int a[], int n, long long exp_sum, int exp_max, int exp_x, bool cont){
    cout << '\n' << name << '\n';
    t.cmp = 0; cout << (t.max_element_value(a, n) == exp_max ? "[OK]" : "[FAIL]") << " max, cmp = " << t.cmp << "\n";
    t.add = 0; cout << (t.sum_elements(a, n) == exp_sum ? "[OK]" : "[FAIL]") << " sum, add = " << t.add << '\n';
    t.cmp = 0; cout << (t.contains(a, n, exp_x) == cont ? "[OK]" : "[FAIL]") << " cont, cmp = " << t.cmp << '\n';
}

// структура, название, массив, длина, искомое, успех поиска, ождидаемое число сравнений
void check_contains(Task1& t, const char* name, int a[], int n, int x, bool expected, int expected_cmp) {
    t.cmp = 0; bool res = t.contains(a, n, x); bool ok = (res == expected && t.cmp == expected_cmp);
    cout << (ok ? "[OK]" : "[FAIL]") << "  " << name << ", cmp = " << t.cmp << " (ждём " << expected_cmp << ")\n";
}

void task1() {
    Task1 t;
    cout << "\n===Тесты для первого задания===\n";

    // пустой массив
    {
        int a[1] = {0};
        int n = 0;
        cout << "\n[] \n";
        cout << "Массив пустой. макса не зовем\n";

        t.add = 0;
        cout << (t.sum_elements(a, n) == 0 ? "[OK]\n" : "[FAIL]\n");
        cout << "  add = " << t.add << '\n';

        t.cmp = 0;
        cout << (t.contains(a, n, 5) == false ? "[OK]\n" : "[FAIL]\n");
        cout << "  cmp = " << t.cmp << '\n';
    }
    // один элемент
    {
        int a[] = {5};
        check_task1(t, "один элемент", a, 1, 5, 5, 5, true);
    }
    // все отриц
    {
        int a[] = { -8, -3, -10 };
        check_task1(t, "все отриц", a, 3, -21, -3, -3, true);
    }
    // норм
    {
        int a[] = { 4, 7, 11 };
        check_task1(t, "норм", a, 3, 22, 11, 6, false);
    }
    //повторы
    {
        int a[] = { 7, 7, 9 };
        check_task1(t, "повторы", a, 3, 23, 9, 7, true);
    }

    // contains отдельно
    {
        int a[] = { 1, 2, 3, 4 };
        cout << "\n[1, 2, 3, 4] — contains\n";
        check_contains(t, "начало", a, 4, 1, true,  1);
        check_contains(t, "конец",  a, 4, 4, true,  4);
        check_contains(t, "нет",    a, 4, 5, false, 4);
    }
    // n = 1, 10...
    cout << "\nn=1, 10, 100, 1000\n";
    for (int len : {1, 10, 100, 1000}) {
        int* a = new int[len];
        for (int i = 0; i < len; i++) a[i] = i;
        t.cmp = 0;
        if (len >= 1) t.max_element_value(a, len);
        t.add = 0;
        t.sum_elements(a, len);
        cout << len << " " << t.cmp << " " << t.add << "\n";

        delete[] a;
    }
}

void task2() {
    Task2 t;
    cout << "\n===Тесты для второго задания===\n";

    // с примера
    {
        int a[] = { 5, 1, 4, 2, 8, 2 };
        int n = 6;
        int b[6], c[6];
        for (int i = 0; i < n; i++) { b[i] = a[i]; c[i] = a[i]; }

        t.bubble_sort(b, n); t.insertion_sort(c, n);
        int true_mass[] = { 1, 2, 2, 4, 5, 8 };
        cout << ((equal(b, b + n, true_mass) && equal(c, c + n, true_mass)) ? "[OK]\n" : "[FAIL]\n");
    }

    // пустой
    {
        int* a = NULL;
        t.bubble_sort(a, 0); t.insertion_sort(a, 0);
        cout << "\n[] n=0: [OK]\n";
    }

    // один элемент
    {
        int a[] = {42}, b[] = {42}; t.bubble_sort(a, 1); t.insertion_sort(b, 1);
        cout << (a[0] == 42 && b[0] == 42 ? "[OK]\n" : "[FAIL]\n");
    }

    run_table();
    measure_table();
}

void check_task3(const char* name, const string& expected, const string& res1, const string& res2){
    bool ok(res1 == expected && res2 == expected);
    cout << (ok ? "[OK] " :"[FAIL] ") << name << "\n";
}

void task3() {
    Task3 t;
    cout << "\n=== Тесты для третьего задания ===\n";

    struct Case{const char* input; const char* expected; const char* name;};
    Case cases[] = {
        {"5\napple\nbanana\ncherry\ndate\nelderberry\n", "date", "пример"},
        {"1\napple\n", "NONE", "одна строка"},
        {"3\npear\npear\npear\n", "NONE", "все одинаковые"},
        {"3\npear\npear\napple\n", "apple", "повтор максимума"},
        {"3\napple\napples\napricot\n", "apples", "общий префикс"},
    };
    for (const auto& c : cases){
        istringstream in1(c.input), in2(c.input);
        int n1, n2; in1 >> n1; in2 >> n2;
        string res1 = t.second_largest(in1, n1);
        string res2 = t.second_largest_sort(in2, n2);
        check_task3(c.name, c.expected, res1, res2);
    }
}

void check_task4(const char* name, bool expected, bool res1, bool res2){
    bool ok = (res1 == expected && res2 == expected);
    cout << (ok ? "[OK] " :"[FAIL] ") << name << "\n";
}

void task4() {
    Task4 t;
    cout << "\n=== Тесты для четвертого задания ===\n";

    struct Case{const char* input; bool expected; const char* name;};
    Case cases[] = {
        {"A man, a plan, a canal, Panama", true, "пример из задания"},
        {"", true, "пустая строка"},
        {"!!!", true, "знаки"},
        {"0P", false, "цифры и буквы различны"},
        {"AbBa", true, "регистр не решает"},
        {"ab ca", false, "после обработки"},
    };

    for (const auto& c : cases){
        bool res1 = t.is_palindrome_approach1(c.input);
        bool res2 = t.is_palindrome_approach2(c.input);
        check_task4(c.name, c.expected, res1, res2);
    }
}

void check_task5(const char* name, int expected, int res1, int res2, int res3) {
    bool ok = (res1 == expected && res2 == expected && res3 == expected);
    cout << (ok ? "[OK]   " : "[FAIL] ") << name << '\n';
}

void task5() {
    Task5 t;
    cout << "\n=== Тесты для пятого задания ===\n";
    struct Case{std::vector<int> data; int expected; const char* name;};
    Case cases[] = {
        {{1, 2, 3, 4, 4, 5}, 5, "пример из задания"},
        {{}, 0, "пустой массив"},
        {{9}, 1, "один элемент"},
        {{4,4,4,4}, 1, "все элементы равны"},
        {{ -1, 0, -1, 2 }, 3, "отриц значения"},
        {{ 5, 4, 3, 2, 1 }, 5, "все различны"},
    };

    for (const auto& c : cases){
        int n = (int)c.data.size();
        vector<int> a1 = c.data;
        vector<int> a2 = c.data;
        vector<int> a3 = c.data;
        int res1 = t.count_unique_bruteforce(a1.data(), n);
        int res2 = t.count_unique_sort(a2.data(), n);
        int res3 = t.count_unique_hash(a3.data(), n);
        check_task5(c.name, c.expected, res1, res2, res3);
    }
}

void check_task6(const char* name, int expected, int res1, int res2) {
    bool ok = (res1 == expected && res2 == expected);
    cout << (ok ? "[OK]   " : "[FAIL] ") << name << '\n';
}

void task6() {
    Task6 t;
    cout << "\n=== Тесты для шестого задания ===\n";

    struct Case{std::vector<int> data; int expected; const char* name;};
    Case cases[] = {
        {{ 1, 2, 0, -1, 3 }, 4, "пример из задания"},
        {{}, 1, "пустой массив"},
        {{ -3, -1, 0 }, 1, "нет положительных"},
        {{ 1, 1, 2 }, 3, "повторы"},
        {{ -3, 4, -1, 1 }, 2, "пропуск"},
        {{ 1, 2, 3, 4 }, 5, "нет пропусков до n"},
        {{ 1000000000 }, 1, "big num"},
    };

    for (const auto& c : cases){
        int n = (int)c.data.size();
        vector<int> a1 = c.data;
        vector<int> a2 = c.data;
        int res1 = t.find_native_miss(a1.data(), n);
        int res2 = t.find_missing_mark(a2.data(), n);
        check_task6(c.name, c.expected, res1, res2);
    }
}