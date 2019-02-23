#include "bikes.h"
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
 */

/*
 Default class constructor.
 */
Bikes::Bikes() {
    
    
}
/*
 Computes and returns the total number
 of gears of the bikes stored in the vector.
 */
int Bikes::getTotalGears() const {
    
    int totalGears = 0;
    
    for (int i = 0; i < bikes.size(); i++) {
        
        totalGears += bikes.at(i)->getGears();
        
    }
    
    
    return totalGears;
}

/*
 Computes and returns the total
 capacity of the bikes stored in the vector.
 */
int Bikes::getTotalCapacity() const {
    
    int totalCapacity = 0;
    int dBikeCount = 0;
    Delivery *dBikeptr = NULL;
    
    for (int i = 0; i < bikes.size(); i++) {
        
        if  (bikes.at(i)->getID()[0] == 'D') {
        
        dBikeptr = dynamic_cast<Delivery*>(bikes.at(i));
        
        dBikeCount++;
            totalCapacity += dBikeptr->getCapacity();
            
        }
        
    }
    
    return totalCapacity;
        
    
}

/*
 Prints to the ostream out this object's bikes.
 The ostream defaults to cout.
 */
void Bikes::print(ostream& out) const {
    
    Delivery *dBikeptr = NULL;
    Urban *uBikeptr = NULL;
    
    for (int i = 0; i < bikes.size(); i++) {
        
        dBikeptr = dynamic_cast<Delivery*>(bikes.at(i));
        
        if (dBikeptr) {
            
            dBikeptr->print(out);
        }
        
        uBikeptr = dynamic_cast<Urban*>(bikes.at(i));
        
        if (uBikeptr) {
            
            uBikeptr->print(out);
            
        }
        
        
        
    }
    
    
    
}
/*
 Uses the BikeFactory to read and make Bike objects from the file named filename,
 storing them the bikes vector. Throws an exception if the file does open successfully.
 Throws an exception if the read operation encounters an invalid argument.
 */
void Bikes::read(string filename) throw (logic_error, invalid_argument) {
    
    logic_error le1("ERROR - file failed to open in "
    "Bikes::read(string)\n"+ filename);
    invalid_argument ia1("ERROR - read operation encountered "
     "invalid input in Bikes::read(string)\n" + filename);
    
    ifstream inFile;
    
    inFile.open(filename.c_str());
    
    if (!inFile) {
        
        throw le1;
        
    }
    
    Bike * b1 = BikeFactory::make(inFile);
    
    while (inFile.good()) {

            bikes.push_back(b1);
        
        b1 = BikeFactory::make(inFile);
        
    }
    
    
    
    

    
}


/*
 Returns the number of bikes.
 */
unsigned Bikes::size() const {
    
    return static_cast<unsigned int>(bikes.size());
    
}

//Class destructor.
Bikes::~Bikes() {
    
    
    
}










