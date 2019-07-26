int findMaxDelta(vector<int>& input){
    //solution one 
    //normal sort and find max Delta nlog(n)
    /*
    sort(input.begin(), input.end());

    int res = INT_MIN;
    for(int i=1;i<input.size();i++){
        res = max(res,abs(input[i]-input[i-1]));
    }

    return res;
    */

    //solution two 
    //try bucket sort

    //find max and min value in input array
    int maxValue = INT_MIN;
    int minValue = INT_MAX;

    for(int i=0;i<input.size();i++){
        maxValue = max(input[i], maxValue);
        minValue = min(input[i], minValue);
    }

    int range =  maxValue - minValue + 1; //8
    
    int bucketNums = (range%input.size()==0) ?range/input.size():range/input.size()+1; //2
    
    int bucketLength = range%bucketNums ==0? range/bucketNums:range/bucketNums+1; //4
    
    vector<vector<int>> buckets(bucketLength, vector<int>(2,-1));

    //put all element into buckets
    for(int i=0;i<input.size();i++){
        int index = (input[i]-minValue)/bucketNums;
        cout<<index<<endl;
        if(buckets[index][0] = -1){
            buckets[index][0] = input[i];
            buckets[index][1] = input[i];
        }else{
            buckets[index][0] = min(buckets[index][0], input[i]);
            buckets[index][1] = max(buckets[index][1], input[i]);
        }
    }

    //find bigeest gap from buckets
    int delta = 0;
    for(int i=1;i<buckets.size();i++){
        cout<<buckets[i][0]<<" "<<buckets[i][1]<<endl;
        delta = max(delta, buckets[i][0] - buckets[i-1][1]);
    }

    return delta;
}

/*
basic bucket sort


*/
vector<int> bucketSort(vector<int>& unsorted, int range){
	int[] sorted = new int[range + 1];
    for (int i = 0; i < unsorted.size(); i++){
        sorted[unsorted[i]] = unsorted[i];
    }
    return sorted;
}