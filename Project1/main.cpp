#include  <SFML/Graphics.hpp> // replace quotes with less than and greater than symbols
#include <stdlib.h>
#include <iostream>
#define ARR_SIZE 50
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bubble Sort");

    sf::Event ev;
    
    sf::RectangleShape arr[ARR_SIZE];

    sf::Color tempColor;
    float tempPos;
    bool sorted = false;

    // for completion text
    sf::Font font;
    sf::Text completionText;
    font.loadFromFile("ArialTh.ttf" );
    completionText.setFont(font);
    completionText.setCharacterSize(40);
    completionText.setPosition(sf::Vector2f(300, 50));
    completionText.setFillColor(sf::Color::Black);
    completionText.setString("Sorting Complete!");
    // pass counter
    int outerCounter = 0; 

    // iteration counter
    int j = 0;

    //randomize height
    time_t t;
    srand((unsigned)time(&t));

    sf::Clock clock;
    sf::Time elapsed;

    sf::Vector2f pos = sf::Vector2f(50, 450);
    int R = 50, G = 240, B = 170;
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i].setFillColor(sf::Color::White );
        arr[i].setPosition(pos.x += 13, pos.y);
        arr[i].setSize(sf::Vector2f(10, rand() % (300 - 20 - 1) + 20));
    }
    


    // set initial selected bar color 
   


    while (window.isOpen()) {

        while (window.pollEvent(ev)) {

            if (ev.type == sf::Event::Closed) {

                window.close();
            }
        }
        elapsed = clock.getElapsedTime();

        // sort alogrithm runs only once every 0.05s for visibility
        if (elapsed.asSeconds() >= 0.015f)
        {
                    // sort the array using bubble sort
                    if (arr[j].getSize().y < arr[j + 1].getSize().y) {
                        tempPos = arr[j].getSize().y;
                        tempColor = arr[j].getFillColor();

                        arr[j].setSize(sf::Vector2f(10, arr[j + 1].getSize().y));
                       // arr[j].setFillColor(arr[j + 1].getFillColor());

                        arr[j + 1].setSize(sf::Vector2f(10, tempPos));
                        //arr[j + 1].setFillColor(tempColor);
                        
                        
                    }
                    arr[j].setFillColor(sf::Color::White);
                    arr[j + 1].setFillColor(sf::Color::White);
                    j++; // increment inner loop

                    if (j >= ARR_SIZE - outerCounter - 1) {
             
                        outerCounter++; // increment pass
                        j = 0;
                    }

                    if (outerCounter == ARR_SIZE - 2) sorted = true;
                    
               
            skip:
            clock.restart();
        }

        window.clear();

  
        for (int i = 0; i < ARR_SIZE; i++) {

            arr[i].setOrigin(0, arr[i].getSize().y);
           
            window.draw(arr[i]);
            

            if (!sorted) {
                arr[j].setFillColor(sf::Color::Red);
                arr[j + 1].setFillColor(sf::Color::Red);
            }
           
        }

        window.draw(completionText);

        if (sorted) {
            completionText.setFillColor(sf::Color::White);
        }
        window.display();
       
    }

    return 0;
}