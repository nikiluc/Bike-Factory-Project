#include "bike.h"
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
 Default constructor.
 */
Bike::Bike():gears(1) {
    
    
}

/*
 Explicit class constructor initializing a
 bike object using the arguments id, name, and
 number of gears.
 */
Bike::Bike(string id, string name, int gears) throw (invalid_argument) {
    
    
    setID(id);
    setName(name);
    setGears(gears);
    
    
}
/*
 Sets this bike's ID, which must have the format [A-Z][0-9][0-9].
 Throws and exception if argument is invalid
 */
void Bike::setID(string id) throw (invalid_argument){
    
    invalid_argument ia0("ERROR - encountered invalid input in Bike::setID(string):"
                         "The ID is not 3 characters.");
    
    invalid_argument ia1("ERROR - encountered invalid input in Bike::setID(string):"
                         "The ID does not start with 'D' or 'U'.");
    
    invalid_argument ia3("ERROR - encountered invalid input in Bike::setID(string):"
                         "Second character of ID is a letter.");
    
    invalid_argument ia4("ERROR - encountered invalid input in Bike::setID(string):"
                         "Third character of ID is a letter.");
    
    invalid_argument ia2("ERROR - Bike::setID(string)\n: ID is not 3 digits.");
    
    
    
    char firstChar = id[0];
    char secondChar = id[1];
    char thirdChar = id[2];
    
    if (id.size() != 3) {
        
        throw ia0;
    }
    
    
    if (firstChar !=  'D' && firstChar !=  'U') {
        
        cout << "First" << endl;
        
        cout << firstChar << endl;
        
        throw ia1;
    }
    
    else if (isalpha(secondChar)) {
        
        throw ia3;
    }
    
    else if (isalpha(thirdChar)) {
        
        throw ia4;
    }
    
    
    else {
        
        this->id = id;
        
    }
}

/*
 Sets this bike's name.
 */
void Bike::setName(string name) {
    
    this->name = name;
}

/*
 Sets this bike's gears, which must be in {1, ..., 24}.
 Throws invalid argument if outside of allowed range.
 */
void Bike::setGears(int gears) throw (invalid_argument) {
    
    invalid_argument ia2("ERROR - encountered invalid input in Bike::setGears(int)\n");
    
    if (gears < 1 || gears > 24) {
        
        throw ia2;
        
    }
    
    
    this->gears = gears;
    
}

/*
 Returns this bike's ID.
 */
string Bike::getID() const {
    
    return id;
    
}

/*
 Returns this bike's Name.
 */
string Bike::getName() const {
    
    return name;
    
}

 /*
 Returns this bike's number of gears.
 */
int Bike::getGears() const {
    
    return gears;
    
}
/*
 Prints this bike's name and gears to the ostream out,
 which defaults to cout.
 */
void Bike::print( ostream& out) const {
    
    out << id << " " <<  name  << " " << gears << endl;
}

/*
 Reads this bike's id, name, and gears from the istream argument,
 storing them in the respective data members.
 */
void Bike::read( istream& in ) throw ( invalid_argument ) {
    
    string i, n;
    
    int g;
    
    in >> i;
    
    char quote = '?';
    char oneChar = '?';
    
    n = "";
    
    in >> quote;
    oneChar = in.get();
    
    while (oneChar != '"') {
        n+=oneChar;
        oneChar = in.get();
        
    }
    
    in >> g;
    
    
    setID(i);
    setName(n);
    setGears(g);
    
    
    
    
}
/*
 Destructor. Does nothing but is recommended for classes with virtual methods.
 */
Bike::~Bike() {
    
    
}
