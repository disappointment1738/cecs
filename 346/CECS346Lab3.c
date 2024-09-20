// CECS346 Lab 3: FSM
// Team members:?
// Lab description:?

// Hardware Design
// 1)	Port E will be used to control 4 LEDs: white(PE3), red (PE2), yellow (PE1), green (PE0).
// 2)	Port A will be used for the two switches: sw1 (PA2), sw2 (PA3)

#include <stdint.h>   // for data type alias


// Registers for switches
// Complete the following register definitions
//#define SENSOR									  // bit addresses for the two switches/Sensors: bits 2&3
//#define GPIO_PORTA_DATA_R       
//#define GPIO_PORTA_DIR_R        
//#define GPIO_PORTA_AFSEL_R      
//#define GPIO_PORTA_DEN_R        
//#define GPIO_PORTA_AMSEL_R      
//#define GPIO_PORTA_PCTL_R       
//#define GPIO_PORTA_PDR_R        

//// Registers for LEDs
//#define LIGHT                   // bit addresses for the four LEDs
//#define GPIO_PORTE_DIR_R        
//#define GPIO_PORTE_AFSEL_R      
//#define GPIO_PORTE_DEN_R        
//#define GPIO_PORTE_AMSEL_R      
//#define GPIO_PORTE_PCTL_R       
//#define SYSCTL_RCGC2_R          
	
// Constants definitions
//#define SYSCTL_RCGC2_GPIOE        // port E Clock Gating Control
//#define SYSCTL_RCGC2_GPIOA        // port A Clock Gating Control
#define HALF_SEC  (0)   							// TODO: define the constant for generating 0.5 second delay

void Delay(uint8_t n);
void Light_Init(void);
void Sensor_Init(void);

// FSM state data structure
struct State {
  uint8_t Out; 
  uint8_t Time;  
  uint8_t Next[4];
}; 

typedef const struct State STyp;

// Constants definitions
//enum my_states {};

// Output pins are:3(white), 2(red), 1(yellow), 0(green)
// Input pins are: 1:sw2, 0:sw1 
// STyp FSM[]={
//             };    

int main(void){ 
  uint8_t S;  // index to the current state 
  uint8_t Input; 
	
	Light_Init();
	Sensor_Init();
//  S = ?;                     // FSM start with green  
    
  while(1){
		// Put your FSM engine here
  }
}

void Delay(uint8_t n){
	volatile uint32_t time;
	
  time = n*HALF_SEC;  // 0.5sec
  while(time){
		time--;
  }
}

void Sensor_Init(void){
//	SYSCTL_RCGC2_R |=       // Activate Port A clocks
//	while (?){} // wait for clock to be active
//		
//	GPIO_PORTA_AMSEL_R  // Disable analog function on PA3-2
//  GPIO_PORTA_PCTL_R  // Enable regular GPIO
//  GPIO_PORTA_DIR_R     // Inputs on PA3-2
//  GPIO_PORTA_AFSEL_R  // Regular function on PA3-2
//  GPIO_PORTA_DEN_R     // Enable digital signals on PA3-2
	//	GPIO_PORTA_PDR_R     // Optional: Enable pull-down resistors for PA3-2
}

void Light_Init(void){
//	SYSCTL_RCGC2_R |=       // Activate Port E clocks
//	while (?){} // wait for clock to be active
//		
//  GPIO_PORTE_AMSEL_R  // Disable analog function on PE3-0
//  GPIO_PORTE_PCTL_R  // Enable regular GPIO
//  GPIO_PORTE_DIR_R     // Outputs on PE3-0
//  GPIO_PORTE_AFSEL_R  // Regular function on PE3-0
//  GPIO_PORTE_DEN_R     // Enable digital on PE3-0
}
