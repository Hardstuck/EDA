#include <iostream>
#include <queue>
using namespace std;

int main(){

  char a;
  int n;
  priority_queue<int> pq;
  while(cin >> a){
    switch(a){
      case 'A':
        if(pq.empty()) cout << "error!"<< endl;
        else cout << pq.top() << endl;
        break;
      case 'S':
        cin >> n;
        pq.push(n);
      break;
      case 'R':
        if(pq.empty()) cout << "error!"<< endl;
        else{
          pq.pop();
        }
        break;
      case 'I':
        if(pq.empty()) cout << "error!"<< endl;
        else{
          cin >> n;
          n = pq.top()+ n;
          pq.pop();
          pq.push(n);
        }
        break;
      case 'D':
        if(pq.empty()) cout << "error!"<< endl;
        else {
          cin >> n;
          n = pq.top()- n;
          pq.pop();
          pq.push(n);
        }
        break;
    }
  }
}
