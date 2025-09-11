//Simspons Paradox
//
//Trend or pattern that appears in different groups of data is inconsistent 
//(disappears or even reverses) with what we see when the groups are combined.
//
//
//In this problem you are to construct an example of the dataset illustrating the Simpson's paradox.0
//More specifically, let us assume (similarly to the example above) that there are two teams who have been 
//solving problems of N categories and the total number of problems solved by each of the teams is M
//Let us denote the number of the problems in i-th category solved by Team X as ai, attempted by bi
//Similarly, let us define ci as the number of problems solved by Team Y in the i-th category and di as the number of problems attempted.

signed main(){
    int n, m;
    cin >> n >> m; 
    // a1 = b1 = 1, isso da um ratio de 1 usando so uma questao
    // c1 = d1-1, isso da um ratio de 0.99 usando quantas questoes eu quiser
    // so resta calcular para as restantes das categorias
    
    int d1 = m - 3*(n-1);
    //debug(d1);
    int c1 = d1-1;
    cout << 1 << " " << 1 << " " << c1 << " " << d1 << endl;
    for (int i = 0; i < n-2; i++){
        cout << 1 << " " << 2 << " " << 1 << " " << 3 << endl;
    }
    int bn = m-((n-2)*2)-1;
    int dn = m-d1-((n-2)*3);
    int an = (c1 - 1);
    int cn = 1;
    cout << an << " " << bn << " " << cn << " " << dn << endl;
}