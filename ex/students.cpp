#include <iostream>

using namespace std;

int main() {
    int total_students = 0, i, input;
    bool found_search = false;
    string search;
    struct student {
        char name[20];
        float gpa, bonus;
    };
    student table[500];
    while (1) {
        cin>>input;
        if (input == 1) {
            cout<<"Enter name for student no. "<<total_students + 1<<": ";
            cin>>table[total_students].name;
            cout<<"\n GPA: ";
            cin>>table[total_students].gpa;
            cout<<"\n Bonus value: ";
            cin>>table[total_students].bonus;
            cout<<"Student no. "<<i+1<<" named "<<table[total_students].name<<" has a GPA of "<<table[total_students].gpa<<" and a bonus of "<<table[total_students].bonus<<"\n";
            total_students++;
        }
        else if (input == 2) {
            for(i=0;i<total_students;i++) {
                cout<<"Student no. "<<i+1<<" named "<<table[i].name<<" has a GPA of "<<table[i].gpa<<" and a bonus of "<<table[i].bonus<<"\n";
            }
        }
        else if (input == 3) {
            cout<<"Input search term: ";
            cin>>search;
            found_search = false;
            for(i=0;i<total_students;i++) {
                if(table[i].name == search) {
                    found_search = true;
                    cout<<"Student no. "<<i+1<<" named "<<table[i].name<<" has a GPA of "<<table[i].gpa<<" and a bonus of "<<table[i].bonus<<"\n";
                }
            }
            if (!found_search)cout<<"\nInvalid search, try again.\n";
        }
        else break;
        }
    return 0;
    }