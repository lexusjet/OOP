// OOP_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <math.h>

enum exeptions
{
    DivisionByZero = 99
};

class Ex
{
public:
    double x;
    Ex(double a): x(a) {}
    ~Ex() {}
};

class Bar
{
public:
    double y = 0;
    Bar() {};
    ~Bar() {};
    void set(double a)
    {
        if ((a + y) > 100)
        {
            //Ex tmp(a * y);
            throw Ex(a * y);
        }
        y = a;
    }
};

class OffTheField
{
public:
    int a = 5;
    OffTheField(){};
    ~OffTheField(){};
};

class IllegalCommand
{
public:
    int b = 5;
    IllegalCommand() {};
    ~IllegalCommand() {};
};

class Robot
{
private:
    const size_t strings;
    const size_t colmns;
public:    
    size_t pos_str = 0;
    size_t pos_clmn = 0;

    Robot(size_t size_a, size_t size_b) :strings(size_a), colmns(size_b) {}
    friend std::ostream& operator<<(std::ostream& ss, Robot robot);
    ~Robot() {};

    void move(size_t str, size_t clmn)
    {
        if((str >= strings)||(str < 0))
        {
            OffTheField tmp;
            throw tmp;
        }
        else if((clmn >= colmns)||(clmn < 0))
        {
            OffTheField tmp;
            throw tmp;
        }
        if(std::abs(static_cast<int>(str - pos_str)) > 1)
        {
            IllegalCommand tmp;
            throw tmp;
        }
        else if(std::abs( static_cast<int>(clmn - pos_clmn)) > 1)
        {
            IllegalCommand tmp;
            throw tmp;
        }

        pos_clmn = clmn;
        pos_str = str;
    }

};

std::ostream & operator<<(std::ostream & ss, Robot robot)
{
    using namespace std;
    cout << "Robot curent position is ( " << robot.pos_str << " , " << robot.pos_clmn << ")";
    return ss;
}

template <typename T> T div(T a, T b)
{
    if (b == 0) throw DivisionByZero;
    else return(a / b);
}

int main()
{
    std::cout << "DIV fundction" << std::endl;
    try
    {   
        std::cout << " if you whant get exeption enter 0 in b" << std::endl;
        int anser = 0;
        int a = 4;
        int b = 1;
        std::cout << " enter the dividend a = ";
        std::cin >> a;
        std::cout << "enter the divisor b = ";
        std::cin >> b;
        anser = div<int>(a, b);
        std::cout << a  << " / " << b << " = " << anser << std::endl;
    }
    catch (exeptions)
    {
        std::cout << "Error: divison By zero " << std::endl;
    }

    std::cout << std::endl << "BAR: if you want get exception enter number higher than 100" << std::endl;

    Bar bar;
    do
    {
        int n;
        try
        {   
            std::cout << "enter n = ";
            std::cin >> n;
            if (n == 0) break;
            bar.set(n);
            std::cout << "y is = " << bar.y << std::endl;
        }
        catch(Ex ex)
        {
            std::cout << "exeption " << ex.x << " > 100" << std::endl;
        }
    } while (true);

    std::cout << std::endl << "ROBOT:" << std::endl;

    Robot robot(10, 10);
    do
    {
        int x;
        int y;
        try
        {
            std::cout << robot << std::endl;
            std::cout << "move to\n";
            std::cout << "x = ";
            std::cin >> x;
            std::cout << "y = ";
            std::cin >> y;
            if (x == 99 && y == 99) break;
            robot.move(x, y);
        }
        catch(OffTheField exept)
        {
            std::cout << "ERROR: Can't pass the border" << std::endl;
        }
        catch(IllegalCommand exept)
        {
            std::cout << "ERROR: Input coordinates out off range " << std::endl;
        }
    
    } while (true);

}


