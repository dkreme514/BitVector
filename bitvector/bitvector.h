//
// Created by Donnie on 2/9/2023.
//

#ifndef BITVECTOR_BITVECTOR_H
#define BITVECTOR_BITVECTOR_H
#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;
// **********************************************************
// * Name: BitVector                                        *
// * Date: 2/09/2023                                        *
// *                                                        *
// * Description: Show an array of bits for a given word    *
// *   size. Have an array of bits of a certain word size.  *
// *   I want allocated words of 32 bits, and have the user *
// *   define how many the want.                            *
// * Author: Donald Kremer                                  *
// * Reference: Dr.David A. Gaitros                         *
// **********************************************************
// **********************************************************
// * Global Constants                                       *
// **********************************************************
const size_t DEFAULTSIZE=8;
const size_t MAXWORDSIZE=32;

// **********************************************************
// * Prototypes                                             *
// **********************************************************
class BitVector {
public:
    BitVector();                          // Default Constructor
    explicit BitVector  (size_t i);         // construct a BitVector with specified size
    BitVector  (const BitVector&);        // copy constructor
    ~BitVector ();                        // Destructor
    void Set   (const size_t index);      // make index bit = 1
    void Set   ();                        // make all bits = 1
    void Unsetmultiple(const size_t index); // Unset all bits up to the max number that are multiples
                                            //    of the number passed in; not including the number passed in

    void Unset (const size_t index);      // make index bit = 0
    void Unset ();                        // make all bits = 0
    void Flip  (const size_t index);      // flip index bit (change value of bit)
    void Flip  ();                        // flip all bits
    bool Test  (size_t index) const;      // return index bit value true if it is set
                                          // false otherwise
    void Print (const string x);          // Prints index value
                                          // of the bits turned on.
    BitVector& operator = (const BitVector& a);   // assignment operator  overload
    size_t Size () const;                 // return the number of bits which is 32 times
    //     the number of words.
private:
    int size;                             // Number of words;
    bitset<32> * bvect;                          // Bit Vector dynamically

};
// make a dynamic integer array
// swap in with bitset 32
// essentially just doing bit set stuff
// mask word.set mask for the mask 
#endif //BITVECTOR_BITVECTOR_H
