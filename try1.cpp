#include<iostream>
using namespace std;
class point{
  private:
    double x,y;
  public:
    void setval(double X,double Y){x=X,y=Y;}
    double getx(){return x;}
    double gety(){return y;}
};
double area(point p[]){
  double area=0;
  for(int i=0;i<3;i++){
    area+=(p[i].getx()*p[i+1].gety());
    area-=(p[i].gety()*p[i+1].getx());
  }
  return abs(area);

}
int main(){
  point p[3];
  for(int i=0;i<3;i++){
    double x,y;
    cin>>x>>y;
    p[i].setval(x,y);
  }
    cout<<fixed<<area(p)/2;
}
