#include <bits/stdc++.h>
using namespace std;

void labelIt(vector<vector<int>> &cost, vector<int> &lx) {
    int n = cost.size();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            lx[i] = max(lx[i], cost[i][j]);
}

void addTree(int x, int prevX, vector<bool> &inTreeX, 
    vector<int> &prev, vector<int> &slack, vector<int> &slackX,
     vector<int> &lx, vector<int> &ly, vector<vector<int>> &cost) {
    inTreeX[x] = true;
    prev[x] = prevX;
    for(int y = 0; y < slack.size(); y++) {
        if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
            slack[y] = lx[x] + ly[y] - cost[x][y];
            slackX[y] = x;
        }
    }
}

void updateLabels(vector<bool> &inTreeX, vector<bool> &inTreeY,
     vector<int> &slack, vector<int> &lx, vector<int> &ly) {
    int n = slack.size();

    int delta = INT_MAX;

    for(int y = 0; y < n; y++)
        if(!inTreeY[y])
            delta = min(delta, slack[y]);

    for(int x = 0; x < n; x++)
        if(inTreeX[x])
            lx[x] -= delta;

    for(int y = 0; y < n; y++)
        if(inTreeY[y])
            ly[y] += delta;

    for(int y = 0; y < n; y++)
        if(!inTreeY[y])
            slack[y] -= delta;

}

void augment(vector<vector<int>> &cost, int &match, vector<bool> &inTreeX, 
    vector<bool> &inTreeY, vector<int> &prev, vector<int> &xy, vector<int> &yx, 
    vector<int> &slack, vector<int> &slackX, vector<int> &lx, vector<int> &ly) {

    // augmenting path algorithm
    int n = cost.size();

    // check if we have found a perfect matching
    if(match == n)
        return;

    int x, y, root;

    queue<int> q;

    // find root of tree
    for(int i = 0; i < n; i++) {

        if(xy[i] == -1) {
            q.push(root = i);
            prev[i] = -2;
            inTreeX[i] = true;
            break;
        }
    }

    // initialize slack
    for(int i = 0; i < n; i++) {
        slack[i] = lx[root] + ly[i] - cost[root][i];
        slackX[i] = root;
    }

    // BFS to find augmenting path
    while(true) {

        // building tree with BFS cycle
        while(!q.empty()) {

            // current vertex
            x = q.front();
            q.pop();

            //iterate through all edges in equality graph
            for(y = 0; y < n; y++) {
                if(lx[x] + ly[y] - cost[x][y] == 0 && !inTreeY[y]) {

                    // if y is an exposed vertex in Y
                    // found, so augmenting path exists
                    if(yx[y] == -1) {
                        x = slackX[y];
                        break;
                    } 
                    
                    // else just add y to inTreeY
                    else {
                        inTreeY[y] = true;

                        // add vertex yx[y], which is 
                        // matched with y, to the queue
                        q.push(yx[y]);

                        // add edges (x, y) and (y, yx[y]) to the tree
                        addTree(yx[y], x, inTreeX, prev, 
                            slack, slackX, lx, ly, cost);
                    }
                }
            }

            // augmenting path found
            if(y < n)
                break;
        }

        // augmenting path found
        if(y < n)
            break; 

        // else improve labeling
        updateLabels(inTreeX, inTreeY, slack, lx, ly);

        for(y = 0; y < n; y++) {

            if(!inTreeY[y] && slack[y] == 0) {

                // if y is an exposed vertex in Y
                // found, so augmenting path exists
                if(yx[y] == -1) {
                    x = slackX[y];
                    break;
                } 
                
                // else just add y to inTreeY
                else {
                    inTreeY[y] = true;

                    // add vertex yx[y], which is matched with y, to the queue
                    if(!inTreeX[yx[y]]) {
                        q.push(yx[y]);

                        // add edges (x, y) and (y, yx[y]) to the tree
                        addTree(yx[y], slackX[y], inTreeX, prev, 
                            slack, slackX, lx, ly, cost);
                    }
                }
            }
        }

        // augmenting path found
        if(y < n)
            break;
    }

    if(y < n) {

        // augmenting path found
        match++;

        // update xy and yx
        for(int cx = x, cy = y, ty; 
            cx != -2; cx = prev[cx], cy = ty) {
            ty = xy[cx];
            xy[cx] = cy;
            yx[cy] = cx;
        }

        // reset inTreeX and inTreeY
        fill(inTreeX.begin(), inTreeX.end(), false);
        fill(inTreeY.begin(), inTreeY.end(), false);

        // recall function, go to step 1 of the algorithm
        augment(cost, match, inTreeX, inTreeY, 
            prev, xy, yx, slack, slackX, lx, ly);
    }
}

int findMinCost(vector<vector<int>> &cost) {
    int n = cost.size();

    // convert cost matrix to profit matrix
    // by multiplying each element by -1
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cost[i][j] = -1 * cost[i][j]; 

    // to store the results
    int result = 0;

    // number of vertices in current matching
    int match = 0;

    vector<int> xy(n, -1), yx(n, -1), lx(n, 0);
    vector<int> ly(n, 0), slack(n), slackX(n), prev(n);

    vector<bool> inTreeX(n, false), inTreeY(n, false);

    labelIt(cost, lx);

    augment(cost, match, inTreeX, inTreeY, prev, 
        xy, yx, slack, slackX, lx, ly);

    for(int i = 0; i < n; i++) {
        result += cost[i][xy[i]];
    }
    return -1 * result;
}

int main() {
    vector<vector<int>> cost = {
        {2500, 4000, 3500},
        {4000, 6000, 3500},
        {2000, 4000, 2500}
    };
    cout << findMinCost(cost);
    return 0;
}
