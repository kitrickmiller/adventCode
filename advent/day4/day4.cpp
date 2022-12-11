#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string preComma(string);
string postComma(string);
void hyphenRemove(string&);
int firstNum(string);
int SecNum(string);
void assignInts(string, int[]);

int main(){

    ifstream file;
    file.open("input4.txt");
    if (!file.is_open())
        cout << "error!\n";

    int counter = 0;
    string line;
    string first, last;
    int firstNums[2], lastNums[2];

    // main loop
    while (true){
        if (file.eof()) break;

        getline(file, line);
        hyphenRemove(line);
        first = preComma(line);
        last = postComma(line);
        assignInts(first, firstNums);
        assignInts(last, lastNums);
        if (firstNums[0] <= lastNums[0] && firstNums[1] >= lastNums[1])
            counter++;
        else if(lastNums[0] <= firstNums[0] && lastNums[1] >= firstNums[1])
            counter++;
        else if ((lastNums[0] >= firstNums[0] && lastNums[0] <= firstNums[1]) || (lastNums[1] >= firstNums[0] && lastNums[1] <= firstNums[1]))
            counter++;
        else if ((firstNums[0] >= lastNums[0] && firstNums[0] <= lastNums[1]) || (firstNums[1] >= lastNums[0] && firstNums[1] <= lastNums[1]))
            counter++;
    }

    // correct!!!
    // correct X2 !!!
    cout << "Total: " << counter;
}

// run this on line first
void hyphenRemove(string & line){
    for (int i = 0; i < line.length(); i++){
        if (line[i] == '-')
            line[i] = 32;
    }
}

string preComma(string line){
    string first;
    int i = 0;
    while (line[i] != ','){
        first += line[i];
        i++;
    }
    
    return first;
}

string postComma(string line){
    string last;
    int i = 0;
    bool pastComma = false;
    while (i < line.length()){
        if (pastComma){
            last += line[i];
        }

        if (line[i] == ','){
            pastComma = true;
        }

        i++;
    }
    
    return last;
}

int firstNum(string line){
    string num;
    int i = 0;
    while (line[i] != ' '){
        num += line[i];
        i++;
    }

    return stoi(num);
}

int lastNum(string line){
    string num;
    bool isSecond = false;
    for (int i = 0; i < line.length(); i++){
        if (isSecond){
            num += line[i];
        }
        else{
            if (!isSecond && line[i] == ' ')
                isSecond = true;
        }
    }

    return stoi(num);
}

void assignInts(string line, int arr[]){
    arr[0] = firstNum(line);
    arr[1] = lastNum(line);
}