#include <iostream>
#include <math.h>
using namespace std;

//CLASES

class arithmetic_op{
  //clase padre
  public:
    //prototipos de funciones aritmeticas basicas (AB)
    float add(int factors); //suma
    float subs(int factors); //resta
    float mult(int factors); //multiplicacion
    float div(float dividend, float divisor); //division
    float pot(float factors, float exp); //potencia
};

class geometric_op : public arithmetic_op{
  //herada funciones AB
  public:
    //prototipos de funciones geometricas (G)
    //Area
    int AT(float base, float altura);
    int AR(float base, float altuta);
    float AC(int radio);
    //Perimetro
    int PT(float la, float lb, float lc);
    int PR(float base, float altura);
    float PC(float diametro);
    //Volumen
    int VR(int largo, int ancho, int alto);
    int VT(int largo, int ancho, int alto);
    float VC(int radio, int altura);

    //nota: T=triangulo R=recttangulo C=circulo
};

class matrix_op : public geometric_op{
  //herada funciones AB y G
  public:
    //prototipos de funciones matriciales (M)
    void matrix_input(int factors, int *ptr); //rellenar matrices
    void matrix_print(int factors, int *ptr); //imprimir matrices
    void matrix_add(int factors, int *ptr1, int *ptr2, int *ptrR); //suma
    void matrix_subs(int factors, int *ptr1, int *ptr2, int *ptrR); //resta
    void matrix_mult(int factors, int *ptr1, int *ptr2, int *ptrR); //multiplicacion
    void matrix_trans(int factors, int *ptr, int *ptrT); //transpocicion
};

class algebraic_op : public matrix_op{
  //herada funciones AB, G y M
  public:
    //prototipos de funciones algebraicas y vectores (AV)
    //Resolucion de sistema de ecuaciones simples
    float ec_x(int ecx[3], int ecy[3]);
    float ec_y(int ecx[3], int ecy[3]);
    //Distancia entre dos puntos
    void puntero_vectores(int* vec);
    float puntero_distancia(int* vec1,int* vec2);
    //Magnitud de un vector
    float puntero_magnitud(int* vec);
    //Suma de dos vectores
    void puntero_suma(int* vec1, int* vec2, int* vec3);
};

class statistic_op : public algebraic_op{
  //herada funciones AB, G, M y AV
  public:
    //prototipos de funciones estadisticas (E)
    void data(int factors, int array[30]); //ingresar datos
    float media(int factors, int array[30]); //media=promedio
    float mediana(int factors, int array[30]); //mediana=valor ubicado en el medio
    float moda(int factors, int array[30]); //moda=valor con mayor frecuencia
};

class scientific_calc : public statistic_op{
  //herada funciones AB, G, M, AV y E para crear la calculadora cientifica
  public:
    //prototipos de funciones para submenus
    int submenu; //variable switch para submenus
    void arithmetic();
    void geometric();
    void matrix();
    void algebraic();
    void statistic();
};

//MAIN

