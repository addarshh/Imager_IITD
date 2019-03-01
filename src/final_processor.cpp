#include "../include/Activation.h"
#include "../include/Pool.h"
#include "../include/FinalLayer.h"
#include "../include/convolution.h"

int main(){
	vector<vector<vector<float> > > image;
	vector<vector<float> > ker;
	int size_image;
	int size_ker;
	vector<vector<vector<float> > > layer1;
	vector<vector<vector<float> > > layer2;
	vector<vector<vector<float> > > layer3;
	vector<vector<vector<float> > > layer4;
	vector<vector<vector<float> > > layer5;
	vector<vector<vector<float> > > layer6;
	vector<float> final_prob;
	int i,j;
	ifstream input_matrix;
	string path_input_mat;

	try{
		cout<<"Enter the size of image: ";
		cin>>size_image;
		if(size_image <=0){
			throw std::invalid_argument("Invalid Image Size");
		}
	}
	catch(const std::invalid_argument& e){
		cout<<"Invalid Image Size"<<'\n';
		return 0;
	}

	try{
		cout<< "Enter the path of the input image: ";
		cin>>path_input_mat;
		path_input_mat = "test_data/" + path_input_mat;
		input_matrix.open(path_input_mat.c_str());
		if(!input_matrix){
			throw std::invalid_argument("File Not Found");
		}
	}

	catch( const std::invalid_argument& e){
		cout<<"Invalid File Path"<<'\n';
		return 0;
	}

	vector<vector<float> > temp_image;
	for(i=0;i<(size_image);i++){
		vector<float> row_trav4;
		string line;
		float value;
		for(j=0;j<size_image;j++){
			getline(input_matrix,line);
			value = strtof(line.c_str(),NULL);
			row_trav4.push_back(1-(value/255));
		}
		temp_image.push_back(row_trav4);
	}
	image.push_back(temp_image);

	layer1 = ((new convolution())->normal_convolution(image, 20));
	layer2 = ((new Pool())->activate_maxpool(layer1));
	layer3 = ((new convolution())->normal_convolution(layer2,50));
	layer4 = ((new Pool())->activate_maxpool(layer3));
	layer5 = ((new convolution())->normal_convolution(layer4,500));
	layer5 = ((new Activation())->activate_relu(layer5));
	layer6 = ((new convolution())->normal_convolution(layer5,10));
	
	for(i=0;i<10;i++){
		final_prob.push_back(layer6.at(i).at(0).at(0));
	}
	((new FinalLayer())->convert_softmax(final_prob));
}