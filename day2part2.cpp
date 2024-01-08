#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
using namespace std;

struct ballCount{
    int red;
    int green;
    int blue;
};


std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

ballCount countBalls(std::vector<std::string> arr){
    ballCount ballCount;
    ballCount.red = 0;
    ballCount.green = 0;
    ballCount.blue = 0;
    
    for (int i = 0; i < arr.size(); i++){
        std::smatch color_match;
        std::regex_search(arr[i], color_match, std::regex("[^\\d ]"));
        string color = color_match[0];
        std::regex_search(arr[i], color_match, std::regex("\\d+"));
        string digit = color_match[0];
        int digitInt = stoi(digit);
        switch (color[0])
        {
        case 'r':
            if (digitInt > ballCount.red)
                ballCount.red = digitInt;
            break;
        case 'g':
            if (digitInt > ballCount.green)
                ballCount.green = digitInt;
            break;
        case 'b':
            if (digitInt > ballCount.blue)
                ballCount.blue = digitInt;
            break;
        default:
            break;
        }
    }
    return ballCount;
}

int parseSSV(string ssv){
    string ssvDelimiter = ";";
    string colonDelimiter = ":";
    string cubeDelimiter = ",";
    // split by colon
    std::vector<std::string> gameNumberSplit = split (ssv, colonDelimiter);
    // process game number
    string gameNumber = gameNumberSplit[0];
    // split by semicolon
    string gameData = gameNumberSplit[1];
    std::vector<std::string> gameDataSplit = split (gameData, ssvDelimiter);
    ballCount masterBall;
    masterBall.red = 0;
    masterBall.green = 0;
    masterBall.blue = 0;
    for (int i = 0; i<gameDataSplit.size(); i++){
        // split by comma
        std::vector<std::string> cubeDataSplit = split (gameDataSplit[i], cubeDelimiter);
        ballCount sperBall = countBalls(cubeDataSplit);
        if (sperBall.red > masterBall.red)
            masterBall.red = sperBall.red;
        if (sperBall.green > masterBall.green)
            masterBall.green = sperBall.green;
        if (sperBall.blue > masterBall.blue)
            masterBall.blue = sperBall.blue;
    }
    return masterBall.red * masterBall.green * masterBall.blue;
}

int setupInput()
{
    fstream calibrationDocument;
    calibrationDocument.open("day2.txt", ios::in);
    int sum = 0;
    if (calibrationDocument.is_open()) { 
        string calibrationString;
        while (getline(calibrationDocument, calibrationString)) {
            int value =  parseSSV(calibrationString);
            sum += value;
        }
    }
    return sum;
}

int main(){
    int total = setupInput();
    cout << total << endl;
    return 1;
}