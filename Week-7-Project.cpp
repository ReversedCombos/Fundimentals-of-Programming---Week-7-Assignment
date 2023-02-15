#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//Does error checking for the fileName - If they are any of those characters then the file wont be made
bool StringErrorCheck(string fileName)
{
    int fileNameLen = fileName.length();

    for (int i = 0; i <= fileNameLen; i++) 
    {
        if (fileName[i] == '*' || fileName[i] == '.' || fileName[i] == '"' || fileName[i] == '/' || fileName[i] == '\\' || fileName[i] == ' [ ' || fileName[i] == ']' || fileName[i] == ':' || fileName[i] == ';' || fileName[i] == '|' || fileName[i] == ',')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //Varables
    string fileName;
    double subTotal;
    double tipAmount;
    double taxRate;
    double total;
    int numInParty;

    //Setting up the outFile refrence
    ofstream outFile;

    while (true)
    {
        //Prompting the filename;
        cout << "Input File Name : ";

        //Outputting the input of the entire line into the fileName variable
        getline(cin, fileName);

        if (StringErrorCheck(fileName))
        {
            break;
        }
        cout << "Please try again without (*) (.) (\") (/) (\\) ({) (}) (:) (;) (|) (,) \n";
    }
    
    //Opening the file with the fileName
    outFile.open(fileName);
    
    while(true)
    {
        cout << "Enter the check amount : ";
        cin >> subTotal;
        cout << endl;
        
        cout << "Enter the tip amount : ";
        cin >> tipAmount;
        cout << endl;
        
        cout << "Enter the tax rate : ";
        cin >> taxRate;
        cout << endl;
        
        cout << "Enter the number of people in your party : ";
        cin >> numInParty;
        cout << endl;
        
        if(numInParty == 0)
        {
            cout << "Make sure to enter the correct values" << endl;
            cin.clear();
            cin.ignore(200, '\n');
        }
        else
        {
            break;
        }
    }
    
    total = subTotal + (subTotal * taxRate);
    
    outFile << "Receipt : " << endl << endl;
    outFile << "Subtotal : " << subTotal << endl;
    outFile << "Tax Rate : " << taxRate << endl;
    outFile << "Total : " << total << endl;
    outFile << "Tip Amount : " << tipAmount << endl;
    outFile << "Number of people in party : " << numInParty << endl;
    outFile << "Recommended split of check : " << total / numInParty << endl;
    outFile << "Recommended split of tip : " << tipAmount / numInParty;
}
