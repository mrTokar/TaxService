#include <iostream>
#include "TaxService/TaxService.h"
using namespace std;

int main(int argc, char* argv[]) {
	
	if (argc == 3) {
		try {
		TaxService ts(argv[1]);
		ts.calculate_and_save(argv[2]);
		cout << "Successful compete" << endl;
		}
		catch (...){
			cout << "Run time error" << endl;
		}
	}
	else {
		clog << "ERROR: 2 parameters expected" << endl;
	}

	return 0;
}
