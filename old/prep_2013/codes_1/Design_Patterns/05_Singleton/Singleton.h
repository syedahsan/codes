#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>

class S
{
        private:
                S() {};
                S(const S &other); // Don't implement
                void operator=(const S &rhs); // Don't implement

        public:
                static S& getInstance()
                {
                        static S instance;
                        return instance;
                }
};

template <class T>
class Singleton
{
        private:
                Singleton(const Singleton&);
                Singleton& operator=(const Singleton&);
        protected:
                Singleton() {};
                virtual ~Singleton() {};
        public:
                static T& getInstance() {
                        static T instance;
                        return (instance);
                }
};

/* A sample class to be made into singleton */
class MyClass: public Singleton<MyClass>
{
        private:
                int x;
        protected:
                friend class Singleton<MyClass>;
                MyClass(): x(0) {};
        public:
                void setValue(int _x) { x = n; }
                int getValue() const { return(x); }
};

class Logger
{
        public:
                Logger() {};
                ~Logger() {};
                bool openLogFile(string);
                void writeToLogFile(string);
                bool closeLogFile(string);
};

/*
 * typedef Singleton<Logger> LoggerSingleton;
 * 
 * int main()
 * {
 *      ...
 *      LoggerSingleton::getInstance()->openLogFile("abc.txt");
 *      ...
 * }
 *
 */

#endif /* __SINGLETON_H__
