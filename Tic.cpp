#include<iostream>
#include<string>
 using namespace std;

 int main()
 {
    int space[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    string n1;
    string n2;
    cout<<"Enter the name of the first player : \n";
    getline(cin,n1);
    cout<<"Enter the name of the second player : \n";
    getline(cin,n2);
    cout<<n1<< "is player1 so he/she will play first \n";
    cout<<n2<< "is player2 so he/she will play second \n";


    
    
    cout<<"  |       | \n";
    cout<<" "<<space[0][0]<<"| "<<space[0][1]<<"    | "<<space[0][2]<<" \n";
    cout<<"__|_______|__ \n";
    cout<<"  |       | \n";
    cout<<" "<<space[1][0]<<"| "<<space[1][1]<<"    | "<<space[1][2]<<" \n";
    cout<<"__|_______|__ \n";
    cout<<"  |       | \n";
    cout<<" "<<space[2][0]<<" | "<<space[2][1]<<"   | "<<space[2][2]<<" \n";
    cout<<"  |       | \n";
   

 }