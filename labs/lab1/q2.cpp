#include<iostream>
#include<string>
using namespace std;

int main() {
    string students[] = {"Ali", "Hiba", "Asma", "Zain", "Faisal"};
    float marks[5][5] = {
        {3.66, 3.33, 4.0, 3.0, 2.66},
        {3.33, 3.0, 3.66, 3.0, -1},
        {4.0, 3.66, 2.66, -1, -1},
        {2.33, 2.33, 4.0, -1, -1},
        {3.33, 3.66, 4.0, 3.0, 3.33}
    };

    for (int i = 0; i < 5; i++) {
        float total = 0;
        int count = 0;
        for (int j = 0; j < 5; j++) {
            if (marks[i][j] != -1) {
                total += marks[i][j];
                count++;
            }
        }
        float gpa = (count > 0) ? total / count : 0;
        cout << students[i] << " Final GPA = " << gpa << endl;
    }

    return 0;
}
