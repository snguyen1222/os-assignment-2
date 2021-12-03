/*
Name: Steven Nguyen
File: OS Programming Assingment #2
Email: snguyen@kent.edu
Date: 12/2/2021
Partial code adapted from: SHUBHAMSINGH10 (2021) "Banker’s Algorithm in Operating System" [source code] https://www.geeksforgeeks.org/bankers-algorithm-in-operating-system-2/.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    const int row = 5, col = 3;
    string file = "matrix.txt";
    ifstream infile;
    infile.open(file);

    string line = "";
    string temp = "";

    int linenum = 0;
    int alloc[row][col];// Allocation Matrix
    int max[row][col]; // Max Matrix
    int avail[3]; // Avaiable Resources

    if (infile.is_open()) {
        int k = 0;
        int j = 0;
        while (getline(infile, line)) {
            j = 0; // reset num iteration to the left
            for (int i = 0; i < line.length(); i++) {
                temp = line[i];
                // stores first row in alloc 010200302211002
                if (linenum == 0) {
                    alloc[k][j] = stoi(temp);
                    temp = "";
                    j++;
                }
                // store second row in max 753322902222433
                else if (linenum == 1) {
                    max[k][j] = stoi(temp);
                    temp = "";
                    j++;
                }
                // stores third row in avail 332
                else {
                    avail[j] = stoi(temp);
                    temp = "";
                    j++;
                }
            }
            linenum++; // go to next row
        }
    }
    int f[row], ans[row], ind = 0;
    for (int k = 0; k < row; k++) {
        f[k] = 0;
    }
    int need[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            need[i][j] = max[i][j] - alloc[i][j]; // find need by subtracting max and allocation matrices
    }
    int y = 0;
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < row; i++) {
            if (f[i] == 0) {

                int flag = 0;
                for (int j = 0; j < col; j++) {
                    if (need[i][j] > avail[j]) { // compare need vs new available
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < col; y++) {
                        avail[y] += alloc[i][y]; // detect and determine the safe sequence by adding the available and allocation matrices
                    }
                    f[i] = 1;
                }
            }
        }
    }
    //  P1 -> P3 -> P4 -> P0 -> P2 result
    cout << "Following is the SAFE Sequence" << endl;
    for (int i = 0; i < row - 1; i++)
        cout << " P" << ans[i] << " ->";
    cout << " P" << ans[row - 1] << endl;

    return (0);
}