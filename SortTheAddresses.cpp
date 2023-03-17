#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class address {
	int home;
	int apartment;
	string city;
	string street;
public:
	address(){}
	address(string p_city, string p_street, int p_home, int p_apartment) {
		city = p_city;
		street = p_street;
		home = p_home;
		apartment = p_apartment;
	}
	string collect_line() {
		return city + " " + street + " " + to_string(home) + " " + to_string(apartment);
	}
	string privatecity() {
		return city;
	}
};

bool address_comparator(  address& a1, address& a2) {
	return  a1.privatecity() < a2.privatecity();
}

int main() {
	ifstream in("in.txt");
	ofstream out("out.txt");
	int N;
	in >> N;
	int home, apartment;
	string city, street;

	address* addresses = new address[N];

	for (int i = 0; i < N; i++) {
		in >> city >> street >> home >> apartment;
		address a(city, street, home, apartment);
		addresses[i] = a;
	}

	sort(addresses, addresses + N, address_comparator);

	for (int i = 0; i < N; i++) {
		out << addresses[i].collect_line() << endl;
	}
	
	delete[] addresses;

	in.close();
	out.close();
};