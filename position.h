#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

class position{
public:
    position(int x, int y);
    int x()const;
    int y()const;
    void deplaceX(int i);
    void deplaceY(int i);
    bool operator==(const position &p)const;
    bool operator!=(const position &p)const;

private:
    int d_x;
    int d_y;

};

#endif // POSITION_H_INCLUDED
