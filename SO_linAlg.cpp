#include <iostream>
using namespace std;

double** matrix_product(double** M1, double** M2, int x1, int y1, int x2, int y2);
double** get_Matrix(int M, int N, int num);

int main()
{
	int x1;
	int x2;
	int y1;
	int y2;
	//Pido las dimensiones de las matrices
	cout<< "Ingrese el numero de filas de matriz 1"<< endl;
	cin >> x1;
	cout<< "Ingrese el numero de columnas de matriz 1"<< endl;
	cin >> y1 ;
	cout<< "Ingrese el numero de filas de matriz 2"<< endl;
	cin >> x2;
	cout<< "Ingrese el numero de columnas de matriz 2"<< endl;
	cin >> y2;
	if(y1!=x2)
	{
		cout<< "No se puede hacer la multiplicacion matricial"<< endl;
		return 0;	
	}
	//Esto es una matriz
	//get_Matrix(x1,y1,1);
	//get_Matrix(x2,y2,2);
	matrix_product(get_Matrix(x1,y1,1),get_Matrix(x2,y2,2),x1,y1,x2,y2);
	return 0;
}

double** matrix_product(double** M1, double** M2, int x1, int y1, int x2, int y2)
{
	double **Mres=new double*[x1];
	for(int i=0;i<x1;i++)
	{
		Mres[i]= new double[y2];	
	}
	//Se hace el calculo
	for(int i=0;i<x1;i++)
	{
		for(int j=0;j<y2;j++)
		{
			for(int k;k<y1;k++)
			{			
								
				Mres[i][j]+=M1[i][k]*M2[k][j];
			}
		}
	}
	//Se imprime la matriz resultado
	cout<< "el resultado es:"<< endl;
	for(int i=0;i<x1;i++)
	{
		for(int j=0;j<y2;j++)
		{
			cout<< Mres[i][j]<< " ";
						
		}	
		cout << endl;
	}
	return Mres;


}


double** get_Matrix(int M, int N, int num)
{
	//Se crea la matriz que se va llenar con los valores recibidos

	double **mat = new double*[M];
	for(int i=0;i<M;i++)
	{
		mat[i]= new double[N];	
	}
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<< "Ingrese el elemento de la fila "<<i<<" y la columna "<< j<<" de la matriz "<<num << endl;
			cin >>mat[i][j];
			
		}	
	
	}
	//Se imprime la matriz recibida
	cout << "La matriz que ingreso es la siguiente:"<< endl;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<< mat[i][j]<< " ";
						
		}	
		cout << endl;
	}
	
	return mat;

}



















