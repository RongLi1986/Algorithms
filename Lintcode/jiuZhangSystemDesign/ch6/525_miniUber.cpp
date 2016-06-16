/*
Support two basic uber features:

Drivers report their locations.
Rider request a uber, return a matched driver.
When rider request a uber, match a closest available driver with him, then mark the driver not available.

When next time this matched driver report his location, return with the rider's information.

You can implement it with the following instructions:

report(driver_id, lat, lng)
1) return null if no matched rider.
2) return matched trip information.

request(rider_id, lat, lng)
1) create a trip with rider's information.
2) find a closest driver, mark this driver not available.
3) fill driver_id into this trip.
4) return trip

This is the definition of Trip in Java:

public class Trip {
    public int id; // trip's id, primary key
    public int driver_id, rider_id; // foreign key
    public double lat, lng; // pick up location
}

report(1, 36.1344, 77.5672) // return null
report(2, 45.1344, 76.5672) // return null
request(2, 39.1344, 76.5672) // return a trip, LOG(INFO): Trip(rider_id: 2, driver_id: 1, lat: 39.1344, lng: 76.5672)
report(1, 38.1344, 75.5672) // return a trip, LOG(INFO): Trip(rider_id: 2, driver_id: 1, lat: 39.1344, lng: 76.5672)
report(2, 45.1344, 76.5672) // return null
*/


#include <iostream>

/**
 * Definition of Trip:
 * class Trip {
 * public:
 *     int id; // trip's id, primary key
 *     int driver_id, rider_id; // foreign key
 *     double lat, lng; // pick up location
 *     Trip(int rider, double lat, double lng);
 * }
 * Definition of Helper
 * class Helper {
 * public:
 *     static double get_distance(double lat1, double lng1,
 *                              double lat2, double lng2) {
 *         // return distance between (lat1, lng1) and (lat2, lng2)
 *     }
 * };
 */
 
class MiniUber {
private:
    unordered_map<int, Trip*> driverMap; //driver_id and available
    unordered_map<int, Trip*> riderMap; //rider_id and available
    map<int, pair<double, double> > driverQueue; //driverID and its location
public:
    MiniUber() {
        // initialize your data structure here.
        riderMap.clear();
        driverMap.clear();
        driverQueue.clear();
    }

    // @param driver_id an integer
    // @param lat, lng driver's location
    // return matched trip information if there have matched rider or NULL
    Trip* report(int driver_id, double lat, double lng) {
        // Write your code here
        if(driverMap.find(driver_id) == driverMap.end()){ //it is not in a trip
            if(driverQueue.find(driver_id) == driverQueue.end()){ //new driver
                pair<double,double> pos;
                pos=make_pair(lat,lng);
                
                
                driverQueue[driver_id] = pos;
            }else{                  //update drive's infomation 
                
                pair<double,double> pos;
                pos=make_pair(lat,lng);
                
                
                driverQueue[driver_id] = pos;
            }
            
            return NULL;                       
        }else{
            return driverMap[driver_id];   //return trip 
        }
    }

    // @param rider_id an integer
    // @param lat, lng rider's location
    // return a trip
    Trip* request(int rider_id, double lat, double lng) {
        // Write your code here
        if(riderMap.find(rider_id) == riderMap.end()){  //new request
            Trip* trip = new Trip(rider_id, lat, lng);
            trip->driver_id = findDriver(lat, lng);
            if(trip->driver_id <0) {
                delete trip;
                return NULL;
            }
            
            driverMap[trip->driver_id] =trip;
            riderMap[rider_id]= trip;
            
            return trip;
        }else{
            
            Trip* trip = new Trip(rider_id, lat, lng);
            trip->driver_id = findDriver(lat, lng);
            if(trip->driver_id <0) {
                delete trip;
                return NULL;
            }
            
            driverMap[trip->driver_id] =trip;
            riderMap[rider_id]= trip;
            
            return trip;
            //return riderMap[rider_id];
        }
    }
    
    int findDriver(double lat, double lng){
        double minDis = 1.79769e+308;
        int driver_min = INT_MIN;
        for(map<int, pair<double, double> >::iterator it=driverQueue.begin();it!=driverQueue.end();it++){
            double dis = Helper::get_distance(lat, lng, (*it).second.first, (*it).second.second);
        
            if(dis < minDis){
                minDis = dis;
                driver_min = (*it).first;
            }else if(dis == minDis){
                if( driver_min < (*it).first){
                    driver_min = (*it).first;
                }
            }
        }
        
        if(driver_min==INT_MIN)
            return -1;
        
        driverQueue.erase(driver_min);
        
        return driver_min;
    }
};

int main(){

    return 0;
}