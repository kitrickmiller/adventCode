#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void charRemover(string, int arr[]);
void arrUpdate(int[], string);
void mover(vector<char>[], int, int, int);
void print(vector<char>[]);

int main(){
    ifstream file;
    file.open("input5.txt");
    if (!file.is_open()){
        cout << "error!\n" << endl;
        return 1;
    }

    vector<char> crates[9];
    crates[0] = {'D', 'T', 'W', 'F', 'J', 'S', 'H', 'N'};
    crates[1] = {'H', 'R', 'P', 'Q', 'T', 'N', 'B', 'G'};
    crates[2] = {'L', 'Q', 'V'};
    crates[3] = {'N', 'B', 'S', 'W', 'R', 'Q'};
    crates[4] = {'N', 'D', 'F', 'T', 'V', 'M', 'B'};
    crates[5] = {'M', 'D', 'B', 'V', 'H', 'T', 'R'};
    crates[6] = {'D', 'B', 'Q', 'J'};
    crates[7] = {'D', 'N', 'J', 'V', 'R', 'Z', 'H', 'Q'};
    crates[8] = {'B', 'N', 'H', 'M', 'S'};

    int arr[3];
    string line;
    string removed;

    while (true){
        if (file.eof()) break;
        getline(file, line);
        charRemover(line, arr);
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
        mover(crates, arr[0], arr[1], arr[2]);
    }

    print(crates);
    return 0;

}

void charRemover(string line, int arr[]){
    string num;
    int counter = 0;
    for (int i = 0; i < line.length(); i++){
        if (line[i] == '0' || line[i] == '1' || line[i] == '2' || line[i] == '3' || line[i] == '4' || 
            line[i] == '5' || line[i] == '6' || line[i] == '7' || line[i] == '8' || line[i] == '9'){
            if (line[i+1] == '0' || line[i+1] == '1' || line[i+1] == '2' || line[i+1] == '3' || line[i+1] == '4' || 
                line[i+1] == '5' || line[i+1] == '6' || line[i+1] == '7' || line[i+1] == '8' || line[i+1] == '9'){
                num += line[i];
                num += line[i+1];
                arr[counter] = stoi(num);
                i++;
            }
            else{
                num += line[i];
                arr[counter] = stoi(num);
                cout << num << endl;

            }
            num.clear();
            counter++;
        }
    }
}

void arrUpdate(int arr[], string newS){
    for (int i = 0; i < newS.length(); i++){
        arr[i] = (newS[i] - 48);
    }
}

void mover(vector<char> crates[], int cMoved, int cOrg, int cFin){
    if (cMoved > 1){
        vector<int> temp;
        for (int i = 0; i < cMoved; i++){
            temp.push_back(crates[cOrg-1].back());
            crates[cOrg-1].pop_back();
        }
        for (int i = 0; i < cMoved; i++){
            crates[cFin-1].push_back(temp.back());
            temp.pop_back();
        }
        temp.clear();
    }   
    else{
        crates[cFin-1].push_back(crates[cOrg-1].back());
        crates[cOrg-1].pop_back();
    }
}

void print(vector<char> crates[]){
    for (int i = 0; i < 9; i++){
        cout << crates[i].back();
    }
}