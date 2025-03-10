#include <iostream>
#include <fstream>

using namespace std;


struct Employee {
    string id;
    double qSales[4];

    double totalSales;
};

void loadData(Employee x[], int size, ifstream& data) {

    for (int i = 0; i < size; i++) {
        data >> x[i].id;
        cout << endl << x[i].id;
        
        for (int j = 0; i < 4; j++) {
            data >> x[i].qSales[j];
            cout << endl << x[i].qSales[j];
        }
        
    }
}
 

int main()
{
    Employee workers[6];
    ifstream mydata("info.txt");
    if(mydata)
    loadData(workers, 6, mydata);
   
    
    cout << "Annual Sales Report";
    cout << "ID \t\t QT1 \t\t QT2 \t\t QT3 \t\t QT4 \t\t Total" << endl;
    cout << workers[0].id;

}

