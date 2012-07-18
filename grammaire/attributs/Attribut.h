#ifndef ATTRIBUT_H
#define ATTRIBUT_H
#include <QString>
#include "../../geometrie/Polygone.h"
class Attribut
{
public:
virtual int intValue(){return -1;}
virtual bool boolValue(){return false;}
virtual float floatValue(){return 0;}
virtual Polygone* polygoneValue(){return NULL;}
virtual string strValue(){return string();}
virtual void* ptrValue(){return NULL;}
virtual QString toString()=0;
};

class AttributBool : public Attribut
{
public : 
AttributBool(bool val){value=val;}
bool boolValue(){return value;}
QString toString(){return value ? "true":"false";}
private: 
bool value;
};

class AttributPoly : public Attribut
{
public : 
AttributPoly(Polygone* p){value=p;}
Polygone* polygoneValue(){return value;}
QString toString(){return QString("polygone")+QString::number(value->number);}
private: 
Polygone* value;
};

class AttributPtr : public Attribut
{
public : 
AttributPtr(void* ptr){value=ptr;}
void* ptrValue(){return value;}
QString toString(){return QString::number((int)	value);}
private: 
void* value;
};

class AttributStr : public Attribut
{
public : 
AttributStr(string str){value=str;}
string strValue(){return value;}
QString toString(){return QString::fromStdString(value);}
private: 
string value;
};

class AttributInt : public Attribut
{
public : 
AttributInt(int val){value=val;}
int intValue(){return value;}
QString toString(){return QString::number(value);}
private: 
int value;
};

class AttributFloat : public Attribut
{
public : 
AttributFloat(float val){value=val;}
float floatValue(){return value;}
QString toString(){return QString::number(value);}
private: 
float value;
};
#endif