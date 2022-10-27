
// 樹莓派 boss
# include <iostream>
# include <wiringPi.h>

using namespace std ;

const int redLED = 1 ;
const int onoff = 4 ;
const int gLED = 5 ;

int main(void) {
  if ( wiringPiSetup () == -1 )
    return 0 ;

  pinMode( redLED , OUTPUT ) ;
  pinMode( onoff , INPUT ) ;
  pinMode( gLED , OUTPUT ) ;
  int loop = 0 ;

  while ( 1 ) {
    if ( digitalRead( onoff ) == 1 ) {
      loop = loop + 1 ;  
    } // if
    
    if ( loop == 1 ) {
      digitalWrite( redLED , 1 ) ;
      digitalWrite( gLED , 0 ) ; 
    } // if
    else if ( loop == 2 ) {
      digitalWrite( redLED , 0 ) ;
      digitalWrite( gLED , 1 ) ;
    } // else if
    else if ( loop == 3 ) {
      digitalWrite( redLED , 0 ) ;
      digitalWrite( gLED , 0 ) ;
      loop = 0 ;
    } // else if

    delay (1000) ;
  } // while

  return 1 ;
} // main

// 樹莓派 mine
# include <iostream>
# include <wiringPi.h>
      
using namespace std ;

const int redLED = 1 ;
const int onoff = 4 ;
const int gLED = 5 ; 
    
int main(void) {
  if ( wiringPiSetup () == -1 )   
    return 0 ;  
    
  pinMode( redLED , OUTPUT ) ;
  pinMode( onoff , INPUT ) ;
  pinMode( gLED , OUTPUT ) ;
  int loop = 1 ;

  while ( 1 ) {
    if ( digitalRead( onoff ) == 1 && loop == 1 ) {
      digitalWrite( redLED , 1 ) ;
      digitalWrite( gLED , 0 ) ;
      delay (1000) ;
      loop = loop + 1 ;
    } // if
    else {
      digitalWrite( redLED , 0 ) ;
      digitalWrite( gLed , 0 ) ;
    } // else
    
    if ( digitalRead( onoff ) == 1 && loop == 2 ) {
      digitalWrite( redLED , 0 ) ;
      digitalWrite( gLED , 1 ) ;
      loop = loop + 1 ;
      delay (1000) ;
    } // if
    else {
      digitalWrite( redLED , 0 ) ;
      digitalWrite( gLed , 0 ) ;
    } // else

    if ( digitalRead( onoff ) == 1 && loop == 3 ) {
      digitalWrite( redLED , 0 ) ;
      digitalWrite( gLED , 0 ) ;
      delay (1000) ;
      loop = 1 ;
    } // if

  } // while

  return 1 ;
} // main

