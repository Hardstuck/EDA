#include <iostream>
#include <queue>
#include <string>

using namespace std;

class comp{
public:
  string key;
  comp(string s1);
  bool operator()(const string&s1, const string&s2){
      if(s1.length() != s2.length()) return s1.length() > s2.length();
      else{
        key.resize(s1.length());
        if((s1 >= key and s2 >= key) or (s1 < key and s2 < key))  return s1 > s2;
        else return s1 < s2;
      }
  }
private:
};

comp::comp (string s1){
  key = s1;
}


int main(){
  string key;
  while(cin >> key){
    int ticket=0;
    int events=1;
    priority_queue<string,vector<string>,comp> fan(key);
    while(cin >> key and key !="E" and events < 100000){
      if(key == "S"){
        cin >> key;
        if(ticket > 0) {
          cout << key << endl;
          --ticket;
        }
        else{
          fan.push(key);
        }
      }
      if(key=="T"){
        if(not fan.empty()) {
          cout << fan.top() << endl;
          fan.pop();
        }
        else ++ticket;
      }
    }
    ++events;
    cout << ticket << " ticket(s) left" << endl << fan.size() << " supporter(s) with no ticket"<<endl<<endl;
  }
}
