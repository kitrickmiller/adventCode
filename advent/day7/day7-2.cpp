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
    long sum();
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

long Direc::sum(){
    long summation = 0; 

    for (int i = 0; i < files.size(); i++){
        // cout << files[i]->nam << " size: " << files[i]->size << endl;
        summation += files[i]->size;
    }

    for (int i = 0; i < folders.size(); i++){
        // cout << folders[i]->n << endl;
        summation += folders[i]->sum();
    }
    
    return summation;
}

string Direc::getName(){
    return n;
}

int tokenOne(string);
Direc *newDirec(string, Direc*);
File *newFile(string, int);
long sumCounter(Direc*);
long sumFinder(Direc*, int);


int main(){
    cout.flush();
    ifstream file;
    file.open("input7.txt");
    if (!file.is_open()){
        cout << "error\n";
        return 1;
    }

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
            if (tokens[2] == ".."){
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
    }

    trav = &main;
    cout << trav->sum() << endl;
    cout << sumCounter(&main) << endl;
    cout << sumFinder(&main, main.sum());

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

long sumCounter(Direc *point){
    long sum = 0;
    for (int i = 0; i < point->folders.size(); i++){
        sum += sumCounter(point->folders[i]);
        if (point->folders[i]->sum() <= 100000)
            sum += point->folders[i]->sum();
    }

    return sum;
}

long sumFinder(Direc *point, int smallestPos){

    for (int i = 0; i < point->folders.size(); i++){
        if ((point->folders[i]->sum() < smallestPos) && (point->folders[i]->sum() > 8748071)){
            smallestPos = point->folders[i]->sum();
        }
        smallestPos = sumFinder(point->folders[i], smallestPos); 
    }

    return smallestPos;
}


