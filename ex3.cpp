#include<iostream>
using namespace std;
struct  donthuc
{
	int a, n, x;
};
int gcd(int a, int b) {
	if (b == 0) return a;
	a %= b;
	return gcd(b, a);
}
void input (donthuc& p)
{
	cout << "please enter a  =	" << endl;
	cin >> p.a;
	cout << "please enter n =" << endl;
	cin >> p.n;
}
void output(donthuc p)
{
	cout << "P(x) =  " << p.a << "x^" << p.n << endl;
}
void input(donthuc& p, donthuc& q)
{
	cout << "please enter a  of monomial 1 =	" << endl;
	cin >> p.a;
	cout << "please enter n of monomial 1 =" << endl;
	cin >> p.n;
	cout << "P1(x) =  " << p.a << "x^" << p.n << endl;
	cout << "please enter a  of monomial 2 =	" << endl;
	cin >> q.a;
	cout << "please enter n of monomial 2 =" << endl;
	cin >> q.n;
	cout << "P2(x) =  " << q.a << "x^" << q.n << endl;
}
void Multi( donthuc p, donthuc q)
{
	donthuc mul;
	mul.a = p.a * q.a;
	mul.n = p.n + q.n;
	cout << " vay tich cua hai don thuc la p(x)=  " << mul.a << "x^" << mul.n << endl;
}
void derivative(donthuc p)
{
	donthuc der;
	der.a = p.a * p.n;
	der.n = p.n - 1;
	cout << " this is derivative p'(x)=" << der.a << "x^" << der.n << endl;
}
void div(donthuc p, donthuc q)
{
	int a = gcd(p.a, q.a);
	cout << "vay thuong cua hai don thuc la p(x)=(" << p.a/a<<"/"<<q.a/a<< ")x^" << p.n-q.n << endl;

}
void DaoHamBacK(donthuc p)
{
	donthuc e;
	int k, d = 1;
	cout << "dao ham bac " << endl;
	cin >> k;
	if (k <= p.n)
	{
		e.n = p.n;
		for (int i = 1; i <= k; i++)
		{
			
			d *= e.n;
			e.n--;
			e.a = p.a * d;

		}
	}
	else
	{
		cout << "nhap lai bac dao ham	" << endl;
		cin >> k;
	}

	cout << "dao ham bac k =	" << e.a << "x^" << p.n - k << endl;
}
void NhapX(donthuc p) 
{
	cout << "nhap x " << endl;
	cin >> p.x;
	cout << "P(x) =  " << p.a << '*'<<p.x<<'^'<< p.n << endl;
	cout << "p(x) =" << p.a * pow(p.x,p.n)<< endl;

}
int main()
{
	donthuc p, q;
	int chon;
	cout << "MENU" << endl;
	cout << "1.xuat don thuc" << endl;
	cout << "2.tich 2 don thuc" << endl;
	cout << "3. dao ham don thuc" << endl;
	cout << "4.thuong hai don thuc" << endl;
	cout << "5.dao ham don  thuc" << endl;
	do
	{
		cout << "vui long chon chuc nang " << endl;
		cin >> chon;
	} while (chon < 0 || chon>6);
	switch (chon)
	{
	case 1:
		input(p);
		output(p);
		break;
	case 2:
		input(p, q);
		Multi(p, q);
		break;
	case 3:
		input(p);
		output(p);
		derivative(p);
		break;
	case 4:
		input(p, q);
		div(p, q);
		break;
	case 5:
		input(p);
		output(p);
		DaoHamBacK(p);
		break;
	}
	return 0;
}