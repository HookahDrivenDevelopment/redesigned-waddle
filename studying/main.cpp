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


//возвращает true если сумма цифр числа нечетна, иначе false
bool is_odd(int d)
{
  int sum = 0;
  while (d != 0)
  {
    sum += d % 10;
    d /= 10;
  }

  // REVIEW: можно написать return ((sum & 2) == 1);
  if ( sum % 2 == 1)
  {
    return true;
  }
  else
  // REVIEW: тут нехватает скобок
    return false;
}


//добавляет числа в массив если сумма цифр чила нечетна
void createnewmas (int*& Z, int X[], int n, int &counter) // REVIEW: лучше писать int& counter, а не int &counter
{
  int *number;
  for ( int i = 0; i < n; i++)
  {
    if ( is_odd( X[i]) )
    {
      counter ++;
      number = (int*) realloc (Z, counter * sizeof(int));
      Z = number;
      Z[counter - 1] = X[i];
    }
  }
}


//проверяет простое ли число
bool simple(int d)
{
  if (d==1)
    return false;
  if (d == 2 || d == 3)
    return true;
  bool b = true;
  for (int i = 2; b != false && i <= (sqrt(d)+1); i++)
  {
    if (d % i==0)
    {
      b=false;
    }
  }

  // REVIEW: return b; имеет тот же эффект
  if (b) return true;
  else return false;
}


//тут все сложно...
//ищет три максимальных простых числа в массиве: сначала ищет самое меньшее простое число
//потом второе наименьшее число, игнорируя первое, потом третье, игнорируя первые два
//если непонятно то на странице 149 принцип алгоритма
//max0, max1, max2 = -1, для того чтобы в дальнейшем посмотреть, были ли вообще простые
//числа и в каком количестве они набрались, при малых объемах массива,
//простые числа могут отсутствовать, если у нас не найдено первое второе или третье
//простое число мы выходим из функции
void search(int &max0, int &max1, int &max2, int Z[], int count)
{
  int i, l;
  for(i = 0; i < count; i++)
  {
    if ( simple(Z[i]) &&  Z[i] > max0)
    {
      max0 = Z[i];
    }
  }
  if ( max0==-1 )
  {
    return;
  }

  for (l = i = 0; i < count; i++)
  {
    if (simple(Z[i]) && Z[i]!=max0)
    {
      l++;
      // REVIEW: тут не хватает скобок
      if (l==1)
        max1=Z[i];
      else
        if (Z[i]>max1)
        {
          max1=Z[i];
        }
    }
  }

  if ( max1 == -1 )
  {
    return;
  }


  for (l = i = 0; i < count; i++)
  {
    if (simple(Z[i]) && Z[i]!=max0 && Z[i]!=max1)
    {
      l++;
      // REVIEW: не помешали бы скобки
      if (l==1)
        max2=Z[i];
      else
        if (Z[i]>max2)
          max2=Z[i];
    }
  }

  if ( max2 == -1 )
  {
    return;
  }

}


void zadacha7()
{
  // REVIEW: Лучше инициализировать переменные все и сразу
  // int* X = nullptr;
  // int* Y = nullptr;
  int *X, *Y, *Z= NULL; // REVIEW: в с++11 используется nullptr
  int n, k;
  cin >> n >> k;
  X = new int[n];
  Y = new int[k];
  srand( time(0) );

  cout << "X:"<< endl;
  for ( int i = 0; i < n; ++i)
  {
    X[i] = 1 + rand() % 100;
    cout << X[i] << ' ';
  }

  cout << endl << "Y:"<< endl;
  for ( int i = 0; i < k; ++i)
  {
    Y[i] = 1 + rand() % 100;
    cout << Y[i] << ' ';
  }

  int counter = 0;
  createnewmas(Z,X,n,counter);
  createnewmas(Z,Y,k,counter);
  cout<< endl;
  for ( int i = 0; i < counter; ++i)
  {
    cout << Z[i] << ' ';
  }

  int max0 = -1, max1 = -1, max2 = -1;
  search(max0, max1, max2, Z, counter);
  if (max0 == -1)
  {
     cout<<endl<<"Net prostyh chisel"<< endl;
  }
  else
  {
    if (max1 == -1)
      cout<< endl<< max0; // REVIEW: скобки
    else
    {
      if (max2 == -1)
        cout<< endl<< max0 << ' ' << max1; // REVIEW: скобки
      else
      {
        cout<< endl<< max0 << ' ' << max1 <<' ' << max2;
      }

    }
  }
  delete []X;
  delete []Y;
  delete []Z;

}


