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
    string getName();
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

string Direc::getName(){
    return nam;
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
    Direc *trav;
    vector <Direc> trav_hist;
    Direc main("/");
    trav = &main;

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

        // check if command
        if (tokens[0] == "$"){
            // if cd, point trav to new directory.
            if (tokens[1] == "cd"){
                if(tokens[2] != ".."){
                    // cout << tokens[0] << " " << tokens[1] << " " << tokens[2] << endl;
                    // cout << "folder name: " << trav->nam << ", # of folders inside folder: " << trav->folders.size() << endl;
                    for (int i = 0; i < trav->folders.size(); i++){
                        cout << "token name: " << tokens[2] << ", folder name: " << trav->folders[i].nam << endl;
                        if (tokens[2] == trav->folders[i].nam){
                            cout << "!!!\n";
                            trav_hist.push_back(*trav);
                            trav = &(trav)->folders[i];
                        }
                        cout << "folder name: " << trav->nam << endl;
                    }
                }
                else{
                    trav = &trav_hist.back();
                    trav_hist.pop_back();
                }
            }
        }
        else if(tokens[0] == "dir"){
            // add dir to direc
            cout << tokens[0] << " " << tokens[1] << endl;
            Direc temp(tokens[1]);
            trav->folders.push_back(temp);
            for (int i = 0; i < trav->folders.size(); i++){
                cout << trav->nam << ": folder added: " << trav->folders[i].getName() << endl;
            }
        }
        else{
            // add file to dir
            File temp(tokens[1], stoi(tokens[0]));
            trav->files.push_back(temp);
        }

        // clear tokens
        tokens.clear();

    }
    return 0;

}

