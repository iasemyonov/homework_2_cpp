#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
double* allocateMemory(int size) {return new double[size];}
void fillArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Enter the value for element " << i + 1 << ": ";
        std::cin >> arr[i];
    }
}
void printArray(double* arr, int size) {
    std::cout << "Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void freeMemory(double* arr) {
    delete[] arr;
}
// task3
void swapEvenOdd(int* arr, int size) {
    if (size < 2) {
        std::cout << "The size of the array is less than 2. No elements to swap." << std::endl;
        return;
    }
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}
double** allocateMemory(int rows, int cols) {
    double** arr = new double*[rows];
    for (int i = 0; i < rows; i++) {arr[i] = new double[cols];}
    return arr;
}
void fillArray(double** arr, int rows, int cols) {for (int i = 0; i < rows; i++) {for (int j = 0; j < cols; j++) {arr[i][j] = std::rand() % 41 + 10;}}}
void printArray(double** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {std::cout << arr[i][j] << " ";}
        std::cout << std::endl;
    }
}
void freeMemory(double** arr, int rows) {
    for (int i = 0; i < rows; i++) {delete[] arr[i];}
    delete[] arr;
}

typedef int (*Operation)(int, int);
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) {
    if (b == 0) {
        std::cout << "Error: Division by zero.\n";
        return 0;
    }
    return a / b;
}

int main() {
    //task1
    // 1.1
    const float constValue = 10.0f;
    const float* const constFloatPtr = &constValue;
    // 1.2
    typedef long int* LongIntPtr;
    long int longIntValue = 1000;
    LongIntPtr longIntPtr = &longIntValue;
    // 1.3
    double doubleValue = 20.0;
    double* doublePtr = &doubleValue;
    // 1.4
    const short int shortIntValue = 30;
    const short int* shortIntPtr = &shortIntValue;
    // 1.5
    typedef const float* const ConstFloatConstPtr;
    const float anotherConstFloatValue = 40.0f;
    ConstFloatConstPtr constFloatConstPtr = &anotherConstFloatValue;
    // 1.6
    typedef const char* ConstCharPtr;
    const char constCharValue = 'A';
    ConstCharPtr constCharPtr = &constCharValue;
    // 1.7
    double anotherDoubleValue = 50.0;
    double* const constDoublePtr = &anotherDoubleValue;
    // 1.8
    typedef unsigned int* const ConstUIntPtr;
    unsigned int unsignedIntValue = 60;
    ConstUIntPtr constUIntPtr = &unsignedIntValue;

//task2
    while (true) {
        std::cout << "Enter the size of the array: ";
        int size;
        std::cin >> size;
        double* arr = allocateMemory(size);
        fillArray(arr, size);
        printArray(arr, size);
        freeMemory(arr);
        std::cout << "Do you want to continue? (yes/no): ";
        std::string answer;
        std::cin >> answer;
        if (answer == "no") {break;}
    }

//task3
    int* arr;
    arr = new int[12];
    for (int i = 0; i < 12; i++) {arr[i] = i + 1;}
    std::cout << "Original array: ";
    for (int i = 0; i < 12; i++) {std::cout << arr[i] << " ";}
    std::cout << std::endl;
    swapEvenOdd(arr, 12);
    std::cout << "Swapped array: ";
    for (int i = 0; i < 12; i++) {std::cout << arr[i] << " ";}
    std::cout << std::endl;
    delete[] arr;

//task4
    while (true) {
        std::cout << "input the number of rows: ";
        int rows;
        std::cin >> rows;
        std::cout << "input the number of columns: ";
        int cols;
        std::cin >> cols;
        if (rows <= 0 || cols <= 0) {
            std::cout <<  "try again.\n";
            continue;
        }
        double** arr = allocateMemory(rows, cols);
        fillArray(arr, rows, cols);
        printArray(arr, rows, cols);
        freeMemory(arr, rows);
        std::cout << "continue? (y/n): ";
        std::string answer;
        std::cin >> answer;

        if (answer == "n") {
            break;
        }
    }


//task5

    while (true) {
        std::cout << "input two integers: ";
        int x, y;
        std::cin >> x >> y;
        std::cout << "input an operation or space to exit: ";
        char op;
        std::cin.get();
        op = std::cin.get();
        if (op == ' ') {
            break;
        }
        Operation operation = nullptr;
        switch (op) {
            case '+':
                operation = add;
                break;
            case '-':
                operation = subtract;
                break;
            case '*':
                operation = multiply;
                break;
            case '/':
                operation = divide;
                break;
            default:
                std::cout << "Try again.\n";
                continue;
        }
        std::cout << "Result: " << operation(x, y) << "\n";
    }

    return 0;
}

class Solution {
public:
//leetcode1
    int minimumDifference(std::vector<int>& nums, int k) {
        int i = 0;
        int j = k-1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 2147483647;
        while(j<n){ans = std::min(ans,nums[j++]-nums[i++]);}
        return ans;
    }
//leetcode2
    int findLucky(std::vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        int l = arr.size()-1;
        while(l >= 0){
            int c = count(arr.rbegin(), arr.rend(), arr[l]);
            if(arr[l] == c){return arr[l];}
            l--;}
        return -1;
    }
//leetcode3
    int majorityElement(std::vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        sort(nums.begin(), nums.end());
        int count = 1, ans = 0, n = nums.size();
        for(int i = 1; i < n; ++i){
            if(nums[i] == nums[i - 1]){
                count++;
                if(count > (n / 2)){
                    ans = nums[i];
                    break;}
            }
        }
        return ans;
    }
};