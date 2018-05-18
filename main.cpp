#include"planeta.h"
#include <iostream>
#include <vector>
#include<fstream>
using namespace std;


int main()
{
    fstream file;
    Planeta planet1={0,-7000,2,0,70,120},planet2={0,0,0,0,70000,300},planet3={4000,5000,-1.6,1.2,25,100}; //definition of planets
    //Planeta planet1={0,0,0,0,50000,200},planet2={-5000,0,0,-2,70,70},planet3={5000,0,0,2,70,70},planet4={0,-5000,2,0,70,70},planet5={0,5000,-2,0,70,70};
    //vector <Planeta> sistema={planet1,planet2,planet3,planet4,planet5};  //vector of planets
    vector <Planeta> sistema={planet1,planet2,planet3};
    int nplanetas=sistema.size(),i,j,puntos;


    file.open("ValoresDePosicion.txt",ios::out);
    file<<"X Planeta1\tY Planeta1\tX Planeta2\tY Planeta2\tX Planeta3\tY Planeta3\n"<<endl;
    //file<<"X Planeta1\tY Planeta1\tX Planeta2\tY Planeta2\tX Planeta3\tY Planeta3\tX Planeta4\tY Planeta4\tX Planeta5\tY Planeta5\n"<<endl;
    for(puntos=0;puntos<10000;puntos++){

        //calculate accelerations
        for(i=0;i<nplanetas;i++){
            sistema[i].setAx(0);   //start accelerations at zero
            sistema[i].setAy(0);

            for(j=0;j<nplanetas;j++)  //calculates the acceleration of one body with respect to another
                if(j!=i){
                    sistema[i].aceleracion(sistema[j]);
                }
        }

        //calculate positions
        for(i=0;i<nplanetas;i++){
            sistema[i].posicion();

            file<<sistema[i].getX()<<"\t\t"<<sistema[i].getY()<<"\t\t";  //write in the file
        }
        file<<endl;  //End of line in the file
    }
    file.close();  //close file

}
