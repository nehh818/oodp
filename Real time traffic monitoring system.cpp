#include <iostream>

using namespace std;

// Function to find the busiest zone using pointers
int findBusiestZone(int **trafficData, int zones, int intervals) {
    int maxVehicles = 0;
    int busiestZone = 0;

    for (int i = 0; i < zones; i++) {
        int totalVehicles = 0;
        for (int j = 0; j < intervals; j++) {
            totalVehicles += *(*(trafficData + i) + j); // Using pointer notation
        }
        if (totalVehicles > maxVehicles) {
            maxVehicles = totalVehicles;
            busiestZone = i;
        }
    }
    return busiestZone;
}

int main() {
    int N, M;
    cout << "Enter the number of zones: ";
    cin >> N;
    cout << "Enter the number of time intervals: ";
    cin >> M;

    // Dynamically allocate memory for 2D array
    int **trafficData = new int*[N];
    for (int i = 0; i < N; i++) {
        trafficData[i] = new int[M];
    }

    // Input traffic data
    cout << "Enter the traffic data (vehicles per interval):\n";
    for (int i = 0; i < N; i++) {
        cout << "Zone " << i + 1 << ": ";
        for (int j = 0; j < M; j++) {
            cin >> *(*(trafficData + i) + j); // Pointer notation
        }
    }

    // Find the busiest zone
    int busiestZone = findBusiestZone(trafficData, N, M);
    cout << "The busiest zone is Zone " << busiestZone + 1 << " with the highest traffic." << endl;

    // Free dynamically allocated memory
    for (int i = 0; i < N; i++) {
        delete[] trafficData[i];
    }
    delete[] trafficData;

    return 0;
}