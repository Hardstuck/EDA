#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
  string name,aux;
  int n;
  map<string, int> casino;
  map<string, int>::const_iterator i;
  while (cin >> name >> aux) {
    if(aux=="enters") {
        if(casino.find(name)==casino.end()) casino[name];
        else cout << name <<" is already in the casino" << endl;
      }
    else if (aux=="leaves"){
        i = casino.find(name);
        if(i==casino.end()) cout << name << " is not in the casino" << endl;
        else {
          cout << name << " has won " << casino[name] << endl;
          casino.erase(i);
        }
      }
    else{
        cin >> n;
        if(casino.find(name)==casino.end()) cout << name << " is not in the casino" << endl;
        else{
          casino[name]=casino[name]+n;
        }
     }
   }
  cout << "----------" << endl;
  i=casino.begin();
  while(i != casino.end()){
    cout << i->first << " is winning " << i->second << endl;
    ++i;
  }
}
