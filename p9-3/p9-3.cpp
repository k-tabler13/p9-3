#include <iostream>
#include <ctime>
using namespace std; 
// Function to simulate 20 random die rolls and store them in an array
void generateDieRolls(int values[], int size) {
    for (int i = 0; i < size; ++i) {
        values[i] = rand() % 6 + 1;  // Random number between 1 and 6
    }
}

// Function to display the die rolls and encapsulate the runs in parentheses.
void displayRun(int values[], int size) {
    int i = 0;

    // Iterate over the die values and print them
    while (i < size) {
        int j = i;
        // If there's a run, find the extent of the run
        while (j < size && values[j] == values[i]) {
            ++j;
        }

        // If run is found, display it in parentheses
        if (j - i > 1) {
           cout << "(";
            for (int k = i; k < j; ++k) {
                cout << values[k];
                if (k < j - 1) {
                   cout << " "; 
                }
            }
            cout << ")";
            i = j;  
        }
        else {
            
          cout << values[i];
            ++i;
        }

       
        if (i < size) {
            cout << " ";
        }
    }
    cout << endl; 
}

int main() {
    const int SIZE = 20;  // Total number of die rolls
    int dieRolls[SIZE];

    // Seed the random number generator
    srand(time(0));

    // Generate the die rolls
    generateDieRolls(dieRolls, SIZE);

    // Display the die rolls with runs marked
    displayRun(dieRolls, SIZE);

    return 0;
}