#include<iostream>
#include<fstream>
#include"Postscript.h"
using namespace std;
void Postscript::setFillColor(int x, int y, int z){
    rf=x;
    gf=y;
    bf=z;

}

void Postscript::setStrokeColor(int x, int y, int z){
    rs=x;
    gs=y;
    bs=z;
}


void Postscript::drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
    ofstream fs;
    fs.open(name,ios::app);
    fs<<x1<<' '<<y1<<' '<<"moveto"<<'\n'<<x2<<' '<<y2
      <<' '<<"lineto"<<'\n'<<x3<<' '<<y3<<' '<<"lineto"<<'\n'
      <<x1<<' '<<y1<<' '<<"lineto"<< '\n'<<"closepath"<<
      '\n'<<rs<<' '<<gs<<' '<<bs<<' '<< "setrgbcolor"<<'\n'<<
      "4 setlinewidth"<<'\n'<<"stroke"<<'\n';
    fs.close();
}

void Postscript::fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
    ofstream fs;
    fs.open(name,ios::app);
    fs<<x1<<' '<<y1<<' '<<"moveto"<<'\n'<<x2<<' '<<y2
      <<' '<<"lineto"<<'\n'<<x3<<' '<<y3<<' '<<"lineto"<<'\n'
      <<x1<<' '<<y1<<' '<<"lineto"<< '\n'<<"closepath"<<
      '\n'<<rf<<' '<<gf<<' '<<bf<<" setrgbcolor"<<'\n'<<"fill"<<'\n';
    fs.close();
}

void Postscript::drawCircle(int x,int y,int radius){
    ofstream fs;
    fs.open(name,ios::app);
    fs<<x<<' '<<y<<' '<<radius<<' '<<0<<' '<<360<<' '<<"arc"<< '\n' <<
      rs<<' '<<gs<<' '<<bs<<' '<< "setrgbcolor"<<'\n'<<
      "4 setlinewidth"<<'\n'<<"stroke"<<'\n';
    fs.close();
}


void Postscript::grid(int x1, int interval_x, int x2, int y1, int interval_y, int y2){
    ofstream fs;
    fs.open(name,ios::app);
    int bins_x = ((x2 - x1) / interval_x);
    int bins_y = ((y2 - y1) / interval_y);
    fs<<"/vline"<<' '<<"{"<<x1<<' '<<y1<<' '<<"moveto"<<' '<<x1<<' '<<y2<<' '<<"lineto"<<' '<<"stroke}"<<' '<<"def"<<'\n'<<
      "gsave"<< '\n'<<"vline"<<'\n'<<bins_x<<' '<<"{"<<interval_x<<' '<<0<<' '<<"translate vline}"<<' '<<"repeat"<<'\n'<<"grestore"<<'\n'<<
      "/hline"<<' '<<"{"<<x1<<' '<<y1<<' '<<"moveto"<<' '<<x2<<' '<<y1<<' '<<"lineto stroke}"<<' '<<"def"<<'\n'<<
      "gsave"<<'\n'<<"hline"<<'\n'<<bins_y<<' '<<"{0"<<' '<<interval_y<<' '<<"translate hline}"<<' '<<"repeat"<<'\n'<<
      "grestore"<<'\n';
    fs.close();
}