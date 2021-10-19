/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Daniel Partika
 * Date        : 9/27/2021
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honors System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {
    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.
    vector<vector<int>> ans;
    if (num_stairs <= 0){
        ans.push_back({});
        return ans;
    }

    for (int i = 1; i<=3;i++){
        if (num_stairs >=i){

            vector<vector <int>> result;  
            result = get_ways(num_stairs-i);
            for (auto &item : result){ 
                item.insert(item.begin(),i);
                ans.push_back(item);
            }
        }
        
    }
    return ans;
}

int num_digits(int num) {
    // TODO: write code to determine how many digits are in an integer
    // Hint: No strings are needed. Keep dividing by 10.
    int n = 0;
    while (num!=0){
        num /= 10;
        n += 1;
    }
    return n;
}


void display_ways(const vector< vector<int> > &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.
    //for (){
    int count = 1;
    for (unsigned int i = 0; i < ways.size(); i++){
         
        cout << setw(num_digits(ways.size())) << count << ". [";
        for (unsigned int j = 0; j < ways[i].size(); j++) {
            if ((j+1) == ways[i].size()) {
                cout << ways[i][j];
            } else {
                cout << ways[i][j] << ", " ;
            }
             
        }
        cout << "]" << endl;
        count ++;
    }
        
        
    //}
}

int main(int argc, char * const argv[]) {
    int n = 0;

	istringstream iss;

	if(argc != 2){ 
	//wrong input
		cerr << "Usage: " << argv[0] << " <number of stairs>" << endl;
		return 1; 
	}

	iss.str(argv[1]);
	if(!(iss >> n)){ //reads iss and stores in s, if the condition is not met error needs to be thrown
		cerr << "Error: Number of stairs must be a positive integer." << endl;
		return 1; //end program
	}
    if (n<1){
        cerr << "Error: Number of stairs must be a positive integer." << endl;
		return 1; //end program
    }
    
    iss.clear(); 
    //input is correct

    //cout << "PRINT      "<< num_digits(30) ;
    int numways = get_ways(n).size();
    if (numways > 1){ 
        cout  << numways << " ways to climb " << n << " stairs."<< endl;
    } else {
        cout << "1 way to climb "<< numways << " stair." << endl;
    } 
    vector<vector<int>> ans = get_ways(n);
	display_ways(ans);
	return 0; 


}
