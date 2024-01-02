#pragma once
#include <iostream> //Header file to provide various functions related to input/output stream.
#include <fstream> //Header file to include file handling operations in a program.
#include<string>  //Header file to include one variable type,one macro and many functions which can be used to mainupulate the string of arrays.
#include<iomanip> //Header file to include part of input/output library of C++ standard library such as setw() etc.
using namespace std; //Used for using names for objects and variables from standard library.
struct Hardware {
    string HARDWARE_NAME;
    string BRAND;
    string PURCHASE_DATE;
    int PRICE;
    string SEARCH_HARDWARE;
};
void addHardware() //Calling Add function, As declared at the top.
{
    Hardware addHardware;
    ofstream fout; //using file handling operations to output the data into a file.
    fout.open("hardwarefile.txt", ios::app); //creating a file with the following file name and opening it...appending data to it.
    cout << "Enter the Hardware name\n(Enter the first letter in Capital letters):" << endl; //The statement displayed to user on screen.Asked to enter data.
    cin >> addHardware.HARDWARE_NAME; //The data enntered by the user taking input.
    cout << "Enter the Brand name:" << endl;
    cin >> addHardware.BRAND;
    cout << "Enter the purchase date of hardware:" << endl;
    cout << "Enter the date in this Format (Days/Months/Years):" << endl;
    cin >> addHardware.PURCHASE_DATE;
    cout << "Enter the Price Rs: " << endl;
    cin >> addHardware.PRICE;
    fout << left << setw(25) << addHardware.HARDWARE_NAME << setw(15) << addHardware.BRAND << setw(20) << addHardware.PURCHASE_DATE << setw(10) << addHardware.PRICE << endl; //displaying following headings in output file with spaces using setw().
    cout << "The hardware record Has Been Saved To The file Successfully!" << endl; //once the record has been saved, follwoing message is displayed over the screen.
    fout.close(); //closing the output file.
}
void searchHardware()
{
    Hardware searchHardware;

    cout << "Enter the Name of Hardware you want to search\n(Enter the first letter in capital letters):" << endl;
    cin >> searchHardware.SEARCH_HARDWARE;

    ifstream fin;
    fin.open("hardwarefile.txt");

    try
    {
        if (fin.fail())
        {
            throw runtime_error("File is not available");
        }
    }
    catch (runtime_error& e)
    {
        cout << "Error occurred\n" << e.what() << endl;
        exit(1);
    }

    bool found = false; // Variable to track if any matching hardware is found

    while (fin >> searchHardware.HARDWARE_NAME >> searchHardware.BRAND >> searchHardware.PURCHASE_DATE >> searchHardware.PRICE)
    {
        if (searchHardware.SEARCH_HARDWARE == searchHardware.HARDWARE_NAME)
        {
            found = true;
            cout << "This Hardware device is available" << endl;
            char choice;
            cout << "Enter 'Y' to show the record of this hardware device and 'N' to exit to the main menu:\n";
            cin >> choice;

            if (choice == 'y' || choice == 'Y')
            {
                cout << left << setw(25) << "HARDWARE_NAME" << setw(15) << "BRAND" << setw(20) << "PURCHASE_DATE" << setw(10) << "PRICE" << endl;
                cout << left << setw(25) << searchHardware.HARDWARE_NAME << setw(15) << searchHardware.BRAND << setw(20) << searchHardware.PURCHASE_DATE << setw(10) << searchHardware.PRICE << endl;
            }
            else if (choice == 'n' || choice == 'N')
            {
                cout << "You have selected 'N' to exit to the main menu!" << endl;
            }
        }
    }

    fin.close();

    if (!found)
    {
        cout << "Can't find such Hardware device!" << endl;
    }
}
void viewHardware() //Calling View function, As declared at the top.
{
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
    Hardware viewHardware;
    // declaring integer datatype with  variable to store integer value entered by the user.
    cout << left << setw(25) << "HARDWARE_NAME" << setw(15) << "BRAND" << setw(20) << "PURCHASE_DATE" << setw(10) << "PRICE" << endl; //headings displayed to the user.
    while (fin >> viewHardware.HARDWARE_NAME >> viewHardware.BRAND >> viewHardware.PURCHASE_DATE >> viewHardware.PRICE) //using while loop,getting input from the file under following variable names,until unless the data is present;checks for it.
    {
        {
            cout << left << setw(25) << viewHardware.HARDWARE_NAME << setw(15) << viewHardware.BRAND << setw(20) << viewHardware.PURCHASE_DATE << setw(10) << viewHardware.PRICE << endl; //data from file with spaces using setw() displayed under the assigned headings.
        }
    }
    fin.close(); //closing the input file.
}
void deleteHardware()
{
    ifstream fin("hardwarefile.txt");
    try
    {
        if (fin.fail())
        {
            throw runtime_error("File is not available");
        }
    }
    catch (runtime_error& e)
    {
        cout << "Error occurred\n" << e.what() << endl;
        exit(1);
    }
    ofstream fout;
    fout.open("tempfile.txt");

    Hardware deleteHardware;
    cout << "Enter the name of the hardware you want to delete\n(Enter the first letter in capital letters):" << endl;
    cin >> deleteHardware.SEARCH_HARDWARE;
    bool found = false;

    while (fin >> deleteHardware.HARDWARE_NAME >> deleteHardware.BRAND >> deleteHardware.PURCHASE_DATE >> deleteHardware.PRICE)
    {
        if (deleteHardware.SEARCH_HARDWARE == deleteHardware.HARDWARE_NAME)
        {
            found = true;
            cout << "Hardware record found and deleted Successfully!\n";
        }
        else
        {
            fout << left << setw(25) << deleteHardware.HARDWARE_NAME << setw(15) << deleteHardware.BRAND << setw(20) << deleteHardware.PURCHASE_DATE << setw(10) << deleteHardware.PRICE << endl;
        }
    }

    if (!found)
    {
        cout << "Cannot find such hardware device to delete record!\n";
    }

    fin.close();
    fout.close();

    remove("hardwarefile.txt");
    rename("tempfile.txt", "hardwarefile.txt");
}

