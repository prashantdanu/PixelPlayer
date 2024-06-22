#include "PixelPlayer.h"
#include "ui_PixelPlayer.h"
#include <QFileDialog>
#include <QMessageBox>

PixelPlayer::PixelPlayer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PixelPlayer)
    , player(new QMediaPlayer(this))
    , playlist(new QMediaPlaylist(this))
    , videoWidget(new QVideoWidget(this))
{
    ui->setupUi(this);
    
    player->setPlaylist(playlist);
    player->setVideoOutput(videoWidget);
    
    setCentralWidget(videoWidget);
    
    connect(ui->actionOpen, &QAction::triggered, this, &PixelPlayer::openFile);
    connect(ui->actionPlay, &QAction::triggered, this, &PixelPlayer::play);
    connect(ui->actionPause, &QAction::triggered, this, &PixelPlayer::pause);
    connect(ui->actionStop, &QAction::triggered, this, &PixelPlayer::stop);
}

PixelPlayer::~PixelPlayer() {
    delete ui;
}

void PixelPlayer::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Media"), "", tr("Media Files (*.mp3 *.mp4 *.wav *.avi *.mkv)"));
    if (!fileName.isEmpty()) {
        playlist->addMedia(QUrl::fromLocalFile(fileName));
        play();
    }
}

void PixelPlayer::play() {
    if (player->state() != QMediaPlayer::PlayingState) {
        player->play();
    }
}

void PixelPlayer::pause() {
    if (player->state() == QMediaPlayer::PlayingState) {
        player->pause();
    }
}

void PixelPlayer::stop() {
    player->stop();
}
