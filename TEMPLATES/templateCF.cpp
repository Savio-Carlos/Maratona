#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define winton ios_base::sync_with_(0);cin.tie(0);cout.tie(NULL)
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
const int MAX = 2e5+7;
const int MOD = 998244353;
//const int MOD = 1000000007;
const int INF = 0x3f3f3f3f3f3f3f3f;

//-------------------------------------PAIR-------------------------------------//
template<class A, class B> ostream& operator<<(ostream& os, const pair<A, B>& p) { 
    os << "(" << p.first << "," << p.second << ")"; 
    return os; 
}
//-------------------------------------VECTOR-------------------------------------//
template<typename T> ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "[ ";
    for(const auto& elem : vec) {
        os << elem << " ";
    }
    os << "]";
    return os;
}
//-------------------------------------SET-------------------------------------//
template<typename T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{ ";
    for(const auto& elem : s) {
        os << elem << " ";
    }
    os << "}";
    return os;
}
//-------------------------------------MULTISET-------------------------------------//
template<typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << "{ ";
    for(const auto& elem : s) {
        os << elem << " ";
    }
    os << "}";
    return os;
}
//-------------------------------------QUEUE-------------------------------------//
template<typename T> ostream& operator<<(ostream& os, queue<T> q) {
    // Print each element in the queue
    os << "{ ";
    while (!q.empty()) {
        os << q.front() << " ";
        q.pop();
    }
    os << "}";
    // Print a newline at the end
    return os;
}
//-------------------------------------DEQUE-------------------------------------//
template<typename T> ostream& operator<<(ostream& os, deque<T> q) {
    // Print each element in the queue
    os << "{ ";
    while (!q.empty()) {
        os << q.front() << " ";
        q.pop_front();
    }
    os << "}";
    // Print a newline at the end
    return os;
}
//-------------------------------------STACK-------------------------------------//
template<typename T> ostream& operator<<(ostream& os, stack<T> q) {
    // Print each element in the queue
    os << "{ ";
    while (!q.empty()) {
        os << q.top() << " ";
        q.pop();
    }
    os << "}";
    // Print a newline at the end
    return os;
}
//-------------------------------------PRIORITY_QUEUE-------------------------------------//
template<typename T> ostream& operator<<(ostream& os, priority_queue<T> q) {
    // Print each element in the queue
    os << "{ ";
    while (!q.empty()) {
        os << q.top() << " ";
        q.pop();
    }
    os << "}";
    // Print a newline at the end
    return os;
}
//-------------------------------------MAP-------------------------------------//
template<typename K, typename V> ostream& operator<<(ostream& os, const map<K, V>& m) {
    os << "{ ";
    for(const auto& pair : m) {
        os << pair.first << " : " << pair.second << ", ";
    }
    os << "}";
    return os;
}
 
template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T> ostream& operator<<(ostream& os, min_pq<T> q) {
    // Print each element in the queue
    os << "{ ";
    while (!q.empty()) {
        os << q.top() << " ";
        q.pop();
    }
    os << "}";
    // Print a newline at the end
    return os;
}































