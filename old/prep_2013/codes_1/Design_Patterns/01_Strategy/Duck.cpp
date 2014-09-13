#include "Duck.h"

void FlyWithWings::fly()
{
	cout << "I am flying" << endl;
}

void FlyNoWay::fly()
{
	cout << "I don't know how to fly" << endl;
}

void FlyRocketPowered::fly()
{
	cout << "I am flying with a rocket" << endl;
}

void Quack::quack()
{
	cout << "Quack!" << endl;
}

void Squeak::quack()
{
	cout << "Squeak" << endl;
}

void MuteQuack::quack()
{
	cout << "<<silence>>" << endl;
}

void Duck::swim()
{
	cout << "Splash, splash. Look am swimming!" << endl;
}

void Duck::performFly()
{
	flyBehavior->fly();
}

void Duck::performQuack()
{
	quackBehavior->quack();
}

void Duck::setFlyBehavior(FlyBehaviour *fb)
{
	flyBehavior = fb;
}

void Duck::setQuackBehavior(QuackBehavior *qb)
{
	quackBehavior = qb;
}

MallarDuck::MallarDuck() : Duck()
{
	flyBehavior = new FlyWithWings();
	quackBehavior = new Quack();
}

void MallarDuck::display()
{
	cout << "I am a Mallar Duck" << endl;
}

RedheadDuck::RedheadDuck() : Duck()
{
	flyBehavior = new FlyWithWings();
	quackBehavior = new Quack();
}

void RedheadDuck::display()
{
	cout << "I am a Redhead Duck" << endl;
}

RubberDuck::RubberDuck() : Duck()
{
	flyBehavior = new FlyNoWay();
	quackBehavior = new Squeak();
}

void RubberDuck::display()
{
	cout << "I am a Rubber Duck" << endl;
}

DecoyDuck::DecoyDuck() : Duck()
{
	flyBehavior = new FlyNoWay();
	quackBehavior = new MuteQuack();
}

void DecoyDuck::display()
{
	cout << "I am a Decoy Duck" << endl;
}

