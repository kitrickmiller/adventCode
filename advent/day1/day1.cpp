#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(){

    ifstream file;
    
    // open file and check for openness
    file.open("C:\\Users\\kitri\\Documents\\vscode\\advent\\day1\\input.txt");
    if (!file.is_open()){
        cout << "error!\n";
        return 1;
    }

    int counter = 1;
    int biggest_val = 0;
    int second_val = 0;
    int third_val = 0;
    int biggest_count = 0;
    int current_val = 0;
    string current_line;

    while (true){
        if (file.eof())
            break;

        getline(file, current_line);
        if (!current_line.empty())
            current_val += stoi(current_line);

        else{
            counter++;

            if (current_val >= biggest_val){
                third_val = second_val;
                second_val = biggest_val;
                biggest_val = current_val; 
                biggest_count = counter;
            }
            else if (current_val >= second_val){
                third_val = second_val;
                second_val = current_val;
            }
            else if (current_val >= third_val){
                third_val = current_val;
            }

            current_val = 0;
        }
        
    }

    // It worked!!! +1 gold star
    // It worked x2 +1 more gold star.
    cout << second_val << " " << third_val << "\n";
    cout << "Elf " << biggest_count << " had " << biggest_val << " calories.\n";
    cout << "The top three Elfs had a combined " << biggest_val + second_val + third_val << " calories.\n";

    return 0;

}