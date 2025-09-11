//Drone Control (3 Equa, 4 Vars)
//
// n(s) = r + s
// e(s) = (y+p-r)/2 - s
// w(s) = (y-p-r)/2 - s
// s(s) = s
 
// n(s) = a + s
// e(s) = b - s
// w(s) = c - s
// s(s) = s
 
// M = max{(|a+s|), (|b-s|), (|c-s|), (|s|)}
 
// |a+s| <= M    ->     -M-a <= s <= M-a
// |b-s| <= M    ->     -M+b <= s <= M+b
// |c-s| <= M    ->     -M+c <= s <= M+c
// |s|   <= M    ->     -M   <= s <= M
 
// achar o minimo e maximo do intervalo de s
 
// smin = max(-a,b,c,0)
// smax = max(-a,b,c,0)
// 
signed main(){
    int q;
    cin >> q;
    while(q--){
        ld p, r, y;
        cin >> p >> r >> y;
        ld a = r;
        ld b = (y+p-r)/2;
        ld c = (y-p-r)/2;
 
        ld smin = max({-a,b,c,(ld)0.0});
        ld smax = min({-a,b,c,(ld)0.0});
 
        ld s = (smin+smax)/2;
 
        ld n = r+s;
        ld e = b-s;
        ld w = c-s;
 
        cout << fixed << setprecision(7) << n << ' ' << e << ' ' << s << ' ' << w << ' ' << endl;
    }
}