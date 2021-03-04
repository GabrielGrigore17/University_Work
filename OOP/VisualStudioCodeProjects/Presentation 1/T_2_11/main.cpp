#include <iostream>
using namespace std;

struct pisica {
	string nume;
	string stapan;
	int age;
};

struct persoana {
	string nume;
	string prenume;
	int age;
};

struct masina {
	string model;
	string nr_inmatriculare;
	int age;
};

template <typename T>
bool age_check( T a, T b ) { // returneaza true daca varstele sunt aceleasi si false daca nu
	if ( a.age == b.age) 
		return true;

	return false;
}
template <typename T>
T age_min( T a, T b ) {  // returneaza varsta minima
	if ( a.age < b.age ) 
		return a;
	else 
		return b;
	
}


int main(){
    
	masina opel;
	opel.age=20;
	masina audi;
	audi.age=10;
	pisica felix;
	felix.age=2;
	pisica oscar;
	oscar.age=2;
	persoana matei;
	matei.age=40;

	cout<<age_min(opel, audi).age<<endl;
	cout<<boolalpha<<age_check(felix,oscar);



    return 0;
}