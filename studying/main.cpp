#include <iostream>
#include<cmath>
#include <array>

using namespace std;

void zadacha1()
{
  double a, y;
  cin>>a;
  //REFACTOR: открытие скобок
  if (abs(a) > 3)
  {
    y = 3;
  }
  else
  {
    if ( abs(a) <= 3 )
    {
      y = -abs(a) + 3;
    }
  }
  cout << "y="<< y << endl;
}

void zadacha2()
{
  double x, y;
  cin >> x >> y;
  // REFACTOR: скобки
  if( ((x - 3) * (x - 3) + y * y <= 9) || ((x - 3) * (x - 3) + (y - 3) * (y - 3) <= 9) )
  {
    cout << "YES!" << endl;
  }
  else
  {
    cout << "NO!" << endl;
  }
}

void zadacha3()
{
  int x, max, min;
  min = 1000000;
  max = -1000000;
  cin >> x;
  if (x == 0)
  {
    cout << "End of seq" << endl;
    return;
  }
  while(x != 0)
  {
    if(x > max)
    {
      max = x;
    }
    if(x < min)
    {
      min = x;
    }
    cin >> x;
  }
  cout<< (double) min / max<< endl;
}

void zadacha4()
{
  int N, M;
  cin >> N >> M;
  if (N >= M)
  {
    cout << "ERROR of input";
    return;
  }
  for (int i = N; i <= M; i++)
  {
    //REFACTOR : добавить скобки
    for (int k = 0; k < i; k++)
    {
      cout << i << ' ';
    }
    cout << endl;
  }
}

int digits(int N) // считает кол-во цифр в числе
{
  int i=0;
  while ( N != 0)
  {
    N = N / 10;
    i++;
  }
  return i;
}

int Arms(int N, int size) //считает степенную сумму
{
  int sum = 0;
  for(int i = 0; i < size; i++)
  {
    sum = sum + pow( N % 10 , size);
    N = N / 10;
  }
  return sum;
}

void zadacha5()
{
  int N, newd, size, q;
  cin >> q;
  for (int i=0; i < q; i++)
  {
    cin >> N;
    size = digits(N);
    newd = Arms(N, size);
    if (N == newd)
    {
      cout << "YES" <<endl;
      return;
    }

  }
  cout << "NO" << endl;
}

int main()
{
  zadacha1();
  zadacha2();
  zadacha3();
  zadacha4();
  zadacha5();
  return 0;
}
