#include <iostream>

int main()
{
    int firstNumber;
    int secondNumber;

    std::cout << "Enter two numbers: ";
    std::cin >> firstNumber >> secondNumber;

    int sum = firstNumber + secondNumber;
    std::cout << "Sum = " << sum << std::endl;

    return 0;
}
