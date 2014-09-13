#include <iostream>
#include <vector>

#include "WeatherData.h"

using namespace std;

Observable::Observable():
        changed(false)
{
}

Observable::Observable(const Observable& other):
        changed(other.changed), observers(other.observers)
{
}

void
Observable::addObserver(Observer *o)
{
        observers.push_back(o);
}

void
Observable::deleteObserver(Observer *o)
{
        for(vector<Observer*>::iterator it = observers.begin();
            it != observers.end(); ++it) {
                if (*it == o) {
                        observers.erase(it);
                        break;
                }
        }
}

void
Observable::notifyObservers(void *arg)
{
        if (changed) {
                for(vector<Observer*>::iterator it = observers.begin();
                    it != observers.end(); ++it) {
                        (*it)->update(this, arg);
                }
                changed = false;
        }
}

void
Observable::notifyObservers()
{
        notifyObservers(NULL);
}

void
Observable::setChanged()
{
        changed = true;
}

WeatherData::WeatherData():
        temperature(0), humidity(0), pressure(0)
{
}

WeatherData::WeatherData(const WeatherData& other):
        Observable(other)
{
}

void
WeatherData::measurementsChanged()
{
        setChanged();
        notifyObservers();
}

void
WeatherData::setMeasurements(float temperature, float humidity, float pressure)
{
        this->temperature = temperature;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementsChanged();
}

float
WeatherData::getTemperature()
{
        return (temperature);
}

float
WeatherData::getHumidity()
{
        return (humidity);
}

float
WeatherData::getPressure()
{
        return (pressure);
}

CurrentConditionDisplay::CurrentConditionDisplay()
{
}

void
CurrentConditionDisplay::update(Observable *obs, void *arg)
{
        WeatherData *weatherData = dynamic_cast<WeatherData*>(obs);
        temperature = weatherData->getTemperature();
        humidity = weatherData->getHumidity();
        display();
}

void
CurrentConditionDisplay::display()
{
        cout << "Current Conditions: Temperature " << temperature << "F degrees and "
            << humidity << "%% humidity" << endl;
}


