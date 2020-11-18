#include<iostream>
using namespace std;

void findans(double **graph, int nodes, int time, int start, double p, double answer[])
{
    
    if(time <= 0)
    {
        answer[start] += p;
        return;
    }

    for(int i=1;i<=nodes;i++)
        if(graph[start][i] != 0)
        {
            p *= graph[start][i];
            findans(graph, nodes, time-10 , i , p ,answer);
            p /= graph[start][i];
        }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int nodes,edges,time;
        cin>>nodes>>edges>>time;
        double **graph = new double*[nodes];
        for(int i=1;i<=nodes;i++)
        {
            graph[i] = new double[nodes];
            for(int j=1;j<=nodes;j++)
                graph[i][j] = 0;
        }

        for(int i=0;i<edges;i++)
        {   
            int start, end;
            double prob;
            cin>>start>>end>>prob;
            graph[start][end] = prob;
        }
        double answer[nodes] = {0.0};
        findans(graph, nodes, time, 1, 1.0, answer);
        double final_prob = -1; int final_div = 0;
        for(int i=1;i<=nodes;i++)
        {
            if(answer[i]>final_prob)
            {
                final_prob = answer[i];
                final_div = i;
            }
        }
        cout<<final_div<<" "<<final_prob<<endl;
    }
    return 0;
}
