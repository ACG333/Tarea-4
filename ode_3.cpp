#include<iostream>
#include<math.h>
#include<fstream>
#define max 10000
using namespace std;
double x;
double y;
double xf;
double yf;
double Vx;
double Vy;
double Vxf;
double Vyf;
double ax;
double ay;
double axf;
double ayf;
int tiempo=10;
double pi=3.141592;
double dt=0.0003;
void actualizar(){
    xf=x;
    yf=y;
    Vxf=Vx;
    Vyf=Vy;
    axf=ax;
    ayf=ay;
}
int main(){
    freopen("ode45.dat","w",stdout);
    double distancia_recorrida_45;
    double g,c,masa,angulo,Yo,Xo;
    g=10;
    c=0.2;
    masa=0.2;
    x=0;
    y=0;
    angulo=45*2*pi/360;
    Vx=300*cos(angulo);
    Vy=300*sin(angulo);
    ax=-(c*sqrt(Vx*Vx+Vy*Vy)*Vx)/masa;
    ay=-g-c*sqrt(Vx*Vx+Vy*Vy)*Vy/masa;
    actualizar();
    bool t=true;
    cout<<max<<endl;
    for(int i=0;i<max;i++){
        x=xf+Vxf*dt+(0.5)*axf*dt*dt;
        y=yf+Vyf*dt+(0.5)*ayf*dt*dt;
        ax=-c*sqrt(Vxf*Vxf+Vyf*Vyf)*Vxf/masa;
        ay=-g-c*sqrt(Vxf*Vxf+Vyf*Vyf)*Vyf/masa;
        Vx=Vxf+(0.5)*(ax+axf)*dt;
        Vy=Vyf+(0.5)*(ay+ayf)*dt;
        cout<<x<<" "<<y<<endl;
        if(y<=0 && t){
            t=false;
            distancia_recorrida_45=x;
        }
        actualizar();
    }
    double distancia_mayor=-1;
    double angulo_distancia_mayor=-1;
    freopen("odeVarios.dat","w",stdout);
    cout<<max<<endl;
    for(int j=10;j<=70;j+=10){
        x=0;
        y=0;
        angulo=j*2*pi/360;
        Vx=300*cos(angulo);
        Vy=300*sin(angulo);
        ax=-(c*sqrt(Vx*Vx+Vy*Vy)*Vx)/masa;
        ay=-g-c*sqrt(Vx*Vx+Vy*Vy)*Vy/masa;
        actualizar();
        t=true;
        for(int i=0;i<max;i++){
            x=xf+Vxf*dt+(0.5)*axf*dt*dt;
            y=yf+Vyf*dt+(0.5)*ayf*dt*dt;
            ax=-c*sqrt(Vxf*Vxf+Vyf*Vyf)*Vxf/masa;
            ay=-g-c*sqrt(Vxf*Vxf+Vyf*Vyf)*Vyf/masa;
            Vx=Vxf+(0.5)*(ax+axf)*dt;
            Vy=Vyf+(0.5)*(ay+ayf)*dt;
            cout<<x<<" "<<y<<endl;
            if(y<=0 && t){
                t=false;
                if(x>distancia_mayor){
                    distancia_mayor=x;
                    angulo_distancia_mayor=j;
                }
            }
            actualizar();
        }
    }
    freopen("Resultados.dat","w",stdout);
    cout<<"La distancia recorrida cuando se lanza el proyectil a 45 grados es de "<<distancia_recorrida_45<<"mt"<<endl;
    cout<<"La distancia mayor recorrida por el proyectil lanzado a 10,  20,  30, 40, 50 ,60 y 70 se genera con "<<angulo_distancia_mayor<<" grados y es "<<distancia_mayor<<" metros"<<endl;

	return 0;

}
