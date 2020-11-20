#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 4;        //节点个数

//finalPath[] 存储最终解决方案，售货员路径
int finalPath[N];

//visited[] 记录已经经过的节点在特殊路线上
bool visited[N];

//存储最短路径长度
int finalRes = INT_MAX;

//将目前解决方案复制给最终解决方案
void copyToFinal(int currPath[]){
    for(int i = 0; i < N; i++){
        finalPath[i] = currPath[i];
    }
    finalPath[N] = currPath[0];
}

//寻找终点是顶点i的最短边
int firstMin(int adj[N][N], int i){
    int min = INT_MAX;
    for(int k=0; k<N; k++){
        if(adj[i][k]<min && i != k)
            min = adj[i][k];
    }
    return min;
}
//寻找终点是顶点i的第二最短边
int secondMin(int adj[N][N], int i){
    int first = INT_MAX, second = INT_MAX;
    for(int j=0; j<N; j++){
        if(i == j)
            continue;
        if(adj[i][j] <= first)
        {
            second = first;
            first = adj[i][j];
        }
        else if(adj[i][j] <= second && adj[i][j] != first)
            second = adj[i][j];
    }
    return second;
}

void TSPRec(int adj[N][N], int curr_bound, int curr_weight, 
            int level, int curr_path[]) 
{  
    //level == N, 经过所有节点一次
    if (level==N) 
    {
        //检查是否有边从末节点到第一个节点
        if (adj[curr_path[level-1]][curr_path[0]] != 0) 
        { 
            //目前解决方案的代价
            int curr_res = curr_weight + 
                    adj[curr_path[level-1]][curr_path[0]]; 
  
            //如果目前代价小，更新最终代价。
            if (curr_res < finalRes) 
            { 
                copyToFinal(curr_path); 
                finalRes = curr_res; 
            } 
        } 
        return; 
    } 
    for (int i=0; i<N; i++) 
    { 
        //如果下一个顶点不同（邻接矩阵中的对角线条目，并且尚未访问），考虑下一个顶点
        if (adj[curr_path[level-1]][i] != 0 && 
            visited[i] == false) 
        { 
            int temp = curr_bound; 
            curr_weight += adj[curr_path[level-1]][i]; 
  
            if (level==1) 
              curr_bound -= ((firstMin(adj, curr_path[level-1]) + 
                             firstMin(adj, i))/2); 
            else
              curr_bound -= ((secondMin(adj, curr_path[level-1]) + 
                             firstMin(adj, i))/2); 
  
            //curr_bound + curr_weight实际节点下界，小于finalRes则进一步探索节点
            if (curr_bound + curr_weight < finalRes) 
            { 
                curr_path[level] = i; 
                visited[i] = true; 
  
                //下一节点调用TSPRec
                TSPRec(adj, curr_bound, curr_weight, level+1, 
                       curr_path); 
            } 
            curr_weight -= adj[curr_path[level-1]][i]; 
            curr_bound = temp; 
  
            //重置路线数组
            memset(visited, false, sizeof(visited)); 
            for (int j=0; j<=level-1; j++) 
                visited[curr_path[j]] = true; 
        } 
    } 
} 
//最终路径
void TSP(int adj[N][N]) 
{ 
    int curr_path[N+1]; 
    //初始curr_path[]数组和visited[]数组
    int curr_bound = 0; 
    memset(curr_path, -1, sizeof(curr_path)); 
    memset(visited, 0, sizeof(curr_path)); 

    //计算最初下限
    for (int i=0; i<N; i++) 
        curr_bound += (firstMin(adj, i) + 
                       secondMin(adj, i)); 
  
    //舍入下限到一个整数 
    curr_bound = (curr_bound&1)? curr_bound/2 + 1 : 
                                 curr_bound/2; 
    //从节点1出发，curr_path[]中第一个点为0
    visited[0] = true; 
    curr_path[0] = 0; 

    //调用TSPRec
    TSPRec(adj, curr_bound, 0, 1, curr_path); 
} 

int main()
{
    int adj[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    TSP(adj);
    cout<<"Minimum cost : "<<finalRes<<endl;
    cout<<"Initial node: "<<finalPath[0]<<endl;
    cout<<"Path taken:";
    for(int i=0; i<N; i++){
        cout<<finalPath[i]<<"->";
    }
    cout<<finalPath[0];
    return 0;
}