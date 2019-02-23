#include "factory.h"
/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

/*
 Makes a bike based on the contents of the input stream.
 Throws an exception if the read operation encounters
 an invalid argument.
 */
Bike* BikeFactory::make(istream& in) throw (invalid_argument) {
    
    Bike *b1 = NULL;
  
    
    char bikeType = '?';
    
    in >> bikeType;
    
    if (in) {
        
        in.putback(bikeType);
        
        
        if (bikeType == 'D') {
            
            
            b1 = new Delivery();
            b1->read(in);

            
            
        }
        
        else if (bikeType == 'U') {
            b1 = new Urban();
            b1->read(in);

        }
        
        else {
            invalid_argument ia10("ERROR - encountered invalid input in Bike* BikeFactory::make(istream)");
        }
        
        
        
        
    }
    
    return b1;
}