int main(){
  //display y seleccion del menu principal y submenus de cada tipo de operacion
    int menu; //variable switch menu principal
    scientific_calc op; //objeto calculadora
    //MENU PRINCIPAL (tipo de operacion)
    cout<<endl<<"--------Menu--------"<<endl;
    cout<<"1: Aritmetica"<<endl;
    cout<<"2: Geometrica"<<endl;
    cout<<"3: Matricial"<<endl;
    cout<<"4: Algebraica o vectorial"<<endl;
    cout<<"5: Estadistica"<<endl;
    cout<<"Seleccione el tipo de operacion que desea realizar:"<<endl;
    cin>>menu;

    switch (menu)
    {
        case 1: //operaciones aritmeticas
          cout<<endl<<"--------Operaciones Aritmeticas--------"<<endl;
          cout<<"1: Suma"<<endl;
          cout<<"2: Resta"<<endl;
          cout<<"3: Multiplicacion"<<endl;
          cout<<"4: Division"<<endl;
          cout<<"5: Potencia"<<endl;
          cout<<"Seleccione la operacion que desea realizar:"<<endl;
          cin>>op.submenu;
          op.arithmetic(); //objeto realiza funcion aritmetica seleccionada
          break;
        case 2: //operaciones geometricas
          cout<<endl<<"--------Operaciones Geometricas--------"<<endl;
          cout<<"1: Area de un triangulo"<<endl;
          cout<<"2: Area de un rectangulo"<<endl;
          cout<<"3: Area de un circulo"<<endl;
          cout<<"4: Perimetro de un triangulo"<<endl;
          cout<<"5: Perimetro de un rectangulo"<<endl;
          cout<<"6: Perimetro de uncirculo"<<endl;
          cout<<"7: Volumen de un prisma triangular"<<endl;
          cout<<"7: Volumen de un prisma rectangular"<<endl;
          cout<<"7: Volumen de un cilindro"<<endl;
          cout<<"Seleccione la operacion que desea realizar:"<<endl;
          cin>>op.submenu;
          op.geometric(); //objeto realiza funcion geometrica seleccionada
          break;
        case 3: //operaciones matriciales
          cout<<endl<<"--------Operaciones Matriciales--------"<<endl;
          cout<<"1: Suma"<<endl;
          cout<<"2: Resta"<<endl;
          cout<<"3: Multiplicacion"<<endl;
          cout<<"4: Transposicion"<<endl;
          cout<<"Seleccione la operacion que desea realizar:"<<endl;
          cin>>op.submenu;
          op.matrix(); //objeto realiza funcion matricial seleccionada
          break;
        case 4: //operaciones algebraicas y vectores
          cout<<endl<<"--------Operaciones Algebraicas y vectores--------"<<endl;
          cout<<"Seleccione la operacion que desea realizar"<<endl;
          cout<<"1: Resolucion de sistemas de ecuaciones simples (2 incognitas)"<<endl;
          cout<<"2: Distancia entre dos puntos"<<endl;
          cout<<"3: Magnitud de un vector"<<endl;
          cout<<"4: Suma de dos vectores"<<endl;
          cout<<"Seleccione la operacion que desea realizar:"<<endl;
          cin>>op.submenu;
          op.algebraic(); //objeto realiza funcion algebraica y vectores seleccionada
          break;
        case 5: //operaciones estadisticas
          cout<<endl<<"--------Operaciones Estadisticas--------"<<endl;
          cout<<"1: Media"<<endl;
          cout<<"2: Mediana"<<endl;
          cout<<"3: Moda"<<endl;
          cout<<"Seleccione la operacion que desea realizar"<<endl;
          cin>>op.submenu;
          op.statistic(); //objeto realiza funcion estadistica seleccionada
          break;
        default:
          break;
    }
}

//FUNCIONES

//OPERACIONES ARITMÉTICAS

float arithmetic_op::add(int factors){
  //suma algebraica de la cantidad de numeros indicada por el usuario
  float ans=0,num;
  cout<<"Ingresar numeros a sumar:"<<endl;
  for(int i=0;i<factors;i++){
    cin>>num;
    ans=ans+num;
  }
  cout<<"Resultado:"<<endl;

  return ans;
}

float arithmetic_op::subs(int factors){
  //resta algebraica de la cantidad de numeros indicada por el usuario
  float ans=0,num;
  cout<<"Ingresar numeros a restar:"<<endl;
  for(int i=0;i<factors;i++){
    cin>>num;
    if(i==0) //primer numero ingresado
      ans=num;
    else if(i>0)
      ans=ans-num;
  }
  cout<<"Resultado:"<<endl;

  return ans;
}

float arithmetic_op::mult(int factors){
  //multiplicacion algebraica de la cantidad de numeros indicada por el usuario
  float ans=1,num;
  cout<<"Ingresar numeros a multiplicar:"<<endl;
  for(int i=0;i<factors;i++){
    cin>>num;
    ans=ans*num;
  }
  cout<<"Resultado:"<<endl;

  return ans;
}

float arithmetic_op::div(float dividend, float divisor){
  //division algebraica de los numeros indicados por el usuario
  cout<<"Resultado:"<<endl;

  return dividend/divisor;
}

