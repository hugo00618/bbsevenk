#include "MyInfoBoard.h"

MyInfoBoard::MyInfoBoard(int width, int height): width(width), height(height) {
    
}

void MyInfoBoard::separatePush(string s) {
    stringstream ss(s);
    string line, word;
    
    while (ss >> word) {
        if (line.length() + word.length() > width - 1) {
            push(line);
            line = "    " + word;
        } else {
            line = " " + word;
        }
    }
}

void MyInfoBoard::push(string s) {
    if (s.length() > width) {
        separatePush(s);
    } else {
        if (infoBoard.end() - infoBoard.begin() >= height) {
            for (vector<string>::iterator it = infoBoard.begin() + 1; it != infoBoard.end(); it++) {
                *(it-1) = *it;
            }
        }
        *(infoBoard.end() - 1) = s;
    }
}

vector<string> &MyInfoBoard::getInfoBoard() {
    return infoBoard;
}


