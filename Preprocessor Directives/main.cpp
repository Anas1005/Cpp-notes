/*
 * Preprocessor Directives in C++
 *
 * This code demonstrates the usage of different types of preprocessor directives:
 *
 * 1. **Include Directives**
 *    - `#include`: Used to include the contents of a file (header files) into the current file.
 *
 * 2. **Macro Definition**
 *    - `#define`: Used to define a macro, which can be a constant or a function-like macro.
 *    - `#undef`: Used to undefine a previously defined macro.
 *
 * 3. **Conditional Compilation Directives**
 *    - `#if`: Conditional directive to include code if a specific condition is true.
 *    - `#ifdef`: Includes code if a macro is defined.
 *    - `#ifndef`: Includes code if a macro is not defined.
 *    - `#else`: Alternative code to include if the condition is false.
 *    - `#elif`: Combines `#else` and `#if` for multiple conditions.
 *    - `#endif`: Ends a conditional directive block.
 *
 * 4. **Predefined Macros**
 *    - `__DATE__`: Contains the date the source file was compiled.
 *    - `__TIME__`: Contains the time the source file was compiled.
 *    - `__FILE__`: Contains the name of the current source file.
 *    - `__LINE__`: Contains the current line number in the source file.
 *
 * This example illustrates these directives with practical use cases.
 */


#include <iostream>
#include <string>

// Practical usage of preprocessor directives in C++
// Shows how they can be used dynamically and practically within the code

int main() {
    // 1. #define - Defining Constants and Macros locally within the code context
    #define MAX_HEALTH 100
    #define GREETING(name) ("Hello, " + name + "! Welcome to the game.")

    std::string playerName = "Hero";
    std::cout << GREETING(playerName) << std::endl; // Using the macro to greet the player

    int playerHealth = 90;
    if (playerHealth > MAX_HEALTH) {
        std::cout << "Health exceeds maximum limit!" << std::endl;
    } else {
        std::cout << "Your current health is: " << playerHealth << " out of " << MAX_HEALTH << std::endl;
    }

    // 2. #undef - Changing a macro value based on context
    #undef MAX_HEALTH
    #define MAX_HEALTH 150 // Redefining MAX_HEALTH based on game difficulty

    int bossHealth = 120;
    std::cout << "Boss health: " << bossHealth << " out of " << MAX_HEALTH << std::endl;

    // 3. Conditional Compilation using #ifdef
    #define DEBUG // Toggle debug mode on or off by defining or commenting this line

    #ifdef DEBUG
        std::cout << "[DEBUG] Debugging information enabled." << std::endl;
        std::cout << "[DEBUG] Player name: " << playerName << std::endl;
        std::cout << "[DEBUG] Player health: " << playerHealth << std::endl;
        std::cout << "[DEBUG] Boss health: " << bossHealth << std::endl;
    #endif

    // 4. Using predefined macros for debugging/logging
    std::cout << "File: " << __FILE__ << std::endl;
    std::cout << "Compiled on: " << __DATE__ << " at " << __TIME__ << std::endl;
    std::cout << "Current line number: " << __LINE__ << std::endl;

    // 5. Conditional Compilation using #if, #elif, and #else
    int difficulty = 2; // Adjust difficulty level

    #if difficulty == 1
        std::cout << "Easy mode activated." << std::endl;
    #elif difficulty == 2
        std::cout << "Normal mode activated." << std::endl;
    #else
        std::cout << "Hard mode activated." << std::endl;
    #endif

    return 0;
}
