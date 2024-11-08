#ifndef MYPAIR_H
#define MYPAIR_H

template <typename fst, typename, sed> class MyPair {
public:
    fst getFirst() const;
    void setFirst(fst, firstVal);
    sed getSecond() const;
    void setSecond(sed sedVal);
private:
    fst first;
    sed second;

};

template < typename fst, typename sed>
            MyPair<fst, sed>::getFirst() const{
    return first;
}

template < typename fst, typename sed>
MyPair<fst, sed>::getSecond() const{
    return scond;
}






#endif // MYPAIR_H
