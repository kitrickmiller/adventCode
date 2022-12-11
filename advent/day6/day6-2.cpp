#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool recursion(string, int);

int main(){
    // open file
    ifstream file;
    file.open("input6.txt");
    if (!file.is_open()){
        cout << "error!" << endl;
        return 1;
    }

    string signal;
    getline(file, signal);

    bool found = false;
    int i = 0;
    while (!found){
        string temp;
        for (int x = 0; x < 14; x++){
            temp += signal[i+x];
        }

        found = recursion(temp, temp.length());

        temp.clear();
        i++;
    }

    cout << i + 13 << endl;

}

bool recursion(string temp, int check){
    if (check == 1)
        return true;

    string newTemp;

    for (int i = 0; i < check - 1; i++){
        if (temp[i] == temp[check - 1])
            return false;
        newTemp += temp[i];
    }
    
    return recursion(newTemp, check - 1);
}