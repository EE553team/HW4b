#include<iostream>
#include<fstream>
#include"Postscript.h"
using namespace std;
class Postscript {
private:
    int r,g,b,rs,gs,bs,rf,gf,bf;
    char name[];
public:
    Postscript(char a[]) {
        int b=(sizeof a)/(sizeof(char));
        for(int i=0;i<b;i++){
            name[i]=a[i];
        }
        ofstream fs;
        fs.open(name);
        fs<<"%BoudingBox: 0 0 800 800"<<endl;
        fs.close();
    }
    void setColor(int m,int n, int i) {
        r=m;
        g=n;
        b=i;
    }
    void line(double x,double y,double x2,double y2){
        fstream fs;
        fs.open(name,ios::app);
        fs<<x<<' '<<y<<" moveto"<<endl
          <<x2<<' '<<y2<<" lineto"<<endl
          <<"stroke"<<endl;
        fs.close();
    }
    void drawRect(double x,double y,double w,double h){
        fstream fs;
        fs.open(name,ios::app);
        fs<<x<<' '<<y<<" moveto "<<x+w<<' '<<y<<" lineto "<<x+w<<' '<<y+h<<" lineto "<<x<<' '<<y+h
          <<" lineto closepath "<<endl
          <<0<<' '<<0<<' '<<0<<" setrgbcolor 4 setlinewidth stroke"<<endl;
        fs.close();
    }
    void fillRect(double x,double y,double w,double h) {
        fstream fs;
        fs.open(name,ios::app);
        fs<<x<<' '<<y<<" moveto "<<x+w<<' '<<y<<" lineto "<<x+w<<' '<<y+h<<" lineto "<<x<<' '<<y+h
          <<" lineto closepath "<<endl
          <<r<<' '<<g<<' '<<b<<" setrgbcolor fill"<<endl;
        fs.close();
    }
    void text(double x,double y,char a[100]) {
        fstream fs;
        fs.open(name,ios::app);
        fs<<"/Courier 20 selectfont "<<x<<' '<<y<<" moveto ("<<a<<") show"<<endl;
        fs.close();
};
int main() {
    Postscript p("test.ps");
    p.line(0,0, 300,400);  // 0 0 moveto 300 400 lineto stroke
    int r = 255, g = 0, b = 0;
    p.setColor(r,g,b);
    double x=100,y=100,w=100,h=100,x1=200,y1=200,x2=300,y2=200,x3=250,y3=300;
    p.drawRect(x, y, w, h);   // x y moveto x+w y lineto x+w y+h lineto ... closepath stroke
    p.fillRect(x, y, w, h);   // x y moveto x+w y lineto x+w y+h lineto ... closepath fill
    p.setFillColor( 50, 50, 0); // 1.0 0.5 0 setrgbcolor
    // optional, figure out how you want to manage color
    p.setStrokeColor( 0, 50, 50);
    p.drawTriangle(x1,y1, x2,y2, x3,y3);
    p.fillTriangle(x1,y1, x2,y2, x3,y3);
    p.drawCircle(x,y,r); // x y 0 360 r arc stroke
    p.text(x,y, "testing testing 123"); // look it up  setfont  (ABC) show
    p.grid(300, 50, 500, 400, 50, 700);
}