void updateHardware() //Calling Update function, As declared at the top.
{
    Hardware updateHardware;

    ifstream fin("hardwarefile.txt"); //takes input from the file named, using file handling.
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
    ofstream fout; //using file handling, writing the output to a temporaray file.
    fout.open("tempfile.txt"); //output temporaray file created,with the folllowing name and opening it.
    cout << "Enter the name of the hardware you want to update\n(Enter the first letter in capital letters):" << endl; //shows on the user screen to enter the name of the hardware to update.
    cin >> updateHardware.SEARCH_HARDWARE; //takes input whatever the user has entered.
    while (fin >> updateHardware.HARDWARE_NAME >> updateHardware.BRAND >> updateHardware.PURCHASE_DATE >> updateHardware.PRICE) //using while loop,getting input from the file under following variable names,until unless the data is present;checks for it.
    {
        if (updateHardware.SEARCH_HARDWARE == updateHardware.HARDWARE_NAME) //applying control structure to check whether the written data is avaliable in the file or not? if it's present in file then,
        {
            cout << "Enter new hardware name: "; //asks to fill all the fields once again to update each field in the file.
            cin >> updateHardware.HARDWARE_NAME; //taking all the inputs from the user.
            cout << "Enter new Brand: ";
            cin >> updateHardware.BRAND;
            cout << "Enter new Purchase Date: ";
            cin >> updateHardware.PURCHASE_DATE;
            cout << "Enter new Price: ";
            cin >> updateHardware.PRICE;

            fout << updateHardware.HARDWARE_NAME << "\t\t" << updateHardware.BRAND << "\t\t" << updateHardware.PURCHASE_DATE << "\t\t" << updateHardware.PRICE << endl; //outputs(writes) all the data to output file with declared variables. New data that user updates is written to file.
            cout << "Hardware record has been updated Successfully!\n"; //after writing successfully displays the following message to user on screen.
        }
        else //if data is not found inside the file then the else statment executes the block of statements.
        {
            cout << "Cannot find such hardware device to update record!\n"; //displays that there is no such entry matching in the file to update.
            fout << updateHardware.HARDWARE_NAME << "\t\t" << updateHardware.BRAND << "\t\t" << updateHardware.PURCHASE_DATE << "\t\t" << updateHardware.PRICE << endl; //hence the old data(not updated) is again written to the file in same manner.
        }
    }
    fin.close(); //closes file from which data was input to significantly update specific data record.
    fout.close(); //closes the temporaray file, which has the written(updated) data to it.

    remove("hardwarefile.txt"); //removing the original file having all the data entries(un-updated).
    rename("tempfile.txt", "hardwarefile.txt"); //renaming the temporary file to the same named file as before it was originally created so that there is no difference in the file containing data; even after updating records.
}
