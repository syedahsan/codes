#ifndef __DUCK_H__
#define __DUCK_H__

#include <iostream>

using namespace std;

/* FLY BEHAVIOR - Interface */
class FlyBehaviour
{
	public:
		virtual ~FlyBehaviour() {};
		virtual void fly() = 0;
};

class FlyWithWings: public FlyBehaviour
{
	public:
		void fly();
};

class FlyNoWay: public FlyBehaviour
{
	public:
		void fly();
};

class FlyRocketPowered: public FlyBehaviour
{
	public:
		void fly();
};

/* QUACK BEHAVIOR */
class QuackBehavior
{
	public:
		virtual ~QuackBehavior() {};
		virtual void quack() = 0;
};

class Quack: public QuackBehavior
{
	public:
		void quack();
};

class Squeak: public QuackBehavior
{
	public:
		void quack();
};

class MuteQuack: public QuackBehavior
{
	public:
		void quack();
};

/* DUCK */
class Duck
{
	protected:
		FlyBehaviour *flyBehavior;
		QuackBehavior *quackBehavior;

	public:
                Duck() {};
		void swim();
		void performFly();
		void performQuack();
		void setFlyBehavior(FlyBehaviour *fb);
		void setQuackBehavior(QuackBehavior *qb);

                /* NOTE TO SELF: either define a virtual function in a base class *
                 * or declare it as a pure virtual function                       */
		virtual void display() = 0;
};

class MallarDuck: public Duck
{
	public:
		MallarDuck();
		void display();
};

class RedheadDuck: public Duck
{
	public:
		RedheadDuck();
		void display();
};

class RubberDuck: public Duck
{
	public:
		RubberDuck();
		void display();
};

class DecoyDuck: public Duck
{
	public:
		DecoyDuck();
		void display();
};

#endif
