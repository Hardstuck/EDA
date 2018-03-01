#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string a, string b){
  if(a.length()==b.length()) return a < b;
  return a.length() < b.length();
}

void write(int& count, const set<string>& a, const set<string>& b, bool last){
  ++count;
  cout << "GAME #" << count << endl <<"HAS:"<< endl;
  for(set<string>::const_iterator i=a.begin(); i!=a.end();++i){
    cout << *i << endl;
  }
  cout << endl;
  vector<string> aux;
  for(set<string>::const_iterator i=b.begin(); i!=b.end();++i){
    aux.push_back(*i);
  }
  cout << "HAD:" << endl;
  sort(aux.begin(),aux.end(),comp);
  for(int i=0; i < aux.size(); ++i){
    cout << aux[i] << endl;
  }
  if(not last)cout << endl;

}

int main(){
  set<string> have, had;
  string s;
  int count=0;
  bool end = false;
  while(not end and cin >> s ){
    if(s=="END"){
      write(count, have, had, false);
      have.clear();
      had.clear();
    }
    else if(s=="QUIT"){
      end = true;
      write(count, have, had, true);
    }
    else{
      if(have.find(s)==have.end()) {
          have.insert(s);
          if(had.find(s)!=had.end()) had.erase(s);
      }
      else{
        have.erase(s);
        had.insert(s);
      }
    }
  }
}
