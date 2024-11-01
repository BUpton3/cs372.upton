//Refresher on chrono from https://www.geeksforgeeks.org/chrono-in-c/
//Utilized code from previous tries at this class. This is the same understanding and way I would have done it before.

#include <iostream>
#include <chrono>
#include <stack>
#include <cmath>
using namespace std;

void moveDisks(int, stack<int> &, stack<int> &, stack<int>&);
void printIt(int , char , char );
void MoveDisksHelper(stack<int> &, stack<int> &, char , char ) ;

int main() {
  for (auto numdisks : { 5,10,15,20,25,30,35 }) 
{
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    stack<int> source;
    stack<int> dest;
    stack<int> aux;

    cout << "Numdisks: " << numdisks << endl;
    moveDisks(numdisks, source, aux, dest);
    cout << "Moved " << numdisks << " pegs." << endl;

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
    return 0;
}

void moveDisks(int num, stack<int> &fromPeg, stack<int> &tempPeg, stack<int> &toPeg) {
  char s = 'S', d = 'D', a = 'A';
  if (num % 2 == 0) { // Swap in num disks is even.
    char temp = d;
    d = a;
    a = temp;
  }
  int numberOfMoves = pow(2, num) - 1;
  for (int i = num; i >= 1; i--) {
    fromPeg.push(i);
  }
  // now do moves:
  for (int i = 1; i <= numberOfMoves; i++) {
    if (i % 3 == 0) {
      MoveDisksHelper(tempPeg, toPeg, a, d);
    }
    else if (i % 3 == 2) {
      MoveDisksHelper(fromPeg,tempPeg, s, a);
    }
    else if (i % 3 ==  1) {
      MoveDisksHelper(fromPeg,toPeg, s, d);
    }
  }
}

void MoveDisksHelper(stack<int> &source, stack<int> &dest, char s, char d) {
  int top1;
  int top2;
  if (source.empty()) {
    top2 = dest.top();
    dest.pop();
    source.push(top2);
    printIt(top2, d, s);
  }
  else if (dest.empty()) {
    top1 = source.top();
    source.pop();
    dest.push(top1);
    printIt(top1, s, d);
  }
  else if (source.top() > dest.top()) {
    top1 = source.top();
    source.pop();
    top2 = dest.top();
    dest.pop();
    source.push(top1);
    source.push(top2);
    printIt(top2,d, s);
  }
  else {
    top2 = dest.top();
    dest.pop();
    top1 = source.top();
    source.pop();
    dest.push(top2);
    dest.push(top1);
    printIt(top1, s, d);
  }
}

void printIt(int disk, char fromPeg, char toPeg) {
  std::cout<< "Move disk "<<disk
           << "from peg " << fromPeg
           << "to peg " << toPeg << std::endl;
}

