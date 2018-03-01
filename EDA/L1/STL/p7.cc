#include <sstream>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){;
  string s;
  while(getline(cin, s)){
    istringstream ss(s);
    set<int> news;
    int n;
    while(ss >> n) news.insert(n);
    set<int>::const_iterator i;
    set<int>::const_iterator ant;
    i=news.begin();
    while(i!=news.end() and not news.empty()){
      if(i==news.begin()) {
        ant=i;
        ++i;
      }
      else{
        if((*i%2==0 and *ant%2==0) or (*i%2==1 and *ant%2==1)) {
          news.erase(i);
          i=ant;
          ++i;
        }
        else{
          ant=i;
          ++i;
        }
      }
    }
    cout << news.size() << endl;
  }
}
