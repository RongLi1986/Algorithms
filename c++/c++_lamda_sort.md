## C++ Lamba Function

```c++
// c++ sort with lambda function

// sort vector 
vector<vector<int>> intervals;
sort(intervals.begin(), intervals.end(),
        [this](const vector<int>& a, const vector<int>& b) -> bool{ return a[0] < b[0]; }
    );

// priority queue
auto comp = []( adjist a, adjlist b ) { return a.second > b.second; };
priority_queue< adjlist_edge , vector<adjlist_edge>, decltype( comp ) >
     adjlist_pq( comp );
```