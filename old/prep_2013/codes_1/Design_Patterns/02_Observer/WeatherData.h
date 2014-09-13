#ifndef __WEATHER_DATE_H__
#define __WEATHER_DATE_H__

#include <iostream>
#include <vector>

using namespace std;

class Observable;

/* Observer Interface */
class Observer
{
        public:
                virtual ~Observer() {};
                virtual void update(Observable *obs, void *arg) = 0;
};

/* Observable Class */
class Observable
{
        public:
                Observable();
                Observable(const Observable& other);
                virtual ~Observable() {};
                void addObserver(Observer *o);
                void deleteObserver(Observer *o);
                void notifyObservers();
                void notifyObservers(void *arg);
                void setChanged();

        private:
                vector<Observer*> observers;
                bool changed;
};

/* Display Element Interface */
class DisplayElement
{
        public:
                virtual ~DisplayElement() {};
                virtual void display() = 0;
};

class WeatherData: public Observable
{
        public:
                WeatherData();
                WeatherData(const WeatherData& other);
                void measurementsChanged();
                void setMeasurements(float temperature, float humidity, float pressure);
                float getTemperature();
                float getHumidity();
                float getPressure();

        private:
                float temperature;
                float humidity;
                float pressure;
};

class CurrentConditionDisplay: public Observer, public DisplayElement
{
        public:
                CurrentConditionDisplay();
                void update(Observable *obs, void *arg);
                void display();

        private:
                float temperature;
                float humidity;
                float pressure;
};

/* TO IMPLEMENT */
#if 0
class StatisticsDisplay: public Observer, public DisplayElement
{
        public:
                StatisticsDisplay();
                void update(Observable &obs, void *arg);
                void display();

        private:
                float temperature;
                float humidity;
                float pressure;
};

class ForecastDisplay: public Observer, public DisplayElement
{
        public:
                ForecastDisplay();
                void update(Observable &obs, void *arg);
                void display();

        private:
                float temperature;
                float humidity;
                float pressure;
};

class ThirdPartyDisplay: public Observer, public DisplayElement
{
        public:
                ThirdPartyDisplay();
                void update(Observable &obs, void *arg);
                void display();

        private:
                float temperature;
                float humidity;
                float pressure;
};
#endif

#endif /* __WEATHER_DATA_H__ */
