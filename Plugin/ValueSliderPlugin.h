#pragma once

#include <QtUiPlugin/QDesignerCustomWidgetInterface>

class QValueSliderPlugin : public QObject, public QDesignerCustomWidgetInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")
	Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
	explicit QValueSliderPlugin(QObject* parent = nullptr);

	QIcon icon() const override;

	QString name() const override
	{
		return QStringLiteral("QValueSlider");
	}

	QString group() const override
	{
		return QStringLiteral("Input Widgets");
	}

	QString toolTip() const override
	{
		return QStringLiteral("Spin box with slider");
	}

	QString whatsThis() const override
	{
		return QStringLiteral("Spin box with slider");
	}

	bool isContainer() const override
	{
		return false;
	}

	void initialize(QDesignerFormEditorInterface*) override {}

	bool isInitialized() const override
	{
		return true;
	}

	QString includeFile() const override
	{
		return QStringLiteral("Lib/ValueSlider.h");
	}

	QString domXml() const override;
	QWidget* createWidget(QWidget* parent) override;
};
