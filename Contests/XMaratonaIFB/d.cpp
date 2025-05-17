#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 1e9

signed main()
{
  string linha, palavra, palavra_ant;
  int pos, offset=0;
  int dcount = 0, scount=0;
  getline(cin, linha);
  string ver1 = "Daniel Sad";
  string ver2 = "DANIEL SAD";
  string ver3 = "daniel sad";
  stringstream ss(linha);

  while((pos = linha.find(ver1, offset) ) != std::string::npos){
    if(pos!=0){
      char x = linha[pos-1];
      if((x>='a' && x<='z') || (x>='a' && x<='z')){
        offset+=pos+11;
        continue;
      }
    }
    if(pos+ver1.size()!=std::string::npos){
      char x = linha[pos+ver1.size()];
      if((x>='a' && x<='z') || (x>='a' && x<='z')){
        offset+=pos+11;
        continue;
      }
    }
    linha.insert(pos + 8, "a");
  }

  offset = 0;
  while((pos = linha.find(ver2, offset) ) != std::string::npos){
    if(pos!=0){
      char x = linha[pos-1];
      if((x>='a' && x<='z') || (x>='a' && x<='z')){
        offset+=pos+11;
        continue;
      }
    }
    if(pos+ver1.size()!=std::string::npos){
      char x = linha[pos+ver1.size()];
      if((x>='a' && x<='z') || (x>='a' && x<='z')){
        offset+=pos+11;
        continue;
      }
    }
    linha.insert(pos + 8, "A");
  }

  offset = 0;
  while((pos = linha.find(ver3, offset) ) != std::string::npos){
    if(pos!=0){
      char x = linha[pos-1];
      if((x>='a' && x<='z') || (x>='a' && x<='z')){
        offset+=pos+11;
        continue;
      }
    }
    if(pos+ver1.size()!=std::string::npos){
      char x = linha[pos+ver1.size()];
      if((x>='a' && x<='z') || (x>='a' && x<='z')){
        offset+=pos+11;
        continue;
      }
    }
    linha.insert(pos + 8, "a");
  }
  cout << linha << endl;
  return 0;
}


// contest: https://codeforces.com/contest/165