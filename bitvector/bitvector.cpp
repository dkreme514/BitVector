/*
#include <iostream>
#include <bitset>
#include <iomanip>
#include "bitvector.h"
using namespace std;
BitVector::BitVector(size_t s)
{
    size = s/32;
    if (size % 32 != 0) { size++; }
    bvect = new bitset<32> [size];
    Unset();
}
BitVector::BitVector()
{
    size =8;
    bvect= new bitset<32> [size];
    Unset();
}
// **********************************************************
// * Destructor                                             *
// **********************************************************
BitVector::~BitVector()
{
    delete [] bvect;
}
// **********************************************************
// * Unset one bit                                          *
// **********************************************************
BitVector & BitVector::operator = (const BitVector& a)
{
    bvect = new bitset<32> [size];
    for (int index=0; index<size*32;index++)
        bvect[index]= index;
    return * this;
}
// **********************************************************
// * Set all bits equal to 0                              *
// **********************************************************
void BitVector::Unset()
{
    for(size_t index=0; index<size*32;index++)
        bvect[index].reset();
}

// **********************************************************
// * Unset multiple bits                                    *
// **********************************************************
void BitVector::Unsetmultiple(const size_t index) {
    for (size_t i=0; i<size*32;i++)
    {
        if (i%index==0 && i!=index)
            bvect[1/32].reset(1%32);
    }
}
// **********************************************************
// * Unset index bit                                        *
// **********************************************************

void BitVector::Unset(const size_t index)
{
    size_t word;
    size_t offset;
    size_t mask=1;

    word = index/32;
    offset = index%32;
    offset = 31 - offset;
    bvect[word].reset(offset);
}

// **********************************************************
// * Set all bits equal to 1                                *
// **********************************************************
void BitVector::Set(const size_t index)
{
    size_t word;
    size_t offset;
    size_t mask=1;

    word = index/32;
    offset = index%32;
    offset = 31 - offset;
    bvect[word].set(offset);
}
// **********************************************************
// * Set all bits equal to 1                                *
// **********************************************************
void BitVector::Set() {
    size_t sizeofit;
    sizeofit = bvect[size].size();
    for (size_t index=0; index<sizeofit;index++)
        bvect[index].set();
}
// **********************************************************
// * Flip                                *
// **********************************************************
void BitVector::Flip() {
    size_t sizeofit = bvect[size].size();
    for (int index=0; index<sizeofit;index++) {
        bvect[index].flip();
    }

}
// **********************************************************
// * Flip value of Index bit                                *
// **********************************************************
void BitVector::Flip  (const size_t index) {
    size_t word;
    size_t offset;
    size_t mask = 1;

    word = index / 32;
    offset = index % 32;
    offset = 31 - offset;

    bvect[word].flip(offset);


}
// **********************************************************
// * Test one bit                                           *
// **********************************************************
bool BitVector::Test(size_t index) const
{

    size_t word;
    size_t offset;
    size_t mask=1;

    word = index/32;
    offset = index%32;
    mask = 31 - offset;

    if (bvect[word].test(mask)==1) return true;
    else return false;


}

void BitVector::Print(const string x)
{
    cout << x << endl;

    for (size_t i = 0; i < size * 32; i++)
    {

        if (Test(i)) cout << "Bit index " << i << " is true" << endl;
        else cout << "Bit index " << i << " is false" << endl;
    }

    return;
}
size_t BitVector::Size () const
{
    return size+1;
}


*/
// Created by Donnie on 2/9/2023.
//
#include <iostream>
#include <bitset>
#include <iomanip>
#include "bitvector.h"
using namespace std;
BitVector::BitVector(size_t s)
{
    // size_t%32 if not
    size = s/32;
    if (size%32!=0) size++;
    bvect = new bitset<32> [size];

}
BitVector::BitVector()
{
    size =8;
    bvect= new bitset<32> [size];
    Unset();
}
// **********************************************************
// * Destructor                                             *
// **********************************************************
BitVector::~BitVector()
{
    delete [] bvect;
}
// **********************************************************
// * Unset one bit                                          *
// **********************************************************
BitVector & BitVector::operator = (const BitVector& a)
{
    bvect = new bitset<32> [size];
    for (int index=0; index<size*32;index++)
        bvect[index]= index;
    return * this;
}
// **********************************************************
// * Set all bits equal to 0                              *
// **********************************************************
void BitVector::Unset()
{
    for(size_t index=0; index<size*32;index++)
       // if (Test(index) Flip(index);
        bvect[index]=0;
}
// **********************************************************
// * Unset multiple bits                                    *
// **********************************************************
void BitVector::Unsetmultiple(const size_t index) {
    for (size_t i=0; i<size*32;i++)
    {
        if (i%index==0 && i!=index)
            bvect[1/32].reset(1%32);
    }
}
// **********************************************************
// * Unset index bit                                        *
// **********************************************************

