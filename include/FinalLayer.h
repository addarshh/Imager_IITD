#include<algorithm>
#include<iterator>
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

class FinalLayer{
	public:

		float softmax(float temp, float den);

		void convert_softmax(vector<float> test);

		float sigmoid(float temp);

		void convert_sigmoid(vector<float> test);

};