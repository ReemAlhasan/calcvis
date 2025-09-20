#include <iostream>
#include <string>
#include <limits>

double readNumber(const std::string& prompt) {
    double x;
    while (true) {
        std::cout << prompt;
        if (std::cin >> x) {
            break;
        }
        else {
            std::cout << "Error: Invalid input! Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return x;
}

char readOp() {
    char op;
    while (true) {
        std::cout << "Enter an operator (+ - * /): ";
        std::cin >> op;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (op == '+' || op == '-' || op == '*' || op == '/') {
            break;
        }
        else {
            std::cout << "Error: Invalid operator! Please use +, -, *, or /.\n";
        }
    }
    return op;
}

// Do the math
double compute(double a, double b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        while (b == 0) {
            std::cout << "Error: Division by zero!\n";
            b = readNumber("Enter a non-zero number: ");
        }
        return a / b;
    default:
        std::cout << "Unknown operator!\n";
        return 0;
    }
}

int main() {
    std::string answer;

    while (true) {
        double a = readNumber("Enter a number: ");
        double b = readNumber("Enter another number: ");
        char op = readOp();

        double result = compute(a, b, op);
        std::cout << "Result: " << result << "\n";

        std::cout << "Do you want to quit? (yes/quit to stop): ";
        std::cin >> answer;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (answer == "yes" || answer == "quit") {
            break;
        }
    }

    std::cout << "Calculator closed. Goodbye!\n";
    return 0;
}