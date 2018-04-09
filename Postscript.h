
#ifndef HW4B_POSTSCRIPT_H
#define HW4B_POSTSCRIPT_H
class Postscript {
private:
    int r,g,b,rs,gs,bs,rf,gf,bf;
    char name[];
public:
    Postscript(char a[]);
    void line(double x,double y,double x2,double y2);
    void setColor(int r,int g, int b);
    void drawRect(double x,double y,double w,double h);
    void fillRect(double x,double y,double w,double h);
    void setFillColor(int x, int y, int z);
    void setStrokeColor(int x, int y, int z);
    void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
    void fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
    void drawCircle(int x,int y,int radius);
    void text(double x,double y,char[100]);
    void grid(int x1, int interval_x, int x2, int y1, int interval_y, int y2);
};
#endif
