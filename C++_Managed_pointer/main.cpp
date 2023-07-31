#include <iostream>
#include "unique_ptr.h"
using namespace std;

#define TEST_TRUE(expr) \
	if(expr) {  \
		cout << "PASS\n"; \
	}  \
	else{       \
		cout << "FAIL\n";  \
	}   
	

struct SimpleData {
	int first;
	char second;
};

int main(){
	int* data = new int(55); // allocate raw pointer
	
	// create a managed pointer and let it managed data
	unique_ptr<int> data_ptr(data);
	
	//make sure that both pointers show the same value;
	TEST_TRUE(*data == *(data_ptr.get()));
	
	//both ways:
	*(data_ptr.get()) = 99;
	TEST_TRUE(*data == *(data_ptr.get()));
	
	//testing with custom struct:
	SimpleData* sdata = new SimpleData;  // allocate raw pointer
	sdata -> first = 55;
	sdata -> second = 'C';
	
	//create a managed pointeer and let it manage sdata
	unique_ptr<SimpleData> sdata_ptr(sdata);
	
	//make sure that both pointers show the same value;
	TEST_TRUE(sdata -> first == sdata_ptr -> first);
	TEST_TRUE(sdata -> second == sdata_ptr -> second);
	
	//both ways
	sdata_ptr -> first = 99;
	sdata_ptr -> second = 'D';
	TEST_TRUE(sdata -> first == sdata_ptr ->first);
	TEST_TRUE(sdata -> second == sdata_ptr -> second);
	
	// both allocation are released here
	
	cout << endl;
	return 0;
}