float arithmetic_op::pot(float factors, float exp){
  //elevar el numero indicado por el usuario a la potencia indicada
  int ans=1;
  for(int i=0;i<exp;i++){
    ans=ans*factors;
  }
  cout<<"Resultado:"<<endl;

  return ans;
}

//OPERACIONES GEOMETRICAS

int geometric_op::AT(float base, float altura){
	return(base*altura)/2;
}

int geometric_op::AR(float base, float altura){
	return(base*altura);
}

float geometric_op::AC(int radio){
	return(3.1416*(radio^2));
}

int geometric_op::PT(float la, float lb, float lc){
	return(la+lb+lc);
}

int geometric_op::PR(float base, float altura){
	return((2*base)+(2*altura));
}

float geometric_op::PC(float diametro){
	return (3.1416*diametro);
}

int geometric_op::VR(int largo, int ancho, int alto){
	return (AR(largo,ancho)*alto);
}

int geometric_op::VT(int base, int alturat, int altura){
	return (AT(base,alturat)*altura);
}

float geometric_op::VC(int radio, int altura){
	return (AC(radio)*altura);
}

//OPERACIONES MATRICIALES

void matrix_op::matrix_input(int factors, int *ptr){
  //ingresa datos de acuerdo al tamaño indicado por el usuario
  for(int i=0;i<factors;i++){
    for(int j=0;j<factors;j++){
      cin>>*(ptr+(i*factors)+j);
    }
  }
}

void matrix_op::matrix_print(int factors, int *ptr){
  //impresion en forma matricial
  for(int i=0;i<factors;i++){
    for(int j=0;j<factors;j++){
      cout<<*(ptr+(i*factors)+j)<<" ";
    }
    cout<<endl;
  }
}

void matrix_op::matrix_add(int factors, int *ptr1, int *ptr2, int *ptrR){
  //obtencion de matriz resultante mediante la suma de las matrices ingresadas por el usuario
  for(int i=0;i<factors;i++){
    for(int j=0;j<factors;j++){
      (*(ptrR+j+(i*factors)))=(*(ptr1+(i*factors)+j))+(*(ptr2+(i*factors)+j));
    }
  }
}

void matrix_op::matrix_subs(int factors, int *ptr1, int *ptr2, int *ptrR){
  //obtencion de matriz resultante mediante la resta de las matrices ingresadas por el usuario
  for(int i=0;i<factors;i++){
    for(int j=0;j<factors;j++){
      (*(ptrR+(i*factors)+j))=(*(ptr1+(i*factors)+j))-(*(ptr2+(i*factors)+j));
    }
  }
}

void matrix_op::matrix_mult(int factors, int *ptr1, int *ptr2, int *ptrR){
  //obtencion de matriz resultante mediante la multiplicacion de las matrices ingresadas por el usuario
  int ans=0;
  for(int i=0;i<factors;i++){
    for(int j=0;j<factors;j++){
      for(int k=0;k<factors;k++){
        ans=ans+((*(ptr1+(i*factors)+k))*(*(ptr2+(i*factors)+j)));
      }

      *(ptrR+(i*factors)+j)=ans;
      ans=0;
    }
  }
}

void matrix_op::matrix_trans(int factors, int *ptr, int *ptrT){
  //transposicion de matrices ingresadas
  for(int i=0;i<factors;i++){
    for(int j=0;j<factors;j++){
      *(ptrT+(i*factors)+j)=*(ptr+(j*factors)+i);
    }
  }
}

//OPERACIONES ALGEBRAICAS Y VECTORES
//Se ocupa el metodo de resolucion por determinantes

float algebraic_op::ec_x(int ecx[3], int ecy[3]){
	int determinante;
	determinante = (ecx[0]*ecy[1])-(ecx[1]*ecy[0]);
	return ((((ecx[2])*(ecy[1]))-((ecy[2])*(ecx[1])))/determinante);
}

float algebraic_op::ec_y(int ecx[3], int ecy[3]){
	int determinante;
	determinante=((((ecx[0])*(ecy[1])))-(((ecx[1])*ecy[0])));
	return ((((ecx[0])*(ecy[2]))-((ecx[2])*(ecy[0])))/determinante);
}

