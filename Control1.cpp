#include <iostream>
#include <math.h>

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
    float funciondev=0;
    float resultado;
    float error;

    cout << "ingrese una funcion"<<endl;
    cin >> funcion;

    cout << "ingrese valor de x"<<endl;
    cin >> x;

    while(error<0.5){
        while (i<10)
        {
            variable = funcion[i];
            variable2 = funcion[i-2];
            if(variable== "x")
            {
                if (isdigit(funcion[i-1]))
                {
                    constante=funcion[i-1];
                    
                }
                if (isdigit(funcion[i+3]))
                {
                    elevado = funcion[i+3];
                    
                }
                if (variable2=="-")
                {
                    funcion1=funcion1+constante*(pow(x,elevado));
                    funciondev= funciondev - constante*(elevado*(pow(x,elevado-1)));
                    
                }
                else
                {
                    funcion1=funcion1+constante*(pow(x,elevado));
                    funciondev= funciondev + constante*(elevado*(pow(x,elevado-1)));
                   
                }
        }
        i++;
    }
    resultado= x - (funcion1/funciondev);
    error=(resultado-x)/resultado;
    }
}
