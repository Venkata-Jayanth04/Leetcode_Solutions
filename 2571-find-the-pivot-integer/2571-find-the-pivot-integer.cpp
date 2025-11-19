class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        for(int x = 1; x <= n; x++){
            sum = sum + x;
            if(sum == data(x,n)){
                return x;
            }
        }
        return -1;
    }
    int data(int x, int n){
        int tot = 0;
        for(int i = x; i <= n; i++){
            tot = tot + i;
        }
        return tot;
    }
};