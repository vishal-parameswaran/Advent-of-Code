#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int returnSum(vector<int> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}

vector<int> extractDigits(vector<std::string> arr)
{
    vector<int> vecDigits;
    for (int i = 0; i < arr.size(); i++)
    {

        string extractedDigits = "";

        for (int j = 0; j < arr[i].length(); j++)
        {

            if (isdigit(arr[i][j]))
            {
                extractedDigits = extractedDigits + arr[i][j];
            }
        }

        string selected_digits = "";

        if (extractedDigits.length() > 1)
        {
            selected_digits = std::string() + extractedDigits[0] + extractedDigits[extractedDigits.length() - 1];
        }
        else if (extractedDigits.length() == 1)
        {
            selected_digits = std::string() + extractedDigits[0] + extractedDigits[0];
        }
        else
        {
            selected_digits = "";
        }
        int intDigits = std::stoi(selected_digits);
        vecDigits.push_back(intDigits);
    }

    return vecDigits;
}

vector<std::string> setupInput()
{
    vector<std::string> arr;
    fstream calibrationDocument;
    calibrationDocument.open("day1.txt", ios::in);
    if (calibrationDocument.is_open()) { 
        string calibrationString;
        while (getline(calibrationDocument, calibrationString)) { 
            arr.push_back(calibrationString);
        }
    }
    return arr;
}

int main()
{
    vector<std::string> arr = setupInput();
    vector<int> vecDigits = extractDigits(arr);
    int sum = returnSum(vecDigits);
    cout << sum << endl;
    return 1;
}