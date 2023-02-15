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

bool inputCheck(int input)
{
    if(isdigit(input) != 0)
    {
        return false;
    }
    return true;
}

int main()
{
    //Varables
    string fileName;
    double checkAmount;
    double tipAmount;
    double taxRate;
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
}
