#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int update(char);
int parser(string);

int main(){

    // input file
    ifstream file;
    file.open("C:\\Users\\kitri\\Documents\\vscode\\advent\\day3\\day3.txt");
    if (!file.is_open()){
        cout << "error!\n";
        return 1;
    }

    int tot_count = 0;
    string line;

    while (true){
        if (file.eof()) break;
        getline(file, line);
        tot_count += parser(line);
    }

    cout << tot_count << endl;


}

int update(char c){
    // cout << "updating!!!" << endl;
    if (c > 97){
        return (c - 96);
    }
    else{
        return (c - 38);
    }
}

int parser(string line){
    int len = line.length();
    int count = 0;
    for (int i = 0; i < (len/2); i++){
        for (int k = (len/2); k < len; k++){
            if (line[i] == line[k])
            // idk how i'd implement this if there were more than one matching char in each half.
                return update(line[i]);
        }
    }
    return 0;
}