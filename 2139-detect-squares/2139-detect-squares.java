class DetectSquares {
    int[][] data;
    public DetectSquares() {
        data=new int[1001][1001]; // array to store count of each point (O(1) lookup in 2-D array)
    }
    
    public void add(int[] point) {
        int a=point[0];
        int b=point[1];
        data[a][b]+=1;
    }
    
    public int count(int[] point) {
        int a=point[0];
        int b=point[1];
        int count=0; // stores count of total squares with one vertex as (a,b)
        for(int i=1;i<=1000;i++){  //loop where i denotes square with edge length i , check for square in each of 4 quadrants wrt (a,b)
            
            if(isValid(a+i,b) && isValid(a,b+i) && isValid(a+i,b+i)){
                count+=(data[a+i][b]*data[a][b+i]*data[a+i][b+i]);
            }
            if(isValid(a+i,b) && isValid(a,b-i) && isValid(a+i,b-i)){
                count+=(data[a+i][b]*data[a][b-i]*data[a+i][b-i]);
            }
            if(isValid(a-i,b) && isValid(a,b+i) && isValid(a-i,b+i)){
                count+=(data[a-i][b]*data[a][b+i]*data[a-i][b+i]);
            }
            if(isValid(a-i,b) && isValid(a,b-i) && isValid(a-i,b-i)){
                count+=(data[a-i][b]*data[a][b-i]*data[a-i][b-i]);
            }
        }
        
        return count;
    }
    public boolean isValid(int x,int y){
        if(x>=0 && x<=1000 && y>=0 && y<=1000) return true;
        return false;
    }
}