#include "Application.hpp"
#include <iostream>

Application::Application()
{
    //ctor
}

void Application::launch()
{
    m_window.create(sf::VideoMode(800, 600), "Trade Inteface");
    m_window.setActive(false);
    thread  t1(&Application::eventLoop,this),
            t2(&Application::logicLoop,this),
            t3(&Application::graphicLoop,this);


    t1.join();
    t2.join();
    t3.join();
}

void Application::graphicLoop()
{
    m_window.setActive(true);
    while(m_window.isOpen()){

        m_window.clear();
        m_window.display();
        sleep(seconds(1/60.f));
    }
}

void Application::logicLoop()
{

    while(m_window.isOpen()){
        sleep(seconds(1/60.f));
    }
}

void Application::eventLoop()
{
    Event event;
    while(m_window.isOpen()){
        while(m_window.pollEvent(event)){
            switch(event.type){
                case Event::Closed:
                    m_window.close();
                break;
            }
        }
    }
}
