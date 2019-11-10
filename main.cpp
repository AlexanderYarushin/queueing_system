#include <QCoreApplication>
#include <cmath>
#include <iostream>
#include <ctime>

double rnd(){
    return rand() / (RAND_MAX * 1.0);
}

struct till{
    unsigned count = 0;
    double Tk = 0;
};

static double Tz = 2; //Время обслуживания одного покупателя
static const unsigned N = 20; //Колличество касс
static double T = 100; //Время работы модели
static till tills[N]; //Массив касс
static unsigned tillsAcc[N+1]; //Аккумулятор
static std::vector<double> buyers; //Массив покупателей
static double a = 1 / 5.0; // Частота появления покупателя
static unsigned not_served = 0; //Количество необслуженых покупателей
static unsigned repeatCount = 10000; //Количество итераций для подсчета среднего значения

void moddeling(){
    for(unsigned i = 0; i < N; ++i){
        if(buyers[buyers.size() - 1] >= tills[i].Tk){
            tills[i].count++;
            tills[i].Tk = buyers[buyers.size() - 1] + Tz;
            return;
        }
    }

    not_served++;

}


void clear(){
    for(unsigned i = 0; i < N; ++i){
        tills[i].Tk = 0;
        tills[i].count = 0;
    }
    buyers.clear();
    not_served = 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    srand(time(nullptr));

    for(unsigned i = 0; i < repeatCount; ++i){
        clear();
        while(true){
            buyers.push_back(-a * log(rnd()));
            if(buyers.size() > 0) buyers[buyers.size() - 1] += buyers[buyers.size() - 2];
            if(buyers[buyers.size() - 1] > T) break;
            moddeling();
        }

        for(unsigned i = 0; i < N; ++i){
            tillsAcc[i] += tills[i].count;
        }
        tillsAcc[N] += not_served;


    }
    for(unsigned i = 0; i < N; ++i){
        std::cout << "Till #" << (i+1) << ": " << tillsAcc[i] / (repeatCount * 1.0) << std::endl;
    }
    std::cout << "Not served: " << tillsAcc[N] / (repeatCount * 1.0) << std::endl;

    return app.exec();
}
