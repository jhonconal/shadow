// =====================================================================================
// 
//	   Filename:  camaredialog.cpp
//
//	Description:  摄像头对话框实现文件
//
//		Version:  1.0
//		Created:  2013年03月07日 20时11分20秒
//	   Revision:  none
//	   Compiler:  cl
//
//		 Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//		Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "camaredialog.h"
#include "camareget.h"

CamareDialog::CamareDialog(QWidget * parent) : QDialog(parent)
{
	setupUi(this);

	label->setPixmap(QPixmap(":/res/images/camarewait.png"));

	camaraGet = new CamaraGet();

	camaraGet->setLabel(label);

	connect(startButton, SIGNAL(clicked()), camaraGet, SLOT(openCamara()));
	connect(stopButton, SIGNAL(clicked()), camaraGet, SLOT(closeCamara()));

	setWindowIcon(QIcon(":/res/images/camare.png"));
}

CamareDialog::~CamareDialog()
{

}

void CamareDialog::closeEvent(QCloseEvent *event)
{
	camaraGet->closeCamara();
}
