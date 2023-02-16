#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
public:
    Vehicle(string id) 
    :   m_id(id)
    {}
    virtual ~Vehicle()
    {};
    string id() const {
        return m_id;
    }
    virtual bool canHover() const =0;
    virtual string description() const = 0;
private:
    string m_id;
};

class Drone : public Vehicle
{
public:
    Drone(string id)
        : Vehicle(id)
    {};
    virtual ~Drone() {
        cout << "Destroying " << id() << ", a drone" << endl;
    }
    virtual bool canHover() const {
        return true;
    }
    virtual string description() const {
        return "a drone";
    }
};

class Balloon : public Vehicle
{
public:
    Balloon(string id, int diameter)
        : Vehicle(id), m_diameter(diameter)
    {

    }
    virtual ~Balloon() {
        cout << "Destroying the balloon " << id() << endl;
    }
    virtual bool canHover() const {
        return true;
    }
    virtual string description() const {
        if (m_diameter >= 8)
            return "a large balloon";
        else
            return "a small balloon";
    }
private:
    int m_diameter;
};

class Satellite : public Vehicle
{
public:
    Satellite(string id) 
        : Vehicle(id) 
    {};
    virtual ~Satellite() {
        cout << "Destroying the satellite " << id() << endl;
    }
    virtual bool canHover() const {
        return false; 
    }
    virtual string description() const {
        return "a satellite";
    }
};

