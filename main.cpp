//This is a program to help display a dissect a study commissioned by the Oregon
//Department of Education to look at differences of scores from males and females
//as well as from community colleges vs Universities. It will ask the user to specify
//a specific path to the plain text document were the data is recored.
//Created: By Thomas Chase
//Created on: October 25,2019
//Sources: None

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    //Decelerations
    string reply;
    string line;
    string name;
    string inputFileName;
    ifstream inputFile;
    char gender;
    string school;
    int score;
    double mScore = 0;
    double fScore = 0;
    double ccScore = 0;
    double unScore = 0;
    int mTotal = 0;
    int fTotal = 0;
    int ccTotal = 0;
    int unTotal = 0;
    double tScore = 0;
    int total = 0;

    //Asking the user to input the file name/path
    cout << "Please input the full path name for intended file: ";
    getline(cin,inputFileName);

    //Opening the file if the given path is correct.
    inputFile.open(inputFileName.c_str());

    //The fallowing can be used for debug purposes only to prevent repeated need to enter path name. Enter your path name to use
    //inputFile.open("C:\\Users\\Thomas Chase\\Desktop\\scores.txt");

    //Check if file exists, if not exiting with appropriate error message.
    if ( ! inputFile.is_open()){
        cout << "Unable to open file." << endl;
        cout << "Please press enter to continue..." << endl;
        getline(cin,reply);
        return(1);
    }

    //If file is open, this will echo what is in the file to the user
    while (inputFile.peek() != EOF){  //Echo out the file to the user
        getline(inputFile,line);
        cout << line << endl;
    }

    cout << "\nEnd of file reached\n" <<endl;

    //Clear EOF flag and rewind file to byte 0.
    inputFile.clear();
    inputFile.seekg(0);

    //Collecting data from the file to give required info
    while (inputFile.peek() != EOF){
        inputFile >> name;
        total++;
        inputFile >> gender;
        inputFile >> school;
        inputFile >> score;
        if (gender == 'M'){
            mTotal++;
            mScore=score+mScore;
        }
        if (gender == 'F'){
            fTotal++;
            fScore=score+fScore;
        }
        if (school == "CC"){
            ccTotal++;
            ccScore=score+ccScore;
        }
        if (school == "UN"){
            unTotal++;
            unScore=score+unScore;
        }
        if (score >= 0){
            tScore=score+tScore;
        }
    }
    // Output the information to the user
    cout << fixed << showpoint << setprecision(2);
    cout << "The average for the male students in the survey is: %" << mScore/mTotal << endl;
    cout << "The average for the female students in the survey is: %" << fScore/fTotal << endl;
    cout << "The average score for students attending Community College is: %" << ccScore/ccTotal << endl;
    cout << "The average score for students attending University is: %" << unScore/unTotal << endl;
    cout << "The overall average for all students in the survey is; %" << tScore/total << endl;

    // Closing the stream
    inputFile.close();
    cout << "Thank your view the student survey. Please press enter to exit...";
    getline(cin, reply);
    return(0);

}
