/*
Geohash is a hash function that convert a location coordinate pair into a base32 string.

Check how to generate geohash on wiki: Geohash or just google it for more details.

Try http://geohash.co/.

You task is converting a (latitude, longitude) pair into a geohash string.

Given lat = 39.92816697, lng = 116.38954991 and precision = 12 which indicate how long the hash string should be. You should return wx4g0s8q3jf9.

The precision is between 1 ~ 12.
*/

class GeoHash {
public:
    /**
     * @param latitude, longitude a location coordinate pair
     * @param precision an integer between 1 to 12
     * @return a base32 string
     */
    string encode(double latitude, double longitude, int precision) {
        // Write your code here
        double leftLatitude = -90;
        double rightLatitude = 90;
        
        double left = -180;
        double right = 180;
        
        vector<int> codec;
        string res;
        int precision_copy = precision;
        if(precision_copy%2!=0)
            precision_copy++;
        
        for(int i=0;i<precision_copy/2 * 5; i++){
            double midLatitdue = (leftLatitude + rightLatitude)/2;
            double mid = (left + right)/2;
            
            if(longitude > mid){
                codec.push_back(1);
                left=mid;
            }else{
                codec.push_back(0);
                right=mid;
            }
            
            if(latitude > midLatitdue){
                codec.push_back(1);
                leftLatitude = midLatitdue;
            }else{
                codec.push_back(0);
                rightLatitude = midLatitdue;
            }
        }
        
        int cnt = 0;
        vector<int> tmp;
        for(int i=0;i<codec.size();i++){
            //cout<<codec[i]<< " ";
            tmp.push_back(codec[i]);
            cnt++;
            if(cnt==5){
                res+=toBase32(tmp);
                cnt=0;
                tmp.clear();
            }
        }
        
        if(precision%2!=0){
            int size = res.size();
            res = res.substr(0, size-1);
        }
        
        //cout<<endl;
        return res;
    }
    
    char toBase32(vector<int> input){
        string base32 = "0123456789bcdefghjkmnpqrstuvwxyz";
        reverse(input.begin(),input.end());
        int number = 0;
        
        //find number
        for(int i=0;i<input.size();i++){
            if(input[i]==1){
                number+=pow(2,i);
            }
        }
        //cout<<number<<endl;
        //find return char
        
        return base32[number];
    }
};