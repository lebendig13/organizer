#ifndef CURRENT_H
#define CURRENT_H

#include <QFile>


class Current
{
public:
    Current();
    ~Current();

    void setPath(QString v);
    QString getPath();

    bool write();
    bool read();

private:
    QFile* curFile;

    QString path;
};

#endif // CURRENT_H
