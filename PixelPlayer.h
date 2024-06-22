#ifndef PIXELPLAYER_H
#define PIXELPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class PixelPlayer; }
QT_END_NAMESPACE

class PixelPlayer : public QMainWindow {
    Q_OBJECT

public:
    PixelPlayer(QWidget *parent = nullptr);
    ~PixelPlayer();

private slots:
    void openFile();
    void play();
    void pause();
    void stop();

private:
    Ui::PixelPlayer *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QVideoWidget *videoWidget;
};

#endif // PIXELPLAYER_H
