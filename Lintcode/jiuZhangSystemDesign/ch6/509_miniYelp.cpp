/*
Design a simple yelp system. Support the following features:

Add a restaurant with name and location.
Remove a restaurant with id.
Search the nearby restaurants by given location.
A location is represented by latitude and longitude, both in double. A Location class is given in code.

Nearby is defined by distance smaller than k Km .

Restaurant class is already provided and you can directly call Restaurant.create() to create a new object. Also, a Helper class is provided to calculate the distance between two location, use Helper.get_distance(location1, location2).

A GeoHash class is provided to convert a location to a string. Try GeoHash.encode(location) to convert location to a geohash string and GeoHash.decode(string) to convert a string to location.

 Notice

Learn about GeoHash http://www.lintcode.com/en/help/geohash/


addRestauraunt("Lint Cafe", 10.4999999, 11.599999) // return 1
addRestauraunt("Code Cafe", 10.4999999, 11.512109) // return 2
neighbors(10.5, 11.6, 6.7) // return ["Lint Cafe"]
removeRestauraunt(1) 
neighbors(10.5, 9.6, 6.7) // return []


// The distance between location(10.5, 11.6) and "Lint Code" is 0.0001099 km
// The distance between location(10.5, 11.6) and "Code Code" is 9.6120978 km
*/



#include <iostream>

/**
 * Definition of Location:
 * class Location {
 * public:
 *     double latitude, longitude;
 *     static Location create(double lati, double longi) {
 *         // This will create a new location object
 *     }
 * };
 * Definition of Restaurant
 * class Restaurant {
 * public:
 *     int id;
 *     string name;
 *     Location location;
 *     static Restaurant create(string &name, Location &location) {
 *         // This will create a new restaurant object,
 *         // and auto fill id
 *     }
 * };
 * Definition of Helper
 * class Helper {
 * public:
 *     static get_distance(Location &location1, Location &location2) {
 *         // return distance between location1 and location2.
 *     }
 * };
 * class GeoHash {
 * public:
 *     static string encode(Location &location) {
 *         // return convert location to a GeoHash string
 *     }
 *     static Location decode(string &hashcode) {
 *          // return convert a GeoHash string to location
 *     }
 * };
 */

class comparator{
public:
    comparator(){
        
    }
    
    bool operator() (const pair<string, double>& lhs, const pair<string, double>& rhs) const{
        return lhs.second > rhs.second;
    }
}; 

class MiniYelp {
private:
    map<int, Restaurant> restaurantMap;
public:
    MiniYelp() {
        // initialize your data structure here.
        restaurantMap.clear();
    }
    
    // @param name a string
    // @param location a Location
    // @return an integer, restaurant's id
    int addRestaurant(string name, Location &location) {
        // Write your code here
        Restaurant tmp = Restaurant::create(name, location);
        int restaurantID = tmp.id;
        restaurantMap[restaurantID] = tmp;
        return restaurantID;
    }

    // @param restaurant_id an integer
    void removeRestaurant(int restaurant_id) {
        // Write your code here
        restaurantMap.erase(restaurant_id);
    }

    // @param location a Location
    // @param k an integer, distance smaller than k miles
    // @return a list of restaurant's name and sort by 
    // distance from near to far.
    vector<string> neighbors(Location &location, double k) {
        // Write your code here
        priority_queue<pair<string, double> ,vector<pair<string, double> >, comparator> pq;
        vector<string> res;
        map<int, Restaurant>::iterator it=restaurantMap.begin();
        
        for(;it!=restaurantMap.end();++it){
            double dis = Helper::get_distance( (*it).second.location, location);
            if(dis<=k){
                pair<string, double> tmp;
                tmp=make_pair((*it).second.name,dis);
                pq.push(tmp);
                //res.push_back((*it).second.name);
            }        
        }
        
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
    }
};

int main(){

    return 0;
}