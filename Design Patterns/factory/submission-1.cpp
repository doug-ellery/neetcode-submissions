class Vehicle {
public:
    virtual string getType() = 0;
};

class Car : public Vehicle {
public:
    string getType() override {
        return "Car";
    }
};

class Bike : public Vehicle {
public:
    string getType() override {
        return "Bike";
    }
};

class Truck : public Vehicle {
public:
    string getType() override {
        return "Truck";
    }
};

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;
};

class CarFactory : public VehicleFactory {
    // Write your code here
private:
    vector<Car*> my_cars;
public:
    CarFactory(){my_cars = {};}
    Vehicle* createVehicle() override {
        return new Car();
    }
    ~CarFactory(){
        for(Car* car : my_cars){delete(car);}
    }
};

class BikeFactory : public VehicleFactory {
    // Write your code here
private:
    vector<Bike*> my_bikes;
public:
    BikeFactory(){my_bikes = {};}
    Vehicle* createVehicle() override {
        return new Bike();
    }
    ~BikeFactory(){
        for(Bike* bike : my_bikes){delete(bike);}
    }
};

class TruckFactory : public VehicleFactory {
    // Write your code here
private:
    vector<Truck*> my_trucks;
public:
    TruckFactory(){my_trucks = {};}
    Vehicle* createVehicle() override {
        return new Truck();
    }
    ~TruckFactory(){
        for(Truck* truck : my_trucks){delete(truck);}
    }
};
