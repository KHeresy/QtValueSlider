#pragma once

#include <QWidget>

namespace Ui { class QValueSlider; };

class QValueSlider : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(int Decimals READ decimals WRITE setDecimals)
	Q_PROPERTY(double Maximum READ maximum WRITE setMaximum)
	Q_PROPERTY(double Minimum READ minimum WRITE setMinimum)
	Q_PROPERTY(double Value READ value WRITE setValue NOTIFY valueChanged)

public:
	QValueSlider(QWidget *parent = Q_NULLPTR);
	~QValueSlider();

	void setDecimals(int);
	int decimals() const;

	void setRange(double dMin, double dMax);
	void setMaximum(double dMax);
	double maximum() const;
	void setMinimum(double dMin);
	double minimum() const;

	void setSingleStep(double dStep);

	void setValue(double dValue);
	double value() const;

signals:
	void valueChanged(double);

protected:
	void updateSliderSetting();
	void paintEvent(QPaintEvent* pEvt) override
	{
		QWidget::paintEvent(pEvt);
	}

protected slots:
	void spinBoxValueChanged(double);
	void sliderValueChanged(int);

private:
	double m_dSliderScale = 1.0;
	Ui::QValueSlider *ui;
};
