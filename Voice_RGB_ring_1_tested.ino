/*=======================================================

[02/09/2017] 

Control the RGB ring with voice commands!
For example, If you say activate the red light, red light will be be turned ON.
It is done by integrating IFTTT, Google allo and Blynk.



 
 =======================================================*/
/* Include libraries */
#define BLYNK_PRINT Serial                                                            // Defines the object that is used for printing
#include <ESP8266WiFi.h>                                                              // Include library to establish Wi-Fi connection
#include <BlynkSimpleEsp8266.h>                                                       // Include library to use Blynk app functionalities
#include <Adafruit_NeoPixel.h>                                                        // Include the library to work with RGB ring


/* Define pins */
#define PIN 12                                                                        // Define a macro variable for GPIO 12

/* Define global variables & constants */
char auth[] = "03276f2cfdf74756ae79d4e44b68a358";                                     // Variable to store auth token from Blynk 
char ssid[] = " ";                                                                    // Variables to store network credentials
char pass[] = " ";

uint32_t red_colour;                                                                  // Variables for storing the colour values.
uint32_t green_colour;
uint32_t blue_colour;
uint32_t yellow_colour;
uint32_t magenta_colour;
uint32_t cyan_colour;
uint32_t white_colour;
uint32_t off_colour;
int randcolor;                                                                        // Variables for storing random colour number and random delay
long randdelay;

/* Declare instances */
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10, PIN, NEO_GRB + NEO_KHZ800);           // Initialising a Adafruit_Nopixel instance-strip


/* Define functions */   

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

/*Function definition to turn ON the Red colour */


void red()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {                                  // Starting from the first RGB pixel, loop all 10 LEDs to set the colour.
    strip.setPixelColor(i, red_colour );                                              // To set the pixel colour, (Pixel_number, Pixel_colour).
  }
  strip.show();                                                                       // Display the set colours on the pixels.
}

/*Function definition to turn ON the Green colour */
void green()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {                                  // Starting from the first pixel(RGB LED), loop all 10 LEDs to set the colour.
    strip.setPixelColor(i, green_colour );                                            // Set the pixel colour, (Pixel_number, Pixel_colour).
  }
  strip.show();                                                                       // Display the set colours on the pixels.
}

/*Function definition to turn ON the Blue colour */
void blue()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {                                  // Starting from the first pixel(RGB LED), loop all 10 LEDs to set the colour.
    strip.setPixelColor(i, blue_colour );                                             // Set the pixel colour, (Pixel_number, Pixel_colour).
  }
  strip.show();                                                                       // Display the set colours on the pixels.
}
void yellow()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {                                  // Starting from the first pixel(RGB LED), loop all 10 LEDs to set the colour.
    strip.setPixelColor(i, yellow_colour );                                           // Set the pixel colour, (Pixel_number, Pixel_colour).
  }
  strip.show();                                                                       // Display the set colours on the pixels.
}

/* Function to display Yellow colour */
void magenta()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {                                  // Starting from the first pixel(RGB LED), loop all 10 LEDs to set the colour.
    strip.setPixelColor(i, magenta_colour );                                          // Set the pixel colour, (Pixel_number, Pixel_colour).
  }
  strip.show();                                                                       // Display the set colours on the pixels.
}

/* Function to display Cyan colour */
void cyan()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {                                  // Starting from the first pixel(RGB LED), loop all 10 LEDs to set the colour.
    strip.setPixelColor(i, cyan_colour );                                             // Set the pixel colour, (Pixel_number, Pixel_colour).
  }
  strip.show();                                                                       // Display the set colours on the pixels.
}

/* Function to display White colour */
void white()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {                                  // Starting from the first pixel(RGB LED), loop all 10 LEDs to set the colour.
    strip.setPixelColor(i, white_colour );                                            // Set the pixel colour, (Pixel_number, Pixel_colour).
  }
  strip.show();                                                                       // Display the set colours on the pixels.
}

/*Function definition to turn OFF colour */
void off()
{
  for (uint16_t i = 0; i < strip.numPixels(); i++) {                                  // Starting from the first pixel(RGB LED), loop all 10 LEDs to set the colour.
    strip.setPixelColor(i, off_colour );                                              // Set the pixel colour, (Pixel_number, Pixel_colour).
  }
  strip.show();                                                                       // Display the set colours on the pixels.
}

void dissolve()
{
  
    uint16_t i, j;                                                                    // Declare variable for parsing the RGB LEDs.
    for (j = 0; j < 256; j++)                                                         // Loop of generating 256 different colours for a smooth transition.
    {
      for (i = 0; i < 10; i++)                                                        // Loop to set colours to each of the 10 pixels.
      {
        strip.setPixelColor(i, Wheel((i + j) & 255));
      }
      strip.show();                                                                   // Display the set colours on the Pixels.
    }
  
}

/* Function to display Rainbow pattern */
void rainbow()
{
  
    uint16_t i, j;                                                                    // Declare variable for parsing the RGB LEDs.
    for (j = 0; j < 256 * 5; j++)
    {
      for (i = 0; i < strip.numPixels(); i++)                                         // Loop to setup colour for each pixel
      {
        strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
      }
      strip.show();                                                                   // Display the set colours on the Pixels.
      delay(20);

  
   // server.handleClient();                                                            // Check for any incoming requests.
  }
}

