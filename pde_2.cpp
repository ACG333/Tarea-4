#include<iostream>
#include<fstream>
#include<math.h>
#define max 101
using namespace std;
double T[max+5][max+5];
double Tf[max+5][max+5];
double Tpromedio[max+5][max+5];
void actualizar(){
    for(int i=0;i<=max;i++)
        for(int j=0;j<=max;j++){
            Tf[i][j]=T[i][j];
            Tpromedio[i][j]+=T[i][j];
        }
}
bool esVarilla(double x,double y){
    while((x-0.5)>=0){
        x-=0.5;
    }
    while((y-0.5)>=0){
        y-=0.5;
    }
    if(x>=0.2 && x<=0.3 && y>=0.2 && y<=0.3 ){
        return true;
    }else{
        return false;
    }
}
int main(){
    //A
    freopen("pde_datosA.dat","w",stdout);
    double v,p,k,Cp,temperatura_varrilla,frontera_fija,dx,dt,altura,ancho,s,tiempo,dy;
    Cp=820;
    p=2.71*1000;
    k=1.62;
    temperatura_varrilla=373.15;
    frontera_fija=283.15;
    tiempo=3000;
    altura=0.5;
    ancho=0.5;
    dt=3;
    v=k/(Cp*p);
    dx=ancho/max;
    dy=altura/max;
    s=v*dt/(dx*dx);
    int t1=2,t2=tiempo/3,t3=t2*2,t4=tiempo-4;
    for(int j=0;j<=max;j++)
        for(int k=0;k<=max;k++)
            Tf[j][k]=frontera_fija;
    cout<<max<<endl;
    for(int k=1;k<tiempo;k++){
        for(int i=0;i<=max;i++){
            for(int j=0;j<=max;j++){
                if(j==0 || i==0 || j==max-1 || i==max-1){
                    T[i][j]=frontera_fija;
                }else if(i*dx>=0.2 && i*dx<=0.3 && j*dx>=0.2 && j*dx<=0.3 ){
                    T[i][j]=temperatura_varrilla;
                }else{
                    T[i][j]=Tf[i][j]+s*(Tf[i][j+1]-2*Tf[i][j]+Tf[i][j-1])+s*(Tf[i+1][j]-2*Tf[i][j]+Tf[i-1][j]);
                }
            }
        }
        actualizar();
        if(k==t1 || k==t2 || k==t3 || k==t4){
            for(int i=0;i<max;i++){
                for(int j=0;j<max;j++){
                    cout<<dx*j<<endl;
                }
            }
            for(int i=0;i<max;i++){
                for(int j=0;j<max;j++){
                    cout<<dx*i<<endl;
                }
            }
            for(int i=0;i<max;i++){
                for(int j=0;j<max;j++){
                    cout<<T[i][j]<<endl;
                }
            }
        }
    }
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
                cout<<dx*j<<endl;
        }
    }
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            cout<<dx*i<<endl;
        }
    }
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            cout<<Tpromedio[i][j]/tiempo<<endl;
        }
    }
    freopen("pde_datosB.dat","w",stdout);
    tiempo=4000;
    dt=3;
    t1=5,t2=tiempo/3,t3=t2*2,t4=tiempo-4;
    cout<<max<<endl;
    for(int j=0;j<=max+1;j++)
        for(int k=0;k<=max+1;k++){
            Tf[j][k]=285.15;
        }
    for(int k=1;k<tiempo;k++){
        for(int i=max/2;i<=max;i++){
            for(int j=max/2;j<=max;j++){
                if(j==0 || i==0 || j==max-1 || i==max-1){
                    if(j<=max/2 && i<=max/2)
                        T[i][j]=Tf[i+2][j+2];
                    if(j>max/2 && i>max/2)
                        T[i][j]=Tf[i-2][j-2];
                    if(j<=max/2 && i>max/2)
                        T[i][j]=Tf[i-2][j+2];
                    if(j>max/2 && i<=max/2){
                        T[i][j]=Tf[i+2][j-2];
                    }
                }else if(i*dx>=0.2 && i*dx<=0.3 && j*dx>=0.2 && j*dx<=0.3 ){
                    T[i][j]=temperatura_varrilla;
                }else{
                    T[i][j]=Tf[i][j]+s*(Tf[i][j+1]-2*Tf[i][j]+Tf[i][j-1])+s*(Tf[i+1][j]-2*Tf[i][j]+Tf[i-1][j]);
                }
            }
        }
        for(int i=0;i<=max/2;i++){
            for(int j=0;j<=max/2;j++){
                T[i][j]=T[max-j][max-i];
            }
        }
        for(int i=0;i<=max/2;i++){
            for(int j=max/2;j<=max;j++){
                T[i][j]=T[max-(max-j)][max-i];
            }
        }
        for(int i=max/2;i<=max;i++){
            for(int j=0;j<=max/2;j++){
                T[i][j]=T[max-j][max-(max-i)];
            }
        }

        actualizar();
        if(k==t1 || k==t2 || k==t3 || k==t4){
            for(int i=0;i<max;i++){
                for(int j=0;j<max;j++){
                    cout<<dx*j<<endl;
                }
            }
            for(int i=0;i<max;i++){
                for(int j=0;j<max;j++){
                    cout<<dx*i<<endl;
                }
            }
            for(int i=0;i<max;i++){
                for(int j=0;j<max;j++){
                    cout<<T[i][j]<<endl;
                }
            }
        }
    }
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
                cout<<dx*j<<endl;
        }
    }
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            cout<<dx*i<<endl;
        }
    }
    for(int i=0;i<max;i++){
        for(int j=0;j<max;j++){
            cout<<Tpromedio[i][j]/tiempo<<endl;
        }
    }
    freopen("pde_datosC.dat","w",stdout);
    tiempo=10000;
    altura=1.5;
    ancho=1.5;
    dt=65;
    int a=(max/3)-18;
    int b=((max*2)/3)+18;
    cout<<b-a<<endl;
    double dx1=0.5/(b-a);
    t1=2,t2=tiempo/3,t3=t2*2,t4=tiempo-4;
    for(int j=0;j<=max;j++)
        for(int k=0;k<=max;k++)
            Tf[j][k]=285.15;
    for(int k=1;k<tiempo;k++){
        for(int i=1;i<=max;i++){
            for(int j=1;j<=max;j++){
                if(esVarilla(i*dx,j*dy)){
                    T[i][j]=temperatura_varrilla;
                }else{
                    T[i][j]=Tf[i][j]+s*(Tf[i][j+1]-2*Tf[i][j]+Tf[i][j-1])+s*(Tf[i+1][j]-2*Tf[i][j]+Tf[i-1][j]);
                }
            }
        }
        actualizar();
        if(k==t1 || k==t2 || k==t3 || k==t4){
            int aux=0;
            for(int i=a;i<b;i++){
                aux=0;
                for(int j=a;j<b;j++){
                    cout<<dx1*aux<<endl;
                    aux++;
                }
            }
            aux=0;
            for(int i=a;i<b;i++){
                for(int j=a;j<b;j++){
                    cout<<dx1*aux<<endl;
                }
                aux++;
            }
            for(int i=a;i<b;i++){
                for(int j=a;j<b;j++){
                    cout<<T[i][j]<<endl;
                }
            }
        }

    }
    for(int i=a;i<b;i++){
        for(int j=a;j<b;j++){
                cout<<dx*j<<endl;
        }
    }
    for(int i=a;i<b;i++){
        for(int j=a;j<b;j++){
            cout<<dx*i<<endl;
        }
    }
    for(int i=a;i<b;i++){
        for(int j=a;j<b;j++){
            cout<<Tpromedio[i][j]/(tiempo)<<endl;
        }
    }
	return 0;

}
