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
const int MAX_SIZE = 560;

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

int ConsoleInputSizeArray(const int sizeMax) {
  int size = 0;
  do {
    cout << " Input size Array (0 < 1 < " << sizeMax << "):";
    cin >> size;
  } while (size <= 0 || size >= sizeMax);
  return size;
}

int ConsoleInputArray(int sizeMax, double A[]) {
  int size = ConsoleInputSizeArray(sizeMax);
  for (int i = 0; i < size; i++) {
    cout << " Array[" << i << "]:";
    cin >> A[i];
  }
  return size;
}

int ConsoleInputArrayRandom(int sizeMax, double A[]) {
  int size = ConsoleInputSizeArray(sizeMax);
  int r1 = 0, r2 = 0;
  srand(size);

  for (int i = 0; i < size; i++) {
    r1 = rand();
    r2 = rand();
    A[i] = 100.0 * r1;
    A[i] = A[i] / (1.0 + r2);
    cout << A[i] << "   ";
  }
  return size;
}

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble &pA) {
  int size = ConsoleInputSizeArray(sizeMax);
  pA = (double *)calloc(
      size, sizeof(double));
  if (pA == nullptr) {
    return 0;
  }
  for (int i = 0; i < size; i++) {
    cout << " Array[ " << i << "] ";
    cin >> pA[i];
  }
  return size;
}

int ConsoleInputDynamicArrayRandom(int sizeMax, pDouble &pA) {
  int size = ConsoleInputSizeArray(sizeMax);
  pA = new double[size];
  int r1 = 0, r2 = 0;
  srand(size);

  for (int i = 0; i < size; i++) {
    r1 = rand();
    r2 = rand();
    pA[i] = 100.0 * r1;
    pA[i] = pA[i] / (1.0 + r2);
    cout << pA[i] << "   ";
  }
  return size;
}

int ConsoleInputDynamicArrayNew(int sizeMax, pDouble &pA) {
  int size = ConsoleInputSizeArray(sizeMax);
  pA = new double[size];
  if (pA == nullptr) {
    return 0;
  }
  for (int i = 0; i < size; i++) {
    cout << " Array[ " << i << "] ";
    cin >> pA[i];
  }
  return size;
}

void ConsoleInputVector(int sizeMax, vector<double> &A) {
  int size = ConsoleInputSizeArray(sizeMax);
  double d;
  for (int i = 0; i < size; i++) {
    cout << " Array[ " << i << "] ";
    cin >> d;
    A.push_back(d);
  }
  return;
}

void inputLocalArray(int sizeMax, double A[]) {
  switch (taskInput) {
  case 1:
    ConsoleInputArray(sizeMax, A);
    break;
  case 2:
    ConsoleInputArrayRandom(sizeMax, A);
  case 3:
    break;
  case 4:
    break;
  default:
    break;
  }
}

void inputDynamicArray(int sizeMax, pDouble &pA) {
  switch (taskInput) {
  case 1:
    ConsoleInputDynamicArray_calloc(sizeMax, pA);
    break;
  case 2:
    ConsoleInputDynamicArrayRandom(sizeMax, pA);
  case 3:
    break;
  case 4:
    break;
  default:
    break;
  }
}

void task1() {
  switch (taskType) {
  case 1:
    double A[MAX_SIZE];
    inputLocalArray(MAX_SIZE, A);
    // solution
    // output
    break;
  case 2:
    pDouble pA;
    inputDynamicArray(MAX_SIZE, pA);
    // solution
    // output
    break;
  default:
    break;
  }

  // double A[MAX_SIZE];
  // pDouble pA;
  // vector<double> vA;

}

void task2() { cout << "2"; }

void task3() { cout << "3"; }

void execTask() {
  switch (taskNumber) {
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
