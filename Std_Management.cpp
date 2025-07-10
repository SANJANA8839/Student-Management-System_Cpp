#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string rollNum,name,fName,address,search;
    fstream file;
    public:
    void addStu();
    void viewStu();
    void searchStu();
}obj;

int main(){
    char choice;
    bool running = true;
    
    while(running) {
        cout<<"\n---------------------------"<<endl;
        cout<<"1- Add Student Record"<<endl;
        cout<<"2- View All Student Record"<<endl;
        cout<<"3- Search Student Record"<<endl;
        cout<<"4- Exit"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case '1':
                cin.ignore();
                obj.addStu();
            break;
            case '2':
                cin.ignore();
                obj.viewStu();
            break;
            case '3':
                cin.ignore();
                obj.searchStu();
            break;
            case '4':
                running = false;
                cout << "Exiting program. Goodbye!" << endl;
            break;
            default:
                cout<<"Invalid Choice...! Please try again."<<endl;
        }
    }
    
    return 0;
}

void temp :: addStu(){
    
    cout<<"Enter Student Roll Number :: ";
    getline(cin,rollNum);
    cout<<"Enter Student Name ::";
    getline(cin,name);
    cout<<"Enter Student Father Name ::";
    getline(cin,fName);
    cout<<"Enter Student Address ::";
    getline(cin,address);

    file.open("stuData.txt",ios :: out | ios :: app);
    file<<rollNum<<"*";
    file<<name<<"*";
    file<<fName<<"*";
    file<<address<<endl;
    file.close();
}

void temp :: viewStu(){
    
    file.open("stuData.txt",ios :: in);
    
    if(!file) {
        cout << "\nError: Unable to open file or file does not exist!" << endl;
        return;
    }
    
    // Check if file is empty
    if(file.peek() == std::ifstream::traits_type::eof()) {
        cout << "\nNo student records found. The file is empty." << endl;
        file.close();
        return;
    }
    
    bool recordsFound = false;
    
    // Read and display all records
    while(getline(file, rollNum, '*') && 
          getline(file, name, '*') && 
          getline(file, fName, '*') && 
          getline(file, address, '\n')) {
        
        recordsFound = true;
        cout<<"\n";
        cout<<"Student Roll Number :: "<<rollNum<<endl;
        cout<<"Student Name :: "<<name<<endl;
        cout<<"Student Father Name :: "<<fName<<endl;
        cout<<"Student Address :: "<<address<<endl;
    }
    
    if(!recordsFound) {
        cout << "\nNo student records found or file format is incorrect." << endl;
    }
    
    file.close();
}

void temp :: searchStu(){

    cout<<"Enter Student Roll Number :: ";
    getline(cin,search);
    
    file.open("stuData.txt",ios :: in);
    
    if(!file) {
        cout << "\nError: Unable to open file or file does not exist!" << endl;
        return;
    }
    
    // Check if file is empty
    if(file.peek() == std::ifstream::traits_type::eof()) {
        cout << "\nNo student records found. The file is empty." << endl;
        file.close();
        return;
    }
    
    bool recordFound = false;
    
    // Read and search for the record
    while(getline(file, rollNum, '*') && 
          getline(file, name, '*') && 
          getline(file, fName, '*') && 
          getline(file, address, '\n')) {
        
        if(rollNum == search){
            cout<<endl;
            cout<<"Student Roll Number :: "<<rollNum<<endl;
            cout<<"Student Name :: "<<name<<endl;
            cout<<"Student Father Name :: "<<fName<<endl;
            cout<<"Student Address :: "<<address<<endl;
            recordFound = true;
        }
    }
    
    if(!recordFound) {
        cout << "\nNo student found with Roll Number: " << search << endl;
    }
    
    file.close();
}