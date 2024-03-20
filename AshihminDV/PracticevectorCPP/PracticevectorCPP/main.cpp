#include "vector.h"

int main(int argc, char **argv)
{
	if(argc<3)
	{
		std::cout << "Incorrect argument" << std::endl;
		return 1;
	}
	char* infilename = argv[1], * outfilename = argv[2];
	std::ofstream out;
	std::ifstream in;
	TVector v1, v2;

	in.open(infilename);
	in >> v1 >> v2;
	in.close();

	TVector res_sum = v1 + v2;
	TVector res_razn = v1 - v2;
	double skalpr = v1 * v2;

	out.open(outfilename);
	out << res_sum << res_razn << "skalpr = " << skalpr << std::endl;
	out.close();

	return 0;
}