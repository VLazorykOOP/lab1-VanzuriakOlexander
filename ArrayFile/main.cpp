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

int ConsoleReadArrayTextFile(int n, double *arr, const char *fileName) {
  int size;
  ifstream fin(fileName);
  if (fin.fail())
    return 0;
  fin >> size;
  if (size <= 0)
    return 0;
  if (size > n)
    size = n;
  for (int i = 0; i < n; i++)
    fin >> arr[i];
  fin.close();
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

  cout << endl;

  return size;
}

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble &pA) {
  int size = ConsoleInputSizeArray(sizeMax);
  pA = (double *)calloc(size, sizeof(double));
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

  cout << endl;

  return size;
}

int ConsoleReadArrayBinFile(int n, double *arr, const char *fileName) {
  int size = 0;
  ifstream bfin(fileName, ios_base::binary);
  if (bfin.fail())
    return 0;
  bfin.read((char *)&size, sizeof(int));
  if (size <= 0)
    return 0;
  if (size > n)
    size = n;
  bfin.read((char *)arr, static_cast<std::streamsize>(size) * sizeof(double));
  bfin.close();
  // ssdhs
  return size;
}

int inputLocalArray(int sizeMax, double A[]) {
  int size;
  switch (taskInput) {
  case 1:
    size = ConsoleInputArray(sizeMax, A);
    break;
  case 2:
    size = ConsoleInputArrayRandom(sizeMax, A);
  case 3:
    size = ConsoleReadArrayTextFile(sizeMax, A, "1.txt");
    break;
  case 4:
    size = ConsoleReadArrayBinFile(sizeMax, A, "1.bin");
    break;
  default:
    break;
  }
  return size;
}

int ConsoleReadDynamicArrayTextFile(int n, pDouble &pA, const char *fileName) {
  int size;
  ifstream fin(fileName);
  if (fin.fail())
    return 0;
  fin >> size;
  if (size <= 0)
    return 0;
  if (size > n)
    size = n;
  pA = new double[size];
  for (int i = 0; i < n; i++)
    fin >> pA[i];
  fin.close();
  return size;
}

int ConsoleReadDynamicArrayBinFile(int n, pDouble &pA, const char *fileName) {
  int size = 0;
  ifstream bfin(fileName, ios_base::binary);
  if (bfin.fail())
    return 0;
  bfin.read((char *)&size, sizeof(int));
  if (size <= 0)
    return 0;
  if (size > n)
    size = n;
  pA = new double[size];
  bfin.read((char *)pA, static_cast<std::streamsize>(size) * sizeof(double));
  bfin.close();
  // ssdhs
  return size;
}

