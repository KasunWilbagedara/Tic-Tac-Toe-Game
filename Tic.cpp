#include<iostream>
#include<string>
using namespace std;

char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token = 'x';
bool isTie = false;
string n1 = "";
string n2 = "";

void functionOne() {
    cout << "\n";
    cout << "   |       |   \n";
    cout << " " << space[0][0] << " |   " << space[0][1] << "   | " << space[0][2] << " \n";
    cout << "___|_______|___\n";
    cout << "   |       |   \n";
    cout << " " << space[1][0] << " |   " << space[1][1] << "   | " << space[1][2] << " \n";
    cout << "___|_______|___\n";
    cout << "   |       |   \n";
    cout << " " << space[2][0] << " |   " << space[2][1] << "   | " << space[2][2] << " \n";
    cout << "   |       |   \n";
}

void functionTwo() {
    int digit;
    
    if(token == 'x') {
        cout << n1 << " please enter: ";
        cin >> digit;
    }
    else if(token == '0') {
        cout << n2 << " please enter: ";
        cin >> digit;
    }

    if(digit == 1) { row = 0; column = 0; }
    else if(digit == 2) { row = 0; column = 1; }
    else if(digit == 3) { row = 0; column = 2; }
    else if(digit == 4) { row = 1; column = 0; }
    else if(digit == 5) { row = 1; column = 1; }
    else if(digit == 6) { row = 1; column = 2; }
    else if(digit == 7) { row = 2; column = 0; }
    else if(digit == 8) { row = 2; column = 1; }
    else if(digit == 9) { row = 2; column = 2; }
    else {
        cout << "Invalid input! Please enter a number between 1 and 9" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        functionTwo();
        return;
    }

    if(space[row][column] != 'x' && space[row][column] != '0') {
        space[row][column] = token;
        token = (token == 'x') ? '0' : 'x';
    }
    else {
        cout << "That space is already taken!" << endl;
        functionTwo();
    }
}

bool functionThree() {
    for(int i = 0; i < 3; i++) {
        if((space[i][0] == space[i][1] && space[i][1] == space[i][2]) ||
           (space[0][i] == space[1][i] && space[1][i] == space[2][i]))
            return true;
    }

    if((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
       (space[0][2] == space[1][1] && space[1][1] == space[2][0]))
        return true;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(space[i][j] != 'x' && space[i][j] != '0')
                return false;
        }
    }
    
    isTie = true;
    return false;
}

int main() {
    cout << "Enter the name of the first player: ";
    getline(cin, n1);
    cout << "Enter the name of the second player: ";
    getline(cin, n2);
    cout << n1 << " is player1 (x) so he/she will play first\n";
    cout << n2 << " is player2 (0) so he/she will play second\n";

    functionOne();
    
    while(!functionThree()) {
        functionTwo();
        functionOne();
    }

    functionOne();
    
    if(isTie) {
        cout << "\nGame Over! It's a draw!" << endl;
    }
    else if(token == 'x') {
        cout << "\nGame Over! " << n2 << " (0) Wins!" << endl;
    }
    else {
        cout << "\nGame Over! " << n1 << " (x) Wins!" << endl;
    }

    cout << "\nPress Enter to exit...";
    cin.clear();             
    cin.ignore(10000, '\n');  
    cin.get();                

    return 0;
}