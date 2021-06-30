#include <iostream>
using namespace std;

int main(){
    int n,m,q;
    cin>>n>>m>>q;

    int arr[n+1][m+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }

    int x=-1,y=0,dir=0,flag=0;
    long long index=0;
    int path[n*m+2][2];
    path[index][0] = x;
    path[index][1] = y;
    index++;

    for(int i=x+1;i<m;i++){
        if(arr[y][i] == 1){
            x=i;
            flag=1;
            path[index][0] = x;
            path[index][1] = y;
            index++;
            dir=1;
            break;
        }
    }
    if(flag==0){
        x = m;
        path[index][0] = x;
        path[index][1] = y;
        index++;
        dir = 2;
    }

    while(x!=-1 || y!=0){
        if(dir==0){
            flag=0;
            for(int i=x+1;i<m;i++){
                if(arr[y][i] == 1){
                    x=i;
                    flag=1;
                    path[index][0] = x;
                    path[index][1] = y;
                    index++;
                    dir=1;
                    break;
                }
            }
            if(flag==0){
                x=m;
                path[index][0] = x;
                path[index][1] = y;
                index++;
                dir = 2;
            }
        }else if(dir==1){
            flag=0;
            for(int i=y+1;i<n;i++){
                if(arr[i][x] == 1){
                    y=i;
                    flag=1;
                    path[index][0] = x;
                    path[index][1] = y;
                    index++;
                    dir=0;
                    break;
                }
            }
            if(flag==0){
                y=n;
                path[index][0] = x;
                path[index][1] = y;
                index++;
                dir = 3;
            }
        }else if(dir==2){
            flag=0;
            for(int i=x-1;i>=0;i--){
                if(arr[y][i] == 1){
                    x=i;
                    flag=1;
                    path[index][0] = x;
                    path[index][1] = y;
                    index++;
                    dir=3;
                    break;
                }
            }
            if(flag==0){
                x=-1;
                path[index][0] = x;
                path[index][1] = y;
                index++;
                dir = 0;
            }
        }else if(dir==3){
            flag=0;
            for(int i=y-1;i>=0;i--){
                if(arr[i][x] == 1){
                    y=i;
                    flag=1;
                    path[index][0] = x;
                    path[index][1] = y;
                    index++;
                    dir=2;
                    break;
                }
            }
            if(flag==0){
                y=-1;
                path[index][0] = x;
                path[index][1] = y;
                index++;
                dir = 1;
            }
        }
    }

    index--;
    long long k;

    for(int i=0;i<q;i++){
        cin>>k;
        k = k%index;
        cout<<path[k][0]+1<<" "<<path[k][1]+1<<"\n";
    }

    return 0;
}