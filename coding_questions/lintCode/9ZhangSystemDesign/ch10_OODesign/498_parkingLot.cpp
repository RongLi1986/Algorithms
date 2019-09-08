/*
Parking Lot
Design a parking lot.

see CC150 OO Design for details.
1) n levels, each level has m rows of spots and each row has k spots.So each level has m x k spots.
2) The parking lot can park motorcycles, cars and buses
3) The parking lot has motorcycle spots, compact spots, and large spots
4) Each row, motorcycle spots id is in range [0,k/4)(0 is included, k/4 is not included), compact spots id is in range [k/4,k/4*3) and large spots id is in range [k/4*3,k).
5) A motorcycle can park in any spot
6) A car park in single compact spot or large spot
7) A bus can park in five large spots that are consecutive and within same row. it can not park in small spots

Have you met this question in a real interview? Yes
Example
level=1, num_rows=1, spots_per_row=11
parkVehicle("Motorcycle_1") // return true
parkVehicle("Car_1") // return true
parkVehicle("Car_2") // return true
parkVehicle("Car_3") // return true
parkVehicle("Car_4") // return true
parkVehicle("Car_5") // return true
parkVehicle("Bus_1") // return false
unParkVehicle("Car_5")
parkVehicle("Bus_1") // return true
*/

#include <iostream>

// enum type for Vehicle
enum class VehicleSize {
    Motorcycle,
    Compact,
    Large
};

class Vehicle {
public:
    virtual VehicleSize size() {}
    virtual int spot_num() {}
};

class Bus: public Vehicle {
public:
    VehicleSize size() {
        return VehicleSize::Large;
    }
    
    int spot_num() {
        return 5;
    }
};

class Car: public Vehicle {
public:
    VehicleSize size() {
        return VehicleSize::Compact;
    }
    
    int spot_num() {
        return 1;
    }
};

class Motorcycle: public Vehicle {
public:
    VehicleSize size() {
        return VehicleSize::Motorcycle;
    }
    
    int spot_num() {
        return 1;
    }
};

class Level {
private:
    vector<vector<Vehicle*>> spots;
    int num_rows;
    int spots_per_row;
    
public:
    Level(int num_rows, int spots_per_row) {
        for (int i = 0 ; i < num_rows; ++i) {
            spots.push_back(vector<Vehicle*>(spots_per_row, NULL));
        }
        this->num_rows = num_rows;
        this->spots_per_row = spots_per_row;
    }
    
    bool park_vehicle(Vehicle* vehicle) {
        for (int row = 0; row < num_rows; ++row) {
            int start;
            
            if(vehicle->size() == VehicleSize::Motorcycle){
                start = 0;
            }else if (vehicle->size() == VehicleSize::Compact) {
                start = spots_per_row / 4;
            } else if (vehicle->size() == VehicleSize::Large) {
                start = spots_per_row / 4 * 3;
            }
            
            for (int i = start; i < spots_per_row - vehicle->spot_num() + 1; ++i) {
                bool can_park = true;
                
                //handle bus parking
                for (int j = i; j < i +  vehicle->spot_num(); ++j) {
                    if (spots[row][j] != NULL) {
                        can_park = false;
                        break;
                    }
                }
                
                if (can_park) {
                    for (int j = i; j < i + vehicle->spot_num(); ++j) {
                        spots[row][j] = vehicle;
                    } 
                    return true;
                }
            }
        }
        
        return false;
    }
    
    void unpark_vehicle(Vehicle *vehicle) {
        for (int row = 0; row < num_rows; ++row) {
            for (int i = 0; i < spots_per_row; ++i)
                if (spots[row][i] == vehicle) {
                    spots[row][i] = NULL;
                }
        }
    }
};

class ParkingLot {
private:
    vector<Level*> levels;
    map<Vehicle*, Level*> vehicle_to_level;
public:
    // @param n number of leves
    // @param num_rows  each level has num_rows rows of spots
    // @param spots_per_row each row has spots_per_row spots
    ParkingLot(int n, int num_rows, int spots_per_row) {
        for (int i = 0; i < n; ++i) {
            Level *level = new Level(num_rows, spots_per_row);
            levels.push_back(level);
        }
    }

    // Park the vehicle in a spot (or multiple spots)
    // Return false if failed
    bool parkVehicle(Vehicle* vehicle) {
        for (int i = 0; i < levels.size(); ++i) {
            if (levels[i]->park_vehicle(vehicle)) {
                vehicle_to_level[vehicle] = levels[i];
                return true;
            }
        }
        return false;
    }

    // unPark the vehicle
    void unParkVehicle(Vehicle* vehicle) {
        Level *level = vehicle_to_level[vehicle];
        if (level) {
            level->unpark_vehicle(vehicle);
        }
    }
};