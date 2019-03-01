#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<iterator>
using namespace std;

class Pool{
	public:

		vector<vector<vector<float> > > activate_avgpool(vector<vector<vector<float> > > test);
		
		vector<vector<vector<float> > > activate_maxpool(vector<vector<vector<float> > > test);

};