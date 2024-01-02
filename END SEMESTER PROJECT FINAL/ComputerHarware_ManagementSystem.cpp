#include <iostream> //Header file to provide various functions related to input/output stream.
#include <fstream> //Header file to include file handling operations in a program.
#include<string>  //Header file to include one variable type,one macro and many functions which can be used to mainupulate the string of arrays.
#include<iomanip> //Header file to include part of input/output library of C++ standard library such as setw() etc.
#include"Purchase_record.h"
#include"Workstation.h"
#include"Department.h"

using namespace std; //Used for using names for objects and variables from standard library.
void add_department();
void addHardware(); //Declaring function to 'add Hardware' in program as per requirement.
void viewHardware(); //Declaring function to 'view Hardware' in program as per requirement.
void updateHardware(); //Declaring function to 'update Hardware' in program as per requirement.
void deleteHardware(); //Declaring function to 'delete Hardware' in program as per requirement.
void searchHardware(); //Declaring function to 'search Hardware' in program as per requirement.
void menu(); //Declaring function to 'add menu' in program as per requirement.



void addWorkstation(); //Declaring function to 'add WorkStation' in program as per requirement.
void viewWorkstation(); //Declaring function to 'view Workstation' in program as per requirement.
void searchWorkstation(); //Declaring function to 'search Workstation' in program as per requirement.
void updateWorkstation(); //Declaring function to 'update Workstation' in program as per requirement.
void deleteWorkstation(); //Declaring function to 'delete Workstation' in program as per requirement.

void add_department();
void view_department();

int main() //Declaration of main function that should return an integer value.
{
    while (true) //Application of 'while' loop and test condition checks whether it's (true) or not.
    {

        menu(); //Only displays the menu if the test condition is true.
    }
}
//Calling Menu function, As declared at the top.
void menu() //Calling Menu function, As declared at the top.
{

    cout << "COMPUTER HARDWARE MANAGEMENT SYSTEM \n    WELCOME TO THE MAIN MENU\n";    //Ouputs the Main Title of the program.
    cout << "             *\n";                       //Spacing.
    cout << "             *\n";                       //Spacing.

    int choice;
    cout << "Please Select Your Desired Category\n             *\n1:Component Purchase Record\n2:WorkStation Record\n3:Department Record\n4.EXIT\n" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "    COMPONENETS MENU\n";                             //Displays title MENU.
        cout << " 1.VIEW Hardware\n 2.ADD Hardware\n 3.UPDATE Hardware\n 4.DELETE Hardware\n 5.SEARCH Hardware\n 6.EXIT\n"; //Displays options to be furthur determined.
        int option; //Declaring integer (option) to select out of given structure.
        cin >> option; //Taking option input by user.
        switch (option) //Applying Decision Structure to check for the selected option by the user.
        {
        case 1: //if option no 1 is selected.
            cout << "calling VIEW hardware function!\n"; //displays the following line to user.
            viewHardware(); //calling the required function.
            break; //ends if it's selected, dosen't display other statments directed by options.

        case 2: //if option no 2 is selected.
            cout << "calling ADD hardware function!\n"; //displays the following line to user.
            addHardware(); //calling the required function.
            break; //ends if it's selected, dosen't display other statments directed by options.

        case 3: //if option no 3 is selected.
            cout << "calling UPDATE hardware function!\n"; //displays the following line to user.
            updateHardware(); //calling the required function.
            break; //ends if it's selected, dosen't display other statments directed by options.

        case 4: //if option no 4 is selected.
            cout << "calling DELETE hardware function!\n"; //displays the following line to user.
            deleteHardware(); //calling the required function.
            break; //ends if it's selected, dosen't display other statments directed by options.

        case 5: //if option no 5 is selected.
            cout << "calling SEARCH hardware function!\n"; //displays the following line to user.
            searchHardware(); //calling the required function.
            break; //ends if it's selected, dosen't display other statments directed by options.

        case 6: //if option no 6 is selected.
            cout << "COMPONENTS\nPROGRAM EXITS HERE! AS PER YOUR REQUEST.\nThank You!\n"; //displays the following line to user.
            exit(0); //exits the program if user selects this option.

        default: //if anything other than given option is pressed so.
            cout << "Invalid Option Selected!\n "; //following displays on screen.
            break; //loop terminates infinitely.
        }
        break; //ends if it's selected, dosen't display other statments directed by Option.
    case 2:
        cout << "    WORKSTATION MENU\n";                             //Displays title MENU.
        cout << " 1.VIEW WorkStation\n 2.ADD WorkStation\n 3.UPDATE WorkStation\n 4.SEARCH WorkStation\n 5.DELETE WorkStation\n 6.EXIT\n";
        int WorkStation; //Declaring integer (WorkStation) to select out of given structure.
        cin >> WorkStation; //Taking option input by user.
        switch (WorkStation) //Applying Decision Structure to check for the selected option by the user.
        {
        case 1: //if option no 1 is selected.
            cout << "calling VIEW WorkStation function!\n"; //displays the following line to user.
            viewWorkstation(); //calling the required function.
            break; //ends if it's selected, dosen't display other statments directed by WorkStation.
        case 2: //if option no 2 is selected.
            cout << "calling ADD WorkStation function!\n"; //displays the following line to user.
            addWorkstation();                              //calling the required function.
            break; //ends if it's selected, dosen't display other statments directed by WorkStation.
        case 3: //if option no 3 is selected.
            cout << "calling UPDATE WorkStation function!\n"; //displays the following line to user.
            updateWorkstation();//calling the required function.
            break; //ends if it's selected, dosen't display other statments directed by WorkStation.
        case 4: //if option no 4 is selected.
            cout << "calling Serach WorkStation function!\n"; //displays the following line to user.
            searchWorkstation();//calling the required function.
            break; //ends if it's selected, dosen't display other statments directed by WorkStation.
        case 5: //if option no 5 is selected.
            cout << "calling Delete WorkStation function!\n"; //displays the following line to user.
            deleteWorkstation();//calling the required function.
            break;
        case 6: //if option no 6 is selected.
            cout << "WORKSTATION\nPROGRAM EXITS HERE! AS PER YOUR REQUEST.\nThank You!\n"; //displays the following line to user.
            exit(0); //exits the program if user selects this option.
            break;
        default: //if anything other than given option is pressed so.
            cout << "Invalid Option Selected!\n "; //following displays on screen.
            break; //loop terminates infinitely.
        }
        break; //ends if it's selected, dosen't display other statments directed by WorkStation.
    case 3:
        cout << "DEPARTMENT MENU\n";
        cout << " 1.ADD DEPARTMENT\n 2.VIEW DEPARTMENT\n 3.EXIT\n";
        int Department_Name;
        cin >> Department_Name;
        switch (Department_Name)
        {
        case 1:
            cout << "Calling ADD Department function!\n";
            add_department();
            break;
        case 2:
            cout << "calling VIEW WorkStation function!\n";
            view_department();
            break;
        case 3:
            cout << "DEPARTMENT\nPROGRAM EXITS HERE! AS PER YOUR REQUEST.\nThank You!\n";
            exit(0);
            break;
        default:
            cout << "Invalid Option Selected!\n ";
            break;
        }
        break;
    case 4:
        cout << "COMPUTER HARWARE MANAGEMENT SYSTEM\nPROGRAM EXITS HERE! AS PER YOUR REQUEST.\nThank You!\n"; //displays the following line to user.
        exit(0); //exits the program if user selects this WorkStation.
        break;
    default: //if anything other than given option is pressed so.
        cout << "Invalid Option Selected!\n "; //following displays on screen.
        break; //loop terminates infinitely.
    }
