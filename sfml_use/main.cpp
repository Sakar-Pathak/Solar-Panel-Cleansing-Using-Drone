#include<SFML/Graphics.hpp>

int shiftX=0,shiftY=0;
    float zoom=1;

int main(){
    sf::RenderWindow window(sf::VideoMode(1920,1080),"My window");

    sf::View view(sf::Vector2f(960.0f,540.0f),sf::Vector2f(1920,1080));

    sf::Texture t1;
    t1.loadFromFile("solarpanel.png");

    sf::Sprite s1;

    s1.setTexture(t1);

    sf::Vector2f scale = s1.getScale();
    sf::Rect<float> size = s1.getGlobalBounds();
    s1.setOrigin(sf::Vector2f(size.width/2,size.height/2));

    s1.setScale(sf::Vector2f(0.5f,0.5f));

    sf::VertexArray lines(sf::Lines, 4);
    lines[0].position = sf::Vector2f(960, -99999);
    lines[0].color  = sf::Color::Black;
    lines[1].position = sf::Vector2f(960,99999);
    lines[1].color  = sf::Color::Black;
    lines[2].position = sf::Vector2f(-99999,540);
    lines[2].color  = sf::Color::Black;
    lines[3].position = sf::Vector2f(99999,540);
    lines[3].color  = sf::Color::Black;

     sf::CircleShape circle;



    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
           switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                    break;
                case sf::Event::KeyPressed:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                         shiftX-=5;
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                        shiftX+=5 ;
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                        shiftY-=5;
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                       shiftY+=5;
                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
                       zoom=zoom+0.001;
                       view.zoom(0.99);


                    }
                    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
                       zoom=zoom-0.001;
                       view.zoom(1.01);


                    }
                    break;
            }

        }




        s1.setPosition(shiftX-500,shiftY-500);



                    circle.setRadius(50);
                    circle.setOutlineColor(sf::Color::Red);
                    circle.setOutlineThickness(5);
                    circle.setPosition(shiftX+910, shiftY+490);


        sf::IntRect pos(0,0,461,763);
        window.clear(sf::Color(200,200,200));
        s1.setTextureRect(pos);
        window.draw(s1);
        window.draw(circle);
        window.draw(lines);
        window.setView(view);
        window.display();
    }
}



