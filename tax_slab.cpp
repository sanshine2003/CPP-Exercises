#include <iostream>
#include <map>
class TaxCalculator {
private:
	static const std::map<unsigned int, unsigned int> slabs;

public:
	TaxCalculator(unsigned int net) : _net(net) {
	}
	~TaxCalculator() = default;

	unsigned int Calculate() {
		unsigned int tax = 0;
		unsigned int last = 0;
		for (auto x : slabs) {
			if (_net > x.first) {
				tax += (((x.first - last) * x.second) / 100);
				std::cout << "Adding tax of " << (((x.first - last) * x.second) / 100)
						  << " at " << x.second << " percentage for " << last
						  << " to " << x.first << std::endl;
			} else {
				tax += (((_net - last) * x.second) / 100);
				std::cout << "Adding tax of "
						  << (((_net - last) * x.second) / 100) << " at "
						  << x.second << " percentage for " << last << " to "
						  << _net << std::endl;
				break;
			}
			last = x.first;
		}

		return tax;
	}

private:
	unsigned int _net;
};

const std::map<unsigned int, unsigned int> TaxCalculator::slabs = {
	{300000, 0},
	{600000, 5},
	{900000, 10},
	{1200000, 15},
	{1500000, 20},
	{UINT32_MAX, 30}};

int main(int argc, char *argv[]) {
	TaxCalculator t(4119763);
	std::cout << "Tax Calculated : \n" << t.Calculate() << std::endl;
	return 0;
}