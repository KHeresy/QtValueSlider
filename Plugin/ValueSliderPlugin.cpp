#include "ValueSliderPlugin.h"

#include "Lib/ValueSlider.h"

QValueSliderPlugin::QValueSliderPlugin(QObject* parent)
{}

QIcon QValueSliderPlugin::icon() const
{
	return QIcon();
}

QString QValueSliderPlugin::domXml() const
{
	return	R"xml(
			<ui language="c++">
			<widget class="QValueSlider" name="QValueSlider">
				<property name="geometry">
					<rect>
						<x>0</x>
						<y>0</y>
						<width>230</width>
						<height>20</height>
					</rect>
				</property>
				<property name="toolTip" >
					<string>Spin box with slider</string>
				</property>
				<property name="whatsThis" >
					<string>Spin box with slider</string>
				</property>
			</widget>
			</ui>)xml";
}

QWidget* QValueSliderPlugin::createWidget(QWidget* parent)
{
	return new QValueSlider(parent);
}
