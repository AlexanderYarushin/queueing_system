#include <QCoreApplication>
#include <cmath>
#include <iostream>
#include <ctime>

double rnd(){
    return rand() / (RAND_MAX * 1.0);
}

struct till{
    double count = 0;
    double Tk = 0;
};

static double Tz = 1; //Время обслуживания одного покупателя
static const unsigned N = 10; //Колличество касс
static double T = 1000; //Время работы модели
static till tills[N]; //Массив касс
static std::vector<double> buyers; //Массив покупателей
static double a = 1.0/20.0;
static unsigned not_served = 0;

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

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    srand(time(nullptr));

    while(true){
        buyers.push_back(-a * log(rnd()));
        if(buyers.size() > 0) buyers[buyers.size() - 1] += buyers[buyers.size() - 2];
        if(buyers[buyers.size() - 1] > T) break;
        moddeling();
    }

    for(unsigned i = 0; i < N; ++i){
        std::cout << "Till #" << (i+1) << " - " << tills[i].count << std::endl;
    }
    std::cout << "Not served: " << not_served << std::endl;

    return app.exec();
}
