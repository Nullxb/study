// xmlzy_1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "tinyxml.h"
#include <tinystr.h>
#include <string.h>
#include <windows.h>
#include <atlstr.h>
using namespace std;


CString GetAppPath()
{//��ȡӦ�ó����Ŀ¼
	TCHAR modulePath[MAX_PATH];
	GetModuleFileName(NULL, modulePath, MAX_PATH);
	CString strModulePath(modulePath);
	strModulePath = strModulePath.Left(strModulePath.ReverseFind(_T('\\')));
	return strModulePath;
}

bool CreateXmlFile(string& szFileName)
{//����xml�ļ�,szFilePathΪ�ļ������·��,�������ɹ�����true,����false
	try
	{
		//����һ��XML���ĵ�����
		TiXmlDocument *myDocument = new TiXmlDocument();
		//����һ����Ԫ��Library�����ӡ�
		TiXmlElement *RootElement = new TiXmlElement("Library");
		myDocument->LinkEndChild(RootElement);
		//����һ��BookԪ�ز����ӡ�
		TiXmlElement *LibraryElement = new TiXmlElement("Book");
		RootElement->LinkEndChild(LibraryElement);
		//����BookԪ�ص����ԡ�
		LibraryElement->SetAttribute("BookId", "978-7-5057-3323-7");
		//����TitleԪ�ء�AuthorԪ�ء�AuthorԪ�ء�PublicsherԪ�ء�CostԪ�ز����ӡ�
		TiXmlElement *TitleElement = new TiXmlElement("Title");
		TiXmlElement *AuthorElement = new TiXmlElement("Author");
		TiXmlElement *PriceElement = new TiXmlElement("Price");
		TiXmlElement *PublicsherElement = new TiXmlElement("Publicsher");
		TiXmlElement *CostElement = new TiXmlElement("Cost");
		LibraryElement->LinkEndChild(TitleElement);
		LibraryElement->LinkEndChild(AuthorElement);
		LibraryElement->LinkEndChild(PriceElement);
		LibraryElement->LinkEndChild(PublicsherElement);
		LibraryElement->LinkEndChild(CostElement);
		//����TitleԪ�ء�AuthorԪ�ء�PriceԪ�ء�PublicsherԪ�ء�CostԪ�ص����ݲ����ӡ�
		TiXmlText *TitleContent = new TiXmlText("��������������");
		TiXmlText *AuthorContent = new TiXmlText("[��] ���ס�����");
		TiXmlText *PriceContent = new TiXmlText("20.00RMB");
		TiXmlText *PublicsherContent = new TiXmlText("�й�������湫˾");
		TiXmlText *CostContent = new TiXmlText("18.00RMB");
		TitleElement->LinkEndChild(TitleContent);
		AuthorElement->LinkEndChild(AuthorContent);
		PriceElement->LinkEndChild(PriceContent);
		PublicsherElement->LinkEndChild(PublicsherContent);
		CostElement->LinkEndChild(CostContent);

		//����һ��MemberԪ�ز����ӡ�
		TiXmlElement *Library1Element = new TiXmlElement("Member");
		RootElement->LinkEndChild(Library1Element);
		//����MemberԪ�ص�NameԪ�ز����ӡ�
		TiXmlElement *NameElement = new TiXmlElement("Name");
		Library1Element->LinkEndChild(NameElement);
		//����FirstNameԪ�ء�MiddleNameԪ�ء�LastNameԪ�ز����ӡ�
		TiXmlElement *FirstNameElement = new TiXmlElement("FirstName");
		TiXmlElement *MiddleNameElement = new TiXmlElement("MiddleName");
		TiXmlElement *LastNameElement = new TiXmlElement("LastName");
		NameElement->LinkEndChild(FirstNameElement);
		NameElement->LinkEndChild(MiddleNameElement);
		NameElement->LinkEndChild(LastNameElement);
		//����FirstNameԪ�ء�MiddleNameԪ�ء�LastNameԪ�ص����ݲ����ӡ�
		TiXmlText *FirstNameContent = new TiXmlText("Xiaohua");
		TiXmlText *MiddleNameContent = new TiXmlText("Mary");
		TiXmlText *LastNameContent = new TiXmlText("Li");
		FirstNameElement->LinkEndChild(FirstNameContent);
		MiddleNameElement->LinkEndChild(MiddleNameContent);
		LastNameElement->LinkEndChild(LastNameContent);

		//����MemberԪ�ص�AddressԪ�ز����ӡ�
		TiXmlElement *AddressElement = new TiXmlElement("Address");
		Library1Element->LinkEndChild(AddressElement);
		//����HouseNumberԪ�ء�StreetԪ�ء�CityԪ�ز����ӡ�
		TiXmlElement *HouseNumberElement = new TiXmlElement("HouseNumber");
		TiXmlElement *StreetElement = new TiXmlElement("Street");
		TiXmlElement *CityElement = new TiXmlElement("City");
		AddressElement->LinkEndChild(HouseNumberElement);
		AddressElement->LinkEndChild(StreetElement);
		AddressElement->LinkEndChild(CityElement);
		//����HouseNumberԪ�ء�StreetԪ�ء�CityԪ�ص����ݲ����ӡ�
		TiXmlText *HouseNumberContent = new TiXmlText("221 B");
		TiXmlText *StreetContent = new TiXmlText("Baker");
		TiXmlText *CityContent = new TiXmlText("London");
		HouseNumberElement->LinkEndChild(HouseNumberContent);
		StreetElement->LinkEndChild(StreetContent);
		CityElement->LinkEndChild(CityContent);

		CString appPath = GetAppPath();
		string seperator = "\\";
		string fullPath = appPath.GetBuffer(0) + seperator + szFileName;
		myDocument->SaveFile(fullPath.c_str());//���浽�ļ�
	}
	catch (string& e)
	{
		return false;
	}
	return true;
}

