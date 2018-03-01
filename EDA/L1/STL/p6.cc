#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
  cout.setf(ios::fixed);
  cout.precision(4);
  int n, count=0;
  string ordre;
  map<int,int> list;
  map<int,int>::const_iterator max,min;
  double mitj=0;
  while (cin >> ordre){
    if(ordre == "number"){
      cin >> n;
      ++count;
      mitj+=n;
      if(list.find(n)==list.end()){
        list[n]=1;
        min=list.begin();
        cout << "minimum: " << min->first << ", maximum: ";
        max=list.end();
        --max;
        cout << max->first << ", average: " << mitj/count << endl;
      }
      else{
        ++list[n];
        min=list.begin();
        cout << "minimum: " << min->first << ", maximum: ";
        max=list.end();
        --max;
        cout << max->first << ", average: " << mitj/count << endl;
      }
    }
    else if (ordre=="delete"){
      if(list.empty()) cout << "no elements" << endl;
      else {
        if(min->second==1){
        --count;
        mitj-=min->first;
        list.erase(min);
          if(list.empty()) cout <<"no elements" << endl;
          else{
            min=list.begin();
            cout << "minimum: " << min->first << ", maximum: ";
            cout << max->first << ", average: " << mitj/count << endl;
          }
        }
        else{
          --count;
          mitj-=min->first;
          --list[min->first];
          cout << "minimum: " << min->first << ", maximum: ";
          cout << max->first << ", average: " << mitj/count << endl;
        }
      }
    }
  }
}
