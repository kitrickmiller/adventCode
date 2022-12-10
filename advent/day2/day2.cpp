#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    // open file and error check
    ifstream file;
    file.open("C:\\Users\\kitri\\Documents\\vscode\\advent\\day2\\input2.txt");
    if (!file.is_open()){
        cout << "error!\n";
        return 1;
    }

    string round;
    int points = 0;
    int count = 0;

    // A & X == Rock (1 point)
    // B & Y == Paper (2 points)
    // C & Z == Scissors (3 points)

    while (true){
        if (file.eof()) break;
        count++;

        getline(file, round);

        // X case, need to lose
        if (round[2] == 'X'){
            if (round[0] == 'A'){
                points += 3;
            }
            else if (round[0] == 'B'){
                points += 1;
            }
            else{
                points += 2;
            }
        }
        // Y case, need to draw
        else if (round[2] == 'Y'){
            if (round[0] == 'A'){
                points += 4;
            }
            else if (round[0] == 'B'){
                points += 5;
            }
            else{
                points += 6;
            }
        }
        // Z case, need to win!
        else{
            if (round[0] == 'A'){
                points += 8;
            }
            else if (round[0] == 'B'){
                points += 9;
            }
            else{
                points += 7;
            }
        }
    }

    

    /*
    while (true){
        if (file.eof()) break;

        getline(file, round);

        // opponent plays rock
        if (round[0] == 'A'){
            
            // draw (1 + 3)
            if (round[2] == 'X'){
                points += 4;
            }
            // win (2 + 6)
            else if(round[2] == 'Y'){
                points += 8;
            }
            // loss (3 + 0)
            else{
                points += 3;
            }
        }

        // opponent plays paper
        else if (round[0] == 'B') {
            
            // loss (1 + 0)
            if (round[2] == 'X'){
                points += 1;
            }
            // draw (2 + 3)
            else if (round[2] == 'Y'){
                points += 5;
            }
            // win (3 + 9)
            else{
                points += 9;
            }
        }

        // opponnent plays scissors
        else{

            // win (1 + 6)
            if (round[2] == 'X'){
                points += 7;
            }
            // loss (2 + 0)
            else if (round[2] == 'Y'){
                points += 2;
            }
            // draw (3 + 3)
            else{
                points += 6;
            }
        }
    }
    */

    // Correct! +1 gold star
    // Double Correct + 1 more gold star
    cout << count << endl;
    cout << points << endl;
}