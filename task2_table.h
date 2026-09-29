#pragma once
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

const char* type_name[] = {
    "sorted",
    "reversed",
    "random"
};

void run_table() {
	Task2 t;
	std::cout << "\n ============== Таблица для задания 2 ==============\n";
	std::cout << "Алгоритм\tn\tВход\tСравнения\tЗаписи\tТест\n";

	for (int n : { 100, 500, 1000, 2000 }) {
		for (int type = 0; type < 3; type++) {
			auto orig = t.make_array(n, type);
			auto ref = orig;
			sort(ref.begin(), ref.end());

			for (int algo = 0; algo < 2; algo++) {
				auto a = orig;
				t.cmp = 0; t.writes = 0;
				algo == 0 ? t.bubble_sort(a.data(), n) : t.insertion_sort(a.data(), n);
				std::cout << algo << '\t' << n << '\t' << type_name[type] << '\t'
					<< t.cmp << '\t' << t.writes << '\t'
					<< (a == ref ? "OK" : "FAIL") << '\n';
			}
		}
	}
}

void measure_table() {
	Task2 t;
	cout << "\nalgo\tn\ttype\tms\n";

	for (int n : {100, 500, 1000, 2000}) {
		for (int type = 0; type < 3; type++) {
			auto original = t.make_array(n, type);

			for (int algo = 0; algo < 2; algo++) {
				auto a = original;
				auto start = steady_clock::now();
				if (algo == 0) t.bubble_sort(a.data(), n);
				else t.insertion_sort(a.data(), n);
				auto end = steady_clock::now();
				auto ms = duration_cast<microseconds>(end - start).count();
				cout << algo << '\t' << n << '\t' << type_name[type] << '\t' << ms << '\n';
			}
		}
	}
}