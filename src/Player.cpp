#include "Player.h"

using namespace std;

int Player::rollDice() {
    srand(time(NULL));
    return rand() % 6 + 1;
}

void Player::setName(string name) {
    this->name = name;
}

string Player::getName() {
    return name;
}

void Player::setPiece(char piece) {
    this->piece = piece;
}

char Player::getPiece() {
    return piece;
}

void Player::setNumber(int number) {
    this->number = number;
}

int Player::getNumber() {
    return number;
}

string Player::getColour() {
    string colour = "\e[48;5;";
    switch (number) {
        case 1:
            colour.append("160");
        case 2:
            colour.append("202");
        case 3:
            colour.append("220");
        case 4:
            colour.append("112");
        case 5:
            colour.append("80");
        case 6:
            colour.append("38");
        case 7:
            colour.append("55");
        default:
            colour.append("15");
    }
    colour.append("m");
    return colour;
}

void Player::roll() {
    rollingTime--;
    int firstDice, secondDice, sum;
    firstDice = rollDice();
    secondDice = rollDice();
    sum = firstDice + secondDice;

    cout << name << " rolled " << firstDice << " and " << secondDice << ", the total is " << sum << "." << endl;
    if (doubleCount == 3){
        cout << "Three Doubles! " << name << " goes to Tim Hortons Line" << endl;
    }
    if (firstDice == secondDice) {
        rollingTime++;
        doubleCount++;
        cout << "Doubles! " << name << " can roll again." << endl;
    }
}

void Player::next() {
    if (rollingTime != 0) {
        cout << name << " still has " << rollingTime << (rollingTime > 1? " chances ": " chance ") << "to roll." << endl;
    } else if (cash < 0) {
        cout << name << " doesn't have enough cash to continue the game." << endl;
    }
}