void search_even_number(int &nmax1,int &nmax2, int x[], int n) //ищет два наибольших четных числа
{
  int i, kvo;
  nmax1 = 0;
  for ( i = 1; i < n; i++)
  {
    if ( (x[i]%2==0) && x[i] > x[nmax1] )
    {
      nmax1=i;
    }
  }
  for ( kvo = i = 0; i < n; i++)
  {
    if ( (x[i]%2==0) && i !=nmax1 )
    {
      kvo++;
      if ( kvo == 1)
        nmax2=i;
      else
      {
        if ( x[i] > x[nmax2] )
        {
          nmax2=i;
        }
      }
    }
  }

}

void sort(int *&x, int begin, int end) //bubblesort
{
  int i, j;
  for(i = end - 1; i > begin;i--)
  {
    for (j =begin; j < i; j++)
    {
      if ( x[j] < x[j+1] )
      {
        int tmp = x[j];
        x[j] = x[j+1];
        x[j+1] = tmp;
      }
    }
  }
}

void zadacha9()
{
  int *x;
  int n = 20;
  x = new int[n];
  srand(time(0));
  for ( int i = 0; i < n; i++)
  {
    x[i]= 1 + rand()%100;
    cout<<x[i]<<" ";
  }

  int nmax1, nmax2;
  search_even_number(nmax1,nmax2, x, n);
  if (nmax1 > nmax2)
  {
    nmax1 = nmax1 + nmax2;
    nmax2 = nmax1 - nmax2;
    nmax1 = nmax1 - nmax2;
  }

  sort(x, nmax1, nmax2);

  cout<<endl;
  for ( int i = 0; i < n; i++)
  {
    cout<<x[i]<< ' ';
  }
  cout<< endl << nmax1<< " " << nmax2;
}
//алгоритм стр157
void searchseq(int x[], int n, int& begin, int &end)
{
  int i, k, kgr, kon_max, max;
  for (kgr = i = 0, k = 1; i < n-1; i++) // REVIEW: скобки
    if ( x[i] % 2 == 1 && x[i+1] % 2 == 1 && x[i] <= x[i+1])
    {
      k++;
    }
    else // REVIEW: скобки, иначе непонятна, куда относиться второй if - скорее всего тут может быть ошибка
      if (k>1)
      {
        kgr++;
        if (kgr==1)
        {
          max = k;
          kon_max = i;
        }
        else // REVIEW: скобки

          if (k > max)
          {
            max = k;
            kon_max = i;
          }

        k = 1;

      }
      if (k > 1)
      {
        kgr++;
        if ( kgr == 1)
        {
          max = k;
          kon_max = n-1;
        }
        else // REVIEW: скобки
          if (k > max)
          {
            max = k;
            kon_max = n - 1;
          }
      }

    if (kgr > 0)
    {
      begin = kon_max-max+1;
      end = kon_max;
    }
    else
    {
      begin=end=0;
    }
}

void zadacha8()
{
  int *x, begin, end, n;
  n = 20;
  x=new int[n] {0, 1, 3, 5, 2, 4, 20, 5, 9, 11, 2, 4,5, 7, 13, 15, 17, 6, 9, 8};
  for ( int i = 0; i < n; i++ )
  {
    cout << x[i] <<  ' ';
  }
  cout << endl;

  searchseq(x, 20, begin, end);

  for (int i = begin; i <=  end; i++) // REVIEW: скобки
    cout << x[i] << ' ';

  for (int i = begin; i < n - (end - begin); i++)
  {
    x[i] = x[i+(end - begin +1)];
  }

  cout << endl;
  for (int i = 0; i <n - (end - begin) -1; i++) // REVIEW: скобки
    cout<<x[i]<<' ';
  delete []x;
}

int main()
{
  /*zadacha1();
  zadacha2();
  zadacha3();
  zadacha4();
  zadacha5();*/
  //zadacha6();
  //zadacha7();
  zadacha8();
  //zadacha9();


  return 0;
}
