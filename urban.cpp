#include "urban.h"

/*
 Default constructor.
 */
Urban::Urban() : Bike() {
    
    
}

/*
 Explicit class constructor that initializes
 this bike object with the arguments id, name, and gears.
 */
Urban::Urban(string uId, string uName, int uGears)
throw (invalid_argument): Bike(uId, uName, uGears) {
    
    setID(uId);
    
    
}
/*
 Sets this urban bike's ID, which must have the format U[0-9][0-9].
 Throws exception if argument doesn't match format.
 */
void Urban::setID(string uId) throw (invalid_argument) {
    invalid_argument ia5("ERROR - encountered invalid input in "
                         "Urban::setID(string): First character is not U");
    invalid_argument ia7("ERROR - encountered invalid input in"
                         " Urban::setID(string):"
                         " ID is not than 3 charcters.");
    invalid_argument ia8("ERROR - encountered invalid input "
                         "(second character) in Urban::setID(string)");
    invalid_argument ia9("ERROR - encountered invalid input "
                         "(third character) in Urban::setID(string)");
    
    if (uId.size() != 3) {
        
        throw ia7;
    }
    
    char letter = uId[0];
    
    
    if (letter != 'U') {
        
        
        throw ia5;
        
    }
    
    else if (isalpha(uId[1])) {
        
        throw ia8;
        
        
    }
    
    else if (isalpha(uId[2])) {
        throw ia9;
    }
    
    
    
    
    id = uId;
}
/*
 Prints this urban bike to the ostream out, which defaults to cout.
 */
void Urban::print(ostream& out) const {
    
    Bike::print(out);
    
}
/*
 Reads information for an urban bike from the
 istream argument, storing the information in
 the respective data members.
 Throws exception if invalid argument.
 */
void Urban::read(istream& in) throw (invalid_argument) {
    
    
    Bike::read(in);
    
    
}

