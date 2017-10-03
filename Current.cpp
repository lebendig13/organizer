#include "Current.h"

Current::Current() : curFile(NULL)
{
    curFile = new QFile();
}

Current::~Current()
{
    if (curFile)
    {
        curFile = NULL;
        delete curFile;
    }
}

void Current::setPath(QString v)
{    path = v;   }

QString Current::getPath()
{    return path;   }

bool Current::write()
{

}

bool Current::read()
{

}
