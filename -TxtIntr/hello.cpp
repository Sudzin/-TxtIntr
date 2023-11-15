#include <iostream>
#include <cmath>
#include <cstdlib>

double sum(double a, double b) {
    return a + b;
}

double height(double angle, double velocity) {
    double radian_angle = angle * M_PI / 180;		
    return (pow(velocity, 2) * pow(sin(radian_angle), 2)) / (2 * 9.8);
}

double range(double angle, double velocity) {
    double radian_angle = angle * M_PI / 180;
    return (pow(velocity, 2) * sin(2 * radian_angle)) / 9.8;
}

void printUsage(){
    std::cout << "Использование: калькулятор -o <операция> <операнд1> <операнд2>" << std::endl;
    std::cout << "Доступные операции:" << std::endl;
    std::cout << "   -help   Справка об использовании" << std::endl;
    std::cout << "   -summa     Сложение двух чисел" << std::endl;
    std::cout << "   -height  Вычисление высоты" << std::endl;
    std::cout << "   -range  Вычисление дальности" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printUsage();
        return 1;
    }

    	std::string operation = argv[1];
    	double angle = std::stod(argv[2]);
    	double velocity = std::stod(argv[3]);

    if (operation == "-summa") {
        double result = sum(angle, velocity);
        std::cout << "Сумма: " << result << std::endl;
    } else if (operation == "-height") {
        double result = height(angle, velocity);
        std::cout << "Высота: " << result << std::endl;
    } else if (operation == "-range") {
        double result = range(angle, velocity);
        std::cout << "Дальность: " << result << std::endl;
    }else if (operation == "-h") {
        printUsage();
    }
    else {
        std::cout << "Неверная операция" << std::endl;
        printUsage();
        return 0;
    }

    return 0;
}