int inputDynamicArray(int sizeMax, pDouble &pA) {
  int size;
  switch (taskInput) {
  case 1:
    size = ConsoleInputDynamicArray_calloc(sizeMax, pA);
    break;
  case 2:
    size = ConsoleInputDynamicArrayRandom(sizeMax, pA);
    break;
  case 3:
    size = ConsoleReadDynamicArrayTextFile(sizeMax, pA, "1.txt");
    break;
  case 4:
    size = ConsoleReadDynamicArrayBinFile(sizeMax, pA, "1.bin");
    break;
  default:
    break;
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

int inputDynamicArrayNew(int sizeMax, pDouble &pA) {
  int size;
  switch (taskInput) {
  case 1:
    size = ConsoleInputDynamicArrayNew(sizeMax, pA);
    break;
  case 2:
    size = ConsoleInputDynamicArrayRandom(sizeMax, pA);
    break;
  case 3:
    size = ConsoleReadDynamicArrayTextFile(sizeMax, pA, "1.txt");
    break;
  case 4:
    size = ConsoleReadDynamicArrayBinFile(sizeMax, pA, "1.bin");
    break;
  default:
    break;
  }
  return size;
}

int ConsoleInputVector(int sizeMax, vector<double> &A) {
  int size = ConsoleInputSizeArray(sizeMax);
  double d;
  for (int i = 0; i < size; i++) {
    cout << " Array[ " << i << "] ";
    cin >> d;
    A.push_back(d);
  }
  return size;
}

int ConsoleInputVectorRandom(int sizeMax, vector<double> &A) {
  int size = ConsoleInputSizeArray(sizeMax);
  double d;
  int r1 = 0, r2 = 0;
  srand(size);

  for (int i = 0; i < size; i++) {
    r1 = rand();
    r2 = rand();
    d = 100.0 * r1;
    d = d / (1.0 + r2);
    A.push_back(d);
    cout << A[i] << "   ";
  }

  cout << endl;

  return size;
}

int ReadInputVectorTextFile(int n, vector<double> &A, const char *fileName) {
  int size;
  double d;
  ifstream fin(fileName);
  if (fin.fail())
    return 0;
  fin >> size;
  if (size <= 0)
    return 0;
  for (int i = 0; i < size; i++) {
    fin >> d;
    A.push_back(d);
  }
  fin.close();
  return size;
}

int ReadArrayVectorBinFile(int n, vector<double> &A, const char *fileName) {
  int size = 0;
  double d;
  ifstream bfin(fileName, ios_base::binary);
  if (bfin.fail())
    return 0;
  bfin.read((char *)&size, sizeof(int));
  if (size <= 0)
    return 0;
  if (size > n)
    size = n;
  for (int i = 0; i < size; i++) {
    bfin.read(reinterpret_cast<char *>(&d), sizeof(double));
    A.push_back(d);
  }
  bfin.close();
  // ssdhs
  return size;
}

int inputVector(int sizeMax, vector<double> &A) {
  int size;
  switch (taskInput) {
  case 1:
    size = ConsoleInputVector(sizeMax, A);
    break;
  case 2:
    size = ConsoleInputVectorRandom(sizeMax, A);
    break;
  case 3:
    size = ReadInputVectorTextFile(sizeMax, A, "1.txt");
    break;
  case 4:
    size = ReadArrayVectorBinFile(sizeMax, A, "1.bin");
    break;
  default:
    break;
  }
  return size;
}

// Із одновимірного масиву А розміру N побудувати масив В із всіх додатних
// елементів.

void task1() {
  double B[MAX_SIZE];
  int nB = 0;
  int nA;
  vector<double> vA;
  switch (taskType) {
  case 1:
    double A[MAX_SIZE];
    nA = inputLocalArray(MAX_SIZE, A);
    for (int i = 0; i < nA; i++) {
      if (A[i] >= 0) {
        B[nB++] = A[i];
      }
    }

    if (nB) {
      cout << "B array:" << endl;
      for (int i = 0; i < nB; i++) {
        cout << "B[" << i << "]=" << B[i] << endl;
      }
    } else {
      cout << "B array has no elements";
    }
    break;
  case 2:
    pDouble pA;
    nA = inputDynamicArray(MAX_SIZE, pA);
    for (int i = 0; i < nA; i++) {
      if (pA[i] >= 0) {
        B[nB++] = pA[i];
      }
    }

    if (nB) {
      cout << "B array:" << endl;
      for (int i = 0; i < nB; i++) {
        cout << "B[" << i << "]=" << B[i] << endl;
      }
    } else {
      cout << "B array has no elements";
    }
    break;
  case 3:
    pDouble pB;
    nA = inputDynamicArrayNew(MAX_SIZE, pB);
    for (int i = 0; i < nA; i++) {
      if (pB[i] >= 0) {
        B[nB++] = pB[i];
      }
    }

    if (nB) {
      cout << "B array:" << endl;
      for (int i = 0; i < nB; i++) {
        cout << "B[" << i << "]=" << B[i] << endl;
      }
    } else {
      cout << "B array has no elements";
    }
    break;
  case 4:
    nA = inputVector(MAX_SIZE, vA);
    for (auto v : vA) {
      if (v >= 0) {
        B[nB++] = v;
      }
    }

    if (nB) {
      cout << "B array:" << endl;
      for (int i = 0; i < nB; i++) {
        cout << "B[" << i << "]=" << B[i] << endl;
      }
    } else {
      cout << "B array has no elements";
    }
    break;
  default:
    break;
  }
}

// Знайти номер останнього максимального елемента серед додатних елементів,
// починаючи з першого елемента, більшого заданого числа Т.

void task2() {
  int nA;
  double max = 0, T;
  int numberOfElement = 0;
  int number = -1;
  vector<double> vA;
  switch (taskType) {
  case 1:
    double A[MAX_SIZE];
    nA = inputLocalArray(MAX_SIZE, A);
    cout << "Enter the T number:";
    cin >> T;
    for (int i = 0; i < nA; i++) {
      if (A[i] > T && A[i] >= max && A[i] >= 0) {
        max = A[i];
        number = i;
      }
    }

    if (number != -1) {
      cout << "The number of last element higher than T: " << number;
    } else {
      cout << "Number not found" << endl;
    }
    break;
  case 2:
    pDouble pA;
    nA = inputDynamicArray(MAX_SIZE, pA);
    cout << "Enter the T number:";
    cin >> T;
    for (int i = 0; i < nA; i++) {
      if (pA[i] > T && pA[i] >= max && pA[i] >= 0) {
        max = pA[i];
        number = i;
      }
    }
    if (number != -1) {
      cout << "The number of last element higher than T: " << number;
    } else {
      cout << "Number not found" << endl;
    }
    break;
  case 3:
    pDouble pB;
    nA = inputDynamicArrayNew(MAX_SIZE, pB);
    cout << "Enter the T number:";
    cin >> T;
    for (int i = 0; i < nA; i++) {
      if (pB[i] > T && pB[i] >= max && pB[i] >= 0) {
        max = pB[i];
        number = i;
      }
    }
    if (number != -1) {
      cout << "The number of last element higher than T: " << number;
    } else {
      cout << "Number not found" << endl;
    }
    break;
  case 4:
    nA = inputVector(MAX_SIZE, vA);
    cout << "Enter the T number:";
    cin >> T;
    for (auto v : vA) {
      if (v > T && v >= max && v >= 0) {
        max = v;
        number = numberOfElement;
      }
      numberOfElement++;
    }
    if (number != -1) {
      cout << "The number of last element higher than T: " << number;
    } else {
      cout << "Number not found" << endl;
    }
    break;
  default:
    break;
  }
}

// Задано дійсні величини a, b (a < b) і масив чисел X(N) 
// Розробити програму, яка обчислує суму всіх X(i) < a,
// Добуток всіх X(i) > b,
// знаходить max і min серед X(i)є[a, b], i=1,2,..,n; 

void task3() {
  double max, min, sum = 0, multiple = 1;
  int a, b, i, nX;
  vector<double> vX;
  switch (taskType) {
  case 1:
    double X[MAX_SIZE];
    nX = inputLocalArray(MAX_SIZE, X);
    cout << "Please enter the a number:";
    cin >> a;
    cout << "Please enter the b number:";
    cin >> b;

    for (i = 0; i < nX; i++) {
      if (X[i] < a) {
        sum += X[i];
      } else if (X[i] > b) {
        multiple *= X[i];
      } else {
        min = X[i];
        max = X[i];
      }
    }

    for (i = 0; i < nX; i++) {
      if (X[i] >= a && X[i] <= b) {
        if (min >= X[i]) {
          min = X[i];
        } else if (max <= X[i]) {
          max = X[i];
        };
      };
    };
    cout << "The min number in interval [a, b]: " << min << endl;
    cout << "The max number in interval [a, b]: " << max << endl;
    cout << "The sum of elements low then a: " << sum << endl;
    cout << "The multiple of elements high than b: " << multiple;
    break;
  case 2:
    pDouble pX;
    nX = inputDynamicArray(MAX_SIZE, pX);
    cout << "Please enter the a number:";
    cin >> a;
    cout << "Please enter the b number:";
    cin >> b;
    for (i = 0; i < nX; i++) {
      if (pX[i] < a) {
        sum += pX[i];
      } else if (pX[i] > b) {
        multiple *= X[i];
      } else {
        min = pX[i];
        max = pX[i];
      }
    }

    for (i = 0; i < nX; i++) {
      if (pX[i] >= a && pX[i] <= b) {
        if (min >= pX[i]) {
          min = pX[i];
        } else if (max <= pX[i]) {
          max = pX[i];
        };
      };
    };
    cout << "The min number in interval [a, b]: " << min << endl;
    cout << "The max number in interval [a, b]: " << max << endl;
    cout << "The sum of elements low then a: " << sum << endl;
    cout << "The multiple of elements high than b: " << multiple;
    break;
  case 3:
    pDouble pX1;
    nX = inputDynamicArrayNew(MAX_SIZE, pX1);
    cout << "Please enter the a number:";
    cin >> a;
    cout << "Please enter the b number:";
    cin >> b;
    for (i = 0; i < nX; i++) {
      if (pX[i] < a) {
        sum += pX[i];
      } else if (pX[i] > b) {
        multiple *= X[i];
      } else {
        min = pX[i];
        max = pX[i];
      }
    }

    for (i = 0; i < nX; i++) {
      if (pX[i] >= a && pX[i] <= b) {
        if (min >= pX[i]) {
          min = pX[i];
        } else if (max <= pX[i]) {
          max = pX[i];
        };
      };
    };
    cout << "The min number in interval [a, b]: " << min << endl;
    cout << "The max number in interval [a, b]: " << max << endl;
    cout << "The sum of elements low then a: " << sum << endl;
    cout << "The multiple of elements high than b: " << multiple;
    break;
  case 4:
    nX = inputVector(MAX_SIZE, vX);
    cout << "Please enter the a number:";
    cin >> a;
    cout << "Please enter the b number:";
    cin >> b;
    for (auto v : vX) {
      if (v < a) {
        sum += v;
      } else if (v > b) {
        multiple *= v;
      } else {
        min = v;
        max = v;
      }
    }

    for (auto v : vX) {
      if (v >= a && v <= b) {
        if (min >= v) {
          min = v;
        } else if (max <= v) {
          max = v;
        };
      };
    };

    cout << "The min number in interval [a, b]: " << min << endl;
    cout << "The max number in interval [a, b]: " << max << endl;
    cout << "The sum of elements low then a: " << sum << endl;
    cout << "The multiple of elements high than b: " << multiple;
  default:
    break;
  }
}

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
