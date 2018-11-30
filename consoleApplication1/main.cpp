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

	while( x != "q" ){
		getline(cin,x) ;
		//cout<<x<<endl;
	if( x[0] == 'v' || x[0]=='V') {
		vector <string> a;
		//a.push_back(x);
		split(x, a, ' ');
		//int n1 = int(a[1][0]) - 48;
		//int n2 = int(a[1][1]) - 48;
		int n1 = stoi(a[1]);
		int n2 = stoi(a[2]);
		float value = stoi(a[3]);
		double phase = stoi(a[4]);
	    Voltage v(value , n1,  n2, phase);
		vs.push_back(v);

	}
	if (x[0] == 'I' || x[0] == 'i') {
		vector <string> a;
		split(x, a, ' ');
		//int n1 = int(a[1][0]) - 48;
		//int n2 = int(a[1][1]) - 48;
		//float value = stoi(a[2]);
		//double phase = stoi(a[3]);
		int n1 = stoi(a[1]);
		int n2 = stoi(a[2]);
		float value = stoi(a[3]);
		double phase = stoi(a[4]);
		Current i(value, n1, n2);
		Is.push_back(i);
		cout << Is[0].value << " " << Is[0].firstNode << " " << Is[0].secondNode << endl;

	}
	if( x[0] == 'R' || x[0]=='r') {
		vector <string> a;
		split(x, a, ' ');
		//int n1 = int(a[1][0]) - 48;
		//int n2 = int(a[1][0]) - 48;
		//float value = stoi(a[2]);
		int n1 = stoi(a[1]);
		int n2 = stoi(a[2]);
		float value = stoi(a[3]);
		//double phase = stoi(a[4]);
		resistance r(value, n1, n2);
		Rs.push_back(r);
		//cout << n1 << "\t" << n2 << "\n";
		//cout << Rs[0].value << endl;
	}
	if( x[0] == 'L' || x[0] == 'l') {
		vector <string> a;
		split(x, a, ' ');
		//int n1 = int(a[1][0]) - 48;
		//int n2 = int(a[1][1]) - 48;
		int n1 = stoi(a[1]);
		int n2 = stoi(a[2]);
		float value = stoi(a[3]);
		//double phase = stoi(a[4]);
		//float value = stoi(a[2]);
		inductance l(value, n1, n2);
		Ls.push_back(l);
		//cout << Ls[0].firstNode << endl;
		//cout << Ls[0].secondNode << endl;
		//cout << Ls[0].value << endl;
		

	}
	if( x[0] == 'C' || x[0]=='c') {
		vector <string> a;
		split(x, a , ' ');
		//int n1 = int(a[1][0]) - 48;
		//int n2 = int(a[1][1]) - 48;
		//double value = stoi(a[2
		int n1 = stoi(a[1]);
		int n2 = stoi(a[2]);
		float value = stoi(a[3]);
		//double phase = stoi(a[4]);
		capacitance c(value, n1, n2);
		Cs.push_back(c);
		//cout << Cs[0].firstNode << "\t" << Cs[0].secondNode << endl;
		//cout << Cs[0].capa << endl;
		//cout << Cs[0].z.real << endl;
	}
	//for (int i = 0; i < 4 - 1; i++) {
		//for (int j = i + 1; j < 4; j++) {
			//cout << endl << i << " " << j;
			//check if the 2 node are equal will return [n1 ,n2 , equivalent Z ]
			//if(  )
		//}
	//}
}
	parallel(numberNodes, Rs,Ls,Cs, result);
	for (auto p : result) {
		cout << p[0] << " " << p[1] << " " << p[2] << endl;
	}
	
	return 0;
}



size_t split(const string &txt, vector <string> &strs, char ch) {
	size_t pos = txt.find(ch);
	size_t initialPos = 0; strs.clear();
	// Decompose statement 
	while( pos != std::string::npos ) 
	{ strs.push_back( txt.substr( initialPos, pos - initialPos ) ); 
	initialPos = pos + 1;
	pos = txt.find( ch, initialPos );
	} 
	// Add the last one 
	strs.push_back( txt.substr( initialPos, fmin( pos, txt.size() ) - initialPos + 1 ) ); 
	return strs.size(); 
}

void parallel(int n, vector <resistance>r, vector <inductance>in, vector <capacitance>c,vector <vector<complex <double>>> &result) {
	vector <vector<int>> nodes;
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = i+1; j < n; j++) {
			//cout << i << " " << j;
			//check if the 2 node are equal will return [n1 ,n2 , equivalent Z ]
			//if(  )
			vector <int> node {i, j};
			nodes.push_back(node);

		}

	}
	for (auto x : nodes) {
		complex <double> zt;
		zt, real(0);
		zt.imag(0);
		complex <double> one;
		one.real(1);
		one.imag(0);
		
		for (auto rs : r) {
			if (x[0] == rs.firstNode && x[1] == rs.secondNode) {
				rs.convertToImpedance();
				//cout << rs.z << endl;
				
				zt = zt + one/rs.z;
				//cout <<zt << endl;
			}
			
		}
		cout << zt << endl;
		for (auto i : in) {
			if (x[0] == i.firstNode && x[1] == i.secondNode) {
				i.convertToImpedance(i.omega);
				zt += one/ i.z;
				//cout << zt << endl;
			}
			
		}
		cout << zt << endl;
		for (auto cc : c) {
			if (x[0] == cc.firstNode && x[1] == cc.secondNode) {
				cc.convertToImpedance(cc.omega);
				zt += one/ cc.z;
			}
			
		}
		//cout << zt << endl;
		complex <double> n1;
		complex <double> n2;
		n1.real(x[0]);
		n1.imag(0);
		n2.real(x[1]);
		n2.imag(0);
		vector <complex<double>> b{ n1,n2 , one/zt  };
		
		result.push_back(b);

	}




}