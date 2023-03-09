#pragma once

#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

#include <QMediaPlayer>

class Button : public QPushButton {
Q_OBJECT
public:
    Button() = default;
    Button(QWidget* parent) {
        setParent(parent);
        setToolTip("Stop");
        setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        up = QPixmap("../image/up.png");
        down = QPixmap("../image/down.png");
        current = up;
        player = new QMediaPlayer(this);
        player->setMedia(QUrl::fromLocalFile("../sound/click.mp3"));
        player->setVolume(100);
        setGeometry(current.rect());
        connect(this, &QPushButton::clicked, this, &Button::setDown);
        connect(this, &QPushButton::clicked, player, &QMediaPlayer::play);
    }
    void paintEvent(QPaintEvent* e) override {
        QPainter p(this);
        p.drawPixmap(e->rect(), current);
    }
    QSize sizeHint() const override {
        return QSize(100, 100);
    }
    QSize minimumSizeHint() const override {
        return sizeHint();
    }
    void keyPressEvent(QKeyEvent* e) override {
        setDown();
    }
public slots:
    void setUp() {
        current = up;
        update();
    }
    void setDown() {
        current = down;
        update();
        QTimer::singleShot(100, this, &Button::setUp);
    }
private:
    QPixmap current;
    QPixmap up;
    QPixmap down;
    QMediaPlayer *player;
};
