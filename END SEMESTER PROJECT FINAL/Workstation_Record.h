#pragma once
#include <iostream> //Header file to provide various functions related to input/output stream.
#include <fstream> //Header file to include file handling operations in a program.
#include<string>  //Header file to include one variable type,one macro and many functions which can be used to mainupulate the string of arrays.
#include<iomanip> //Header file to include part of input/output library of C++ standard library such as setw() etc.
using namespace std; //Used for using names for objects and variables from standard library.
struct Workstation {
    int ID;
    int CPUcores;
    int GPUvRAM;
    int Powersupply;
}Myworkstation[5];
void addWorkstation() //Calling add function, As declared at the top.
{
    Workstation* MyWorkstation = new Workstation[5];
    ofstream fout; //Gives output in the following file.
    fout.open("workstation.txt", ios::app); //opening the file and writing data to it. append used to store at the end of last entry.
    char choice; //character variable is declared. 

    for (int j = 0; j <= 5; j++)
    {
        cout << "Enter WorkStation ID: "; //asks user to enter the new record to store the updated version of all the record attributes present in one row.
        cin >> MyWorkstation[j].ID;
        cout << "Enter CPU Cores: ";
        cin >> MyWorkstation[j].CPUcores;
        cout << "Enter GPU VRAM: ";
        cin >> MyWorkstation[j].GPUvRAM;
        cout << "Enter Power Supply: ";
        cin >> MyWorkstation[j].Powersupply;
        fout << left << setw(25) << MyWorkstation[j].ID << setw(15) << MyWorkstation[j].CPUcores << setw(20) << MyWorkstation[j].GPUvRAM << setw(10) << MyWorkstation[j].Powersupply << endl; //outputs the new data to the file and saves in it.
        cout << "Enter Y if you want to add data again and N if not" << endl;
        cin >> choice;
        if (choice == 'N' || choice == 'n') {
            j = 5;
        }
    }
    fout.close(); //closing the output file.
    cout << "The records have been saved to the file" << endl; //displays the follwoing message to the user. after successfully exection.
    delete[] MyWorkstation;
}
void viewWorkstation() //Calling view function, As declared at the top.
{

    ifstream fin; //takes input from the file.
    fin.open("workstation.txt"); //opening and inputing the data from the file.
    try //using exceptional handling to increase the efficiency of the code.
    {
        if (fin.fail())
        {
            throw runtime_error("File is not available"); //throws following error on screen in case of failure of not finding a file.
        }
    }
    catch (runtime_error& e) //catching errors.
    {
        cout << "File not found!\n"
            << e.what() << endl;
        exit(1);
    }
    int recordcount = 0; //number of records the user wants to save. increasing rows, shifting to the next rows. one by one.
    cout << left << setw(25) << "ID" << setw(15) << "CPU_CORES" << setw(20) << "GPUV_RAM(IN GBs)" << setw(10) << "POWER_SUPPLY(IN WATTS)" << endl; // displays following headings with the spacing.
    while (fin >> Myworkstation[recordcount].ID >> Myworkstation[recordcount].CPUcores >> Myworkstation[recordcount].GPUvRAM >> Myworkstation[recordcount].Powersupply) //using loop to take input from the file releated to the specific fields with 4 columns.
    {
        cout << left << setw(25) << Myworkstation[recordcount].ID << setw(15) << Myworkstation[recordcount].CPUcores << setw(20) << Myworkstation[recordcount].GPUvRAM << setw(10) << Myworkstation[recordcount].Powersupply << endl; //displays the record on the screen in the follwoing format.
        recordcount++; //adding rows one after another everytime loop executes.
    }
    fin.close(); //closing the file which was opened before.

}
void searchWorkstation() //Calling search function, As declared at the top.
{

    ifstream fin; //takes input from the file.
    fin.open("workstation.txt"); //opening and inputing the data from the file.
    try //using exceptional handling to increase the efficiency of the code.
    {
        if (fin.fail())
        {
            throw runtime_error("File is not available"); //throws following error on screen in case of failure of not finding a file.
        }
    }
    catch (runtime_error& e) //catching errors.
    {
        cout << "File not found!\n"
            << e.what() << endl;
        exit(1);
    }
    int searchID; //declaring variable of int type search id.
    bool found = false; //applying bool by making false.
    cout << "Enter the WorkStation ID to search for: "; //asks user to enter id to search.
    cin >> searchID; //takes input.
    int recordcount = 0; //recordcount variable declared to shift to next no of rows. as the user enter the records successfully.
    while (fin >> Myworkstation[recordcount].ID >> Myworkstation[recordcount].CPUcores >> Myworkstation[recordcount].GPUvRAM >> Myworkstation[recordcount].Powersupply) //using loop to take input from the file releated to the specific fields with 4 columns.
    {
        if (Myworkstation[recordcount].ID == searchID) //applying condition to check if the entered id matches the records placed inside the file beforehand.
        {
            cout << "Workstation found!\n"; //if found displays following message.
            cout << left << setw(25) << "ID" << setw(15) << "CPU_Cores" << setw(20) << "GPUV_RaM" << setw(10) << "Power_Supply" << endl; //with details under the headings.
            cout << left << setw(25) << Myworkstation[recordcount].ID << setw(15) << Myworkstation[recordcount].CPUcores << setw(20) << Myworkstation[recordcount].GPUvRAM << setw(10) << Myworkstation[recordcount].Powersupply << endl;
            found = true; //bool remains true as the record is found.
            break;
        }
        recordcount++; //this add the row and the control shifts to the next row.
    }
    if (!found) //if record is not found.
    {
        cout << "Workstation with ID " << searchID << " not found.\n"; //displays the follwoing message.
    }
    fin.close(); ///closes the file.

}
void updateWorkstation() //Calling update function, As declared at the top.
{
    ifstream fin("workstation.txt"); //input the data from the file after opening it.
    try //using exceptional handling to increase the efficiency of the code.
    {
        if (fin.fail())
        {
            throw runtime_error("File is not available"); //throws following error on screen in case of failure of not finding a file.
        }
    }
    catch (runtime_error& e) //catching errors.
    {
        cout << "File not found!\n"
            << e.what() << endl;
        exit(1);
    }

    ofstream fout("tempfile1.txt"); //gives output of data to a temporary file created.
    int recordcount = 0; //declartions of variables as before accordingly.
    int updateID;
    bool found = false; //applying bool variable which is false.

    cout << "Enter the WorkStation ID to update: "; //asks user to enter the ID to update.
    cin >> updateID; //takes input from the user.

    while (fin >> Myworkstation[recordcount].ID >> Myworkstation[recordcount].CPUcores >> Myworkstation[recordcount].GPUvRAM >> Myworkstation[recordcount].Powersupply) //reads the data accordingly using the variables from the file.
    {
        if (Myworkstation[recordcount].ID == updateID) //if records in arrays matches the ID's input by the user.
        {
            found = true; //bool returns true.
            cout << "Workstation Record found!\n"; //displays following on the screen.
            cout << left << setw(25) << "ID" << setw(15) << "CPU_Cores" << setw(20) << "GPUV_RaM" << setw(10) << "Power_Supply" << endl; //shows the ouput of the attributes headings() in the following order with the spaces.
            cout << left << setw(25) << Myworkstation[recordcount].ID << setw(15) << Myworkstation[recordcount].CPUcores << setw(20) << Myworkstation[recordcount].GPUvRAM << setw(10) << Myworkstation[recordcount].Powersupply << endl;

            cout << "Enter new WorkStation ID: "; //asks user to enter the new record to store the updated version of all the record attributes present in one row.
            cin >> Myworkstation[recordcount].ID;
            cout << "Enter new CPU Cores: ";
            cin >> Myworkstation[recordcount].CPUcores;
            cout << "Enter new GPU VRAM: ";
            cin >> Myworkstation[recordcount].GPUvRAM;
            cout << "Enter new Power Supply: ";
            cin >> Myworkstation[recordcount].Powersupply;

            fout << left << setw(25) << Myworkstation[recordcount].ID << setw(15) << Myworkstation[recordcount].CPUcores << setw(20) << Myworkstation[recordcount].GPUvRAM << setw(10) << Myworkstation[recordcount].Powersupply << endl; //outputs the new data to the file and saves in it.
            cout << "Updated Record Saved Successfully to the file\n"; //displays the following message to the user on the screen.
        }
        else //otherwise if it dosen't match then,
        {
            fout << left << setw(25) << Myworkstation[recordcount].ID << setw(15) << Myworkstation[recordcount].CPUcores << setw(20) << Myworkstation[recordcount].GPUvRAM << setw(10) << Myworkstation[recordcount].Powersupply << endl;
        }
        recordcount++; //shifts to the next row everytime adding the rows as the user enters the records.
    }
    if (!found) //if the records is not found.
    {
        cout << "Cannot find such Workstation ID to update record!\n"; //displays the following message on screen.
    }
    fin.close(); //closes the input data file.
    fout.close(); //closes the output data file.
    remove("workstation.txt"); //removes the original file with the data stored un-updated.
    rename("tempfile1.txt", "workstation.txt"); //renames the tempfile having all the records unupdated and updated all together....back to the same title as before. there's no purpose for tempfile rather than saving data accumulated after updating.

}
void deleteWorkstation() //Calling delete function, As declared at the top.
{
    ifstream fin("workstation.txt"); //input the data from the file after opening it.
    try //using exceptional handling to increase the efficiency of the code.
    {
        if (fin.fail())
        {
            throw runtime_error("File is not available"); //throws following error on screen in case of failure of not finding a file.
        }
    }
    catch (runtime_error& e) //catching errors.
    {
        cout << "File not found!\n"
            << e.what() << endl;
        exit(1);
    }
    ofstream fout("tempfile.txt"); //gives output of data to a temporary file created.
    bool found = false;  //applying bool variable which is false.
    int recordcount = 0; //declartions of variables as before accordingly.
    int deleteID;
    cout << "Enter the WorkStation ID to delete: "; //asks user to enter the ID to delete.
    cin >> deleteID; //user inputs the ID and record related to that to delete.
    while (fin >> Myworkstation[recordcount].ID >> Myworkstation[recordcount].CPUcores >> Myworkstation[recordcount].GPUvRAM >> Myworkstation[recordcount].Powersupply) //reads the data accordingly using the variables from the file.
    {

        if (Myworkstation[recordcount].ID == deleteID) //if records in arrays matches the ID's input by the user.
        {
            found = true; //bool returns true.
            cout << "Workstation ID Record found and deleted!\n"; //deletes the record and displays the following messsage.
        }
        else
        {
            fout << left << setw(25) << Myworkstation[recordcount].ID << setw(15) << Myworkstation[recordcount].CPUcores << setw(20) << Myworkstation[recordcount].GPUvRAM << setw(10) << Myworkstation[recordcount].Powersupply << endl; // otherwise is undeleted and gives the records with undeleted iD record.
        }
        recordcount++; //this add the row and the control shifts to the next row.
    }
    if (!found) //if the records is not found.
    {
        cout << "Cannot find such Workstation ID to update record!\n"; //displays the following message on screen.
    }
    fin.close(); //closes the input data file.
    fout.close(); //closes the output data file.
    remove("workstation.txt"); //removes the original file with the data stored un-updated.
    rename("tempfile.txt", "workstation.txt"); //renames the tempfile having all the records unupdated and updated all together....back to the same title as before. there's no purpose for tempfile rather than saving data accumulated after updating.
}