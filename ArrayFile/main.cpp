#include <fstream>
#include <ios>
#include <iostream>
#include <vector>

#include <time.h>

using namespace std;

typedef double *pDouble;
int taskNumber;
int taskType;
int taskInput;

int GetInput() {
  int choice;
  cin >> choice;
  return choice;
}

void showMainMenu() {
  cout << "    Main Menu  \n";
  cout << "    1.  Task 1  \n";
  cout << "    2.  Task 2  \n";
  cout << "    3.  Task 3  \n";
}

void mainMenu() {
  bool isSelected = false;
  while (!isSelected) {
    system("cls");
    showMainMenu();
    int ch = GetInput();
    switch (ch) {
    case 1:
      isSelected = true;
      taskNumber = 1;
      break;
    case 2:
      isSelected = true;
      taskNumber = 2;
      break;
    case 3:
      isSelected = true;
      taskNumber = 3;
      break;
    default:
      break;
    }
  }
}

void showMenuTask() {
  cout << "     Menu Task   \n";
  cout << "    1.  Local array  \n";
  cout << "    2.  Dynamic array 1 \n";
  cout << "    3.  Dynamic array 2  new \n";
  cout << "    4.  Dynamic array : vector \n";
  cout << "    5.  Exit \n";
}

void menuTask() {
  bool isSelected = false;
  while (!isSelected) {
    system("cls");
    showMenuTask();
    int ch = GetInput();
    switch (ch) {
    case 1:
      isSelected = true;
      taskType = 1;
      break;
    case 2:
      isSelected = true;
      taskType = 2;
      break;
    case 3:
      isSelected = true;
      taskType = 3;
      break;
    case 4:
      isSelected = true;
      taskType = 4;
      break;
    case 5:
      isSelected = true;
      break;
    default:
      break;
    }
  }
}

void showMenuInput() {
  cout << "     Menu Input   \n";
  cout << "    1.  Console all \n";
  cout << "    2.  Console - size, array - random \n";
  cout << "    3.  File 1.txt \n";
  cout << "    4.  bb    \n";
  cout << "    5.  Exit \n";
}

void menuInput() {
  bool isSelected = false;
  while (!isSelected) {
    system("cls");
    showMenuInput();
    int ch = GetInput();
    switch (ch) {
    case 1:
      isSelected = true;
      taskInput = 1;
      break;
    case 2:
      isSelected = true;
      taskInput = 2;
      break;
    case 3:
      isSelected = true;
      taskInput = 3;
      break;
    case 4:
      isSelected = true;
      taskInput = 4;
      break;
    case 5:
      isSelected = true;
      break;
    default:
      break;
    }
  }
}

void task1() {
    cout << "1";
}

void task2() {
    cout << "2";
}

void task3() {
    cout << "3";
}

void execTask() {
    switch (taskNumber)
    {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    default:
        break;
    }
}

int main() {
  mainMenu();
  menuTask();
  menuInput();
  execTask();
  return 0;
}
