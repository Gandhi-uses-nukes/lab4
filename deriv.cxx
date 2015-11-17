#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

void fill_fct(double p[], const int N, const double xmin, const double xmax, const double dx){
  int n = 0;
  for(double x = xmin; x<=xmax; x += dx, n++)
    p[n]=exp(-pow(x,2));
}

void calc_fct(double p[], const int N, const double dx){
  double p_minus_one, p_temp;
  p_minus_one = 0;
  for(int i=0 ; i<N-2 ; i++){
    p_temp = p[i];
    p[i] = (p[i+1]-p_minus_one)/(2*dx);
    p_minus_one = p_temp;
  }
  p[N-1] = (0 - p_minus_one)/(2*dx);
}

int main(){
  const int N = 500;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);
  
  fill_fct(p, N, xmin, xmax, dx);
  calc_fct(p, N, dx);
  print(p,N,dx,xmin);

  return 0;
}
