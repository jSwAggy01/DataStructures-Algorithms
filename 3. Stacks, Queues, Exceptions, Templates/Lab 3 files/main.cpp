// Collaborated with demo partner Peter Chu
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <ctime>

using namespace std;

template<typename T>
unsigned min_index(const vector<T>& vals, unsigned index){
	unsigned min = index;

	for(unsigned int i = index; i < vals.size(); ++i){
		if(vals.at(min) > vals.at(i)){
			min = i;
		}
	}

	return min;
}

template<typename T>
void selection_sort(vector<T>& vals){

	for(unsigned i = 0; i < vals.size(); ++i){
		unsigned min = min_index(vals, i);
		T temp = vals.at(min);
		vals.at(min) = vals.at(i);
		vals.at(i) = temp;
	}
}

template<typename T>
T getElement(vector<T> vals, int index){
	try{
		return vals.at(index);
	}
	catch(out_of_range &excpt){
		cout << "out of range exception occurred" << endl;
	}

	return vals.at(index);
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main(){

	/*vector<int> nums;

	nums.push_back(1);
	nums.push_back(7);
	nums.push_back(9);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(2);

	//cout << min_index(nums, 1) << endl;
	selection_sort(nums);

	for(unsigned i = 0; i < nums.size(); ++i){
		cout << nums.at(i);
	}*/


	//Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         curChar = getElement(vals,index);
         cout << "Element located at " << index << ": is " << curChar << endl;
    }
    return 0;

}