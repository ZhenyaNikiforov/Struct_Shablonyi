/*- Задание-1 (Рендеринг HTML) -*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Text
{
private:
  string text;

public:
  Text()
  {
    this->text = "";
  }

  void setText(string textContent)
  {
    this->text = textContent;
  }

  string getText()
  {
    return this->text;
  }
};

class Paragraph
{
private:
  Text *ptr;

public:
  Paragraph(Text *ptr)
  {
    this->ptr = ptr;
  }

  ~Paragraph()
  {
    delete this->ptr;
  }

  void render(string content)
  {
    this->ptr->setText(content);
    cout << "<p>" << this->ptr->getText() << "</p>" << endl;
  }
};

class Reversed
{
private:
  Text *ptr;

public:
  Reversed(Text *ptr)
  {
    this->ptr = ptr;
  }

  ~Reversed()
  {
    delete this->ptr;
  }

  void render(string content)
  {
    this->ptr->setText(content);
    string line = this->ptr->getText();
    reverse(line.begin(), line.end());
    cout << "<p>" << line << "</p>" << endl;
  }
};

class Link
{
private:
  Text *ptr;

public:
  Link(Text *ptr)
  {
    this->ptr = ptr;
  }

  ~Link()
  {
    delete this->ptr;
  }

  void render(string href, string content)
  {
    this->ptr->setText(content);
    cout
        << "<a href = "
        << href
        << ">"
        << this->ptr->getText()
        << "</a>"
        << endl;
  }
};

int main()
{
  Paragraph *text_block = new Paragraph(new Text());
  text_block->render("Hello, World!");
  delete text_block;

  Reversed *reversed_block = new Reversed(new Text());
  reversed_block->render("Hello, Word!");
  delete reversed_block;

  Link *link_block = new Link(new Text());
  link_block->render("netology.ru", "Hello, World!");
  delete link_block;

  return 0;
}