/* Function to display Dancing Lights pattern */
void dancingLights()
{
  
    for (int j = 0; j < 256; j++)
    {
      for (int q = 0; q < 3; q++)
      {
        for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {                      
          strip.setPixelColor(i + q, Wheel( (i + j) % 255));                          // Set every third pixel ON.
        }
        strip.show();                                                                 // Display the set colours onthe pixels.
        delay(50);
        for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
          strip.setPixelColor(i + q, 0);                                              // Set every third pixel OFF.
        }
       // server.handleClient();                                                        // Check for any incoming requests.
        
      }
      //server.handleClient();                                                          // Check for any incoming requests.
     
    }
    //server.handleClient();                                                            // Check for any incoming requests.
 
}

/* Function to display Random Colours pattern 
 *  Random Lights turn ON for an interval of 1 second.
 */
void randomColour()
{
  while(1){                                      // Continue displaying random colours until the argument of incoming request changes.
    randcolor = random(0, 7);                                                         // Generate a random number between 0-6 to display a random colour.
    if (randcolor == 0) {                                                             // If generated random number is 0, display Red colour for 1 second.
      red();
      delay(1000);
    }
    else if (randcolor == 1) {                                                        // If generated random number is 1, display Green colour for 1 second.
      green();
      delay(1000);
    }
    else if (randcolor == 2) {                                                        // If generated random number is 2, display Blue colour for 1 second.
      blue();
      delay(1000);
    }
    else if (randcolor == 3) {                                                        // If generated random number is 3, display Magenta colour for 1 second.
      magenta();
      delay(1000);
    }
    else if (randcolor == 4) {                                                        // If generated random number is 4, display Cyan colour for 1 second.
      cyan();
      delay(1000);
    }
    else if (randcolor == 5) {                                                        // If generated random number is 5, display White colour for 1 second.
      white();  
      delay(1000);
    }
    else if (randcolor == 6) {                                                        // If generated random number is 6, display Yellow colour for 1 second.
      yellow();
      delay(1000);
    }
    //server.handleClient();                                                            // Check for any incoming requests for other patterns or colours.
  //server.handleClient();                                                              // Check for any incoming requests for other patterns or colours.
}
}

/* Function to display Party Lights pattern
 *  Display random lights with random ON times.
 */
void party()
{
 while(1){                                           // Continue displaying Party lights pattern until the argument of incoming request changes.
    randcolor = random(0, 7);                                                         // Generate a random number between 0 and 6 to display a random colour.
    randdelay = random(20, 100);                                                      // Generate a random number between 20 and 99 to generate a random turn ON time.
    if (randcolor == 0) {                                                             // If generated random number is 0, display Red colour.
      red();
      delay(randdelay);                                                               // Display the colour for a random time which is generated above.
    }
    else if (randcolor == 1) {                                                        // If generated random number is 1, display Green colour.
      green();
      delay(randdelay);                                                               // Display the colour for a random time which is generated above.
    }
    else if (randcolor == 2) {                                                        // If generated random number is 2, display Blue colour.
      blue();
      delay(randdelay);                                                               // Display the colour for a random time which is generated above.
    }
    else if (randcolor == 3) {                                                        // If generated random number is 3, display Magenta colour.
      magenta();
      delay(randdelay);                                                               // Display the colour for a random time which is generated above.
    }
    else if (randcolor == 4) {                                                        // If generated random number is 4, display Cyan colour.
      cyan();
      delay(randdelay);                                                               // Display the colour for a random time which is generated above.
    }
    else if (randcolor == 5) {                                                        // If generated random number is 5, display White colour.
      white();
      delay(randdelay);                                                               // Display the colour for a random time which is generated above.
    }
    else if (randcolor == 6) {                                                        // If generated random number is 6, display Yellow colour.
      yellow();
      delay(randdelay);                                                               // Display the colour for a random time which is generated above.
    }
    //server.handleClient();                                                            // Check for any incoming requests for other patterns or colours.
 }                                                     // Check for any incoming requests for other patterns or colours.
}



BLYNK_WRITE(V0)                                                                        // Function that is called when device receives an update of virtual Pin value from the server
{   
  int value = param.asInt(); // Get value as integer
  Serial.print("Recieved Value: ");Serial.println(value);                              // get a virtual pin value and store it in a variable as integer

  /* Based on the received value from blynk server, call different functions to turn on different colors */
  if(value==0)
  off();
  
  if(value==1)
  red();
  
  if(value==2)
  green();
  
  if(value==3)
  blue();
  
  if(value==4)
  yellow();
  
  if(value==5)
  magenta();
  
  if(value==6)
  cyan();
  
  if(value==7)
  party();
    
  if(value==8)
  white();
  
  if(value==9)
  rainbow();
  
  if(value==10)
  dancingLights();
  
  if(value==11)
  randomColour();
  
  if(value==12)
  dissolve();
  
}

void setup()
{
  // Debug console
  Serial.begin(115200);                                                               // Initialize the serial library
  strip.begin();                                                                      // Initialize the Adafruit neopixel library
  strip.setBrightness(128);                                                           // Set the brightness of RGB ring

  //strip.Color returns an integer according to a spcific color set in its arguements
  red_colour = strip.Color(255, 0, 0);                                                 // 255,0,0 for Red                                                                                              
  green_colour = strip.Color(0, 255, 0);                                               // 0,255,0 for Green
  blue_colour = strip.Color(0, 0, 255);                                                // 0,0,255 for Blue
  off_colour = strip.Color(0, 0, 0);                                                   // 0,0,0 for no color/To turn OFF
  
  Blynk.begin(auth, ssid, pass);                                                       // Establishes Wi-Fi connection and connection with Blynk server                                             
}

void loop()
{
  Blynk.run();                                                                          // Processes incoming commands and perform housekeeping of Blynk connection
}

