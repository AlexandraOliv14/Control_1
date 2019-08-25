#include <iostream>
#include <math.h>
#include <complex>
#include <complex.h>

using namespace std;

int main()
{
    string funcion;
    float x, i=0;
    float constante=1;
    float elevado;
    float funcion1=0;
    string variable;
    string variable2;
    string variable3;
    float funciondev=0;
    float resultado;
    float error;
    string fin;
    string finmenos;

    cout << "ingrese una funcion"<<endl;
    cin >> funcion;

    cout << "ingrese valor de x"<<endl;
    cin >> x;

    while(error<0.05){
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
                    constante=funcion[i-1];
                     cout<<"constante"<<endl;
                            cout<<constante<<endl;
                    if (isdigit(funcion[i+3]))  //ve si el exponente es numero
                    {
                        elevado = funcion[i+3];
                         cout<<"elevado"<<endl;
                            cout<<elevado<<endl;
                        if (variable2=="-")
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            cout<<"funcion"<<endl;
                            cout<<funcion1<<endl;
                            funciondev= funciondev - abs(constante*(elevado*(pow(x,elevado-1))));

                        }
                        else
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev + abs(constante*(elevado*(pow(x,elevado-1))));

                        }
                    }
                    else {
                            // entra si no tiene exponente
                            elevado=1;
                         if (variable2=="-")
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev - abs(constante*(elevado*(pow(x,elevado-1))));

                        }
                        else
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev + abs(constante*(elevado*(pow(x,elevado-1))));

                        }
                    }

                }
                else
                {
                    if (isdigit(funcion[i+3]))
                    {
                        elevado = funcion[i+3];
                        constante= 1;
                        if (variable3=="-")
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev - abs(constante*(elevado*(pow(x,elevado-1))));

                        }
                        else
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev + abs(constante*(elevado*(pow(x,elevado-1))));

                        }
                    }
                    else
                    {
                        elevado=0;
                        constante=1;
                        if (variable3=="-")
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev - abs(constante*(elevado*(pow(x,elevado-1))));

                        }
                        else
                        {
                            funcion1=funcion1+abs(constante*(pow(x,elevado)));
                            funciondev= funciondev + abs(constante*(elevado*(pow(x,elevado-1))));

                        }
                    }

                }

        }
        i++;
    }
    fin=funcion[funcion.length()];
    finmenos= funcion[funcion.length()-1];
    if (finmenos == "-")
    {
        if((fin != "x"))
        {
            funcion1 =funcion1 - funcion[funcion.length()];
                cout<< "menos" <<endl;

        }
    }
    else if (finmenos == "+")
    {
        if((fin != "x"))
        {
            funcion1 =funcion1 + funcion[funcion.length()];
        }
    }
    resultado= x - (funcion1/funciondev);
    error=(resultado-x)/resultado;
    x= resultado;

    cout<< funciondev <<endl;
     cout<< funcion1 <<endl;
    cout<< x <<endl;

    }
    return 0;
}