bool ReadXmlFile(string& szFileName)
{//��ȡXml�ļ���������
	try
	{
		CString appPath = GetAppPath();
		string seperator = "\\";
		string fullPath = appPath.GetBuffer(0) + seperator + szFileName;
		//����һ��XML���ĵ�����
		TiXmlDocument *myDocument = new TiXmlDocument(fullPath.c_str());
		myDocument->LoadFile();
		//��ø�Ԫ�أ���Library��
		TiXmlElement *RootElement = myDocument->RootElement();
		//�����Ԫ�����ƣ������Library
		cout << RootElement->Value() << endl;

		//���Book�ڵ㡣
		TiXmlElement *Book = RootElement->FirstChildElement();
		//���Book��ID��Title�ڵ㡢Author�ڵ㡢Price�ڵ㡢Public�ڵ㡢Cost�ڵ����ԡ�
		TiXmlElement *TitleElement = Book->FirstChildElement();
		TiXmlElement *AuthorElement = TitleElement->NextSiblingElement();
		TiXmlElement *PriceElement = AuthorElement->NextSiblingElement();
		TiXmlElement *PublicElement = PriceElement->NextSiblingElement();
		TiXmlElement *CostElement = PublicElement->NextSiblingElement();
		TiXmlAttribute *BookIdAttribute = Book->FirstAttribute();
		cout << BookIdAttribute->Value() << endl;
		cout << TitleElement->FirstChild()->Value() << endl;
		cout << AuthorElement->FirstChild()->Value() << endl;
		cout << PriceElement->FirstChild()->Value() << endl;
		cout << PublicElement->FirstChild()->Value() << endl;
		cout << CostElement->FirstChild()->Value() << endl;

		//���Member�ڵ㡣
		TiXmlElement *Member = Book->NextSiblingElement();
		//���Member��Name,Address�ڵ㡣
		TiXmlElement *Name1Element = Member->FirstChildElement();
		TiXmlElement *Address = Name1Element->NextSiblingElement();
		//���Name��FirstName�ڵ㡢MiddleName�ڵ㡢LastName�ڵ�����ԡ�
		TiXmlElement *FirstNameElement = Name1Element->FirstChildElement();
		TiXmlElement *MiddleNameElement = FirstNameElement->NextSiblingElement();
		TiXmlElement *LastNameElement = MiddleNameElement->NextSiblingElement();
		cout << FirstNameElement->FirstChild()->Value() << endl;
		cout << MiddleNameElement->FirstChild()->Value() << endl;
		cout << LastNameElement->FirstChild()->Value() << endl;
		//���Address��HouseNumber�ڵ㡢Street�ڵ㡢City�ڵ�����ԡ�
		TiXmlElement *HouseNumberElement = Address->FirstChildElement();
		TiXmlElement *StreetElement = HouseNumberElement->NextSiblingElement();
		TiXmlElement *CityElement = StreetElement->NextSiblingElement();
		cout << HouseNumberElement->FirstChild()->Value() << endl;
		cout << StreetElement->FirstChild()->Value() << endl;
		cout << CityElement->FirstChild()->Value() << endl;

	}
	catch (string& e)
	{
		return false;
	}
	return true;
}
int main()
{
	string fileName = "info.xml";
	CreateXmlFile(fileName);
	ReadXmlFile(fileName);
	getchar();
	return 0;
}
