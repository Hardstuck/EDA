#include <iostream>
#include <string>

using namespace std;

int main(){
  string s1,s2,key;
  cin >> key;
  cin >> s1 >> s2;
  if(s1 > key) cout << s1;
  else cout << key;
  if(s2 > key) cout << s2;
  else cout << key;
  }

}
