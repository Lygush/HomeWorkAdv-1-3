#include <iostream>
#include <vector>
#include <functional>
#include <math.h>

int main()
{
	const double pi{ 3.1415926 };
	std::vector<double> angles{ 30, 60, 90, 45, 99 };
	auto sin = [&pi](auto angle) {
		std::cout << "sin: " << std::sin(angle * pi / 180) << " ";
	};
	auto cos = [&pi](auto angle) {
		std::cout << "cos: " << std::cos(angle * pi / 180) << " ";
	};
	auto tan = [&pi](auto angle) {
		std::cout << "tan: " << std::tan(angle * pi / 180) << " ";
	};
	std::vector<std::function<void(double)>> functions{sin, cos, tan};
	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}
}
