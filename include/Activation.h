#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iterator>
#include<fstream>
using namespace std;

class Activation{
	public:

		vector<vector<vector<float> > > activate_relu(vector<vector<vector<float> > > test);
	
		vector<vector<vector<float> > > activate_tanh(vector<vector<vector<float> > > test);

};