/*
                                 .::^?J?7^.                                                        
                              :!?J5GBB##BBBPJ~.                                                     
                            ^JGB###GPP5PGBBBBBPJ~.                                                  
                          .YG#B##PJ7!7JJ7JGBBBBBB57.                                                
                         :5BB#BPY!~^^!?J!!75GB##BBBP~                                               
                        .Y#BPJ?!^^^^^~!J7~^^~7J5BBBBG~                                              
                    .~?J5BBY?!7??JYYYYYYY5YJJJ??YPBBBG5?~.                                          
                   ~YPPPBBY7JPPPPGPPP5PPGPPGGP5PPYG##BBGP?                                          
                  !PPPPBBG7?YPPGGBPJJY5555GBBGPPPPG##BGGGP!                                         
                  YGPPPBBG??Y55555Y?7?JY55555YYYYYP##GGGGGJ                                         
                  YGPPGBBBJ?JJJJJJJJJJJJJJJJYYJJJJ?G##GGGG?.                                        
                  7GPGBBBGJ?J?J?????JYYYYY5Y5Y5YY5Y5B#BBG5?7!.                                      
                :~~YGBB##5?Y55555555PPPPGPPP555P555YP##GJ???7!.                                     
               :7!~^7Y5G##5J?J???JJYYYYYYYY55555555G#BP5?!!77!^...                                  
              .~!~^^:^~?5PBGY????JJJJJYYYYY555555G#BJ5PY?7!77!~~!77!~^:.                            
          :^~~~~~~!!!~^^!7Y55YJJYYYYYYYY55555PPB#BP?!?Y?!!~~^:^~~!7?7??!^::..                       
       .^~~~^~~~~!!!?77!~~~^^^^!?JYYY555PPPPGGGPY?7!!!!7~^^^::~~~~~~^!7^^~~~^^^:.                   
      ^!~^^:^^^~!!7?J?77!~^^:::.:^~!77?YYYYJJ?77!~~~~!!!!!~~^~!!!~!~^:^::^^^~~~~~^.                 
    .!7~~^^::^^^^~?JJ?7??~~^:....::::^^~~~~~~~~~~~~~~~!!!77!^7?77777!^:.:^^^^~~^^^^::..             
   :!!~^^:::::^^^^~7??J5?!~^^::..::^^^~~~~~~~!~^^^~~~~!!!7?YJJYJJ????!:..:::^^^^^^^^^^^:            
  .!7!~^:..::^:^~~~!!JGY7!~^^:.~!^:::^^^^~~~!!!!J?~~~~!7?5PB#JY5YJJ?!~^:....:::::^^^^^^^^:          
  !!!!^:...::^^^~^~!!Y#BPY?7!!JPP5?~~!!!777777?PGGP555GBBBGB#G^~?Y5!~!~^::::::::.::^^!77??7:        
 :7!!~~~~!!!!~~^^^~~!YBGGGGGGGGPPGGPPPPPPPGGGGGGGGGGBPYJ?77JG#?  :7!7!!~^^^^::::^7J5PGGGGGGP?:      
 ^!7Y5PGGGGGGGPY????J5PYJ7!!5GGPPPPPPPPPGGGGGGGGGGGGB5~^~!7??GP.   .~77!~~~~^::?PGGGGGGGGGGGGPJ:    
 ~5GGGGGGGGGGGGGGGGGGPPGGP?7GGGPPPPPPPPPPPPPGGGGGGGGGBG55PJ?YGG^     .~7!~~~~!75GGGGGGGGGGGGBPPP.   
 YGGGGGGGGGGGPGGGGGGGGGGPPPBBGGGGPGGGGGPPPPPPGGGGGGBBBBB##B5YPB^       .~?J5PGGGGGGGGGGGGGBBBP?BY.  
~GG5?PGGPPGGGGGGBGP5YYY5PGBBBBBGGGGGGGGGGPPGGGGGBBBBBBBPYYJ7?JG:        :PBGGGBBBBBBGGGGGGBBBP?BB!  
7PGP?7PGPPGGGGBBP???J5555YYBBBBBBGBGGGGGGGGGGBBBBBBBBBBJ!!77?PY          ^7JY5PPPPY7YBBBBBBBB5YBBY: 
?5YGP?75GGGPPGGGP??J?Y55YYJG###BBBBBBBBBBBBBBBBBBBBBBBBGPP55PB! ....         !J5PY!?PGGGBBBBGJG#PP? 
7GJYGGJ!JPGPPPPGGPGP55Y5G###########BBBBBBBBBBBBBBBBBBBBBB###P!^::^^^~^^.    .7?7?YGBGBBBBBBJP#B5GP.
^PGYYGGP?75GPGGBGBBBBBBGG&&##############B####BBBBBBBB#B###P?~^^^^~~~~~!!~.  .!7YGBBBBBBBB#BB##PP#Y.
.?PGYJ5GGPPGGBBBBBBBBB##BB&&&####################B#######GJ!~^^:^~!7777777!: :YGBGGGBBBBB######B#B? 
 755GPYYGBBBBBBB#######B55P#&&&########################B57!!7!~^:^!!7??JYYJ!:^5BGGBBBBB##########B^ 
 :GP5PBGBBBBBB########GYYY5GBBB&######################GJ777?J!^^^~!?J77?Y55YYYPGGBB#############B!  
  7BG5PBBBBB##########BGGGGGY77P#&&&#######&###BG5?YBPYYJJ??J!^:~?5J^!?7J7~^~7J5PBB5PGB######BP?:   
   !PB#############&&#BP55YYJ?7!^7J5PGGBBPY?7~^.   .7J555555Y!~?PG7:^777?777?JY55PP: .:^^^~~^:      
    .~?YPGBBBGPB##BG5YJ?77777???.    ....             ^~7?J?J!JBB7^!7???????JY55P5!                 
         ..... 5GYJJ?????????JJJ.                             ~GG7?JJJJJJJYY55PP?:                  
               ~YJJJJJYYYYYYYYY7                               :JYYYYYY555PPP5?^                    
                :!?JJY55555PPY7.                                .~?JY5555Y?!^.                      
                  .:^!7??JJ?!:                                     .::::.                                                                                                        
*/