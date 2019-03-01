/*All headers required are in the sigmoid.h file*/
#include "../include/FinalLayer.h"
using namespace std;

float FinalLayer::sigmoid(float temp){
    float val = exp(temp);
    float ans = val/(1+val);
    return ans;
}


float FinalLayer::softmax(float temp, float den){
    float val = exp(temp);
    float ans = val/den;
    return ans;
}

void FinalLayer::convert_sigmoid(vector<float> test){
    int index = 0;
    
    for(index = 0; index < test.size(); index++){
        test.at(index) = sigmoid(test.at(index));
    }
    /*Giving output to file named sigmoid.txt*/    
    ofstream output_file("sigmoid_result.txt");
    ostream_iterator<float> output_iterator(output_file, "\t");
    copy(test.begin(), test.end(), output_iterator);
    output_file<< '\n';

}

void FinalLayer::convert_softmax(vector<float> test){
    int index = 0;
    float sum = 0;
    
    for(int j = 0; j<test.size(); j++){
        // cout<<test.at(j)<<endl;
        sum += exp(test.at(j));
    }
    // cout<<sum<<endl;
    for(index = 0; index < test.size(); index++){
        test.at(index) = softmax(test.at(index), sum);
    }
    /*Write the result matrix in the file named softmax_result.txt*/

    ofstream output_file("softmax_result.txt");
    ostream_iterator<float> output_iterator(output_file, "\t");
    copy(test.begin(), test.end(), output_iterator);
    output_file<< '\n';
}