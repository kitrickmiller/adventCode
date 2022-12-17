#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int scenicLeft(int **, int, int, int);
int scenicRight(int **, int, int, int, int);
int scenicUp(int **, int, int, int);
int scenicDown(int **, int, int, int, int);
int scenicSum(int **, int, int, int, int, int);

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

    int highest = 0;
    for (int row = 0; row < counter; row++){
        for (int col = 0; col < line.length(); col++){
            cout << "sum: " << scenicSum(trees, row, col, trees[row][col], counter, line.length()) << endl;
            if ((scenicSum(trees, row, col, trees[row][col], counter, line.length()) > highest)){
                highest = scenicSum(trees, row, col, trees[row][col], counter, line.length()); 
            }
        }
    }

    cout << highest << endl;
    return 0;
}

int scenicLeft(int **trees, int row, int col, int treeHouse){
    col -= 1; // iterate column to the left
    if (col == 0){ // checking last tree, return 1 no matter what, I think.
        return 1;
    }
    else if (col == -1){ // edge case, return 0;
        return 0;
    }

    if (treeHouse > trees[row][col]){ // if treehouse is larger than tree, keep returning function
        return (1 + scenicLeft(trees, row, col, treeHouse));
    }

    return 1; // base case, return 1 when tree is equal or larger than treeHouse
}

int scenicUp(int **trees, int row, int col, int treeHouse){
    row -= 1; // iterate row up
    if (row == 0){ // checking last tree, return 1
        return 1;
    }
    else if(row == -1){ // edge case
        return 0;
    }

    if (treeHouse > trees[row][col]){ // continue
        return (1 + scenicUp(trees, row, col, treeHouse));
    }

    return 1; // base case
}

int scenicRight(int **trees, int row, int col, int treeHouse, int colMax){
    col += 1;
    if (col == (colMax - 1)){ // checking last tree
        return 1;
    }
    else if (col == colMax){ // edge case
        return 0;
    }

    if (treeHouse > trees[row][col]){ // continue 
        return (1 + scenicRight(trees, row, col, treeHouse, colMax));
    }

    return 1; // base case
}

int scenicDown(int **trees, int row, int col, int treeHouse, int rowMax){
    row += 1;
    if (row == (rowMax - 1)){
        return 1;
    }
    else if (row == rowMax){
        return 0;
    }

    if (treeHouse > trees[row][col]){
        return (1 + scenicDown(trees, row, col, treeHouse, rowMax));
    }

    return 1;
}

int scenicSum (int **trees, int row, int col, int treeHouse, int rowMax, int colMax){
    int left = scenicLeft(trees, row, col, treeHouse);
    int right = scenicRight(trees, row, col, treeHouse, colMax);
    int up = scenicUp(trees, row, col, treeHouse);
    int down = scenicDown(trees, row, col, treeHouse, rowMax);
    // cout << "left: " << left << "right: " << right << endl;

    return (left * right * up * down);
}