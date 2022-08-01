#include <vector>

#include "../headers/ScrollFrame.h"

using namespace std;

ScrollFrame::ScrollFrame() {}

ScrollFrame::ScrollFrame(float w, float h, vector<TextBox> &obj)
{
    font.loadFromFile("../assets/fonts/Segoe_UI.ttf");
    width = w;
    height = h;
    mouseDown = false;
    frame.setSize(sf::Vector2f(w, h));
    frame.setPosition(sf::Vector2f(0, 550));
    frame.setFillColor(sf::Color(255, 255, 255, 100));
    scrollBar.setSize(sf::Vector2f(20, 50));
    scrollBar.setPosition(sf::Vector2f(980, 550));
    scrollBar.setFillColor(sf::Color(0, 0, 0, 100));
    rows = obj;
}

sf::RectangleShape ScrollFrame::getFrame()
{
    return frame;
}
sf::RectangleShape ScrollFrame::getScrollBar()
{
    return scrollBar;
}
bool ScrollFrame::getMouseDown()
{
    return mouseDown;
}

vector<TextBox> &ScrollFrame::getRows()
{
    return rows;
}
void ScrollFrame::setScrollBar(sf::Vector2f worldPos)
{
    float xPos = scrollBar.getPosition().x;
    if (xPos < 400)
    {
        xPos = 400;
    }
    scrollBar.setPosition(xPos, worldPos.y);
}

void ScrollFrame::setMouseDown(bool tf)
{
    mouseDown = tf;
}
void ScrollFrame::Scroll(sf::Vector2f worldPos)
{
    float yPos = worldPos.y;
    if (yPos < 550)
        yPos = 550;
    if (yPos > 850)
        yPos = 850;
    float scrollRatio = (yPos - 550.0f) / 300.0f;
    scrollBar.setPosition(scrollBar.getPosition().x, yPos);
    setRow(scrollRatio);
}

void ScrollFrame::setRow(float ratio)
{
    for (int i = 0; i < rows.size(); i++)
        rows[i].setBox(50, 550 + 40 * (i - (ratio * rows.size())));
}

void ScrollFrame::newRow(string s)
{
    TextBox text(make_pair(50, 550 + rows.size() * 40), make_pair(750, 30), s, font, 3);
    rows.push_back(text);
}
/*
    size_t pos;
    size_t pos2;
    pos = line.find(" ");
    string from = line.substr(0, pos);
    pos2 = line.find(" ", pos + 1);
    string to = line.substr(pos + 1, pos2 - pos - 1);
    double amount = stod(line.substr(pos2 + 1));

*/