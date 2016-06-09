/*
This is a followup question for Geohash.

Convert a Geohash string to latitude and longitude.

Try http://geohash.co/.

Check how to generate geohash on wiki: Geohash or just google it for more details.

Have you met this question in a real interview? Yes
Example
Given "wx4g0s", return lat = 39.92706299 and lng = 116.39465332.

Return double[2], first double is latitude and second double is longitude.
*/

class GeoHash {
public:
    /**
     * @param geohash a base32 string
     * @return latitude and longitude a location coordinate pair
     */
    vector<double> decode(string& geohash) {
        // Write your code here
        
        /*
        vector<int> test = ReverseToBase32("w");
        
        for(int i=0; i<test.size();i++){
            cout<<test[i]<<" ";
        }
        cout<<endl;
        */
        
        vector<int> binaryCode= ReverseToBase32(geohash);
        vector<int> latitdueVector;
        vector<int> longitudeVector;
        
        //cout<<binaryCode.size()<<endl;
        //generate latitdueVector and longitudeVector
        for(int i=0; i<binaryCode.size(); i++){
            if(i%2 ==0){
                longitudeVector.push_back(binaryCode[i]);         
            }else{
                latitdueVector.push_back(binaryCode[i]);
            }
        }
        
        //cout<<longitudeVector.size()<<endl;
        //cout<<latitdueVector.size()<<endl;
        
        double leftLatitude = -90;
        double rightLatitude = 90;
        
        double left = -180;
        double right = 180;
        
        double latitude;
        double longitude;
        

        //???????why it need size +1??
        for(int i=0;i<latitdueVector.size()+1;i++){
            latitude = (leftLatitude + rightLatitude)/2;
            //cout<<leftLatitude<<" "<<rightLatitude<<" "<<latitude<<endl;
            if(latitdueVector[i]==1){
                leftLatitude = latitude;
            }else{
                rightLatitude = latitude;
            }
        }
        
        for(int i=0;i<longitudeVector.size()+1;i++){
            longitude = (left + right)/2;
            if(longitudeVector[i]==1){
                left = longitude;
            }else{
                right = longitude;
            }
        }
        
        vector<double> res;
        res.push_back(latitude);
        res.push_back(longitude);
        
        return res;
    }
    
    vector<int> ReverseToBase32(string geohash){
        string base32 = "0123456789bcdefghjkmnpqrstuvwxyz";
        vector<int> number;
        vector<int> res;
        //FIND NUMBER
        for(int i=0; i<geohash.size(); i++){
            for(int j=0; j<base32.size(); j++){
                if(geohash[i] == base32[j]){
                    number.push_back(j);
                    //cout<<j<<endl;
                    break;
                }
            }
        }
        
        
        for(int i=0;i<number.size();i++){
            //cout<<number[i]<<endl;
            //convert number to binary
            vector<int> tmp;
            while(1){
                if(number[i]%2==1){
                    tmp.push_back(1);
                }else{
                    tmp.push_back(0);
                }
                
                number[i]=number[i]/2;
                if(number[i]==0) break;
            }
            
            //generate binary vector 
            while(tmp.size()<5){
                tmp.push_back(0);
            }
            
            
            
            reverse(tmp.begin(), tmp.end());
            
            /*
            for(int j=0;j<tmp.size();j++){
                cout<<tmp[j]<<" ";
            }
            cout<<endl;
            */
            res.insert(res.end(), tmp.begin(), tmp.end());
            
            tmp.clear();
        }
        
        return res;
    }
};