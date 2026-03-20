/**

E - Knapsack 2  
Problem Statement
There are 
N items, numbered 
1,2,…,N. For each 
i (
1≤i≤N), Item 
i has a weight of 
w 
i
​
  and a value of 
v 
i
​
 .

Taro has decided to choose some of the 
N items and carry them home in a knapsack. The capacity of the knapsack is 
W, which means that the sum of the weights of items taken must be at most 
W.

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.
1≤N≤100
1≤W≤10 
9
 
1≤w 
i
​
 ≤W
1≤v 
i
​
 ≤10 
3
 
Input
Input is given from Standard Input in the following format:

N 
W
w 
1
​
  
v 
1
​
 
w 
2
​
  
v 
2
​
 
:
w 
N
​
  
v 
N
​
 
Output
Print the maximum possible sum of the values of items that Taro takes home.

Sample Input 1
Copy
3 8
3 30
4 50
5 60
Sample Output 1
Copy
90
Items 
1 and 
3 should be taken. Then, the sum of the weights is 
3+5=8, and the sum of the values is 
30+60=90.

Sample Input 2
Copy
1 1000000000
1000000000 10
Sample Output 2
Copy
10
Sample Input 3
Copy
6 15
6 5
5 6
6 4
6 6
3 5
7 2
Sample Output 3
Copy
17
Items 
2,4 and 
5 should be taken. Then, the sum of the weights is 
5+6+3=14, and the sum of the values is 
6+6+5=17.
**/



#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    long long W;

    cin >> n >> W;

    vector<int> w(n), v(n);

    for(int i=0;i<n;i++)
        cin >> w[i] >> v[i];

    int MAXV = 100000;

    vector<long long> dp(MAXV+1, LLONG_MAX);

    dp[0] = 0;

    for(int i=0;i<n;i++){
        for(int val = MAXV; val >= v[i]; val--){
            if(dp[val - v[i]] != LLONG_MAX)
                dp[val] = min(dp[val], dp[val - v[i]] + w[i]);
        }
    }

    int ans = 0;

    for(int val=0; val<=MAXV; val++){
        if(dp[val] <= W)
            ans = val;
    }

    cout << ans;
}
