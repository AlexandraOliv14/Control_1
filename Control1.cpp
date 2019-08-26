#include <iostream>
#include <math.h>
#include <complex>
#include <complex.h>
#include <stdio.h>

using namespace std;

int main(char *argv[],int argc)
{
    string funcion;
    funcion = argv[1];
    double x, i=0;
    double constante=1;
    double elevado;
    double funcion1=0;
    string variable;
    string variable2;
    string variable3;
    double funciondev=0;
    double resultado;
    double error;
    string fin;
    string finmenos;
    int cont =0;

  //cd p  cout << "ingrese una funcion"<<endl;
//   cin >> funcion;


    x=1.5;

    while(error < 0.05){
        funcion1=0;
        funciondev=0;
        while (i<funcion.length())        // largo del string
        {
            variable = funcion[i];
            variable2 = funcion[i-2];
            variable3 = funcion[i-1];

            if(variable== "x")    // Encuenta X
            {
                if (isdigit(funcion[i-1]))  //Ve si el anterior a la x es un numero
                {
                    constante=funcion[i-1]-48;
                    if (isdigit(funcion[i+3]))  //ve si el exponente es numero
                    {
                        elevado = funcion[i+3]-48;
                        if (variable2=="-")
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev - fabs(constante*(elevado*(pow(x,elevado-1))));

                        }
                        else
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev + fabs(constante*(elevado*(pow(x,elevado-1))));

                        }
                    }
                    else {
                            // entra si no tiene exponente
                            elevado=1;
                         if (variable2=="-")
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev - fabs(constante*(elevado*(pow(x,elevado-1))));

                        }
                        else
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev + fabs(constante*(elevado*(pow(x,elevado-1))));

                        }
                    }

                }
                else
                {
                    if (isdigit(funcion[i+3]))
                    {
                        elevado = funcion[i+3]-48;
                        constante= 1;
                        if (variable3=="-")
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev - fabs(constante*(elevado*(pow(x,elevado-1))));

                        }
                        else
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev + fabs(constante*(elevado*(pow(x,elevado-1))));

                        }
                    }
                    else
                    {
                        elevado=0;
                        constante=1;
                        if (variable3=="-")
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev - fabs(constante*(elevado*(pow(x,elevado-1))));

                        }
                        else
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev + fabs(constante*(elevado*(pow(x,elevado-1))));

                        }
                    }

                }

        }
        i++;
    }

    fin=funcion[funcion.length()-1];
    finmenos= funcion[funcion.length()-2];


    if (x=!resultado)
    {
        while (funcion1*funciondev <= 0)
        {
            x=x/2;
        }
    }

        if (finmenos == "-")
        {
            if(fin != "x")
            {
            funcion1 =funcion1 - funcion[funcion.length()];

            resultado= x - (funcion1/funciondev);
            error= fabs(resultado-x);
            x= resultado;

            cout<< "resultado obtenido: " << x <<endl;
            cout<< "error obtenido: "<< error <<endl;
            }

        }
        else if (finmenos == "+")
        {
            if((fin != "x"))
            {
            funcion1 =funcion1 + funcion[funcion.length()];

            resultado= x - (funcion1/funciondev);
            error=fabs(resultado-x);
            x= resultado;

            cout<< "resultado obtenido: " << x <<endl;
            cout<< "error obtenido: "<< error <<endl;
            }

        }

        else
        {

            resultado= x - (funcion1/funciondev);
            error=fabs(resultado-x);
            x= resultado;

            cout<< "resultado obtenido: " << x <<endl;
            cout<< "error obtenido: "<< error <<endl;

        }

    }



    cout<< "resultado obtenido: " << x <<endl;
    cout<< "error obtenido: "<< error <<endl;
    return 0;
}
