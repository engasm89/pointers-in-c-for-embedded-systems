/*
 * Course: Pointers In C For Embedded Systems
 * Platform: Embedded Systems
 * Author: Ashraf S A AlMadhoun
 * Purpose: Auto-generated metadata block to document the learning goals.
 * Notes: Auto-generated metadata block (2025-11-18)
 */

#include <stdio.h> // Include standard I/O for printing
#include <stdlib.h> // Include stdlib for dynamic memory allocation
#include <stdint.h> // Include stdint for fixed-width integer types

// Define a simulated memory-mapped register address
#define LED_REG_ADDR 0x40000000u // Base address for a simulated LED register

// Declare a volatile pointer to the LED register
volatile uint32_t *LED_REG = (volatile uint32_t *)LED_REG_ADDR; // Volatile pointer to hardware

// Function type for pointer-to-function demonstration
typedef void (*action_t)(int); // Function pointer type taking an int

// Example function that matches the action_t signature
void scale_and_print(int x) { // Function to scale and print a value
  int y = x * 2; // Scale the input by 2
  printf("scaled=%d\n", y); // Print the scaled value
} // End function

// Write a value to the simulated LED register
void write_led(uint32_t value) { // Function to write to LED register
  *LED_REG = value; // Dereference volatile pointer and assign value
  printf("LED_REG=0x%08X\n", *LED_REG); // Print the register contents
} // End function

// Demonstrate pointer arithmetic on an array
void array_pointer_demo(void) { // Function to demonstrate pointer arithmetic
  uint8_t *buf = (uint8_t *)malloc(8); // Allocate 8 bytes of memory
  if (!buf) { // Check if allocation failed
    printf("malloc failed\n"); // Print error message
    return; // Early return on failure
  } // End allocation check
  for (size_t i = 0; i < 8; ++i) { // Loop over allocated bytes
    *(buf + i) = (uint8_t)(i * 3); // Write a pattern using pointer arithmetic
  } // End write loop
  for (size_t i = 0; i < 8; ++i) { // Loop to read back values
    printf("buf[%zu]=%u\n", i, (unsigned)buf[i]); // Print each value
  } // End read loop
  free(buf); // Free allocated memory
} // End function

// Demonstrate const and volatile pointer qualifiers
void qualifiers_demo(void) { // Function to demonstrate qualifiers
  const uint16_t value = 1234; // Constant value that cannot be modified
  const uint16_t *p_const = &value; // Pointer to const data
  printf("const=%u\n", (unsigned)*p_const); // Read and print const data
  volatile uint16_t sensor = 0; // Volatile data that may change outside code
  volatile uint16_t *p_vol = &sensor; // Pointer to volatile data
  *p_vol = 55; // Write to volatile location
  printf("volatile=%u\n", (unsigned)*p_vol); // Read and print volatile data
} // End function

// Demonstrate pointer-to-pointer usage
void pointer_to_pointer_demo(void) { // Function demonstrating pointer-to-pointer
  int value = 7; // Initialize an integer value
  int *p = &value; // Pointer to the integer
  int **pp = &p; // Pointer to the pointer
  **pp = 42; // Modify the original value via double pointer
  printf("value=%d\n", value); // Print the modified value
} // End function

// Entry point for the program
// Main routine: orchestrates the pointers in c for embedded systems scenario
int main(void) { // Start of main function
  printf("Pointers in C for Embedded Systems\n"); // Print title
  write_led(0x00000001u); // Write a value to the simulated LED register
  array_pointer_demo(); // Run the array pointer arithmetic demo
  qualifiers_demo(); // Run the qualifiers demo
  pointer_to_pointer_demo(); // Run the pointer-to-pointer demo
  action_t act = scale_and_print; // Assign function address to function pointer
  act(21); // Invoke function via pointer
  return 0; // Return success
} // End of main

