#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<string,int> si

bool comp(si a, si b){

  if(a.second==b.second) return a.first < b.first;

  return a.second > b.second;
}

int main(){
  string s,s2;
  int n;
  map<string, pair<bool,int>> server;
  while(cin >> s){
    if(s=="LOGIN") {
      cin >> s;
      if(server.find(s)!=server.end()) server[s].first = true;
      else server[s]=make_pair(true,1200);
    }
    else if(s== "LOGOUT"){
      cin >> s;
      if(server.find(s)!=server.end()) server[s].first = false;
    }
    else if(s== "PLAY"){
      cin >> s >> s2;
      if(server.find(s)==server.end() or server.find(s2)==server.end()) cout << "jugador(s) no connectat(s)" << endl;
      else if(server[s].first== false or server[s2].first == false) cout << "jugador(s) no connectat(s)" << endl;
      else{
        server[s].second+=10;
        server[s2].second-=10;
        if(server[s2].second < 1200) server[s2].second=1200;
      }
    }
    else{
      cin >> s;
      cout << s << " " << server[s].second << endl;
    }
  }
    cout << endl;

    vector<si> aux;

    for(map<string,pair<bool,int>>::const_iterator i=server.begin(); i!=server.end();++i){
        aux.push_back(make_pair(i->first,i->second.second));
    }

    sort(aux.begin(),aux.end(),comp);
    cout << "RANKING" << endl;

    for(int i=0; i <aux.size();++i){
      cout << aux[i].first << " " << aux[i].second << endl;
    }

}
