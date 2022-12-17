#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool checker(int **, int , int , int , int , char );
int scenicRating(int**, int, int, int, int);

int main(){
    ifstream file;
    file.open("input8.txt");
    if (!file.is_open()){
        cout << "error!\n";
        return 1;
    }

    string line;
    int counter = 0;
    // count # of rows
    while(true){
        if (file.eof()) break;
        getline(file, line);
        counter++;
    }
    
    file.open("input8.txt");
    int ** trees = new int*[counter];
    for (int i = 0; i < counter; i++){
        trees[i] = new int[line.length()];
    }

    if(file.eof()) cout << "uhhh\n";
    file.clear();
    file.seekg(0);

    int i = 0;
    while(true){
        if (file.eof()) break;
        getline(file, line);

        for (int j = 0; j < line.length(); j++){
            trees[i][j] = line[j] - 48;
            // cout << trees[i][j] << " ";
        }
        i++;
        // cout << endl;
    }
    
    // correctly arrayed :)
    cout << "counter: " << counter << endl;

    int vis_trees = 0;
    cout << "line length: " << line.length() << endl;
    
    for (int k = 0; k < counter; k++){
        for (int j = 0; j < line.length(); j++){
            // cout << "k: " << k << " j: " << j << endl;
            if (k == 0 || j == 0 || k == (counter - 1) || j == (line.length() - 1)){
                vis_trees++;
                // cout << "tree added\n";
            }
            else if (checker(trees, k, j, (counter - 1), (line.length() - 1), 'a') == true){
                vis_trees++;
                // cout << "tree added!\n";
            }
            else if(checker(trees, k, j, (counter - 1), (line.length() - 1), 'b') == true){
                vis_trees++;
                // cout << "tree added!\n";
            }
            else if(checker(trees, k, j, (counter - 1), (line.length() - 1), 'r') == true){
                vis_trees++;
                // cout << "tree added!\n";
            }
            else if(checker(trees, k, j, (counter - 1), (line.length() - 1), 'l') == true){
                vis_trees++;
                // cout << "tree added!\n";
            }
        }
    }

    int highest = 0; 

    for (int k = 0; k < counter; k++){
        for (int j = 0; j < line.length(); j++){
            if (scenicRating(trees, k, j, (counter - 1), (line.length() - 1)) > highest){
                highest = scenicRating(trees, k, j, (counter - 1), (line.length() - 1));
            }
        }
    }

    cout << vis_trees << endl;
    cout << highest;
    return 0;
}

bool checker(int **trees, int x, int y, int xMax, int yMax, char dir){
    int check = trees[x][y];
    switch(dir){
    case 'a':
            // cout << "checking above...\n";
            for (int x1 = x - 1; x1 >= 0; x1--){
                // cout << "x1: " << x1 << " y: " << y << endl;
                if (trees[x1][y] < check){
                    if (x1 == 0){
                        return true;
                    }
                }
                else{
                    break;
                } 
            }
            break; 
    case 'b':
            // cout << "checking below...\n";
            for (int x1 = x + 1; x1 <= xMax; x1++){
                // cout << "x1: " << x1 << " y: " << y << endl;
                if (trees[x1][y] < check){
                    if (x1 == xMax){
                        return true;
                    }
                }
                else{
                    break;
                } 
            }
            break;
    case 'r':
            // cout << "checking right...\n";
            for (int y1 = y + 1; y1 <= yMax; y1++){
                // cout << "x: " << x << " y1: " << y1 << endl;
                // cout << "check: " << check << " > " << trees[x][y1] << endl;
                if (trees[x][y1] < check){
                    if (y1 == yMax){
                        return true;
                    }
                }
                else{
                    break;
                } 
            }
            break;
    case 'l':
            // cout << "checking left...\n";
            for (int y1 = y - 1; y1 > -1; y1--){
                // cout << "x: " << x << " y1: " << y1 << endl;
                // cout << "val checked: " << trees[x][y1] << "versus check: " << check << endl;
                if (trees[x][y1] < check){
                    if (y1 == 0){
                        return true;
                    }
                }
                else{
                    break;
                } 
            }
            break;
    }
    return false;
}

int scenicRating(int** trees, int x, int y, int xMax, int yMax){
    int aboveRtg = 0, belowRtg = 0, rightRtg = 0, leftRtg = 0;
    int check1 = trees[x][y];
    int check = 10;
    // above check

    
    for (int i = (x - 1); i >= 0; i--){
        if (trees[i][y] < check && trees[i][y] < check1){
            aboveRtg++;
            // check = trees[i][y];
        }
        else{
            break;
        }
    }
    cout << "abv rtg: " << aboveRtg << endl;
    // below check
    check = 10;
    for (int i = (x + 1); i <= xMax; i++){
        if (trees[i][y] < check && trees[i][y] < check1){
            belowRtg++;
            // check = trees[i][y];
        }
        else{
            break;
        }
    }
    cout << "blw rtg: " << belowRtg << endl;
    // right check
    check = 10;
    for (int i = (y + 1); i <= yMax; i++){
        if (trees[x][i] < check && trees[x][i] < check1){
            rightRtg++;
            cout << "Not broken!\n";
            // check = trees[x][i];
        }
        else{
            cout << "broken\n";
            break;
        }
    }
    cout << "rit rating: " << rightRtg << endl;
    // left check
    check = 10;
    for (int i = (y - 1); i >= 0; i--){
        if (trees[x][i] < check && trees[x][i] < check1){
            leftRtg++;
            // check = trees[x][i];
        }
        else{
            break;
        }
    }
    cout << "let rating: " << leftRtg << endl;

    if (x == 0){
        aboveRtg = 0;
    }

    if (x == xMax){
        belowRtg = 0;
    }

    if (y == 0){
        leftRtg = 0;
    }

    if (y == yMax){
        rightRtg = 0;
    }
    
    return (aboveRtg * belowRtg * rightRtg * leftRtg);
}