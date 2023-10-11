// Collaborated with demo partner Peter Chu
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstddef>
#include <vector>

using namespace std;
vector<int> coded;

struct Node{
    string data;
    int freq;
    int hashNum;
    int code;
    Node(string label) : data(label), freq(1), hashNum(0), code(0) {}
};

//general outline
//get words from file, seperate the words as needed -> "the-" = "the" + "-""
//push into vector and make it a node
//sort vector by freq and ajust node values

int sHash(const string& word){
    //hash function got from my own lab 8 hashtable
    unsigned hash = 5381;
	int M = 33;
    int size = 50;
	
	for(unsigned i = 0; i < word.size(); ++i){
		hash = ((M * hash)% size + word.at(i)) % size;
	}

    return hash;
	
}

void code(vector<Node> &name){
    //commented out stuff would make it so that items with the same freq have the same code
    //int k = 1;
    for(unsigned i =1; i < name.size(); ++i){
        unsigned j = i;
        while(j > 0 && name.at(j).freq > name.at(j-1).freq){
            int temp = name.at(j).freq;
            name.at(j).freq = name.at(j-1).freq;
            name.at(j-1).freq = temp;

            string temp1 = name.at(j).data;
            name.at(j).data = name.at(j-1).data;
            name.at(j-1).data = temp1;

            j--;
        }
    }
    
    for(unsigned i =0; i < name.size(); ++i){
        name.at(i).hashNum = sHash(name.at(i).data);
        name.at(i).code = i + 1;
        /*name.at(i).code = k;
        if(i > 0){
            if(name.at(i).freq == name.at(i-1).freq){
                name.at(i).code = name.at(i-1).code;
                k--;
            }
        }

        k++;*/
    }
}
int main(){
    vector<Node> dataSet;
    string iword;
    string fileName;
    size_t y = 0;
    char* x;
    string converted;

    ifstream inFS;
    ofstream outFS;

    //fileName = "Assignment 4 Test File.txt";
    fileName = "inputFile.txt";

    //test files one accounts for duplicates in a row at any position of the word and if only single characters are entered
    // '-' = 6, '.' = 5, ',' = 5, "apple" = 4, "app" = 2 and the rest are = 1  

    inFS.open(fileName.c_str());
    if(!inFS.is_open()){
        cout << "error inFS";
        exit(1);
    }
    //Accounts for capitilization, WORD != word, they are recorded as two seperate words
    while(inFS >> iword){
        int cnt = 0;
        if(iword.size() == 1){
            char temp[2];
            string(x) = strcpy(temp, iword.c_str());
            
            if(dataSet.size() == 0){
                dataSet.push_back(x);
            }

            else{
                for(unsigned j  = 0; j < dataSet.size(); ++j){
                    if(x == dataSet.at(j).data){
                    dataSet.at(j).freq++;
                    break;
                    }
            

                else if(j == dataSet.size()-1){
                    dataSet.push_back(x);
                    break;
                    }
                }   
            }


        }


        else{
            y = iword.find_first_of("-,&.*;!$:/^");

            while(y != string::npos){
                if(y+1 == 1){
                    if(iword.at(y) == iword.at(y+1)){
                        y = iword.find_first_of("-,&.*;!$:/^", y+1);
                    }
                    else if(iword.at(y) != iword.at(y+1)){
                        iword.insert(y+1, " ");
                        cnt++;
                        y = iword.find_first_of("-,&.*;!$:/^", y+2);
                    
                    }

                }

                else{
                    iword.insert(y, " ");
                    cnt++;
                    if(y+2 < iword.size()){
                        if(iword.at(y+1) != iword.at(y+2)){
                            iword.insert(y+2, " ");
                            cnt++;
                        }
                    }
            

                    y = iword.find_first_of("-,&.*;!$:/^", y+2);
                }

            }
        
            int p = iword.length();
            char word[p+1];
            strcpy(word, iword.c_str());

            x = strtok(word, " ");
            converted = string(x);

            if(dataSet.size() == 0){
                dataSet.push_back(converted);
            }

            else{
                for(unsigned j  = 0; j < dataSet.size(); ++j){
                    if(converted == dataSet.at(j).data){
                    dataSet.at(j).freq++;
                    break;
                    }
            

                else if(j == dataSet.size()-1){
                    dataSet.push_back(converted);
                    break;
                    }
                }
            }
    


            for(int i = 0; i < cnt; ++i){
                x = strtok(nullptr, " ");
                converted = string(x);

                for(unsigned j  = 0; j < dataSet.size(); ++j){
                    if(converted == dataSet.at(j).data){
                        dataSet.at(j).freq++;
                        break;
                    }

                    else if(j == dataSet.size()-1){
                        dataSet.push_back(converted);
                        break;
                    }      
                }
            }
        }

    }

    code(dataSet);

    /*cout << "freqs ";
    for(unsigned i =0; i < dataSet.size(); ++i){
        cout << dataSet.at(i).freq << " ";
    }

    cout << endl;

    cout << "hashed ";
    for(unsigned i =0; i < dataSet.size(); ++i){
        cout << dataSet.at(i).hashNum << " ";
    }

    cout << endl;

    cout << "code ";
    for(unsigned i =0; i < dataSet.size(); ++i){
        cout << dataSet.at(i).code << " ";
    }*/

    outFS.open("outputFile.txt");

    if(!outFS.is_open()){
        cout << "error outFS" << endl;
        exit(1);
    }

    for(unsigned i =0; i < dataSet.size(); ++i){
        outFS << dataSet.at(i).code << " ";
    }

    outFS << endl;

    for(unsigned i =0; i < dataSet.size(); ++i){
        outFS << dataSet.at(i).data << " ";
    }

}


/*x = strtok(nullptr, " ");
    converted = string(x);
    dataSet.push_back(converted);*/