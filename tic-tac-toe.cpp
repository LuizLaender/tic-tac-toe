#include <iostream>     // Input/Output stream
#include <string>       // Access and manipulate strings 
#include <vector>       // Vector support

void printPlayground(const std::vector < std::string >& matrix) // Function used to print the playground
{
    for (const auto& row : matrix)
    {
        std::cout << row << std::endl;
    }
}

int main()
{
    std::string col1 = " | | ";
    std::string col2 = "-+-+-";
    std::string col3 = " | | ";
    std::string col4 = "-+-+-";
    std::string col5 = " | | ";

    std::vector < std::string > matrix = { col1, col2, col3, col4, col5 }; // Stores the strings into the playground matrix

    std::string playerInput; // Stores the player input as a raw string

    int currentPlayer = 1; // Variable used to control each player's turn

    int playerInputRow; // Variable used to store in witch row the player will place his 'X' or 'O'
    int playerInputCol; // Variable used to store in witch column the player will place his 'X' or 'O'

    bool gameStatePlay = true; // Stores the value for controlling if the game runs or not
    bool isValidInput = false;

    std::cout << "  __________________________________  " << std::endl;
    std::cout << " |                                  | " << std::endl;
    std::cout << " |  Hello World!                    | " << std::endl;
    std::cout << " |  Let's play tic-tac-toe!         | " << std::endl;
    std::cout << " |__________________________________| " << std::endl;
    std::cout << std::endl;

    while (gameStatePlay == true) // Runs the game
    {
        std::getline(std::cin, playerInput); // Receives player input

        int playerInputRow = playerInput[0] - '1'; // Selects and stores the -first- number that the player typed
        int playerInputCol = playerInput[2] - '1'; // Selects and stores the -second- number that the player typed

        if (playerInputRow >= 0 && playerInputRow < 3 && playerInputCol >= 0 && playerInputCol < 3) // Player can only type 1, 2 or 3
        {
            isValidInput = true;

            switch (currentPlayer) // Controls witch player goes next
            {
            case 1: // Player 1
                matrix[2 * playerInputCol][2 * playerInputRow] = 'X'; // Marks the spot desired by the player 1
                printPlayground(matrix); // Prints the playground
                currentPlayer = 2; // Sets who's going to be the next player
                break;
            case 2: // Player 2
                matrix[2 * playerInputCol][2 * playerInputRow] = 'O'; // Marks the spot desired by the player 2
                printPlayground(matrix); // Prints the playground
                currentPlayer = 1; // Sets who's going to be the next player
                break;
            }
        }
        else
        {
            std::cout << "Invalid input, try again!" << std::endl; // If the player chose a number different from 1,2 or 3 = Error
            isValidInput = true;
        }

        if (isValidInput == true)
        {
            continue;
        }

    }

}
