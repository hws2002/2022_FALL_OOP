#include <iostream>
#include "Monomial.h"
#include <cmath>
using namespace std;
Monomial::Monomial(){

};
Monomial::Monomial(int _c, int _d):coe(_c),deg(_d){
};
Monomial Monomial::operator+(const Monomial &x) const{
    Monomial tmp(coe+x.coe,deg);
    return tmp;
};
Monomial Monomial::operator-(const Monomial &x) const{
    Monomial tmp(coe-x.coe,deg);
    return tmp;
};
Monomial Monomial::operator*(const Monomial &x) const{
    if(coe ==0 ) {
        Monomial tmp(0,0);
        return tmp;
    }
    Monomial tmp(coe*x.coe,deg+x.deg);
    if(tmp.coe ==0)
        tmp.deg =0;
    return tmp;
};
Monomial Monomial::operator/(const Monomial &x) const{
    if(coe ==0 ) {
        Monomial tmp(0,0);
        return tmp;
    }
    Monomial tmp(coe/x.coe,deg-x.deg);
    return tmp;
};
int Monomial::definite_integral(const int a, const int b) const{
    if(coe ==0) return 0;
    int s = coe;
    int p = deg;
    int res = (s/(p+1))*(pow(b,p+1)-pow(a,p+1));
    return res;
};

Monomial Monomial::derive() const{
    Monomial tmp(coe*deg,deg-1);
    if (coe*deg==0){
        tmp.deg = 0;
    }
    return tmp;
};
int Monomial::get_val(int x) const{
    int res = (coe)*(pow(x,deg));
    return res;
};

istream& operator>>(istream& in, Monomial& Px){
    string poly;
    in>>poly;
    int index = poly.find('x');
    string s = poly.substr(0,index);
    string p = poly.substr(index+2);
    int coef = stoi(s);
    int degr = stoi(p);
    Px.coe = coef;
    Px.deg = degr;
    return in;
};

ostream& operator<<(ostream& out,const Monomial& Px){
    out<<Px.coe<<"x^"<<Px.deg<<endl;
    return out;
};
int main()
{
    int n;
    int m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Monomial x, y;
        cin >> x;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int opr, a, b;
            cin >> opr;
            switch (opr)
            {
            case 1:
                cin >> y;
                x = x + y;
                cout << x;
                break;

            case 2:
                cin >> y;
                x = x - y;
                cout << x;
                break;

            case 3:
                cin >> y;
                x = x * y;
                cout << x;
                break;

            case 4:
                cin >> y;
                x = x / y;
                cout << x;
                break;

            case 5:
                cin >> a >> b;
                cout << x.definite_integral(a, b) << "\n";
                break;

            case 6:
                x = x.derive();
                cout << x;
                break;

            default:
                break;
            }
        }
        int par;
        cin >> par;
        cout << x.get_val(par) << endl;
    }
    return 0;
}