void algebraic_op::puntero_vectores(int* vec){
	for (int i=0;i<3;i++)
	{
		cin>> *(vec+i);
	}
}

float algebraic_op::puntero_distancia(int* vec1, int* vec2){
	int total[3];
	int suma_tot;
	for (int i=0;i<3; i++)
	{
		total[i]=((*(vec1+i))-(*(vec2+i)));
	}
	suma_tot=(total[0]*total[0])+(total[1]*total[1])+(total[2]*total[2]);

	return (sqrt(suma_tot));
}

float algebraic_op::puntero_magnitud(int* vec){
	int suma_tot= ((*(vec))*(*(vec)))+((*(vec+1))*(*(vec+1)))+((*(vec+2))*(*(vec+2)));
	return (sqrt(suma_tot));
}

void algebraic_op::puntero_suma(int* vec1,int* vec2,int* vec3){
	for (int i=0;i<3;i++)
	 {
		*(vec3+i)=((*(vec1+i))+(*(vec2+i)));
	}
}

//OPERACIONES ESTADÍSTICAS

void statistic_op::data(int factors, int array[30]){
  //ingresa datos de acuerdo a la cantidad indicada por el usuario (max 30)
  for(int i=0;i<factors;i++)
    cin>>array[i];
}

float statistic_op::media(int factors, int array[30]){
  //obtencion del promedio de los datos indicados
  int ans=0;
  for(int i=0;i<factors;i++)
    ans=ans+array[i];

  return div(ans, factors);
}

float statistic_op::mediana(int factors, int array[30]){
  //obtencion de la mediana de los datos indicados
  int aux,i,j;
  float ans,x;
  //ordena los datos de menor a mayor
  for(i=0;i<factors;i++){
    for(j=0;j<factors;j++){
      if(array[j]>array[j+1]){
        aux=array[j];
        array[j]=array[j+1];
        array[j+1]=aux;
      }
    }
  }
  if (factors%2==0){ //si es una cantidad de datos par, obtiene el promedio de los dos datos centrales
    x=(array[factors/2]+array[factors/2-1]);
    ans=x/2;
  }
	else //si es una cantidad de datos impar, selecciona el dato central
		ans=array[factors/2];

  return ans;
}

float statistic_op::moda(int factors, int array[30]){
  //obtencion de la moda de los datos indicados
  int sum=0, ans=1;
  int aux=sum;
  for(int i=0;i<factors;i++){
		sum=0;
		for (int j=0;j<factors;j++){
			if((array[i]==array[j])&&(i!=j))
				sum++; //contador de valores repetidos
	  }
		if(sum>=aux){ //selecciona dato con mayor frecuencia
			aux=sum;
			ans=i;
		}
	}

	return array[ans];
}

//SUB-MENUS

void scientific_calc::arithmetic(){
  //submenu de operaciones aritmeticas disponibles
  //se crean y solicitan las variables necesarias
  float size,a,b;

  switch (submenu)
    {
      case 1:
        cout<<"Cantidad de datos a sumar:"<<endl;
        cin>>size;
        cout<<add(size)<<endl;
        break;
      case 2:
        cout<<"Cantidad de datos a restar"<<endl;
        cin>>size;
        cout<<subs(size)<<endl;
        break;
      case 3:
        cout<<"Cantidad de datos a multiplicar"<<endl;
        cin>>size;
        cout<<mult(size)<<endl;
        break;
      case 4:
        cout<<"Ingrese numero a dividir:"<<endl;
        cin>>a;
        cout<<"Ingrese numero divisor"<<endl;
        cin>>b;
        cout<<div(a,b)<<endl;
        break;
      case 5:
        cout<<"Ingrese numero a elevar:"<<endl;
        cin>>a;
        cout<<"Seleccione la potencia"<<endl;
        cin>>b;
        cout<<pot(a,b)<<endl;
        break;
      default:
        break;
    }
}

