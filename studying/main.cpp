#include <iostream>
#include <cmath>
#include <array>
#include <ctime>
#include <cstdlib>

using namespace std;

void zadacha1()
{
  double a = 0;
  double y = 0.0;

  cin>>a;

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

  cout << "y=" << y << endl;
}

void zadacha2()
{
  double x = 0;
  double y = 0;

  cin >> x >> y;

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
  int x = 0;
  int min = 1000000;
  int max = -1000000;

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

  double returnValue = static_cast<double>(min) / static_cast<double>(max);

  cout << returnValue << endl;
}

void zadacha4()
{
  int N = 0;
  int M = 0;

  cin >> N >> M;

  if (N >= M)
  {
    cout << "ERROR of input";
    return;
  }

  for (int i = N; i <= M; ++i)
  {
    for (int k = 0; k < i; ++k)
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
    ++i;
  }

  return i;
}

int Arms(int N, int size) //считает степенную сумму
{
  int sum = 0;

  for(int i = 0; i < size; ++i)
  {
    sum = sum + pow( N % 10 , size);
    N = N / 10;
  }

  return sum;
}

void zadacha5()
{
  int N = 0;
  int newd = 0;
  int size = 0;
  int q = 0;

  cin >> q;

  for (int i=0; i < q; ++i)
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

// здесь следует передавать массив не как int A[], а как int* A
//
// но и в этом случае не будет работать функция realloc, так как она
// изменяет указатель, который передается по значению в функцию
//
// он измениться внутри функции, но на выходе вернется к прежнему значению
// поэтому его следует передать по ссылке - через &
//
// получается int*& A

void notpl (int*& A, int X[], int n, int &counter)
{
  int *number;
  for ( int i = 0; i < n; i++)
  {
    if ( X[i] >= 0 )
    {
      counter ++;
      number = (int*) realloc (A, counter * sizeof(int));  //не выделяет память :(
      A = number;
      A[counter - 1] = X[i];
    }
  }
}

void zadacha6()
{
  int n = 0;
  int mult = 1;
  long int max = -100;

  //cin >> n;
  n = 5;
  cout << "n = " << n << "\n";

  int *B;
  B = new int[n];
  srand( time(0) );

  for ( int i = 0; i < n; ++i)
  {
    B[i] = rand() % 101 + (-50);
    cout << B[i] << ' ';
  }

  for ( int i = 0; i < n; i++)
  {
    if ( (B[i] < 0) && ( (i % 2) == 0) )
    {
      mult *= B[i];
    }

    if ( ( (B[i] % 3) == 0 ) && B[i] > max)
      max = B[i];
  }

  cout << endl << mult << ' ' << max << endl;

  int *C, *A = NULL;
  int m = 0;

  //cin >> m;
  m = 5;
  cout << "m = " << m << "\n";

  C = new int[m];

  for ( int i = 0; i < m; ++i)
  {
    C[i] = rand() % 201 + (-100);
    cout << C[i] << ' ';
  }

  int counter=0;

  notpl(A, B, n, counter);
  notpl(A, C, m, counter);

  cout << "\nresult: \n";

  for ( int i = 0; i < counter; ++i)
  {
    cout << A[i] << ' ';
  }

  bool flag = true;

  for (int i = 0; flag == true, i < counter; i++)
  {
    if ( A[i] % 4 == 0)
    {
      flag = false;
      for (int k = i; k < counter -1; k++)
      {
        A[i] = A[i+1];
      }
      counter--;
    }
  }

  cout << "\nresult without kratnoe 4: \n";

  for ( int i = 0; i < counter; ++i)
  {
    cout << A[i] << ' ';
  }

  delete [] A;
  delete [] B;
  delete [] C;
}

int main()
{
  /*zadacha1();
  zadacha2();
  zadacha3();
  zadacha4();
  zadacha5();*/
  zadacha6();

  return 0;
}
