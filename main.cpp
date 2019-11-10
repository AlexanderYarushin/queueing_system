#include <QCoreApplication>

struct till{
    int count = 0;
    int Tk;
};

static unsigned Tz = 2; //Время обслуживания одного покупателя
static const unsigned N = 10; //Колличество касс
static unsigned T = 100; //Время работы модели
static till tills[N]; //Массив касс

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    return a.exec();
}
