// Test driver with instructions for filling in specific
//  information
#include <iostream>
#include <fstream>
#include <string>
#include "AUList.h"

// Testing driver for AUList class. Note:Assuming ItemType is defined as int in ItemType.h.

// #include file containing class to be tested
int main()
{
    using namespace std;
    ifstream inFile;     // file containing operations
    ofstream outFile;    // file containing output
    string inFileName;   // input file external name
    string outFileName;  // output file external name
    string outputLabel;
    string command;    // operation to be executed
    int numCommands;

	AUList auList;

    // Declare a variable of the type being tested
    // Prompt for file names, read file names, and prepare files
    cout << "Enter name of input file; press return." << endl;
    cin >> inFileName;
    inFile.open(inFileName.c_str());

    cout << "Enter name of output file; press return." << endl;
    cin >> outFileName;
    outFile.open(outFileName.c_str());

    cout << "Enter name of test run; press return." << endl;
    cin >> outputLabel;
    outFile << outputLabel << endl;

    inFile >> command;
    numCommands = 0;
    while (command != "Quit")
    {

        // The following should be specific to structure being tested
        // Execute the command by invoking the member function of the
        //   same name
        // Print the results to the output file
        // The default option on the branching statement should be for
        // misspelled commands

        if (command == "isEmpty")
        {
            if (auList.isEmpty())
                outFile << "List is empty.\n";
            else
                outFile << "List is not empty.\n";
        }
        else if(command == "isFull")
        {
            if (auList.isFull())
                outFile << "List is full.\n";
            else
                outFile << "List is not full.\n";
        }
        else if(command == "getLength")
        {
            outFile << "List length: " << auList.getLength() << "\n";
        }
        else if(command == "Insert")
        {
            int value;
            inFile >> value;
            ItemType item;
            item.Initialize(value);
            if (auList.Insert(item))
                outFile << "Inserted " << value << " into the list.\n";
            else
                outFile << "Failed to insert " << value << "; list may be full.\n";
        }
        else if(command == "Remove")
        {
            int value;
            inFile >> value;
            ItemType item;
            item.Initialize(value);
            if (auList.Remove(item))
                outFile << "Removed " << value << " from the list.\n";
            else
                outFile << value << " not found in the list.\n";
        }
        else if(command == "GetItem")
        {
            int value;
            inFile >> value;
            ItemType item;
            item.Initialize(value);
            bool found;
            ItemType result = auList.GetItem(item, found);
            if (found)
            {
                outFile << "Found item: ";
                result.Print(outFile);
                outFile << "\n";
            }
            else
            {
                outFile << value << " not found in the list.\n";
            }
        }
        else if(command == "EmptyList")
        {
            auList.EmptyList();
            outFile << "List emptied.\n";
        }
        else if(command == "GetNextItem")
        {
            ItemType item = auList.GetNextItem();
            outFile << "Next item: ";
            item.Print(outFile);
            outFile << "\n";
        }
        else if(command == "ResetList")
        {
            auList.ResetList();
            outFile << "List reset.\n";
        }
        else if(command == "PrintList")
        {
            outFile << "List contents: ";
            auList.PrintList(outFile);
            outFile << "\n";
		}
        else
        {
            outFile << "Unknown command: " << command << "\n";
		}

        numCommands++;
        cout << "Command number " << numCommands << " completed."
            << endl;
        inFile >> command;
    }

    cout << "Testing completed." << endl;
    inFile.close();
    outFile.close();
    return 0;
}

