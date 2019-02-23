#include "delivery.h"


/*
 Default constructor.
 */
Delivery::Delivery() {
    
    capacity = 1;
    
}

/*
 Explicit class constructor initializing a
 Delivery object using the arguments
 id, name, gears, and capacity.
 */
Delivery::Delivery(string dId, string dName, int dGears, int dCapacity)
throw (invalid_argument) : Bike(dId, dName, dGears) {
    
    setID(dId);
    setCapacity(dCapacity);
    
    
}

/*
 Sets this delivery bike's ID, which must have the format D[0-9][0-9].
 Throws invalid argument if the format is incorrect.
 */
void Delivery::setID(string dId) throw (invalid_argument) {
    
    invalid_argument ia3("ERROR - encountered invalid input in Delivery::setID(string):"
                         " First character is not 'D'.");
    invalid_argument ia6("ERROR - encountered invalid input in Delivery::setID(string):"
                         " ID is less than 3 characters.");
    invalid_argument ia8("ERROR - encountered invalid input (second character) in Delivery::setID(string)");
    invalid_argument ia9("ERROR - encountered invalid input (third character) in Delivery::setID(string)");
    
    
    if (dId.size() != 3) {
        
        throw ia6;
    }
    
    char letter = dId[0];
    
    
    if (letter != 'D') {
        
        throw ia3;
        
    }
    
    else if (isalpha(dId[1])) {
        
        throw ia8;
        
    }
    
    else if (isalpha(dId[2])) {
        throw ia9;
    }
    
    id = dId;
    
}

/*
 Sets this bike's capacity, which must be in {1, ..., 120}.
 Throws an exception if the capacity is outside of this range
 */
void Delivery::setCapacity(int dCapacity) throw (invalid_argument) {
    
    invalid_argument ia4("ERROR - encountered invalid input in Delivery::setCapapcity(int)");
    
    if (dCapacity > 120) {
        
        throw ia4;
        
    }
    
    else if (dCapacity < 1) {
        
        throw ia4;
    }
    
    capacity = dCapacity;
    
}

/*
 Returns this bike's capacity.
 */
int Delivery::getCapacity() const {
    
    return capacity;
}

/*
 Prints this delivery bike to the ostream out, which defaults to cout.
 */
void Delivery::print(ostream& out) const {
    
    
    out << id << " " << name  << " " << gears << " " << capacity << endl;
    
}


/*
 Reads information for a delivery bike from the istream argument,
 storing the information in the respective data members.
 Throws an exception if invalid argument
 */
void Delivery::read(istream &in) throw ( invalid_argument ) {
    
    int c;
    
    
    Bike::read(in);
    
    in >> c;
    
    setCapacity(c);
    
    
}