void scientific_calc::geometric(){
  //submenu de operaciones geometricas disponibles
  //se crean y solicitan las variables necesarias
	int x,y,z;

		switch (submenu)
		{
			case 1:
        cout<<"Base: "<<endl;
        cin>>x;
        cout<<"Altura: "<<endl;
        cin>>y;

        if(x<0)
        {
          x=x*(-1);
        }

        if(y<0)
        {
          y=y*(-1);
        }
        cout<<"El area del triangulo es: "<<AT(x,y)<<endl;
			break;

		 case 2:
        cout<<"Largo: "<<endl;
				cin>> x;
				cout<< "Ancho: "<<endl;
				cin>> y;

				if(x<0)
				{
					x=x*(-1);
				}

				if(y<0)
				{
					y=y*(-1);
				}
				cout<< "El area del rectangulo es: "<<AR(x,y)<<endl;
			break;

		case 3:
			cout<<"Base: "<<endl;
			cin>>x;

			if(x<0)
			{
				x=x*(-1);
			}
			cout<<"El area del circulo es: " <<AC(x)<<endl;
			break;

		case 4:
      cout<<"Lado 1: "<<endl;
      cin>>x;
      cout<<"Lado 2: "<<endl;
      cin>>y;
      cout<<"Lado 3: "<<endl;
      cin>>z;

      if(x<0)
      {
        x=x*(-1);
      }

      if(y<0)
      {
        y=y*(-1);
      }

      if(z<0)
      {
        z=z*(-1);
      }
      cout<< "El perimetro del triangulo es: " << PT(x,y,z)<<endl;
		break;

		case 5:
      cout<<"Largo: "<<endl;
			cin>>x;
			cout<<"Ancho: "<<endl;
			cin>>y;

			if(x<0)
			{
				x=x*(-1);
			}

			if(y<0)
			{
				y=y*(-1);
			}
			cout<<"El perimetro del rectangulo es: "<<PR(x,y)<<endl;
		break;

		case 6:
			cout<<"Base: "<<endl;
			cin>>x;

			if(x<0)
			{
				x=x*(-1);
			}
			cout<<"El perimetro del circulo es: "<<PC(x)<<endl;
		break;

		case 7:
        cout<<"Largo: "<<endl;
        cin>>x;
        cout<<"Altura del triangulo: "<<endl;
        cin>>y;
        cout<<"Altura del prisma: "<<endl;
        cin>>z;

        if(x<0)
        {
          x=x*(-1);
        }

        if(y<0)
        {
          y=y*(-1);
        }

        if(z<0)
        {
          z=z*(-1);
        }
        cout<<"El volumen del prisma triangular es: " <<VT(x,y,z)<<endl;
			break;

		case 8:
      cout<<"Largo: "<<endl;
			cin>>x;
			cout<<"Ancho: "<<endl;
			cin>>y;
			cout<<"Altura: "<<endl;
			cin>>z;

			if(x<0)
			{
				x=x*(-1);
			}

			if(y<0)
      {
				y=y*(-1);
			}
			if(z<0)
      {
				z=z*(-1);
			}
			cout<<"El volumen del prisma rectangular es: "<<VR(x,y,z)<<endl;
			break;

		case 9:
			cout<<"Radio: "<<endl;
			cin>>x;
			cout<<"Altura del cilindro: "<<endl;
			cin>>y;

			if(x<0)
			{
				x=x*(-1);
			}

			if(y<0)
      {
				y=y*(-1);
			}
			cout<<"El volumen del cilindro es: "<<VC(x,y)<<endl;
			break;
		default:
			break;
	}
}

