#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <set>
using namespace std;

std::set<char> charSet = {'o', 't', 'f', 's', 'e', 'n', 'z'};

int extractDigits(string calibrationString)
{
    vector<int> vecDigits;
    string window = "";

    for (int i = 0; i < calibrationString.length(); i++)
    {
        bool found = (std::find(charSet.begin(), charSet.end(), calibrationString[i]) != charSet.end());
        if(found == 1){
            switch (calibrationString[i])
            {
            case 'o':
                window = calibrationString.substr(i, 3);
                if(window == "one"){
                    vecDigits.push_back(1);
                }
                break;
            case 't':
                window = calibrationString.substr(i, 3);
                if(window == "two"){
                    vecDigits.push_back(2);
                }
                window = calibrationString.substr(i, 5);
                if(window == "three"){
                    vecDigits.push_back(3);
                }
                break;
            case 'f':
                window = calibrationString.substr(i, 4);
                if(window == "four"){
                    vecDigits.push_back(4);
                }
                else if(window == "five"){
                    vecDigits.push_back(5);
                }
                break;
            case 's':
                window = calibrationString.substr(i, 3);
                if(window == "six"){
                    vecDigits.push_back(6);
                }
                window = calibrationString.substr(i, 5);
                if(window == "seven"){
                    vecDigits.push_back(7);
                }
                break;
            case 'e':
                window = calibrationString.substr(i, 5);
                if(window == "eight"){
                    vecDigits.push_back(8);
                }
                break;
            case 'n':
                window = calibrationString.substr(i, 4);
                if(window == "nine"){
                    vecDigits.push_back(9);
                }
                break;
            case 'z':
                window = calibrationString.substr(i, 4);
                if(window == "zero"){
                    vecDigits.push_back(0);
                }
                break;
            default:
                break;
            }
        }
        if (isdigit(calibrationString[i]))
        {
            vecDigits.push_back(calibrationString[i] - '0');
        }
    }

    string extractedDigits = "";
    string extractDigits = std::to_string(vecDigits[0]) + std::to_string(vecDigits[vecDigits.size() - 1]);
    int intDigits = std::stoi(extractDigits);
    return intDigits;
}

int setupInput()
{
    fstream calibrationDocument;
    calibrationDocument.open("day1.txt", ios::in);
    int sum = 0;
    if (calibrationDocument.is_open()) { 
        string calibrationString;
        while (getline(calibrationDocument, calibrationString)) {
            int value =  extractDigits(calibrationString);
            sum += extractDigits(calibrationString);
        }
    }
    return sum;
}

int main()
{
    int total = setupInput();
    cout << total << endl;
    return 1;
}