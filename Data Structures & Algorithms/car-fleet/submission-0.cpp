class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

       //we need to make pair of (position, speed)
       int n=position.size();

       vector<pair<int,int>>v;
       for(int i=0;i<n;i++)
       {
        v.push_back({position[i],speed[i]});
    
       }


       //sort this descending order based on position

       sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first; 
        });
       //we need to extract each element from top and check if it makes a new 
       double max_time=0.0;
       int fleet=0;
       for(int i=0;i<n;i++)
       {
            double time=(((double)target -(double)v[i].first)/(double)v[i].second);
            if(time>max_time)
            {
                  fleet++;
                  max_time=time;
            }


       }
       //fleet or its a part of an old fleet 
       //we need to calculate the time to reacj the destination 
       // if if the car ahead has a time that is greater than or equal to the time of the car behind it.
       //then they form a fleet 
        return fleet;
    }
};
