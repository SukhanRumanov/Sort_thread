#include "sort.hpp"
#include "help_func.hpp"
#include <iostream>
#include <chrono>

#define MAX__RAND_NUM 10000

int main() {

	std::vector<int> num1, num2;
	generate(num1, MAX__RAND_NUM);
	
	num2 = num1;

	auto start_time1 = std::chrono::high_resolution_clock::now();
	sort1(num1);
	auto end_time1 = std::chrono::high_resolution_clock::now();
	auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time1 - start_time1).count();

	print_vecs(num1);
	std::cout << "=======================================================================================" <<std::endl;

	auto start_time2 = std::chrono::high_resolution_clock::now();
	sort2(num2);
	auto end_time2 = std::chrono::high_resolution_clock::now();
	auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end_time2 - start_time2).count();
	print_vecs(num2);


	std::cout << "=======================================================================================" << std::endl;
	std::cout << "time 1: " << duration1 << std::endl;
	std::cout << "time 2: " << duration2 << std::endl;
}

