#include <iostream>
using namespace std;
typedef long long LL;
LL n, a[100005], d[270000], b[270000];
void build(LL l, LL r, LL p) {
  if (l == r) {
    d[p] = a[l];
    return;
  }
  LL m = (l + r) >> 1;
  build(l, m, p << 1), build(m + 1, r, (p << 1) | 1);
  d[p] = d[p << 1] + d[(p << 1) | 1];
}
void update(LL l, LL r, LL c, LL s, LL t, LL p) {
  if (l <= s && t <= r) {
    d[p] += (t - s + 1) * c, b[p] += c;
    return;
  }
  LL m = (s + t) >> 1;
  if (b[p])
    d[p << 1] += b[p] * (m - s + 1), d[(p << 1) | 1] += b[p] * (t - m),
        b[p << 1] += b[p], b[(p << 1) | 1] += b[p];
  b[p] = 0;
  if (l <= m) update(l, r, c, s, m, p << 1);
  if (r > m) update(l, r, c, m + 1, t, (p << 1) | 1);
  d[p] = d[p << 1] + d[(p << 1) | 1];
}
LL getsum(LL l, LL r, LL s, LL t, LL p) {
  if (l <= s && t <= r) return d[p];
  LL m = (s + t) >> 1;
  if (b[p])
    d[p << 1] += b[p] * (m - s + 1), d[(p << 1) | 1] += b[p] * (t - m),
        b[p << 1] += b[p], b[(p << 1) | 1] += b[p];
  b[p] = 0;
  LL sum = 0;
  if (l <= m) sum = getsum(l, r, s, m, p << 1);
  if (r > m) sum += getsum(l, r, m + 1, t, (p << 1) | 1);
  return sum;
}


// int main() {
//   std::ios::sync_with_stdio(0);
//   LL q, i1, i2, i3, i4;
//   std::cin >> n >> q;
//   for (LL i = 1; i <= n; i++) std::cin >> a[i];
//   build(1, n, 1);
//   while (q--) {
//     std::cin >> i1 >> i2 >> i3;
//     if (i1 == 2)
//       std::cout << getsum(i2, i3, 1, n, 1) << std::endl;
//     else
//       std::cin >> i4, update(i2, i3, i4, 1, n, 1);
//   }
//   return 0;
// }

int main()
{
    LL n,m;
    std::ios::sync_with_stdio(0);

    cin>>n>>m;
    for(LL i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    build(1,n,1);// init left,right,position=1

    LL op,x,y,k;
    while(m--)
    {
        cin>>op>>x>>y;
        if(op==1)
        {
            cin>>k;
            update(x,y,k,1,n,1);
        }
        else if(op==2)
            cout<<getsum(x,y,1,n,1)<<endl;
    }
    return 0;
}