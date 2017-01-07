#include <iostream>
#include <queue>
#include <stack>
#define R 3
#define C 6
using namespace std;

int spiral(int r, int c, int a[R][C]){
    int x=0;
    int y=r;
    int z=0;
    int w=c;
    
    while(x<y && z<w){
        for(int i=z;i<w;i++){
        cout<<a[x][i]<<" ";
    }
    x++;
    for(int i=x;i<y;++i){
        cout<<a[i][w-1]<<" ";
    }
    w--;
    if(x<y){
        for(int i=w-1;i>=z;i--){
        cout<<a[y-1][i]<<" ";
        }
    }
    
    y--;
    
    if(z<w){
        for(int i=y-1;i>x;i--){
        cout<<a[i][z]<<" ";
        }
    }
    
    z++;
    
    }
}

int main()
{
    int a[R][C] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
 
    spiral(R, C, a);
    return 0;
}