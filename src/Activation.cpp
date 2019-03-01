#include "../include/Activation.h"
using namespace std;


vector<vector<vector<float> > > Activation::activate_tanh(vector<vector<vector<float> > > test){
   int rows = test.at(0).size();
    int cols = rows;
    int depth  = test.size();
    /*Processing matrix*/
    for(int count=0;count<depth;count++){
        for(int i = 0; i<rows; ++i){
            for(int j = 0; j<cols; ++j){
                test.at(count).at(i).at(j) = tanh(test.at(count).at(i).at(j));
            }
        }
    }
    return test;
}


vector<vector<vector<float> > > Activation::activate_relu(vector<vector<vector<float> > > test){
    int rows = test.at(0).size();
    int cols = rows;
    int depth  = test.size();
    /*Processing matrix*/
    for(int count=0;count<depth;count++){
        for(int i = 0; i<rows; ++i){
            for(int j = 0; j<cols; ++j){
                test.at(count).at(i).at(j) = fmax(0,test.at(count).at(i).at(j));
            }
        }
    }
    return test;
}