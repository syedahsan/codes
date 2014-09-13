#include <iostream>
#include "Duck.h"

using namespace std;

int main(int argc, char **argv)
{
        Duck *mallard = new MallarDuck();
        mallard->performQuack();
        mallard->performFly();

        Duck *model = new DecoyDuck();
        model->performQuack();
        model->performFly();
        model->setFlyBehavior(new FlyRocketPowered());
        model->performFly();

        return 0;
}
