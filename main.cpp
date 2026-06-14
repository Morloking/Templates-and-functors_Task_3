#include <iostream>
#include <vector>
#include <algorithm>

//Alternative solution
//=================================================
/*
class Counter {
public:
	struct GetSum {
		template <typename T>
		T operator()(const std::vector<T>& values) const {
			T sum{ 0 };
			for (const auto& el : values) {
				if (el % 3 == 0) {
					sum += el;
				}
			}
			return sum;
		}
	};

	struct GetCount {
		template <typename T>
		int operator()(const std::vector<T>& values) const {
			int count{ 0 };
			for (const auto& el : values) {
				if (el % 3 == 0) {
					++count;
				}
			}
			return count;
		}
	};

};
*/

//second solution
//==============================================================

class Counter {
public:
	template <typename T>
	struct GetSum {
		T sum = 0;

		void operator()(T value) {
			if (value % 3 == 0) {
				sum += value;
			}
		}
		T result() const {
			return sum;
		}
	};

	template <typename T>
	struct GetCount {
		int count = 0;

		void operator()(T value) {
			if (value % 3 == 0) {
				++count;
			}
		}
		int result() const {
			return count;
		}
	};

};
int main() {
	std::vector <int> nums { 4, 1, 3, 6, 25, 54 };
	Counter::GetSum <int> getterSum;
	getterSum = std::for_each(nums.begin(), nums.end(), getterSum);

	std::cout << "Sum: " << getterSum.result() << "\n";
		
	Counter::GetCount <int> getterCount; 
	getterCount = std::for_each(nums.begin(), nums.end(), getterCount);

	std::cout << "Count: " << getterCount.result() << "\n";

	return 0;
}