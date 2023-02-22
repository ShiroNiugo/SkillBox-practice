#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QGridLayout>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>

class Circle : public QWidget {
    Q_OBJECT

public:
    Circle() = default;
    Circle(QWidget* parent) {
        setParent(parent);
        circleGreen = QPixmap("../image/green.png");
        circleYellow = QPixmap("../image/yellow.png");
        circleRed = QPixmap("../image/red.png");
        circleCurrent = circleGreen;
        setGeometry(circleCurrent.rect());
    }

    void paintEvent(QPaintEvent* e) override {
        QPainter paintCurrent(this);
        paintCurrent.drawPixmap(e->rect(), circleCurrent);
    }
    QSize minimumSizeHint() const override {
        return QSize(100, 100);
    }
public slots:
    void setGreen() {
        circleCurrent = circleGreen;
        update();
    }
    void setYellow() {
        circleCurrent = circleYellow;
        update();
    }
    void setRed() {
        circleCurrent = circleRed;
        update();
    }
private:
    QPixmap circleCurrent;
    QPixmap circleGreen;
    QPixmap circleYellow;
    QPixmap circleRed;
};
#include "CMakeProject1.moc"
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    auto window = new QWidget();
    window->setFixedSize(200, 250);

    auto layout = new QVBoxLayout(window);

    auto circle = new Circle(window);
    circle->setFixedSize(180, 150);

    auto slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(100);

    layout->addWidget(circle);
    layout->addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged, [slider, &circle](int newValue) {
        if (slider->value() <= 33) { circle->setGreen(); }
        else if (slider->value() <= 66) { circle->setYellow(); }
        else if (slider->value() <= 100) { circle->setRed(); }
        });
    window->show();
    app.exec();
    delete circle;
    return 0;
}
