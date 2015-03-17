/*
 * QCVTool.h
 *
 *  Created on: 13 Mar, 2015
 *      Author: adrian
 */

#ifndef QCVTOOL_H_
#define QCVTOOL_H_

#include "cvtool.h"
#include <QObject>

class QCVTool: public QObject, protected CVTool
{
	Q_OBJECT

public:
	QCVTool();
	virtual ~QCVTool();

public slots:
	void setImageDirectory(QString qdir);
	void showResultSIFT();
	void showResultSURF();
	void showResultMSER();
	void showResultHaris();
	void showResultRepair();

signals:
	void imageDirectoryChanged(QString dir);
	void featuresDetectedAndMatched(QString method);
	void imageRepaired(QImage img);

private:
	CVTool cvtool;
};

#endif /* QCVTOOL_H_ */
