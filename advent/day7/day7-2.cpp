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
    string n; // name;
    vector <Direc *> folders;
    vector <File *> files;
    Direc *parent;
    Direc(string);
    Direc(string, Direc*);
    void addFolder(Direc*);
    void addFile(File*);
    int sum();
    string getName();
};

Direc::Direc(string nam){
    n = nam;
}

Direc::Direc(string nam, Direc* d){
    parent = d;
    n = nam;
}

void Direc::addFolder(Direc *d){
    folders.push_back(d);
}

void Direc::addFile(File *f){
    files.push_back(f);
}

int Direc::sum(){
    int summation; 
    if (folders.size() > 0){
        for (int i = 0; i < folders.size(); i++){
            summation += folders[i]->sum();
        }
    }

    for (int i = 0; i < files.size(); i++){
        summation += files[i]->size;
    }

    return summation;
}

string Direc::getName(){
    return n;
}

int tokenOne(string);
Direc *newDirec(string, Direc*);
File *newFile(string, int);


int main(){
    ifstream file;
    cout << "?\n" << endl;
    file.open("input7.txt");
    if (!file.is_open()){
        cout << "error\n";
        return 1;
    }

    cout << "?\n" << endl;

    string line;
    // init first direc
    getline(file,line);
    Direc main("/");
    Direc *trav = &main;

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

        // handle cd
        if (tokenOne(tokens[0]) == 1 && tokens[1] == "cd"){
            // handle ..
            if (tokens[2] != ".."){
                trav = trav->parent;
            }
            else{ // handle entering a direc
                for (int i = 0; i < trav->folders.size(); i++){
                    // if direc is in folders, jump into it
                    if (tokens[2] == trav->folders[i]->n){
                        trav = trav->folders[i];
                    }
                }
            }
        }
        else if(tokenOne(tokens[0]) == 2){
            // add direc to folders
            trav->addFolder(newDirec(tokens[1], trav));
        }
        else if (tokenOne(tokens[0]) == 3){
            trav->addFile(newFile(tokens[1], stoi(tokens[0])));
        }

        cout << "?\n" << endl;

    }

    trav = &main;
    cout << "Did we make it?\n";
    cout << trav->sum() << endl;

    return 0;
}

int tokenOne(string lineOne){ 
    if (lineOne == "$"){ // open direc or do nothing
        return 1;
    }
    else if (lineOne == "dir"){ // add direc to folders
        return 2;
    }
    else{
        return 3; // add file to direc
    }
}

Direc *newDirec(string name, Direc *p){
    Direc *temp = new Direc(name, p);
    return temp;
}

File *newFile(string name, int size){
    File *temp = new File(name, size);
    return temp;
}



