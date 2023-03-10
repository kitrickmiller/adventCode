#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
void cycleCheck(int, int, int*);
void cycleCommand(int, int);
int CPUcycle(string[][2], int);

int main(){

    // open file and check for error
    ifstream file;
    file.open("day10input.txt");
    if(!file.is_open()){
        cout << "File not opening! Error!!!\n";
        return 1;
    }

    // count how many commands there are, for array of commands
    string command;
    int counter = 0;
    while(true){
        if(file.eof())
            break;
        getline(file, command);
        counter++;
    }

    // reset file.
    file.open("day10input.txt");
    file.clear();
    file.seekg(0);

    // setup variables
    string commands[counter][2];   
    string token;
    int j;

    // fill array
    for (int i = 0; i < counter; i++){
        getline(file, command);
        stringstream tokenizer(command);
        j = 0;
        if (command.length() > 5){
            while (getline(tokenizer, token, ' ')){
                commands[i][j] = token;
                // cout << commands[i][j] << " ";
                j++;
            }
        }
        else{
            commands[i][j] = command;
            // cout << commands[i][j];
            commands[i][1] = "na";
        }
        cout << endl;
    }

    int sum = CPUcycle(commands, counter);
    cout << sum << endl;
    return 0;
}

int CPUcycle(string commandList[][2], int numCommands){
    int cycleCounter = 0;
    int cycleSum = 1;
    int sumCycles = 0;
    for (int i = 0; i < numCommands; i++){
        if (commandList[i][0] == "noop"){
            cycleCounter++;
            cycleCheck(cycleCounter, cycleSum, &sumCycles);
        }
        else{
            cycleCounter++;
            cycleCheck(cycleCounter, cycleSum, &sumCycles);
            cycleCounter++;
            cycleCheck(cycleCounter, cycleSum, &sumCycles);
            cycleSum += stoi(commandList[i][1]);
        }

        // cout << i << endl;
    }

    return sumCycles;
}

void cycleCheck(int counter, int currentSum, int * refSum){
    int value = counter * currentSum;
   
    
    if (counter == 20 || counter == 60 || counter == 100
        || counter == 140 || counter == 180 || counter == 220){
        
        // cout << "register: " << currentSum << " cycle #: " << counter << " value: " << value << endl;
        *refSum += value;;
    }

    if ((counter - 1) < 40){    
        if ((counter - 1) == currentSum || (counter - 1) == (currentSum - 1) || (counter - 1) == (currentSum + 1)){
            cout << "#";
        }
        else{
            cout << ".";
        }
    }
    else if ((counter - 1) < 80){
        counter -= 40;
        if ((counter - 1) == currentSum || (counter - 1) == (currentSum - 1) || (counter - 1) == (currentSum + 1)){
            cout << "#";
        }
        else{
            cout << ".";
        }
        counter += 40;
    }
    else if (counter < 120){
        counter -= 80;
        if ((counter - 1) == currentSum || (counter - 1) == (currentSum - 1) || (counter - 1) == (currentSum + 1)){
            cout << "#";
        }
        else{
            cout << ".";
        }
        counter += 80;
    }
    else if ((counter - 1) < 160){
        counter -= 120;
        if ((counter - 1) == currentSum || (counter - 1) == (currentSum - 1) || (counter - 1) == (currentSum + 1)){
            cout << "#";
        }
        else{
            cout << ".";
        }
        counter += 120;
    }
    else if ((counter - 1) < 200){
        counter -= 160;
        if ((counter - 1) == currentSum || (counter - 1) == (currentSum - 1) || (counter - 1) == (currentSum + 1)){
            cout << "#";
        }
        else{
            cout << ".";
        }
        counter += 160;
    }
    else{
        counter -= 200;
        if ((counter - 1) == currentSum || (counter - 1) == (currentSum - 1) || (counter - 1) == (currentSum + 1)){
            cout << "#";
        }
        else{
            cout << ".";
        }
        counter += 200;
    }
    if ((counter - 1) == 40 || (counter - 1) == 80 || (counter - 1) == 120 || (counter - 1) == 160 || (counter - 1) == 200 || (counter - 1) == 240){
        cout << endl;
    }
}