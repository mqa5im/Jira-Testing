#include <iostream>
using namespace std;

int main() {
    const int n = 4; 
    int AT[n]; 
    int BT[n]; 
    int WT[n] = {0};
    int TT[n] = {0}; 
    int remainingBT[n]; 
    int timeQuantum;
    float ATT = 0, AWT = 0;

    cout << "\nROUND ROBIN SCHEDULING ALGORITHM." << endl;

    cout << "* ARRIVAL TIME *" << endl;
    cout << "Enter the arrival time of 4 processes: " << endl;
    for (int index = 0; index < n; index++) {
        cout << "P[" << index << "]: ";
        cin >> AT[index];
    }

    cout << "* BURST TIME *" << endl;
    cout << "Enter the burst time of 4 processes: " << endl;
    for (int index = 0; index < n; index++) {
        cout << "P[" << index << "]: ";
        cin >> BT[index];
        remainingBT[index] = BT[index]; 
    }

    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    int time = 0; 
    bool done;
    int count = 0; 

    do {
        done = true;
        for (int index = 0; index < n; index++) {
            if (remainingBT[index] > 0 && AT[index] <= time) {
                done = false; 
                if (remainingBT[index] > timeQuantum) {
                    time += timeQuantum;
                    remainingBT[index] -= timeQuantum;
                } else {
                    time += remainingBT[index];
                    WT[index] = time - BT[index] - AT[index];
                    remainingBT[index] = 0;
                    count++;
                }
            }
        }
        if (count < n) {
            time++;
        }
    } while (!done);

    for (int index = 0; index < n; index++) {
        TT[index] = BT[index] + WT[index];
    }

    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (int index = 0; index < n; index++) {
        cout << "P[" << index << "]\t" << AT[index] << "\t\t" << BT[index] << "\t\t" << WT[index] << "\t\t" << TT[index] << endl;
        AWT += WT[index];
        ATT += TT[index];
    }

    cout << "Average Waiting Time: " << AWT / n << endl;
    cout << "Average Turnaround Time: " << ATT / n << endl;

    return 0;
}
