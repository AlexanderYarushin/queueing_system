#include <QCoreApplication>
#include <cmath>
#include <iostream>
#include <ctime>

double rnd(){
    return rand() / (RAND_MAX * 1.0);
}

struct till{
    int count = 0;
    int Tk = 0;
};

static unsigned Tz = 2; //Время обслуживания одного покупателя
static const unsigned N = 10; //Колличество касс
static unsigned T = 100; //Время работы модели
static till tills[N]; //Массив касс
static std::vector<double> buyers; //Массив покупателей
static double a = 1.0/5.0;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    srand(time(nullptr));


    for(int i = 0; i < 10; ++i)
        std::cout << -a * log(rnd()) << std::endl;



    return app.exec();
}
