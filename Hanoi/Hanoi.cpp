//
// Created by steph on 3/26/2020.
//

#include <iostream>
#include <stack>
using namespace std;

struct Problem {
    int n;
    char src, mid, dest;
    // constructor
    Problem (int nn, char s, char m, char d) : n(nn), src(s), mid(m), dest(d) {}
};

stack<Problem> stk;

int main() {
    int n;
    cin>>n;
    stk.push(Problem(n,'A','B','C')); // initialize 1st envelop
    while (!stk.empty()) { // keep running as long as there exists envelop
        Problem curPrb = stk.top(); // obtain top envelop as current problem
        stk.pop(); // discard the top envelop
        if (curPrb.n == 1) cout<<curPrb.src<<"->"<<curPrb.dest<<endl;
        else { // split the problem into subsidiary problems
            // put 3rd problem into stack, which is the last step to go
            stk.push(Problem(curPrb.n-1,curPrb.mid,curPrb.src,curPrb.dest));
            // put 2nd problem into stack
            stk.push(Problem(1,curPrb.src,curPrb.mid,curPrb.dest));
            // put 1st problem into stack, which is the first step to go
            stk.push(Problem(curPrb.n-1,curPrb.src,curPrb.dest,curPrb.mid));
        }
    }
    return 0;
}