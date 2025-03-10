#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Employee {
    string id;
    double qSales[4] = {};
    double totalSales = 0;
};

void loadData(Employee x[], int size, ifstream& saleData, ifstream& idData) {
    string tempID;
    double sales;
    int month;

    for (int i = 0; i < size; i++) {
        idData >> x[i].id;
    }

    while (saleData >> tempID >> month >> sales) {
        for (int i = 0; i < size; i++) {
            if (tempID == x[i].id) {
                if (month <= 3) {
                    x[i].qSales[0] += sales;
                }
                else if (month <= 6) {
                    x[i].qSales[1] += sales;
                }
                else if (month <= 9) {
                    x[i].qSales[2] += sales;
                }
                else if (month <= 12) {
                    x[i].qSales[3] += sales;
                }
                x[i].totalSales += sales;
            }
        }
    }
}

int main() {
    Employee workers[6];
    ifstream mySales("info.txt");
    ifstream myId("id.txt");

    loadData(workers, 6, mySales, myId);

    double totalQuarterSales[4] = {}; 
    string bestEmployeeID;
    double highestSales = 0;

    int bestQuarter = 0;
    double highestQuarterSales = 0;

    cout << fixed << setprecision(2);
    cout << "Annual Sales Report" << endl;
    cout << "=========================================================" << endl;
    cout << "ID       |   QT1      |   QT2      |   QT3      |   QT4   |  Total " << endl;
    cout << "---------------------------------------------------------" << endl;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            totalQuarterSales[j] += workers[i].qSales[j]; 
        }
        if (workers[i].totalSales > highestSales) {
            highestSales = workers[i].totalSales;
            bestEmployeeID = workers[i].id;
        }

        cout << setw(8) << workers[i].id << " | " << setw(10) << workers[i].qSales[0]
            << " | " << setw(10) << workers[i].qSales[1] << " | "
            << setw(7) << workers[i].qSales[2] << " | " << setw(10) << workers[i].qSales[3]
            << " | " << setw(10) << workers[i].totalSales << endl;
    }

    for (int i = 0; i < 4; i++) {
        if (totalQuarterSales[i] > highestQuarterSales) {
            highestQuarterSales = totalQuarterSales[i];
            bestQuarter = i + 1;
        }
    }

    cout << "---------------------------------------------------------" << endl;
    cout << "Totals   | " << setw(10) << totalQuarterSales[0] << " | "
        << setw(7) << totalQuarterSales[1] << " | " << setw(7)
        << totalQuarterSales[2] << " | " << setw(10)
        << totalQuarterSales[3] << " | " << setw(10) << (totalQuarterSales[0]+totalQuarterSales[1]+ totalQuarterSales[2]+ totalQuarterSales[3]) << endl;
    cout << "=========================================================" << endl;

    cout << "Top Employee: " << bestEmployeeID << " with $" << highestSales << " in sales." << endl;
    cout << "Best Performing Quarter: Q" << bestQuarter << " with $"
        << highestQuarterSales << " in sales." << endl;

    return 0;
}