void BitVector::Unset(const size_t index)
{
    size_t word;
    size_t offset;
    size_t mask=1;

    word = index/32;
    offset = index%32;
    offset = 31 - offset;
    if (Test(index)) Flip(index);

    mask = mask << offset;
   // if (bvect[word] !=0) bvect[word].flip();
}

// **********************************************************
// * Set all bits equal to 1                                *
// **********************************************************
void BitVector::Set(const size_t index)
{
    //flip(index);
    size_t word;
    size_t offset;
    size_t mask=1;

    word = index/32;
    offset = index%32;
    offset = 31 - offset;
    mask = mask << offset;

    word=word+offset;
    bvect[word]=1;

   // if (bvect[index] == 0) Flip(index);
   // bvect[index] = bvect[index] | mask;

}
// **********************************************************
// * Set all bits equal to 1                                *
// **********************************************************
void BitVector::Set() {
    size_t sizeofit = sizeof(bvect)/sizeof(bvect[0]);
    for (int index=0; index<sizeofit;index++)
        Set(index);
}
// **********************************************************
// * Flip                                *
// **********************************************************
void BitVector::Flip() {
    size_t sizeofit = sizeof(bvect)/sizeof(bvect[0]);
    for (int index=0; index<sizeofit;index++) {
        bvect[index].flip();
    }

}
// **********************************************************
// * Flip value of Index bit                                *
// **********************************************************
void BitVector::Flip  (const size_t index)
{
    size_t word;
    size_t offset;
    size_t mask=1;

    word = index/32;
    offset = index%32;
    offset = 31 - offset;
    mask = mask << offset;
    bvect[word].flip(mask);


}
// **********************************************************
// * Test one bit                                           *
// **********************************************************
bool BitVector::Test(size_t index) const
{

    size_t word;
    size_t offset;
    size_t mask=1;

    word = index/32;
    offset = index%32;
    offset = 31 - offset;
    // mask = mask << offset;

    cout << mask << endl;

    word=word+offset;
 //***************************************
 //   if (bvect[word]!=0) return true;
  //  else return false;
//**************** maybe this? **************************
    // for loop
 //   mask = bvect[word].test(mask);
    if (bvect[word].test(mask)==1) return true;
    else return false;
//******************************************
    //if (bvect[word] & mask) return true;
   // else return false;

}
void BitVector::Print(const string x)
{
    cout << x << endl;
   // size_t sizeofit = sizeof(bvect)/sizeof(bvect[0]);

       for (size_t i = 0; i < size * 32; i++)
       {

           if (Test(i)) cout << "Bit index " << i << " is true" << endl;
           else cout << "Bit index " << i << " is false" << endl;
       }

        /*
    {
        y++;
        for (int i = 0; i < 32; i++)
        {
            j++;
            //  bvect[word].test(i);
            if (bvect[y-1].test(j))
                cout << "Bit index " << j << " is true" << endl;
            else
                cout << "Bit index " << j << " is false" << endl;

        }// lkmnfdsidfvhp0fihds9if piwejfkjfid uns9f9ojjfijmdcvoput coufr fn<< iof iffboiuOUC fifhejwfnjnfnoienif
    }
         */

    return;
}
size_t BitVector::Size () const
{
    return size*32;
}
