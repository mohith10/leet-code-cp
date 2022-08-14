#include <bits/stdc++.h>
using namespace std;

pair<int,int> computeIntersection(pair<int,int> startL1, pair<int,int> endL1, pair<int,int> startL2, pair<int,int> endL2){
    int x1 = startL1.first, y1=startL1.first, x2 = endL1.first, y2 = endL1.second;
    int x3 = startL2.first, y3 = startL2.second, x4 = endL2.first, y4 = endL2.second;
    
    int  xPointNumerator = (x1*y2 - y1*x2)*(x3-x4) - (x3*y4 - y3*x4)*(x1-x2);
    int PointDenominator = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
    if(PointDenominator == 0){
        return {INT_MAX,INT_MAX}; //Lines not intersecting
    }
    int yPointNumerator = (x1*y2 - y1*x2)*(y3-y4) - (x3*y4 - y3*x4)*(y1-y2);
    return {xPointNumerator/PointDenominator, yPointNumerator/PointDenominator};
}


int main() {
	pair<int, int> startL1 ={0,0}, endL1={5,5}, startL2={2,-10}, endL2={3,10};
	pair<int,int> res = computeIntersection(startL1,endL1, startL2, endL2);
	if(res.first == INT_MAX && res.second == INT_MAX){
	    cout<<"Lines doesnt INTERSECT";
	}else{
	    cout<<"Intersecting at "<<res.first<<" "<<res.second;
	}
}
