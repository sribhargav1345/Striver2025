lass Solution {
    public:
      int floorSqrt(int n) {
          // Your code goes here
          int low = 1;
          int high = n;
          
          while(low <= high)
          {
              int mid = (low+high)/2;
              
              if(mid*mid == n) return mid;
              else if(mid*mid > n){
                  high = mid - 1;
              }
              else
              {
                  low = mid + 1;
              }
          }
          return high;
      }
  };