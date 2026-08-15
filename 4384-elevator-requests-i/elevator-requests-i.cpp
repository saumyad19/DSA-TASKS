class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int tt=0;  int curr=0;
         for(int floor: requests){
            tt+=abs(curr-floor);
            curr=floor;
         }
        return tt;
    }
};