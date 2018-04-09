#include<iostream>
#include<fstream>
#include"Postscript.h"
using namespace std;

Postscript::Postscript(char a[]) {
    int b=(sizeof a)/(sizeof(char));
    for(int i=0;i<b;i++){
        name[i]=a[i];
    }
    ofstream fs;
    fs.open(name);
    fs<<"%BoudingBox: 0 0 800 800"<<endl;
    fs.close();
}

void Postscript::setColor(int m,int n, int i) {
    r=m;
    g=n;
    b=i;
}

void Postscript::line(double x,double y,double x2,double y2){
    fstream fs;
    fs.open(name,ios::app);
    fs<<x<<' '<<y<<" moveto"<<endl
      <<x2<<' '<<y2<<" lineto"<<endl
      <<"stroke"<<endl;
    fs.close();
}

void Postscript::drawRect(double x,double y,double w,double h){
    fstream fs;
    fs.open(name,ios::app);
    fs<<x<<' '<<y<<" moveto "<<x+w<<' '<<y<<" lineto "<<x+w<<' '<<y+h<<" lineto "<<x<<' '<<y+h
      <<" lineto closepath "<<endl
      <<0<<' '<<0<<' '<<0<<" setrgbcolor 4 setlinewidth stroke"<<endl;
    fs.close();
}
void Postscript::fillRect(double x,double y,double w,double h) {
    fstream fs;
    fs.open(name,ios::app);
    fs<<x<<' '<<y<<" moveto "<<x+w<<' '<<y<<" lineto "<<x+w<<' '<<y+h<<" lineto "<<x<<' '<<y+h
      <<" lineto closepath "<<endl
      <<r<<' '<<g<<' '<<b<<" setrgbcolor fill"<<endl;
    fs.close();
}
void Postscript::text(double x,double y,char a[100]) {
    fstream fs;
    fs.open(name,ios::app);
    fs<<"/Courier 20 selectfont "<<x<<' '<<y<<" moveto ("<<a<<") show"<<endl;
    fs.close();
}

