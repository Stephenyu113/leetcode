//
// Created by steph on 3/28/2020.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
 * N: number of cities
 * R: number of one-way path
 * K: savings
 * L: length of each path
 * T: cost of each path
 * */
int K,N,R,S,D,L,T;
struct Road {
    int d, L, t; // d:destination L:length t:price
};
vector<vector<Road>> cityMap(110); // adjacency list
int minLen = 1 << 30; // init current minimal length is large
int totalLen; // length of current traj
int totalCost; //  cost of current traj
int visited[110]; // mark the visited city
int minL[110][10100]; // minL[i][j] represents the min-length traj with cost j from 1 to i

void Dfs (int s) { // travel from s to N

    if (s==N) { // already reach N, return
        minLen = min(minLen,totalLen);
        return;
    }
    // s!=N, still travel
    for (int i=0; i<cityMap[s].size(); ++i) { // traverse adjacent cities of s
        int d = cityMap[s][i].d; // s has a road to d
        if (!visited[d]) {// if d has not been visited
            int cost = totalCost + cityMap[s][i].t; // cost from 1 to d
            // optimize tree
            if (cost > K)
                continue; // discard this city i
            if (totalLen + cityMap[s][i].L > minLen // over min length, discard
                || totalLen+cityMap[s][i].L >= minL[d][cost]) // find a road with the same length but min cost. discard
                continue;
            // try this road
            totalLen += cityMap[s][i].L;
            totalCost += cityMap[s][i].t;
            minL[d][cost] = totalLen;
            visited[d] = 1;
            Dfs(d);
            visited[d] = 0; // other traj may go through d
            // go back
            totalCost -= cityMap[s][i].t;
            totalLen -= cityMap[s][i].L;
        }
    }
}

int main() {
    cin>>K>>N>>R;
    for (int i=0; i<R; ++i) {
        int s;
        Road r;
        cin>>s>>r.d>>r.L>>r.t;
        if (s!=r.d) // start!=destination
            cityMap[s].push_back(r);
    }
    for (int i=0; i<110; ++i)
        for (int j=0; j<10100; ++j)
            minL[i][j] = 1 << 30;
    memset(visited, 0, sizeof(visited));
    totalLen = 0;
    totalCost = 0;
    visited[1] = 1; // init 1st city is visited
    minLen = 1 << 30;
//    Dfs(1); // update minLen
    if (minLen<(1<<30))
        cout<<minLen<<endl;
    else
        cout<<"-1"<<endl;
}

