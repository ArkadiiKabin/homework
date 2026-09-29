#pragma once
#include <vector>
#include <random>
#include <string>
#include <iostream>

struct Task1 {
    int cmp = 0, add = 0;

    int max_element_value(const int a[], int n);
    long long sum_elements(const int a[], int n);
    bool contains(const int a[], int n, int x);
};

struct Task2 {
	long long cmp = 0;
	long long writes = 0;

	void bubble_sort(int a[], int n);
	void insertion_sort(int a[], int n);

	std::vector<int> make_array(int n, int type) {
		std::vector<int> a(n);
		if (type == 0) { for (int i = 0; i < n; i++) a[i] = i; }
		else if (type == 1) { for (int i = 0; i < n; i++) a[i] = n - i; }
		else {
			std::mt19937 rng(5);
			std::uniform_int_distribution<int> dist(-10000, 10000);
			for (int i = 0; i < n; i++) a[i] = dist(rng);
		}
		return a;
	}
};

struct Task3 {
	std::string second_largest(std::istream& in, int n);
	std::string second_largest_sort(std::istream& in, int n);
};

struct Task4 {
	bool is_palindrome_approach1(const std::string& s);
	bool is_palindrome_approach2(const std::string& s);
};

struct Task5 {
	int count_unique_bruteforce(const int a[], int n);
	int count_unique_sort(int a[], int n);
	int count_unique_hash(const int a[], int n);
};

struct Task6 {
	int find_native_miss(int a[], int n);
	int find_missing_mark(int a[], int n);
	int find_hash_miss(int a[], int n);
};