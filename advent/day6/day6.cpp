#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
        if ((signal[i] != signal[i+1]) && (signal[i] != signal[i+2]) && (signal[i] != signal[i+3])
        && (signal[i+1] != signal[i+2]) && (signal[i+1] != signal[i+3])
        && (signal[i+2] != signal[i+3]))
        {
            found = true;
        }
        i++;
    }

    cout << i + 3 << endl;

}