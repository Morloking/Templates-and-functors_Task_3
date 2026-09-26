#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Counter {
public:
	
	void operator()(T value) {
		if (value % 3 == 0) {
			sum += value;
			++count;
		}
	}

	T get_sum() const {
		return sum;
	}
	int get_count() const {
		return count;
	}
	
private:
	int sum{ 0 };
	int count{ 0 };
};
int main() {
	std::vector<int> nums{ 4, 1, 3, 6, 25, 54 };


	Counter<int> counter = std::for_each(nums.begin(), nums.end(), Counter<int>{});

	std::cout << "get_sum() = " << counter.get_sum() << "\n";
	std::cout << "get_count() = " << counter.get_count() << "\n";

	return 0;
}