void scientific_calc::matrix(){
  //submenu de operaciones matriciales disponibles
  //se crean y solicitan las variables necesarias
  int factors;

  cout<<"Tamano de las matrices:"<<endl;
	cin>>factors;

  int matrixA[factors][factors];
  int matrixB[factors][factors];
  int matrixR[factors][factors];

  cout<<"Ingrese los datos de la matriz 1"<<endl;
  matrix_input(factors, (int*)matrixA);
  cout<<"Ingrese los datos de la matriz 2"<<endl;
  matrix_input(factors, (int*)matrixB);

  switch (submenu)
    {
      case 1:
        cout<<"Matriz resultante:"<<endl;
        matrix_add(factors, (int*)matrixA, (int*)matrixB, (int*)matrixR); //en caso de que se elija 1 hace la suma por la funcion remplazando los valores de las matrices
        matrix_print(factors,(int*)matrixR);
        break;
      case 2:
        cout<<"Matriz resultante:"<<endl;
        matrix_subs(factors, (int*)matrixA, (int*)matrixB, (int*)matrixR); //en caso de que se elija 2 hace la resta por la funcion remplazando los valores de las matrices
        matrix_print(factors,(int*)matrixR);
        break;
      case 3: //multiplicacion
        cout<<"Matriz resultante:"<<endl; //en casao de que se elija 3 hace la funcion de multiplicacion remplazando los valores de la matreiz
        matrix_mult(factors, (int*)matrixA, (int*)matrixB, (int*)matrixR);
        matrix_print(factors,(int*)matrixR);
        break;
      case 4: //transpuesta
        cout<<"Matriz 1 transpuesta:"<<endl;//en casao de que se elija hace la funcion de transpuesta usando solo la matriz y dando el resultado
        matrix_trans(factors, (int*)matrixA, (int*)matrixR);
        matrix_print(factors,(int*)matrixR);
        cout<<"Matriz 2 transpuesta:"<<endl;
        matrix_trans(factors, (int*)matrixB, (int*)matrixR);
        matrix_print(factors,(int*)matrixR);
        break;
      default:
        break;
    }

}

void scientific_calc::algebraic(){
  //submenu de operaciones algebraicas y vectores disponibles
  //se crean y solicitan las variables necesarias
  int ecuacion1[3],ecuacion2[3];
	int vector1[3],vector2[3],vector3[3];

	switch (submenu)
  {
		case 1:
			cout<<"Dame los valores para la ecuacion 1"<<endl;
			cout<<"x= "<<endl;
			cin>>ecuacion1[0];
			cout<<"y= "<<endl;
			cin>>ecuacion1[1];
			cout<<"r= "<<endl;
			cin>>ecuacion1[2];

			cout<<"Dame los valores para la ecuacion 2"<<endl;
			cout<<"x= "<<endl;
			cin>>ecuacion2[0];
			cout<<"y= "<<endl;
			cin>>ecuacion2[1];
			cout<<"r= "<<endl;
			cin>>ecuacion2[2];
			cout<<"x="<<ec_x(ecuacion1, ecuacion2);
			cout<<"y="<<ec_y(ecuacion1, ecuacion2);
			break;

		case 2:
			cout<<"Dame el vector 1"<<endl;
			puntero_vectores((int*)vector1);
			cout<<"Dame el vector 2"<<endl;
			puntero_vectores((int*)vector2);
			cout<<endl;
			cout<<"La distancia entre los puntos es: "<<puntero_distancia((int*)vector1,(int*)vector2)<<endl;
			break;

		case 3:
			cout<<"Dame el vector"<<endl;
			puntero_vectores((int*)vector1);
			cout<<endl;
			cout<<"La magnitud del vector es: "<<puntero_magnitud((int*)vector1);
			break;

		case 4:
			cout<<"Dame el vector 1"<<endl;
			puntero_vectores((int*)vector1);
			cout<<"Dame el vector 2"<<endl;
			puntero_vectores((int*)vector2);
			cout<<endl;
			cout<<"La suma de vectores es: "<<endl;
			puntero_suma((int*)vector1, (int*)vector2, (int*)vector3);
			cout<<"("<<vector3[0]<<", "<<vector3[1]<<", "<<vector3[2]<<")"<<endl;
			break;
		default:
			break;
	}
}

void scientific_calc::statistic(){
  //submenu de operaciones estadisticas disponibles
  //se crean y solicitan las variables necesarias
  int array[30];
  int size;

  cout<<"Cantidad de datos:"<<endl;
  cin>>size;
  cout<<"Ingrese los datos:"<<endl;
  data(size,array);

  switch(submenu)
    {
      case 1:
        cout<<media(size,array)<<endl;
        break;
			case 2:  //mediana
        cout<<"Mediana: "<<mediana(size,array);
        break;
      case 3:  //moda
        cout<<"Moda: "<<moda(size,array);
        break;
      default:
        break;
    }

}
