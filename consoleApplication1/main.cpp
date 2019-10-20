#include <iostream>
#include "Current.h"
#include "Voltage.h"
#include <string>
#include <vector>
#include "resistance.h"
#include "inductance.h"
#include"capacitance.h"
#include <cmath>
#include <complex>
using namespace std;

size_t split(const string &txt, vector <string> &strs, char ch);

void parallel(int n,vector <resistance> , vector <inductance> , vector <capacitance>, vector <vector<complex <double>>> &);


int main(){
	string x;
	int numberNodes;

	vector <Voltage> vs;
	vector <resistance> Rs;
	vector <inductance> Ls;
	vector <capacitance> Cs;
	vector <Current> Is;
	vector <vector<complex <double>>> result;
	cout << "enter number of nodes";
	cin >> numberNodes;

	while (x != "q") {
		getline(cin, x);
		if (tolower(x[0]) == 'v') {
			vector <string> a;
			split(x, a, ' ');
			string n = a[0];
			int n1 = stoi(a[1]);
			int n2 = stoi(a[2]);
			float value = stoi(a[3]);
			double phase = stoi(a[4]);
			Voltage v(n, value, n1, n2, phase);
			vs.push_back(v);
		}
		else if (tolower(x[0]) == 'i') {
			vector <string> a;
			split(x, a, ' ');
			string n = a[0];
			int n1 = stoi(a[1]);
			int n2 = stoi(a[2]);
			float value = stoi(a[3]);
			double phase = stoi(a[4]);
			Current i(n, value, n1, n2, phase);
			Is.push_back(i);
			cout << Is[0].value << " " << Is[0].firstNode << " " << Is[0].secondNode << endl;
		}
		else if (tolower(x[0]) == 'r') {
			vector <string> a;
			split(x, a, ' ');
			string n = a[0];
			int n1 = stoi(a[1]);
			int n2 = stoi(a[2]);
			float value = stoi(a[3]);
			resistance r(n, value, n1, n2);
			Rs.push_back(r);
		}
		else if (tolower(x[0]) == 'l') {
			vector <string> a;
			split(x, a, ' ');
			string n = a[0];
			int n1 = stoi(a[1]);
			int n2 = stoi(a[2]);
			float value = stoi(a[3]);
			inductance l(n, value, n1, n2);
			Ls.push_back(l);
		}
		else if (tolower(x[0]) == 'c') {
			vector <string> a;
			split(x, a, ' ');
			string n = a[0];
			int n1 = stoi(a[1]);
			int n2 = stoi(a[2]);
			float value = stoi(a[3]);
			capacitance c(n, value, n1, n2);
			Cs.push_back(c);
		}
	}
	parallel(numberNodes, Rs, Ls, Cs, result);
	for (auto& p : result) {
		cout << p[0] << " " << p[1] << " " << p[2] << endl;
	}
	
	return 0;
}


size_t split(const string &txt, vector <string> &strs, char ch) {
	size_t pos = txt.find(ch);
	size_t initialPos = 0; 
	strs.clear();
	// Decompose statement 
	while (pos != std::string::npos)
	{
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;
		pos = txt.find(ch, initialPos);
	}
	// Add the last one 
	strs.push_back(txt.substr(initialPos, fmin(pos, txt.size()) - initialPos + 1));
	return strs.size(); 
}

void parallel(int n, vector <resistance>r, vector <inductance>in, vector <capacitance>c, vector <vector<complex <double>>> &result) {
	vector <vector<int>> nodes;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			//check if the 2 node are equal will return [n1 ,n2 , equivalent Z ]
			vector <int> node{ i, j };
			nodes.push_back(node);
		}
	}
	for (auto& x : nodes) {
		complex <double> zt;
		zt, real(0);
		zt.imag(0);
		complex <double> one;
		one.real(1);
		one.imag(0);

		for (auto rs : r) {
			if (x[0] == rs.firstNode && x[1] == rs.secondNode) {
				rs.convertToImpedance();
				zt = zt + one / rs.z;
			}
		}
		cout << zt << endl;
		for (auto i : in) {
			if (x[0] == i.firstNode && x[1] == i.secondNode) {
				i.convertToImpedance(50);
				zt += one / i.z;
			}
		}
		cout << zt << endl;
		for (auto cc : c) {
			if (x[0] == cc.firstNode && x[1] == cc.secondNode) {
				cc.convertToImpedance(50);
				zt += one / cc.z;
			}
		}
		complex <double> n1;
		complex <double> n2;
		n1.real(x[0]);
		n1.imag(0);
		n2.real(x[1]);
		n2.imag(0);
		vector <complex<double>> b{ n1,n2 , one / zt };
		result.push_back(b);
	}
}