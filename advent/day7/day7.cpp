#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class File{
    public: 
    string nam;
    int size;
    File(string, int);
    string getName();
    int getSize();
};

File::File(string named, int sized){
    nam = named; 
    size = sized;
}

string File::getName(){
    return nam;
}

int File::getSize(){
    return size;
}

class Direc{
    public:
    string nam;
    vector <Direc> folders;
    vector <File> files;
    Direc(string);
    void addFolder(Direc);
    void addFile(File);
    int sumFiles();
};

Direc::Direc(string n){
    nam = n;
}

void Direc::addFolder(Direc f){
    folders.push_back(f);
}

void Direc::addFile(File f){
    files.push_back(f);
}

int sumFiles(){
    return 1;
}

int main(){
    ifstream file;
    file.open("input7.txt");
    if (!file.is_open()){
        cout << "error\n";
        return 1;
    }

    string line;
    // push to second line.
    getline(file, line);

    while (true){
        if (file.eof()) break;

        // get tokenized data 
        getline(file, line);
        vector<string> tokens;
        string delimiter = " ";
        size_t pos = 0;
        while((pos = line.find(delimiter)) != std::string::npos){
            tokens.push_back(line.substr(0, pos));
            line.erase(0, pos + delimiter.length());
        }
        tokens.push_back(line);

        /* print out tokenized data
        for (int i = 0; i < tokens.size(); i++){
            cout << tokens[i] << " ";
        }
        */

        Direc *trav;
        vector<Direc> trav_hist;
        Direc main("/");

        // check if command
        if (tokens[0] == "$"){
            // if cd, point trav to new directory.
        }
        else if(tokens[0] == "dir"){
            // add dir to direc
        }
        else{
            // add file to dir
        }

        // clear tokens
        tokens.clear();

    }
    return 0;

}

