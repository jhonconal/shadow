// =====================================================================================
// 
//	   Filename:  debug.h
//
//	Description:  ��������ͷ�ļ�
//
//		Version:  1.0
//		Created:  2013��03��06�� 16ʱ37��20��
//	   Revision:  none
//	   Compiler:  cl
//
//		 Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//		Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef DEBUG_H_
#define DEBUG_H_

#include <QDebug>
#include <QFile>
#include <QTextStream>

#define _TIME_ qPrintable(QTime::currentTime ().toString ("hh:mm:ss:zzz"))

void customMessageHandler(QtMsgType type, const char *msg)
{
	QString qstrText;

	switch (type)
		{
		case QtDebugMsg:
			qstrText = QString("%1: %2").arg(_TIME_, msg);
			break;
		case QtWarningMsg:
			qstrText = QString("%1: %2").arg(_TIME_, msg);
			break;
		case QtCriticalMsg:
			qstrText = QString("%1: %2").arg(_TIME_, msg);
			break;
		case QtFatalMsg:
			qstrText = QString("%1: %2").arg(_TIME_, msg);
			exit(0);
		}

		QFile outFile("debug.log");

		outFile.open(QIODevice::WriteOnly | QIODevice::Append);
		QTextStream logStream(&outFile);

		logStream << qstrText << endl;
}

#endif // DEBUG_H_