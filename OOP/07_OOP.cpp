#include <iostream>
#include <map>
#include <string>
#include <iomanip>

int main()
{
    // Map to store state names as keys and population as values
    std::map<std::string, long> statePopulation;

    // Adding some Indian states and their populations (in millions)
    statePopulation["Uttar Pradesh"] = 240000000;
    statePopulation["Maharashtra"] = 124000000;
    statePopulation["Bihar"] = 127000000;
    statePopulation["West Bengal"] = 100000000;
    statePopulation["Madhya Pradesh"] = 87000000;
    statePopulation["Tamil Nadu"] = 78000000;
    statePopulation["Rajasthan"] = 81000000;
    statePopulation["Karnataka"] = 68000000;
    statePopulation["Gujarat"] = 64000000;
    statePopulation["Andhra Pradesh"] = 54000000;

    std::string state;
    char choice;

    do
    {
        // Prompt the user to enter a state name
        std::cout << "\nEnter the name of an Indian state: ";
        std::getline(std::cin, state); // Use getline to handle state names with spaces

        // Search for the state in the map
        auto it = statePopulation.find(state);

        if (it != statePopulation.end())
        {
            // If the state is found, output the population in millions
            std::cout << "The population of " << state << " is "
                      << std::fixed << std::setprecision(2) << it->second / 1000000.0
                      << " million people." << std::endl;
        }
        else
        {
            // If the state is not found
            std::cout << "State not found in the map." << std::endl;
        }

        // Ask the user if they want to continue
        std::cout << "\nWould you like to search for another state? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(); // To clear the newline character from the input buffer

    } while (choice == 'y' || choice == 'Y');

    std::cout << "Exiting dashboard. Thank you!" << std::endl;

    return 0;
}
