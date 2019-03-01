#include "../include/convolution.h"
using namespace std;

vector<vector<vector<float> > > convolution::normal_convolution(vector<vector<vector<float> > > input, int num_kernel){
	int count,size_ker,j,i;
	ifstream kernel;
	vector<vector<vector<vector<float> > > > ker1;
	string path_ker_mat;

	try{
		cout<<"Enter the size of kernel: ";
		cin>>size_ker;
		
		if(size_ker <=0){
			throw std::invalid_argument("Invalid Kernel Size");
		}
	}

	catch(const std::invalid_argument& e){
		cerr<<"Invalid Kernel Size"<<'\n';
	}

	try{
		cout<< "Enter the path of the input kernel & weights: ";
		cin>>path_ker_mat;
		path_ker_mat = "test_data/" + path_ker_mat;
		kernel.open(path_ker_mat.c_str());
		if(!kernel){
			throw std::invalid_argument("File Not Found");
		}
	}

	catch( const std::invalid_argument& e){
		cerr<<"Invalid File Path"<<'\n';
		// return NULL;
	}

	int count1 = 0;
	
	for(count=0;count<num_kernel;count++){
		vector<vector<vector<float> > > ker_temp1;
		for(count1=0;count1<input.size();count1++){
			vector<vector<float> > temp;
			for(i=0;i<size_ker;i++){
				vector<float> row_trav4;
				string line;
				float value;
				for(j=0;j<size_ker;j++){
					getline(kernel,line);
					value = strtof(line.c_str(),NULL);
					row_trav4.push_back(value);
				}
				temp.push_back(row_trav4);
			}
			ker_temp1.push_back(temp);
		}
		ker1.push_back(ker_temp1);
	}

	float z;
	vector<vector<vector<float> > > answer;
	int k,l;
	int n = input[0][0].size();
	int m = ker1[0][0].size();
	int div = input[0].size();

	for(count=0;count<num_kernel;count++){
		vector<vector<float> > temp1;
		string line;
		getline(kernel,line);
		float temp_bias = strtof(line.c_str(), NULL);
		for(i=0;i<n-m+1;i++){
			vector<float> row_trav;
			for(j=0;j<n-m+1;j++){
				z=0;
				for(count1=0;count1<input.size();count1++){
					// z=0;
					for(k=0;k<m;k++){
						for(l=0;l<m;l++){	
							z = z + (input.at(count1).at(i+k).at(j+l))*(ker1.at(count).at(count1).at(k).at(l));
						}
					}
				}
				row_trav.push_back(z+(temp_bias));
			}
			temp1.push_back(row_trav);
		}
		answer.push_back(temp1);
	}
	return answer;
}