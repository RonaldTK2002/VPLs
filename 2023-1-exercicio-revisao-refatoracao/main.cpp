#include "Streaming.hpp"
#include <iostream>
#include <list>
#include <string>
#include <vector>

int main()

{
Streaming ss;
string t;

while (cin >> t) {
if (t == "Filme")

{
string n, g;
int a, d;
cin >> g >> a >> d;
getline(cin, n);

Video *v;
v = new Video(n, a, g, t, d, 0, 0);
if (50 <= d)

{
ss.cadastrar_filme(v);
}
}
if (t == "Serie") {

string n;
string g;
int a, nt, te;
cin >> g >> a >> nt >> te;
getline(cin, n);
Video *v;
v = new Video(n, a, g, t, 0, nt, te);
if (2 <= te) {
{
ss.cadastrar_serie(v);
}
}
}

if (t == "Nota") {
int i, n;
cin >> i >> n;

if (n <= 10) {
if (n >= 0) {
ss.avaliacao(i, n);
}
}
}
}
ss.print_catalogo();

return 0;
}
