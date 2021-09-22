#include "ValueSlider.h"
#include "ui_ValueSlider.h"

#include <cmath>

QValueSlider::QValueSlider(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::QValueSlider();
	ui->setupUi(this);

	setDecimals(0);
}

QValueSlider::~QValueSlider()
{
	delete ui;
}

void QValueSlider::setDecimals(int iDec)
{
	if (iDec == 0)
		m_dSliderScale = 1.0;
	else
		m_dSliderScale = std::pow(10, iDec);

	ui->doubleSpinBox->setDecimals(iDec);
	updateSliderSetting();
}

int QValueSlider::decimals() const
{
	return ui->doubleSpinBox->decimals();
}

void QValueSlider::setRange(double dMin, double dMax)
{
	ui->doubleSpinBox->setRange(dMin, dMax);
	updateSliderSetting();
}

void QValueSlider::setMaximum(double dMax)
{
	ui->doubleSpinBox->setMaximum(dMax);
	updateSliderSetting();
}

double QValueSlider::maximum() const
{
	return ui->doubleSpinBox->maximum();
}

void QValueSlider::setMinimum(double dMin)
{
	ui->doubleSpinBox->setMinimum(dMin);
	updateSliderSetting();
}

double QValueSlider::minimum() const
{
	return ui->doubleSpinBox->minimum();
}

void QValueSlider::setSingleStep(double dStep)
{
	ui->doubleSpinBox->setSingleStep(dStep);
	updateSliderSetting();
}

void QValueSlider::setValue(double dValue)
{
	ui->doubleSpinBox->setValue(dValue);
}

double QValueSlider::value() const
{
	return ui->doubleSpinBox->value();
}

void QValueSlider::updateSliderSetting()
{
	ui->horizontalSlider->setRange(ui->doubleSpinBox->minimum() * m_dSliderScale, ui->doubleSpinBox->maximum() * m_dSliderScale);
	ui->horizontalSlider->setTickInterval(ui->doubleSpinBox->singleStep() * m_dSliderScale);
}

void QValueSlider::spinBoxValueChanged(double dValue)
{
	ui->horizontalSlider->blockSignals(true);
	ui->horizontalSlider->setValue(dValue * m_dSliderScale);
	ui->horizontalSlider->blockSignals(false);

	emit valueChanged(dValue);
}

void QValueSlider::sliderValueChanged(int iValue)
{
	double dValue = ((double)iValue) / m_dSliderScale;
	ui->doubleSpinBox->blockSignals(true);
	ui->doubleSpinBox->setValue(dValue);
	ui->doubleSpinBox->blockSignals(false);

	emit valueChanged(dValue);
}
