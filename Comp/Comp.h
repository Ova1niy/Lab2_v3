//
// Created by Ova1niy on 05/05/2020.
//

#ifndef LAB2_COMP_H
#define LAB2_COMP_H

#include <iostream>

using namespace std;

class Comp {
private:
    float re;
    float im;
public:
    Comp(){
        re = 0;
        im = 0;
    }
    Comp(float r){
        re = r;
        im = 0;
    }
    Comp(float r, float i){
        re = r;
        im = i;
    }
    Comp(Comp const &c){
        re = c.re;
        im = c.im;
    }
    //унарный +
    friend const Comp& operator+(const Comp& c){
        return c;
    }
    //унарный -
    friend const Comp& operator-(const Comp& c){
        return Comp(-c.re, -c.im);
    }
    //префиксный инкремент
    friend const Comp& operator++(Comp& c){
        ++c.re;
        return c;
    }
    //постфиксный инкремент
    friend Comp operator++(Comp& c, int){
        Comp Old = Comp(c);
        ++c.re;
        return Old;
    }
    //префиксный декремент
    friend const Comp& operator--(Comp& c){
        --c.re;
        return c;
    }
    //постфиксный декремент
    friend Comp operator--(Comp& c, int){
        Comp Old(c);
        --c.re;
        return Old;
    }
    friend Comp operator+(const Comp& left, const Comp& right){
        return Comp(left.re + right.re, left.im + right.im);
    }
    friend Comp& operator+=(Comp& left, const Comp& right){
        left.re += right.re;
        left.im += right.im;
        return left;
    }
    friend Comp operator-(const Comp& left, const Comp& right){
        return Comp(left.re - right.re, left.im - right.im);
    }
    friend Comp& operator-=(Comp& left, const Comp& right){
        left.re -= right.re;
        left.im -= right.im;
        return left;
    }
    friend Comp operator*(const Comp& left, const Comp& right){
        return Comp(left.re*right.re - left.im*right.im, left.re*right.im +left.im*right.re);
    }
    friend Comp& operator*=(Comp& left, const Comp& right){
        left.re = left.re*right.re - left.im*right.im;
        left.im = left.re*right.im +left.im*right.re;
        return left;
    }
    friend Comp operator/(const Comp& left, const Comp& right){
        return Comp((left.re*right.re + left.im*right.im)/(right.re*right.re + right.im*right.im), (left.im*right.re - left.re*right.im)/(right.re*right.re + right.im*right.im));
    }
    friend Comp& operator/=(Comp& left, const Comp& right){
        left.re = (left.re*right.re + left.im*right.im)/(right.re*right.re + right.im*right.im);
        left.im = (left.im*right.re - left.re*right.im)/(right.re*right.re + right.im*right.im);
        return left;
    }
    friend bool operator==(const Comp& left, const Comp& right){
        return (left.re == right.re && left.im == right.im);
    }
    Comp& operator=(const Comp& right) {
        //проверка на самоприсваивание
        if (this == &right) {
            return *this;
        }
        re = right.re;
        im = right.im;
        return *this;
    }
    Comp& operator=(const float& right) {
        re = right;
        im = 0;
        return *this;
    }
    const float operator[] (int index) const{
        if (index < 0 || index > 1) {
            throw "IndexOutOfRange";
        }
        if (index == 0){
            return re;
        } else {
            return im;
        }
    }
};

ostream& operator<<(ostream &os, const Comp& c) {
    return os  << c[0] << "+" << c[1] << "i";
}


#endif //LAB2_COMP_H
