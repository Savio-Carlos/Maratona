// Segment Tree (Range Minimum Query)
// build: O(N)
// update: O(logN)
// query: O(logN)

vector<ll>arr(inf);
vector<ll>seg(4*inf);

    void build(ll i, ll low, ll high){
        if(low==high){
            seg[i]=arr[low];
            return;
        }
        ll m = low+(high-low)/2;
        build(2*i+1, low, m);
        build(2*i+2, m+1, high);
        seg[i]=min(seg[2*i+1],seg[2*i+2]);
    }
    
    void update(ll i,ll low,ll high,ll pos,ll val){
        if(low==high){
            seg[i]=val;
            return;
        }
        ll m = low+(high-low)/2;
        if (pos<=m){
            update(2*i+1,low,m,pos,val);
        }else{
            update(2*i+2,m+1,high,pos,val);
        }
        seg[i]=min(seg[2*i+1],seg[2*i+2]);
    }

    ll query(ll i,ll low,ll high,ll l,ll r){
        if (high<l||low>r)return INT_MAX;
        if(low>=l && high<=r)return seg[i];

        ll m = low+(high-low)/2;
        return min(query(2*i+1,low,m,l,r),query(2*i+2,m+1,high,l,r));
    }
