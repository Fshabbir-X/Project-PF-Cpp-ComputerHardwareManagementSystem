#pragma once
#include <iostream> //Header file to provide various functions related to input/output stream.
#include <fstream> //Header file to include file handling operations in a program.
#include<string>  //Header file to include one variable type,one macro and many functions which can be used to mainupulate the string of arrays.
#include<iomanip> //Header file to include part of input/output library of C++ standard library such as setw() etc.
using namespace std; //Used for using names for objects and variables from standard library.
struct department {
	int Workstation_ID;
	string Hardware_Name;
	string Department_Name;
	string Manager;
}MyDepartment[20];
void add_department(){
    ifstream fin;
    fin.open("workstation.txt");

    try //using exceptional handling try block to check:
    {
        if (fin.fail()) //if the file under the follwing title fails to open/not found...so the error appears.
        {
            throw runtime_error("File is not available"); //throws error on screen to show user that the file is not avaliable.
        }

    }
    catch (runtime_error& e) //catch block retaining runtime errors: such as file not found.
    {
        cout << "Error occurred\n" << e.what() << endl; //shows error has occured...and used to identify the exception.returns a null terminated character.
        exit(1); //interrupted or abnormal termination.
    }
    int recordcount = 0;
    int count = 0;
    int Search_ID;
    
    cout << "Enter the Workstation ID you want Added to your desired Department"<<endl;
    cin >> Search_ID;
    while (fin >> MyDepartment[recordcount].Workstation_ID) {
        if (Search_ID == MyDepartment[recordcount].Workstation_ID) {
            fin.close();
            ifstream fin; //using file handling to take input from file, the data already present in the file.
            fin.open("hardwarefile.txt"); //opening the file, under the following title.
            try //using exceptional handling try block to check:
            {
                if (fin.fail()) //if the file under the follwing title fails to open/not found...so the error appears.
                {
                    throw runtime_error("File is not available"); //throws error on screen to show user that the file is not avaliable.
                }

            }
            catch (runtime_error& e) //catch block retaining runtime errors: such as file not found.
            {
                cout << "Error occurred\n" << e.what() << endl; //shows error has occured...and used to identify the exception.returns a null terminated character.
                exit(1); //interrupted or abnormal termination.
            }
            string Search_Hardware;
            cout << "Enter the name of hardware" << endl;
            cin>> Search_Hardware;
            while (fin >> MyDepartment[count].Hardware_Name) {
                if (Search_Hardware == MyDepartment[count].Hardware_Name) {
                    fin.close();
                    cout << "The workstation with the required hardware is found!" << endl;
                    cout << "Enter the name of the Department you want your workstation to be added:" << endl;
                    cin >> MyDepartment[count].Department_Name;
                    cout << "Enter the name of the Manager of your Department:" << endl;
                    cin>>MyDepartment[count].Manager;

                    ofstream fout;
                    fout.open("department.txt",ios::app);
                    fout << MyDepartment[count].Workstation_ID <<" " << MyDepartment[count].Hardware_Name <<" " << MyDepartment[count].Department_Name <<" " << MyDepartment[count].Manager << endl;
                }
                else {
                    count++;
                }
            }
        }
        else {
            recordcount++;
        }
    }

}
void view_department() {
    ifstream fin;
    fin.open("department.txt");
    int count = 15;
    cout << left << setw(25) <<"Workstation_ID" << setw(15) << "Hardware_Name" << setw(20) <<"Department_Name" << setw(10) << "Manager" << endl;
    while (fin >> MyDepartment[count].Workstation_ID >> MyDepartment[count].Hardware_Name >>MyDepartment[count].Department_Name >> MyDepartment[count].Manager) {
        cout << left << setw(25) << MyDepartment[count].Workstation_ID << setw(15) << MyDepartment[count].Hardware_Name << setw(20) << MyDepartment[count].Department_Name << setw(10) << MyDepartment[count].Manager << endl;
count++;
    }
    fin.close();
}