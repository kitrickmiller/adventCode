#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int prioCalc(char);
int parseThree(string, string, string);

int main(){

    // input file
    ifstream file;
    file.open("C:\\Users\\kitri\\Documents\\vscode\\advent\\day3\\day3.txt");
    if (!file.is_open()){
        cout << "error!\n";
        return 1;
    }

    // init strings to hold lines
    string one;
    string two;
    string three;

    int count = 0;

    // while loop to parse through txt file
    while (true){
        // break if at end of file
        if (file.eof()) break;

        // setup strings 
        getline(file, one);
        getline(file, two);
        getline(file, three);

        count += parseThree(one, two, three);
    }

    // correct!!!
    cout << "The sum of the priority scores is: " << count << endl;
}

int prioCalc (char c){
    if (c > 97){
        return (c - 96);
    }
    else{
        return (c - 38);
    }
}

int parseThree(string one, string two, string three){

    int len1 = one.length();
    int len2 = two.length();
    int len3 = three.length();

    // when char matches, calculate priority score and return score
    for (int x = 0; x < len1; x++){
        for (int y = 0; y < len2; y++){
            for (int z = 0; z < len3; z++){
                if (one[x]== two[y] && one[x] == three[z])
                    return prioCalc(one[x]);
            }
        }
    }

    // else return 0
    return 0;
}