/**
*	FractalMandelbrot
*	Programa que genera en formato PPM  (Portable Pixel Map) el conjunto del fractal de Mandelbrot, usando OPENMP
**/
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <cmath>
# include <ctime>
# include <cstring>
# include <omp.h>

using namespace std;

int main ( );
int min ( int i1, int i2 );
void eliminar_matriz ( int **a, int m, int n );
int **crear_matriz ( int m, int n );


int main ( void )
{

    //prueba 3
  int m = 4360;
  int n = 4360;
  int color = 1;

//prueba 2
 // int m = 2000;
  //int n = 2000;
  // int color = 2;


//  prueba 1
  //int m = 500;
  //int n = 500;
  //int color = 3;



  int **b;
  int c;
  int **cant;
  int cant_max = 2000;//Cantidad maxima de iteraciones para un pixel en particular
  int **g;
  int i;
  int j;
  int jmax;
  int jmin;
  int k;
  string nombrearchivosecuencial = "fractal_secuencial.ppm";
  string nombrearchivoparalelo = "fractal_paraleo.ppm";
  ofstream salida;
  int **r;
  double tiempo;
  clock_t t;
  double x_max =   2.25;
  double x_min = - 3.25;
  double x;
  double x1;
  double x2;
  double y_max =   2.75;
  double y_min = - 2.75;
  double y;
  double y1;
  double y2;

  b = crear_matriz ( m, n );
  cant = crear_matriz ( m, n );
  g = crear_matriz ( m, n );
  r = crear_matriz ( m, n );

  cout << "\n";
  cout << "Fractal de Mandelbrot con OPENMP\n";
  cout << "\n";
  cout << "  Crea una imagen PPM ASCII del conjunto de Mandelbrot.\n";
  cout << "\n";
  cout << "  Para cada punto C = X + i*Y (plano complejo)\n";
  cout << "  con el rango de X entre [" << x_min << "," << x_max << "]\n";
  cout << "  y el rango de Y entre [" << y_min << "," << y_max << "]\n";
  cout << "  se realizan " << cant_max << " iteraciones del mapa\n";
  cout << "  Z(n+1) = Z(n)^2 + C.\n";
  cout << "\n";
  cout << "  Una imagen ASCII PPM es creada usando\n";
  cout << "    M = " << m << " pixeles en la direccion X y\n";
  cout << "    N = " << n << " piceles en la direccion Y.\n";

  cout << "\nComienza ejecucion secuencial...\n";
  t = clock();

//Iteración para cada pixel
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      x = ( ( double ) (     j - 1 ) * x_max
          + ( double ) ( m - j     ) * x_min )
          / ( double ) ( m     - 1 );

      y = ( ( double ) (     i - 1 ) * y_max
          + ( double ) ( n - i     ) * y_min )
          / ( double ) ( n     - 1 );

      cant[i][j] = 0;

      x1 = x;
      y1 = y;

      for ( k = 1; k <= cant_max; k++ )
      {
        x2 = x1 * x1 - y1 * y1 + x;
        y2 = 2 * x1 * y1 + y;

        if ( x2 < -2.0 || 2.0 < x2 || y2 < -2.0 || 2.0 < y2 )
        {
          cant[i][j] = k;
          break;
        }
        x1 = x2;
        y1 = y2;
      }

      if ( ( cant[i][j] % 2 ) == 1 )
      {
        r[i][j] = 255;
        g[i][j] = 255;
        b[i][j] = 255;
      }
      else
      {
        c = ( int ) ( 255.0 * sqrt ( sqrt ( sqrt (
          ( ( double ) ( cant[i][j] ) / ( double ) ( cant_max ) ) ) ) ) );
        r[i][j] = 3 * c / color;
        g[i][j] = 3 * c / color;
        b[i][j] = c;
      }
    }
  }

  t = clock() - t;
  cout << "\n";
  cout << "  Tiempo = " << ((double)t)/CLOCKS_PER_SEC << " segundos.\n";

//Se guarda el archivo en un PPM ASCII
  salida.open ( nombrearchivosecuencial.c_str ( ) );

  salida << "P3\n";
  salida << n << "  " << m << "\n";
  salida << 255 << "\n";
  for ( i = 0; i < m; i++ )
  {
    for ( jmin = 0; jmin < n; jmin = jmin + 4 )
    {
      jmax = min ( jmin + 4, n );
      for ( j = jmin; j < jmax; j++ )
      {
        salida << "  " << r[i][j]
               << "  " << g[i][j]
               << "  " << b[i][j] << "\n";
      }
      salida << "\n";
    }
  }

  salida.close ( );
  cout << "\n";
  cout << "  Archivo guardado con el nombre \"" << "fractal_secuencial.ppm" << "\".\n";

