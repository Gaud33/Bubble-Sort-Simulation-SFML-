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
    int outerCounter = 0;
    int j = 0;
    //randomize height
    time_t t;
    srand((unsigned)time(&t));

    sf::Clock clock;
    sf::Time elapsed;

    sf::Vector2f pos = sf::Vector2f(50, 450);
    int R = 50, G = 240, B = 170;
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i].setFillColor(sf::Color(R+= 5,  G, B += 5 ));
        arr[i].setPosition(pos.x += 13, pos.y);
        arr[i].setSize(sf::Vector2f(10, rand() % (200 - 20 - 1) + 20));
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
        if (elapsed.asSeconds() >= 0.05f)
        {
                    // sort the array using bubble sort
                    if (arr[j].getSize().y < arr[j + 1].getSize().y) {
                        tempPos = arr[j].getSize().y;
                        tempColor = arr[j].getFillColor();

                        arr[j].setSize(sf::Vector2f(10, arr[j + 1].getSize().y));
                        arr[j].setFillColor(arr[j + 1].getFillColor());

                        arr[j + 1].setSize(sf::Vector2f(10, tempPos));
                        arr[j + 1].setFillColor(tempColor);
   
                    }
                    j++; // increment inner loop

                    if (j >= ARR_SIZE - outerCounter - 1) {
             
                        outerCounter++; // increment pass
                        j = 0;
                    }
                    
               
            skip:
            clock.restart();
        }

        

        window.clear();

  
        for (int i = 0; i < ARR_SIZE; i++) {

            arr[i].setOrigin(0, arr[i].getSize().y);
            window.draw(arr[i]);
        }

        window.display();
       
    }

    return 0;
}