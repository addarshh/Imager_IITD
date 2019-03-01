/*All headers required are in the avgpool.h file*/
#include "../include/Pool.h"
using namespace std;

vector<vector<vector<float> > > Pool::activate_avgpool(vector<vector<vector<float> > > test){
    int depth = test.size();
    int rows = test.at(0).size();
    int cols = rows;
    vector<vector<vector<float> > > answer;
    int count;
/*Processing matrix*/
    for(count = 0; count<depth; count++){
	    if(rows%2==1){
	    	vector<float> app (rows,0);
	    	test.at(count).push_back(app);
	    	for(int i=0; i<cols+1; i++){
	    		test.at(count).at(i).push_back(0);
	    	}
	    }
    	vector<vector<float> > var;
	    for(int i = 0; i<rows; i = i+2){
	    	vector<float> row_trav;
	        for(int j = 0; j<cols; j = j+2){
	            float temp = test.at(count).at(i).at(j)+test.at(count).at(i).at(j+1);
	            float temp1 = test.at(count).at(i+1).at(j)+test.at(count).at(i+1).at(j+1);
	            row_trav.push_back((temp+temp1)/4);
	        }
	        var.push_back(row_trav);
	    }
	    answer.push_back(var);
	}

	return answer;
}


vector<vector<vector<float> > > Pool::activate_maxpool(vector<vector<vector<float> > > test){
	int depth = test.size();
    int rows = test.at(0).size();
    int cols = rows;
    vector<vector<vector<float> > > answer;
    int count;
/*Processing matrix*/
    for(count = 0; count<depth; count++){
	    if(rows%2==1){
	    	vector<float> app (rows,0);
	    	test.at(count).push_back(app);
	    	for(int i=0; i<cols+1; i++){
	    		test.at(count).at(i).push_back(0);
	    	}
	    }
    	vector<vector<float> > var;
	    for(int i = 0; i<rows; i = i+2){
	    	vector<float> row_trav;
	        for(int j = 0; j<cols; j = j+2){
	            float temp = fmax(test.at(count).at(i).at(j),test.at(count).at(i).at(j+1));
	            float temp1 = fmax(test.at(count).at(i+1).at(j),test.at(count).at(i+1).at(j+1));
	            row_trav.push_back(fmax(temp,temp1));
	        }
	        var.push_back(row_trav);
	    }
	    answer.push_back(var);
	}
	return answer;
}