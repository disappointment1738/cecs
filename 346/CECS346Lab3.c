// CECS346 Lab 3: FSM
// group 2
// Team members: Stephanie Lee, Kayla Watt, & Daniel Espinosa
// Lab description: ?

// Hardware Design
// 1)	Port E will be used to control 4 LEDs: white(PE3), red (PE2), yellow (PE1), green (PE0).
// 2)	Port A will be used for the two switches: sw1 (PA2), sw2 (PA3)

#include <stdint.h>   // for data type alias


// Registers for switches
// Complete the following register definitions
#define SENSOR									(*((volatile unsigned long *)0x40004018))  // bit addresses for the two switches/Sensors: bits 2&3
#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_R        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))
#define GPIO_PORTA_PDR_R        (*((volatile unsigned long *)0x40004514))

//// Registers for LEDs
#define LIGHT                   (*((volatile unsigned long *)0x4002403C))  // bit addresses for the four LEDs
#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
	
// Constants definitions
#define SYSCTL_RCGC2_GPIOE      0x00000010  // port E Clock Gating Control
#define SYSCTL_RCGC2_GPIOA      0x00000001  // port A Clock Gating Control
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
enum my_states {goN, waitN, goE, waitE};

// Output pins are:3(white), 2(red), 1(yellow), 0(green)
// Input pins are: 1:sw2, 0:sw1 
STyp FSM[4]={ //CHANGE OUTPUT
  {0x21,2,{goN,waitN,goN,waitN}},
  {0x22, 1,{goE,goE,goE,goE}},
  {0x0C,2,{goE,goE,waitE,waitE}},
  {0x14, 1,{goN,goN,goN,goN}}
};    

int main(void){ 
  uint8_t S;  // index to the current state 
  uint8_t Input; 
	
	Light_Init();
	Sensor_Init();
  S = goN;                     // FSM start with green  
    
  while(1){
		LIGHT = FSM[S].Out; // set traffic lights
    Delay(FSM[S].Time);
    Input = SENSOR; // read sensors (switches)
    S = FSM[S].Next[Input];
    // TODO (?): If SENSOR does not have inputs in the least significant bits, right shift (>>) the bits to
    //  move them to the least significant bits.
    // • Make sure the bits in Input count 0, 1, ... in decimal for the Next[Input]line to work as expected
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
	SYSCTL_RCGC2_R |=       // Activate Port A clocks
	while (?){} // wait for clock to be active
		
	GPIO_PORTA_AMSEL_R  // Disable analog function on PA3-2
  GPIO_PORTA_PCTL_R  // Enable regular GPIO
  GPIO_PORTA_DIR_R     // Inputs on PA3-2
  GPIO_PORTA_AFSEL_R  // Regular function on PA3-2
  GPIO_PORTA_DEN_R     // Enable digital signals on PA3-2
	GPIO_PORTA_PDR_R     // Optional: Enable pull-down resistors for PA3-2
}

void Light_Init(void){
	SYSCTL_RCGC2_R |=       // Activate Port E clocks
	while (?){} // wait for clock to be active
		
  GPIO_PORTE_AMSEL_R  // Disable analog function on PE3-0
  GPIO_PORTE_PCTL_R  // Enable regular GPIO
  GPIO_PORTE_DIR_R     // Outputs on PE3-0
  GPIO_PORTE_AFSEL_R  // Regular function on PE3-0
  GPIO_PORTE_DEN_R     // Enable digital on PE3-0
}
