#include "vector.h"
int main() 
{
	TVector v1, v2;
	std::cin >> v1 >> v2;
	TVector res_sum = v1 + v2;
	std::cout << "Summa vectorov"<< std::endl;
	std::cout << v1;
	std::cout << v2;
	std::cout << res_sum;
	TVector res_razn = v1 - v2;
	std::cout << "Razn vectorov" << std::endl;
	std::cout << v1;
	std::cout << v2;
	std::cout << res_razn;
	double skalpr = v1 * v2;
	std::cout << "skalyarnoe proizvedenie vectorov" << std::endl;
	std::cout << v1;
	std::cout << v2;
	std::cout << skalpr << std::endl;

	return 0;
}