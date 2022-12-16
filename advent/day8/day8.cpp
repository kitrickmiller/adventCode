#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

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
            cout << trees[i][j] << " ";
        }
        i++;
        cout << endl;
    }
    
    // correctly arrayed :)
    cout << "counter: " << counter << endl;

    int vis_trees = 0;
    for (int x = 0; x < counter; x++){
        for (int y = 0; y < line.length(); y++){
            if ((y == 0) || (x == 0) || (x == counter - 1) || (y == line.length() - 1)){
                vis_trees++;
            }
            else{
                // trees to left
                int blocked = trees[x][y];
                for (int x1 = x - 1; x1 >= 0; x1--){
                    cout << "check left\n";
                    if (trees[x1][y] < blocked){
                        if (x1 == 0){
                            vis_trees++;
                            cout << "found!!\n";
                            break;
                        }
                        else{
                            blocked = trees[x1][y];
                        }
                    }
                    else{
                        break;
                    }
                }

                // trees to right
                blocked = trees[x][y];
                for (int x2 = x + 1; x2 < counter; x2++){
                    cout << "check right\n";
                    cout << "x2: " << x2 << "y: " << y << endl;
                    if (trees[x2][y] < blocked){
                        if (x2 == counter - 1){
                            vis_trees++;
                            cout << "found!!\n";
                            break;
                        }
                        else{
                            blocked = trees[x2][y];
                        }
                    }
                    else{
                        break;
                    }
                }

                // trees below
                blocked = trees[x][y];
                for (int y2 = y + 1; y2 < line.length() - 1; y2++){
                    cout << "check below\n";
                    if (trees[x][y2] < blocked){
                        if (y2 == counter - 1){
                            vis_trees++;
                            cout << "found!!\n";
                            break;
                        }
                        else{
                            blocked = trees[x][y2];
                        }
                    }
                    else{
                        break;
                    }
                }

                // trees above
                blocked = trees[x][y];
                for (int y1 = y - 1; y1 >= 0; y1--){
                    cout << "check above\n";
                    if (trees[x][y1] < blocked){
                        if (y1 == 0){
                            vis_trees++;
                            cout << "found!!\n";
                            break;
                        }
                        else{
                            blocked = trees[x][y1];
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }

    cout << vis_trees;
    return 0;
}