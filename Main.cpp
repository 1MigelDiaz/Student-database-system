#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <fstream>
using namespace std;

// global variables
string dot = "...";
int choice2;
string lf;
int refresh = 0;
struct Student {string name; string section; int age; int lrn; float grade;};
vector<Student> students;

void searchinstruct() 
 {for (int l = 0; l < students.size(); l++)
  {if (students[l].name == lf)
    {cout << "\n\nName: " << students[l].name << "\nSection: " 
     << students[l].section
     << "\nAge: " << students[l].age << "\nLRN: " << students[l].lrn
     << "\nGrade: " << students[l].grade;}
   else {cout << "Student not found";}}
   this_thread::sleep_for(chrono::milliseconds(600));}
   
void returntomainmenu() 
{cout << "\n\nWould you like to return to main menu?";
   cout << "\n1. Return\n2. Exit\nOption: ";
   cin >> choice2;
   if (choice2 > 2||choice2 < 1)
    {cout << "Invalid option.";
     this_thread::sleep_for(chrono::milliseconds(400));
     cout << "\nExiting";
     for (int i = 0; i < dot.length(); i++)
      {cout << dot[i] << flush; this_thread::sleep_for(chrono::milliseconds(100));}
       system("clear");}
   else if (choice2 == 1) {system("clear"); refresh = 0;}
   else if (choice2 == 2) 
    {cout << "\nExiting";
     for (int i = 0; i < dot.length(); i++)
      {cout << dot[i] << flush; this_thread::sleep_for(chrono::milliseconds(100));}
       system("clear");}};

int main() {
 string tempname;
 string tempsection;
 int tempage;
 int templrn;
 float tempgrade;
 Student temp;
 string loadtext = "Student database system v2.0";
 string choices = "1. Add student\n2. Edit student\n3. Delete student\n4. View students\n5. Find student\n6. Exit\n\nOption: ";
 int option;

 while (refresh == 0) {
 refresh = 1;
 for (int i = 0; i < 55; i++) {cout << "─" << flush;
  this_thread::sleep_for(chrono::milliseconds(20));}
 cout << "\n             ";
 for (int j = 0; j < loadtext.length(); j++) { cout << loadtext[j];
  this_thread::sleep_for(chrono::milliseconds(25));}
 cout << "\n";
 for (int p = 0; p < 55; p++) {cout << "─" << flush;
  this_thread::sleep_for(chrono::milliseconds(20));}
 cout << "\n\n";
 for (int l = 0; l < choices.length(); l++)
  { cout << choices[l]; 
   this_thread::sleep_for(chrono::milliseconds(10));}
 cin >> option;

 // invalid option
 if (option > 7 || option < 1)
  {cout << "\nInvalid option." << flush;
   this_thread::sleep_for(chrono::milliseconds(500));
   system("clear"); refresh = 0;}
 
 // exit option
 if (option == 6)
  {cout << "\nExiting";
   for (int i = 0; i < dot.length(); i++)
   {cout << dot[i] << flush;
   this_thread::sleep_for(chrono::milliseconds(100));}
   system ("clear");}

 // add option
 else if (option == 1)
  {cout << "\nName: "; getline(cin >> ws, temp.name);
   cout << "Section: "; getline(cin >> ws, temp.section);
   cout << "Age: "; cin >> temp.age;
   cout << "LRN: "; cin >> temp.lrn;
   cout << "Grade: "; cin >> temp.grade;
   students.push_back(temp);
   cout << "Loading";
   this_thread::sleep_for(chrono::milliseconds(250));
   for (int o = 0; o < 3; o++)
    {cout << dot[o]; this_thread::sleep_for(chrono::milliseconds(50));}
   ofstream writefile("list.txt", ios::app);
   writefile << tempname << "   "
   << tempsection << "   " << tempage
   << "  " << templrn << "   "
   << tempsection << "\n";
   if (writefile.is_open())
    { cout << " Success!";}
   else {cout << " Failed, please try again later.";}
   writefile.close();
   this_thread::sleep_for(chrono::milliseconds(600));
   returntomainmenu();}

 // view option
 else if (option == 4)
  {cout << "\nStudent list:\n";
   for (int j = 0; j < students.size(); j++)
   {cout << students[j].name << "   " << students[j].section << " "
    << students[j].age << "  " << students[j].lrn << "   "
    << students[j].grade << "\n";}
   this_thread::sleep_for(chrono::milliseconds(600));
   returntomainmenu();}

 // find option
 if (option == 5)
 {cout << "\nName: "; getline(cin >> ws, lf);
 cout << "Searching";
   for (int i = 0; i < dot.length(); i++)
    {cout << dot[i] << flush;
    this_thread::sleep_for(chrono::milliseconds(100));}
 for (int l = 0; l < students.size(); l++)
  {if (students[l].name == lf)
    {cout << "\n\nName: " << students[l].name << "\nSection: " 
     << students[l].section
     << "\nAge: " << students[l].age << "\nLRN: " << students[l].lrn
     << "\nGrade: " << students[l].grade;}
   else {cout << "Student not found";}}
   this_thread::sleep_for(chrono::milliseconds(600));
   returntomainmenu();}

 // edit option
 if (option == 2)
 {cout << "Student name: "; getline(cin >> ws, lf);
  cout << "\nInsert new student info";
  cout << "\nName: "; getline(cin >> ws, temp.name);
   cout << "Section: "; getline(cin >> ws, temp.section);
   cout << "Age: "; cin >> temp.age;
   cout << "LRN: "; cin >> temp.lrn;
   cout << "Grade: "; cin >> temp.grade;
   for (int l = 0; l < students.size(); l++)
   {if (students[l].name == lf)
    {students[l].name = temp.name; students[l].section = temp.section;
     students[l].age = temp.age; students[l].lrn = temp.lrn;
     students[l].grade = temp.grade; cout << "Success!";}
    else {cout << "Error please try again later.";}}
   this_thread::sleep_for(chrono::milliseconds(600));
   returntomainmenu();}

// delete option
if (option == 3)
{cout << "Student name: "; getline(cin >> ws, lf);
 for (int l = 0; l < students.size(); l++)
  {if (students[l].name == lf)
    {students.erase(students.begin() + l); 
     cout << "Success!"; break;}
   else {cout << "Student not found";}}
this_thread::sleep_for(chrono::milliseconds(600));
returntomainmenu();}
 }
}