//Se libera memoria
  eliminar_matriz ( b, m, n );
  eliminar_matriz ( cant, m, n );
  eliminar_matriz ( g, m, n );
  eliminar_matriz ( r, m, n );

  b = crear_matriz ( m, n );
  cant = crear_matriz ( m, n );
  g = crear_matriz ( m, n );
  r = crear_matriz ( m, n );

  cout << "\nComienza ejecucion paralela...\n";
  tiempo = omp_get_wtime ( );

//Iteración para cada pixel
# pragma omp parallel \
  shared ( b, cant, cant_max, g, r, x_max, x_min, y_max, y_min ) \
  private ( i, j, k, x, x1, x2, y, y1, y2 )
{
# pragma omp for

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      x = ( ( double ) (     j - 1 ) * x_max
          + ( double ) ( m - j     ) * x_min )
          / ( double ) ( m     - 1 );

      y = ( ( double ) (     i - 1 ) * y_max
          + ( double ) ( n - i     ) * y_min )
          / ( double ) ( n     - 1 );

      cant[i][j] = 0;

      x1 = x;
      y1 = y;

      for ( k = 1; k <= cant_max; k++ )
      {
        x2 = x1 * x1 - y1 * y1 + x;
        y2 = 2 * x1 * y1 + y;

        if ( x2 < -2.0 || 2.0 < x2 || y2 < -2.0 || 2.0 < y2 )
        {
          cant[i][j] = k;
          break;
        }
        x1 = x2;
        y1 = y2;
      }

      if ( ( cant[i][j] % 2 ) == 1 )
      {
        r[i][j] = 255;
        g[i][j] = 255;
        b[i][j] = 255;
      }
      else
      {
        c = ( int ) ( 255.0 * sqrt ( sqrt ( sqrt (
          ( ( double ) ( cant[i][j] ) / ( double ) ( cant_max ) ) ) ) ) );
        r[i][j] = 3 * c / color;
        g[i][j] = 3 * c / color;
        b[i][j] = c;
      }
    }
  }
}

  tiempo = omp_get_wtime ( ) - tiempo;
  cout << "\n";
  cout << " Tiempo = " << tiempo << " segundos.\n";

//Se guarda el archivo en un PPM ASCII
  salida.open ( nombrearchivoparalelo.c_str ( ) );

  salida << "P3\n";
  salida << n << "  " << m << "\n";
  salida << 255 << "\n";
  for ( i = 0; i < m; i++ )
  {
    for ( jmin = 0; jmin < n; jmin = jmin + 4 )
    {
      jmax = min ( jmin + 4, n );
      for ( j = jmin; j < jmax; j++ )
      {
        salida << "  " << r[i][j]
               << "  " << g[i][j]
               << "  " << b[i][j] << "\n";
      }
      salida << "\n";
    }
  }

  salida.close ( );
  cout << "\n";
  cout << "  Archivo guardado con el nombre \"" << "fractal_paralelo.ppm" << "\".\n";

//Se libera memoria
  eliminar_matriz ( b, m, n );
  eliminar_matriz ( cant, m, n );
  eliminar_matriz ( g, m, n );
  eliminar_matriz ( r, m, n );

//Fin
  cout << "\n";
  getchar();
  return 0;
}

int min ( int i1, int i2 )
{
  int value;

  if ( i1 < i2 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}

void eliminar_matriz ( int **a, int m, int n )
{
  int i;

  for ( i = 0; i < m; i++ )
  {
    delete [] a[i];
  }

  delete [] a;

  return;
}

int **crear_matriz ( int m, int n )
{
  int **a;
  int i;

  a = new int *[m];

  if ( a == NULL )
  {
    cerr << "\n";
    cerr << "crear_matriz - Error fatal!\n";
    cerr << "  No se pudo allocar memoria.\n";
    exit ( 1 );
  }

  for ( i = 0; i < m; i++ )
  {
    a[i] = new int[n];
    if ( a[i] == NULL )
    {
      cerr << "\n";
      cerr << "crear_matriz - Error fatal!\n";
      cerr << "  No se pudo allocar memoria..\n";
      exit ( 1 );
    }
  }

  return a;
}
